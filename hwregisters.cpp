/*******************************************************************************
  Snes9x - Portable Super Nintendo Entertainment System (TM) emulator.
 
  (c) Copyright 1996 - 2002 Gary Henderson (gary.henderson@ntlworld.com) and
                            Jerremy Koot (jkoot@snes9x.com)

  (c) Copyright 2001 - 2004 John Weidman (jweidman@slip.net)

  (c) Copyright 2002 - 2004 Brad Jorsch (anomie@users.sourceforge.net),
                            funkyass (funkyass@spam.shaw.ca),
                            Joel Yliluoma (http://iki.fi/bisqwit/)
                            Kris Bleakley (codeviolation@hotmail.com),
                            Matthew Kendora,
                            Nach (n-a-c-h@users.sourceforge.net),
                            Peter Bortas (peter@bortas.org) and
                            zones (kasumitokoduck@yahoo.com)

  C4 x86 assembler and some C emulation code
  (c) Copyright 2000 - 2003 zsKnight (zsknight@zsnes.com),
                            _Demo_ (_demo_@zsnes.com), and Nach

  C4 C++ code
  (c) Copyright 2003 Brad Jorsch

  DSP-1 emulator code
  (c) Copyright 1998 - 2004 Ivar (ivar@snes9x.com), _Demo_, Gary Henderson,
                            John Weidman, neviksti (neviksti@hotmail.com),
                            Kris Bleakley, Andreas Naive

  DSP-2 emulator code
  (c) Copyright 2003 Kris Bleakley, John Weidman, neviksti, Matthew Kendora, and
                     Lord Nightmare (lord_nightmare@users.sourceforge.net

  OBC1 emulator code
  (c) Copyright 2001 - 2004 zsKnight, pagefault (pagefault@zsnes.com) and
                            Kris Bleakley
  Ported from x86 assembler to C by sanmaiwashi

  SPC7110 and RTC C++ emulator code
  (c) Copyright 2002 Matthew Kendora with research by
                     zsKnight, John Weidman, and Dark Force

  S-DD1 C emulator code
  (c) Copyright 2003 Brad Jorsch with research by
                     Andreas Naive and John Weidman
 
  S-RTC C emulator code
  (c) Copyright 2001 John Weidman
  
  ST010 C++ emulator code
  (c) Copyright 2003 Feather, Kris Bleakley, John Weidman and Matthew Kendora

  Super FX x86 assembler emulator code 
  (c) Copyright 1998 - 2003 zsKnight, _Demo_, and pagefault 

  Super FX C emulator code 
  (c) Copyright 1997 - 1999 Ivar, Gary Henderson and John Weidman


  SH assembler code partly based on x86 assembler code
  (c) Copyright 2002 - 2004 Marcus Comstedt (marcus@mc.pp.se) 

 
  Specific ports contains the works of other authors. See headers in
  individual files.
 
  Snes9x homepage: http://www.snes9x.com
 
  Permission to use, copy, modify and distribute Snes9x in both binary and
  source form, for non-commercial purposes, is hereby granted without fee,
  providing that this license information and copyright notice appear with
  all copies and any derived work.
 
  This software is provided 'as-is', without any express or implied
  warranty. In no event shall the authors be held liable for any damages
  arising from the use of this software.
 
  Snes9x is freeware for PERSONAL USE only. Commercial users should
  seek permission of the copyright holders first. Commercial use includes
  charging money for Snes9x or software derived from Snes9x.
 
  The copyright holders request that bug fixes and improvements to the code
  should be forwarded to them so everyone can benefit from the modifications
  in future versions.
 
  Super NES and Super Nintendo Entertainment System are trademarks of
  Nintendo Co., Limited and its subsidiary companies.
*******************************************************************************/

#include "snes9x.h"
#include "memmap.h"
#include "hwregisters.h"
#include "apu.h"
#include "obc1.h"

