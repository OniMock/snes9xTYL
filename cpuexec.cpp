/*
 * Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
 *
 * (c) Copyright 1996 - 2001 Gary Henderson (gary.henderson@ntlworld.com) and
 *                           Jerremy Koot (jkoot@snes9x.com)
 *
 * Super FX C emulator code 
 * (c) Copyright 1997 - 1999 Ivar (ivar@snes9x.com) and
 *                           Gary Henderson.
 * Super FX     assembler emulator code (c) Copyright 1998 zsKnight and _Demo_.
 *
 * DSP1 emulator code (c) Copyright 1998 Ivar, _Demo_ and Gary Henderson.
 * C4 asm and some C emulation code (c) Copyright 2000 zsKnight and _Demo_.
 * C4 C code (c) Copyright 2001 Gary Henderson (gary.henderson@ntlworld.com).
 *
 * DOS port code contains the works of other authors. See headers in
 * individual files.
 *
 * Snes9x homepage: http://www.snes9x.com
 *
 * Permission to use, copy, modify and distribute Snes9x in both binary and
 * source form, for non-commercial purposes, is hereby granted without fee,
 * providing that this license information and copyright notice appear with
 * all copies and any derived work.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event shall the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Snes9x is freeware for PERSONAL USE only. Commercial users should
 * seek permission of the copyright holders first. Commercial use includes
 * charging money for Snes9x or software derived from Snes9x.
 *
 * The copyright holders request that bug fixes and improvements to the code
 * should be forwarded to them so everyone can benefit from the modifications
 * in future versions.
 *
 * Super NES and Super Nintendo Entertainment System are trademarks of
 * Nintendo Co., Limited and its subsidiary companies.
 */

#include "snes9x.h"
#include "memmap.h"
#include "cpuops.h"
#include "ppu.h"
#include "cpuexec.h"
#include "debug.h"
#include "snapshot.h"
#include "gfx.h"
#include "missing.h"
#include "apu.h"
#include "dma.h"
#include "fxemu.h"
#include "fxinst.h"
#include "sa1.h"

extern struct SSA1 SA1;
extern struct FxInit_s SuperFX;
bool8 finishedFrame = false;

#ifdef DEBUGGER
#define IRQ_ACTIVE	CPU.IRQActive && !Settings.DisableIRQ
#else
#define IRQ_ACTIVE	CPU.IRQActive
#endif

void (*S9x_Current_HBlank_Event)();
void (*S9x_Current_Main_Loop_cpuexec)();
void (*S9x_Current_HBLANK_END_EVENT)();

// Doing the HBlank check before Adding MemSpeed seems to improve performance
// Optimizations based on snes9x 3DS
//
void S9xMainLoop_SA1_APU (void) {
	do{//for (;;) {
		UPDATE_APU_COUNTER();
	
	#ifdef CPU_SHUTDOWN
		CPU.PCAtOpcodeStart = CPU.PC;
	#endif
			
		if (CPU.Cycles >= CPU.NextEvent){
	#ifdef CPU_SHUTDOWN
			CPU.WaitCounter++;
	#endif
			(*S9x_Current_HBlank_Event)();
			
			if (finishedFrame) return;
		}
		
		CPU.Cycles += CPU.MemSpeed;
		(*ICPU.S9xOpcodes [*CPU.PC++].S9xOpcode)();
		
		if (SA1.Executing)
		{
			if (SA1.Flags & IRQ_PENDING_FLAG) S9xSA1CheckIRQ();
			(*SA1.S9xOpcodes [*SA1.PC++].S9xOpcode) ();
			(*SA1.S9xOpcodes [*SA1.PC++].S9xOpcode) ();
			(*SA1.S9xOpcodes [*SA1.PC++].S9xOpcode) ();
		}
	
		if (CPU.Flags) {
			if (CPU.Flags & NMI_FLAG)
				if (--CPU.NMICycleCount == 0){
					CPU.Flags &= ~NMI_FLAG;
					S9xOpcode_NMI ();
				}
			if (CPU.Flags & IRQ_PENDING_FLAG){
				if (CPU.IRQCycleCount == 0){
					if (!CheckFlag (IRQ))
						S9xOpcode_IRQ ();
				}
				else
					CPU.IRQCycleCount--;
			}
			if (CPU.Flags & SCAN_KEYS_FLAG) return;
		}
	}while(1);
}

void S9xMainLoop_NoSA1_APU (void) {
	do{//for (;;) {
		UPDATE_APU_COUNTER();
	
	#ifdef CPU_SHUTDOWN
		CPU.PCAtOpcodeStart = CPU.PC;
	#endif
	
		if (CPU.Cycles >= CPU.NextEvent){
	#ifdef CPU_SHUTDOWN
			CPU.WaitCounter++;
	#endif
			(*S9x_Current_HBlank_Event)();
			
			if (finishedFrame) return;
		}
		
		CPU.Cycles += CPU.MemSpeed;
		(*ICPU.S9xOpcodes [*CPU.PC++].S9xOpcode)();
	
		if (CPU.Flags) {
			if (CPU.Flags & NMI_FLAG)
				if (--CPU.NMICycleCount == 0){
					CPU.Flags &= ~NMI_FLAG;
					S9xOpcode_NMI ();
				}
			if (CPU.Flags & IRQ_PENDING_FLAG){
				if (CPU.IRQCycleCount == 0){
					if (!CheckFlag (IRQ))
						S9xOpcode_IRQ ();
				}
				else
					CPU.IRQCycleCount--;
			}
			if (CPU.Flags & SCAN_KEYS_FLAG) return;
		}
	}while(1);
}

void S9xMainLoop (void)
{
	//START_PROFILE_FUNC (S9xMainLoop);
	
	do{
		// This is a modification inspired on CATSFC.
		// The emulator executes the Main Loop selected on init_snes_rom
		// This avoids the constant Settings.SA1 and Settings.APUEnabled checks on S9xMainLoop.
		//
		(*S9x_Current_Main_Loop_cpuexec)();
		
		
#ifndef ME_SOUND	
		if (cpu_glob_cycles>=0x00000000)
				APU_EXECUTE2 ();
#endif	
		Registers.PCw = CPU.PC - CPU.PCBase;

		if (!finishedFrame)
        {
			S9xPackStatus ();
			if (CPU.Flags & SCAN_KEYS_FLAG) {
				//FINISH_PROFILE_FUNC (S9xMainLoop);
				S9xSyncSpeed ();
				CPU.Flags &= ~SCAN_KEYS_FLAG;
			}
		}
        else
        {
            finishedFrame = false;
            break;
        }
    }while(!finishedFrame);
}

void S9xSetIRQ (uint32 source)
{
  CPU.IRQActive |= source;
  CPU.Flags |= IRQ_PENDING_FLAG;
// For most games, IRQCycleCount should be set to 3.
// But for Mighty Morphin Power Rangers Fighting Edition, we must set to 0.
//
  CPU.IRQCycleCount = SNESGameFixes.IRQCycleCount;
  if (CPU.WaitingForInterrupt)
    {
    // Force IRQ to trigger immediately after WAI - 
    // Final Fantasy Mystic Quest, Chrono Trigger and many others
    // crash without this.
      CPU.IRQCycleCount = 0;
      CPU.WaitingForInterrupt = FALSE;
      CPU.PC++;
    }
}

void S9xClearIRQ (uint32 source)
{
  CLEAR_IRQ_SOURCE (source);
}

void S9xDoHBlankProcessing_HBLANK_START_EVENT ()
{
	//START_PROFILE_FUNC (S9xDoHBlankProcessing);
  if (IPPU.HDMA && CPU.V_Counter <= PPUPack.PPU.ScreenHeight) IPPU.HDMA = S9xDoHDMA (IPPU.HDMA);
  S9xReschedule ();
  //FINISH_PROFILE_FUNC (S9xDoHBlankProcessing); 
}

static void S9xDoHBlankProcessing_HBLANK_END_EVENT_2();