uint8 S9xGetByteFromRegister (uint8 *GetAddress, uint32 Address)
{
	switch ((int) GetAddress)
	{
		case CMemory::MAP_PPU:
			return (S9xGetPPU (Address & 0xffff));
		case CMemory::MAP_CPU:
			return (S9xGetCPU (Address & 0xffff));
		case CMemory::MAP_DSP:
			return (S9xGetDSP (Address & 0xffff));
		case CMemory::MAP_SA1RAM:
		case CMemory::MAP_LOROM_SRAM:
			return (*(SRAM + ((((Address&0xFF0000)>>1) |(Address&0x7FFF)) &Memory.SRAMMask)));
		case CMemory::MAP_RONLY_SRAM:
		case CMemory::MAP_HIROM_SRAM:
			return (*(SRAM + (((Address & 0x7fff) - 0x6000 +
					  ((Address & 0xf0000) >> 3)) & Memory.SRAMMask)));
		case CMemory::MAP_DEBUG:
		case CMemory::MAP_BWRAM:
			return (*(BWRAM + ((Address & 0x7fff) - 0x6000)));
		case CMemory::MAP_C4:
			return (S9xGetC4 (Address & 0xffff));
		case CMemory::MAP_SPC7110_ROM:
			return (S9xGetSPC7110Byte(Address));

		case CMemory::MAP_SPC7110_DRAM:
			return (S9xGetSPC7110(0x4800));

	#ifdef _BSX_151_
		case CMemory::MAP_BSX:
			return S9xGetBSX(Address);
	#endif
		case CMemory::MAP_OBC1:
			return S9xGetOBC1(Address & 0xffff);
		default:
		case CMemory::MAP_NONE:
			return ((Address >> 8) & 0xff);
	}
}

uint16 S9xGetWordFromRegister (uint8 *GetAddress, uint32 Address)
{
	switch ((int) GetAddress)
    {
		case CMemory::MAP_PPU:
			return (S9xGetPPU (Address & 0xffff) |
			(S9xGetPPU ((Address + 1) & 0xffff) << 8));
		case CMemory::MAP_CPU:
			return (S9xGetCPU (Address & 0xffff) |
			(S9xGetCPU ((Address + 1) & 0xffff) << 8));
		case CMemory::MAP_DSP:
			return (S9xGetDSP (Address & 0xffff) |
			(S9xGetDSP ((Address + 1) & 0xffff) << 8));
		case CMemory::MAP_SA1RAM:
		case CMemory::MAP_LOROM_SRAM:
		   	/* no READ_WORD here, since if Memory.SRAMMask=0x7ff
			 * then the high byte doesn't follow the low byte. */
			return
				(*(SRAM + ((((Address&0xFF0000)>>1) |(Address&0x7FFF)) &Memory.SRAMMask)))|
				((*(SRAM + (((((Address+1)&0xFF0000)>>1) |((Address+1)&0x7FFF)) &Memory.SRAMMask)))<<8);

		case CMemory::MAP_RONLY_SRAM:
		case CMemory::MAP_HIROM_SRAM:
			
			/* no READ_WORD here, since if Memory.SRAMMask=0x7ff
			 * then the high byte doesn't follow the low byte. */
			return (*(SRAM +
					  (((Address & 0x7fff) - 0x6000 +
						((Address & 0xf0000) >> 3)) & Memory.SRAMMask)) |
					(*(SRAM +
					   ((((Address + 1) & 0x7fff) - 0x6000 +
						 (((Address + 1) & 0xf0000) >> 3)) & Memory.SRAMMask)) << 8));

		case CMemory::MAP_BWRAM:
		return (*(BWRAM + ((Address & 0x7fff) - 0x6000)) |
			(*(BWRAM + (((Address + 1) & 0x7fff) - 0x6000)) << 8));

		case CMemory::MAP_DEBUG:
	
		case CMemory::MAP_C4:
		return (S9xGetC4 (Address & 0xffff) |	
			(S9xGetC4 ((Address + 1) & 0xffff) << 8));
	
		case CMemory::MAP_SPC7110_ROM:
			return (S9xGetSPC7110Byte(Address) |
			(S9xGetSPC7110Byte(Address + 1) << 8));

		case CMemory::MAP_SPC7110_DRAM:
			return (S9xGetSPC7110(0x4800) |
			(S9xGetSPC7110(0x4800) << 8));

	#ifdef _BSX_151_
		case CMemory::MAP_BSX:
			return S9xGetBSX(Address)| (S9xGetBSX((Address+1))<<8);
	#endif

		default:
		case CMemory::MAP_NONE:
			return (((Address >> 8) | (Address & 0xff00)) & 0xffff);
    }
}