void S9xDoHBlankProcessing_HBLANK_END_EVENT_SFX ()
{
	if (!SuperFX.oneLineDone && CHECK_EXEC_SUPERFX())
		S9xSuperFXExec();
	SuperFX.oneLineDone = false;
	
	static const int addr[] = { 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31 };
	uint sizeAddr = sizeof(addr) / sizeof(int);
	
	for (uint i = 0; i < sizeAddr; i++)
	{
		int a = addr[i];
		if (IPPU.DeferredRegisterWrite[a] != 0xff00 &&
			IPPU.DeferredRegisterWrite[a] != ROM_GLOBAL[a + 0x2100])
		{
			//DEBUG_FLUSH_REDRAW(a + 0x2100, IPPU.DeferredRegisterWrite[a]);
			FLUSH_REDRAW();
			ROM_GLOBAL[a + 0x2100] = IPPU.DeferredRegisterWrite[a];
		}
		IPPU.DeferredRegisterWrite[a] = 0xff00;
	}
	
	S9xDoHBlankProcessing_HBLANK_END_EVENT_2();
}

void S9xDoHBlankProcessing_HBLANK_END_EVENT_SA1()
{
	static const int addr[] = { 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31 };
	uint sizeAddr = sizeof(addr) / sizeof(int);
	
	for (uint i = 0; i < sizeAddr; i++)
	{
		int a = addr[i];
		if (IPPU.DeferredRegisterWrite[a] != 0xff00 &&
			IPPU.DeferredRegisterWrite[a] != ROM_GLOBAL[a + 0x2100])
		{
			//DEBUG_FLUSH_REDRAW(a + 0x2100, IPPU.DeferredRegisterWrite[a]);
			FLUSH_REDRAW();
			ROM_GLOBAL[a + 0x2100] = IPPU.DeferredRegisterWrite[a];
		}
		IPPU.DeferredRegisterWrite[a] = 0xff00;
	}
	
	S9xDoHBlankProcessing_HBLANK_END_EVENT_2();
}

void S9xDoHBlankProcessing_HBLANK_END_EVENT ()
{
	//START_PROFILE_FUNC (S9xDoHBlankProcessing);			
	//if (Settings.SuperFX) S9xSuperFXExec ();

	// Based on snes9x 3DS
	// Optimization for a small number of PPU registers,
	// we will trigger the FLUSH_REDRAW here instead of
	// us doing it when the register values change. This is
	// because some games like FF3 and Ace o Nerae changes
	// the registers multiple times in the same scanline,
	// even though the end value is the same by the end of
	// the scanline. But because they modify the registers,
	// the rendering is forced to do a FLUSH_REDRAW.
	//
	// In this optimization, we simply defer the FLUSH_REDRAW
	// until this point here and only when we determine that 
	// at least one of the registers have changed from the
	// value in the previous scanline.
	//
	static const int addr[] = { 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31 };
	uint sizeAddr = sizeof(addr) / sizeof(int);
	
	if (SNESGameFixes.AceONeraeHack)
	{
		for (uint i = 0; i < sizeAddr; i++)
		{
			int a = addr[i];
			if (IPPU.DeferredRegisterWrite[a] != 0xff00 &&
				IPPU.DeferredRegisterWrite[a] != ROM_GLOBAL[a + 0x2100])
			{
				if (a == 0x31 &&
					ROM_GLOBAL[0x2126] == 0xFF && ROM_GLOBAL[0x2127] == 0x00 &&
					ROM_GLOBAL[0x2128] == 0xFF && ROM_GLOBAL[0x2129] == 0x00)
				{
					ROM_GLOBAL[a + 0x2100] = IPPU.DeferredRegisterWrite[a];
					continue;
				}
				//DEBUG_FLUSH_REDRAW(a + 0x2100, IPPU.DeferredRegisterWrite[a]);
				FLUSH_REDRAW();
				ROM_GLOBAL[a + 0x2100] = IPPU.DeferredRegisterWrite[a];
			}
			IPPU.DeferredRegisterWrite[a] = 0xff00;
		}
	}
	else
	{
		for (uint i = 0; i < sizeAddr; i++)
		{
			int a = addr[i];
			if (IPPU.DeferredRegisterWrite[a] != 0xff00 &&
				IPPU.DeferredRegisterWrite[a] != ROM_GLOBAL[a + 0x2100])
			{
				//DEBUG_FLUSH_REDRAW(a + 0x2100, IPPU.DeferredRegisterWrite[a]);
				FLUSH_REDRAW();
				ROM_GLOBAL[a + 0x2100] = IPPU.DeferredRegisterWrite[a];
			}
			IPPU.DeferredRegisterWrite[a] = 0xff00;
		}
	}
	
	S9xDoHBlankProcessing_HBLANK_END_EVENT_2();
}

static void S9xDoHBlankProcessing_HBLANK_END_EVENT_2()
{
	cpu_glob_cycles += CPU.Cycles-old_cpu_cycles;		
	CPU.Cycles -= Settings.H_Max;	
	old_cpu_cycles=CPU.Cycles;
	
#ifdef FAST_IAPU_APUEXECUTING_CHECK
	if (IAPU_APUExecuting_Main==false || APUExecuting_Main_Counter==0)
		IAPU_APUExecuting_Main = IAPU_APUExecuting;
	if (IAPU_APUExecuting_Main){
		apu_glob_cycles_Main=cpu_glob_cycles;
		if (cpu_glob_cycles>=0x00700000) {
			APU_EXECUTE2();
		}
	}
	else {
  		apu_glob_cycles=apu_glob_cycles_Main=0;
  		Uncache_APU_Cycles = 0;
	}
	if (APUExecuting_Main_Counter==0){
		FLUSH_APU();
	}
#else
  //(IAPUuncached.NextAPUTimerPos) -= (Settings.H_Max * 10000L);      
  if (  (IAPU_APUExecuting_Main)) {
  	//(APUPack.APU.Cycles) -= Settings.H_Max;
		apu_glob_cycles=cpu_glob_cycles;
#ifdef ME_SOUND		
		if (cpu_glob_cycles>=0x00700000)
			APU_EXECUTE2 ();
#endif		
  }
  else {
  	//(APUPack.APU.Cycles) = 0;
  	apu_glob_cycles=0;
  	Uncache_APU_Cycles = 0;
  }
#endif
  
  CPU.NextEvent = -1;
// not use
//  ICPU.Scanline++;

  if (++CPU.V_Counter > (Settings.PAL ? SNES_MAX_PAL_VCOUNTER : SNES_MAX_NTSC_VCOUNTER)) {
  	//PPUPack.PPU.OAMAddr = PPUPack.PPU.SavedOAMAddr;
    //PPUPack.PPU.OAMFlip = 0;            
    CPU.V_Counter = 0;
    ROM_GLOBAL[0x213F]^=0x80;
    CPU.NMIActive = FALSE;
    //ICPU.Frame++;
    PPUPack.PPU.HVBeamCounterLatched = 0;
    CPU.Flags |= SCAN_KEYS_FLAG;
    S9xStartHDMA ();
  }

  if (PPUPack.PPU.VTimerEnabled && !PPUPack.PPU.HTimerEnabled && CPU.V_Counter == PPUPack.PPU.IRQVBeamPos) S9xSetIRQ (PPU_V_BEAM_IRQ_SOURCE);
#if (1)
//  pEvent->apu_event1[pEvent->apu_event1_cpt2 & 0xFFFF]=(os9x_apu_ratio != 256) ? cpu_glob_cycles * os9x_apu_ratio / 256: cpu_glob_cycles;
//  pEvent->apu_event1_cpt2++;
  uint32 EventVal = (os9x_apu_ratio != 256) ? cpu_glob_cycles * os9x_apu_ratio / 256: cpu_glob_cycles;
  if (CPU.V_Counter & 1) {
    EventVal |= 0x80000000;
  }
#ifdef ME_SOUND
  int pos=apu_event1_cpt2_main++;
  apu_event1[pos & APU_EVENT_MASK] = EventVal;
  apu_event1_cpt2=apu_event1_cpt2_main;
#else
  int pos=apu_event1_cpt2;
  apu_event1[pos & APU_EVENT_MASK] = EventVal;
  apu_event1_cpt2=pos+1;
#endif

  //APU_EXECUTE2 ();
    
#else
	if (CPU.V_Counter & 1) {		
		apu_event2[(apu_event2_cpt2)&0xFFFF]=cpu_glob_cycles * os9x_apu_ratio / 256;  
		(apu_event2_cpt2)++;
	}	  
#endif

  if (CPU.V_Counter == FIRST_VISIBLE_LINE)
    {
      ROM_GLOBAL[0x4210] = 0;
      CPU.Flags &= ~NMI_FLAG;
      S9xStartScreenRefresh ();
    }
  if (CPU.V_Counter >= FIRST_VISIBLE_LINE &&
      CPU.V_Counter < PPUPack.PPU.ScreenHeight + FIRST_VISIBLE_LINE)
    {
      RenderLine (CPU.V_Counter - FIRST_VISIBLE_LINE);
      S9xReschedule ();                  
  		//FINISH_PROFILE_FUNC (S9xDoHBlankProcessing); 
  		return;
    }

  if (CPU.V_Counter == PPUPack.PPU.ScreenHeight + FIRST_VISIBLE_LINE)
    {
      // Start of V-blank
      S9xEndScreenRefresh ();
      //PPUPack.PPU.FirstSprite = 0;
      IPPU.HDMA = 0;
      // Bits 7 and 6 of $4212 are computed when read in S9xGetPPUPack.PPU.
#ifdef DEBUGGER
	  missing.dma_this_frame = 0;
#endif
	  IPPU.MaxBrightness = PPUPack.PPU.Brightness;
      PPUPack.PPU.ForcedBlanking = (ROM_GLOBAL[0x2100] >> 7) & 1;
      
      if(!PPUPack.PPU.ForcedBlanking){
				PPUPack.PPU.OAMAddr = PPUPack.PPU.SavedOAMAddr;			
				uint8 tmp = 0;
				if(PPUPack.PPU.OAMPriorityRotation)
					tmp = (PPUPack.PPU.OAMAddr&0xFE)>>1;
				if((PPUPack.PPU.OAMFlip&1) || PPUPack.PPU.FirstSprite!=tmp){
					PPUPack.PPU.FirstSprite=tmp;
					IPPU.OBJChanged=TRUE;
				}			
				PPUPack.PPU.OAMFlip = 0;
			}

      ROM_GLOBAL[0x4210] = 0x80;
      if (ROM_GLOBAL[0x4200] & 0x80) {
	  		CPU.NMIActive = TRUE;
	  		CPU.Flags |= NMI_FLAG;
	  		CPU.NMICycleCount = CPU.NMITriggerPoint;
			}

			S9xReschedule ();
  		//FINISH_PROFILE_FUNC (S9xDoHBlankProcessing); 
  		return;
    }

  if (CPU.V_Counter == PPUPack.PPU.ScreenHeight + 3)
    S9xUpdateJoypads ();

  S9xReschedule ();
  //FINISH_PROFILE_FUNC (S9xDoHBlankProcessing); 
}

void S9xDoHBlankProcessing_HTIMER_BEFORE_EVENT ()
{
	//START_PROFILE_FUNC (S9xDoHBlankProcessing);
  if (PPUPack.PPU.HTimerEnabled && (!PPUPack.PPU.VTimerEnabled || CPU.V_Counter == PPUPack.PPU.IRQVBeamPos)){
    S9xSetIRQ (PPU_H_BEAM_IRQ_SOURCE);
  }
  S9xReschedule ();
  //FINISH_PROFILE_FUNC (S9xDoHBlankProcessing); 
}

void S9xDoHBlankProcessing_HTIMER_AFTER_EVENT ()
{
	//START_PROFILE_FUNC (S9xDoHBlankProcessing);
  if (PPUPack.PPU.HTimerEnabled && (!PPUPack.PPU.VTimerEnabled || CPU.V_Counter == PPUPack.PPU.IRQVBeamPos)) {
    S9xSetIRQ (PPU_H_BEAM_IRQ_SOURCE);
  }
  S9xReschedule ();
  //FINISH_PROFILE_FUNC (S9xDoHBlankProcessing); 
}