#define COMPARE_WRITE_SRAM(addr, data)  if (*(addr) != data) { *(addr) = data; CPU.SRAMModified = TRUE; }

void S9xSetByteToRegister (uint8 Byte, uint8* SetAddress, uint32 Address)
{
	switch ((int) SetAddress)
		{
		case CMemory::MAP_PPU:
			S9xSetPPU (Byte, Address & 0xffff);
		return;

		case CMemory::MAP_CPU:
			S9xSetCPU (Byte, Address & 0xffff);
		return;

		case CMemory::MAP_DSP:
			S9xSetDSP (Byte, Address & 0xffff);
		return;

		case CMemory::MAP_LOROM_SRAM:
			if (Memory.SRAMMask)
				COMPARE_WRITE_SRAM(SRAM + ((((Address&0xFF0000)>>1)|(Address&0x7FFF))& Memory.SRAMMask), Byte);
		return;

		case CMemory::MAP_HIROM_SRAM:
			if (Memory.SRAMMask)
				COMPARE_WRITE_SRAM(SRAM + (((Address & 0x7fff) - 0x6000 + 
					((Address & 0xf0000) >> 3)) & Memory.SRAMMask), Byte);
			return;

		case CMemory::MAP_BWRAM:
			COMPARE_WRITE_SRAM(BWRAM + ((Address & 0x7fff) - 0x6000), Byte);
		return;

		case CMemory::MAP_DEBUG:
	
		case CMemory::MAP_SA1RAM:
			*(SRAM + (Address & 0xffff)) = Byte;
		SA1.Executing = !SA1.Waiting;
		SA1.WaitCounter = 3;
		break;
	
		case CMemory::MAP_C4:
		S9xSetC4 (Byte, Address & 0xffff);
		return;
	
	#ifdef _BSX_151_
		case CMemory::MAP_BSX:
			S9xSetBSX(Byte,Address);
			return;
	#endif

		case CMemory::MAP_OBC1:
			S9xSetOBC1(Byte, Address & 0xffff);
			return;

		default:
		case CMemory::MAP_NONE:
			return;
		}
}

void S9xSetWordToRegister(uint16 Word, uint8 *SetAddress, uint32 Address)
{
	switch ((int) SetAddress)
	{
	case CMemory::MAP_PPU:
	S9xSetPPU ((uint8) Word, Address & 0xffff);
	S9xSetPPU (Word >> 8, (Address & 0xffff) + 1);
	return;

	case CMemory::MAP_CPU:
	S9xSetCPU ((uint8) Word, (Address & 0xffff));
	S9xSetCPU (Word >> 8, (Address & 0xffff) + 1);
	return;

	case CMemory::MAP_DSP:
	S9xSetDSP ((uint8) Word, (Address & 0xffff));
	S9xSetDSP (Word >> 8, (Address & 0xffff) + 1);
	return;

	case CMemory::MAP_LOROM_SRAM:
	   if (Memory.SRAMMask) {
			/* no WRITE_WORD here, since if Memory.SRAMMask=0x7ff
			* then the high byte doesn't follow the low byte. */
			COMPARE_WRITE_SRAM(SRAM + ((((Address&0xFF0000)>>1)|(Address&0x7FFF))& Memory.SRAMMask), (uint8) Word);
			COMPARE_WRITE_SRAM(SRAM + (((((Address+1)&0xFF0000)>>1)|((Address+1)&0x7FFF))& Memory.SRAMMask), Word >> 8);
		}
		return;

	case CMemory::MAP_HIROM_SRAM:
		if (Memory.SRAMMask)
		{
			/* no WRITE_WORD here, since if Memory.SRAMMask=0x7ff
			 * then the high byte doesn't follow the low byte. */
			COMPARE_WRITE_SRAM(SRAM + 
				((((Address & 0x7fff) - 0x6000 +
				((Address & 0xf0000) >> 3)) & Memory.SRAMMask)), (uint8) Word);
			COMPARE_WRITE_SRAM(SRAM + 
				(((((Address + 1) & 0x7fff) - 0x6000 +
				(((Address + 1) & 0xf0000) >> 3)) & Memory.SRAMMask)), (uint8) (Word >> 8));
		}
	return;

	case CMemory::MAP_BWRAM:
		COMPARE_WRITE_SRAM(BWRAM + ((Address & 0x7fff) - 0x6000), (uint8) Word);
		COMPARE_WRITE_SRAM(BWRAM + (((Address + 1) & 0x7fff) - 0x6000), (uint8) (Word >> 8));
	return;

	case CMemory::MAP_DEBUG:
	case CMemory::MAP_SA1RAM:
	*(SRAM + (Address & 0xffff)) = (uint8) Word;
	*(SRAM + ((Address + 1) & 0xffff)) = (uint8) (Word >> 8);
	SA1.Executing = !SA1.Waiting;
	SA1.WaitCounter = 3;
	break;
	
	case CMemory::MAP_C4:
	S9xSetC4 (Word & 0xff, Address & 0xffff);
	S9xSetC4 ((uint8) (Word >> 8), (Address + 1) & 0xffff);
	return;
	
	#ifdef _BSX_151_
	case CMemory::MAP_BSX:
		S9xSetBSX ((uint8) (Word >> 8),(Address + 1));
		S9xSetBSX (Word & 0xff, Address);
		return;
	#endif

	default:
	case CMemory::MAP_NONE:

	return;
	}
}

void S9xSetPCBaseOthers(uint8 *GetAddress, uint32 Address)
{
    switch ((int) GetAddress)
    {
        case CMemory::MAP_PPU:
            CPU.PCBase = ROM_GLOBAL;
            CPU.PC = CPU.PCBase + (Address & 0xffff);
            return;
            
        case CMemory::MAP_CPU:
            CPU.PCBase = ROM_GLOBAL;
            CPU.PC = CPU.PCBase + (Address & 0xffff);
            return;
            
        case CMemory::MAP_DSP:
            CPU.PCBase = ROM_GLOBAL - 0x6000;
            CPU.PC = CPU.PCBase + (Address & 0xffff);
            return;
            
        case CMemory::MAP_SA1RAM:
        case CMemory::MAP_LOROM_SRAM:
            CPU.PCBase = SRAM;
            CPU.PC = CPU.PCBase + (Address & 0xffff);
            return;
            
        case CMemory::MAP_BWRAM:
            CPU.PCBase = BWRAM - 0x6000;
            CPU.PC = CPU.PCBase + (Address & 0xffff);
            return;
        case CMemory::MAP_HIROM_SRAM:
            CPU.PCBase = SRAM - 0x6000;
            CPU.PC = CPU.PCBase + (Address & 0xffff);
            return;
            
        case CMemory::MAP_C4:
            CPU.PCBase = Memory.C4RAM - 0x6000;
            CPU.PC = CPU.PCBase + (Address & 0xffff);
            return;
			
#ifdef _BSX_151_
		case CMemory::MAP_BSX:
			CPU.PCBase = Memory.ROM;
            CPU.PC = CPU.PCBase + (Address & 0xffff);
			return;
#endif
		
        case CMemory::MAP_DEBUG:
#ifdef DEBUGGER
            printf ("SBP %06x\n", Address);
#endif
            
        default:
        case CMemory::MAP_NONE:
#ifdef DEBUGGER
            printf ("SBP %06x\n", Address);
#endif
            CPU.PCBase = SRAM;
            CPU.PC = SRAM + (Address & 0xffff);
            return;
    }
}