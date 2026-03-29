/*
 * OBC1 emulation code
 * (c) Copyright 2001-2004 zsKnight, pagefault, Kris Bleakley
 * Ported from x86 assembler to C by sanmaiwashi
 *
 * Used by: Metal Combat: Falcon's Revenge
 *
 * The OBC1 is a simple sprite management chip that provides
 * fast OAM manipulation. It maps to $7ff0-$7fff for registers
 * and uses SRAM at $6000-$7fef for OAM data storage.
 */

#include "snes9x.h"
#include "memmap.h"
#include "obc1.h"

uint8 *OBC1RAM = NULL;

static uint8 obc1_ram[8192]; // 8KB internal RAM

#define OBC1_LOWER  0x6000
#define OBC1_UPPER  0x7fff

static int OBC1_Address;
static int OBC1_BasePtr;
static int OBC1_Shift;

uint8 S9xGetOBC1(uint16 Address)
{
    switch (Address)
    {
    case 0x7ff0:
        return obc1_ram[OBC1_BasePtr + (OBC1_Address << 2)];
    case 0x7ff1:
        return obc1_ram[OBC1_BasePtr + (OBC1_Address << 2) + 1];
    case 0x7ff2:
        return obc1_ram[OBC1_BasePtr + (OBC1_Address << 2) + 2];
    case 0x7ff3:
        return obc1_ram[OBC1_BasePtr + (OBC1_Address << 2) + 3];
    case 0x7ff4:
        return obc1_ram[OBC1_BasePtr + (OBC1_Address >> OBC1_Shift)];
    case 0x7ff5:
        // OBC1 status register
        return 0x01;
    default:
        if (Address >= OBC1_LOWER && Address <= OBC1_UPPER)
            return obc1_ram[Address - OBC1_LOWER];
        return 0;
    }
}

void S9xSetOBC1(uint8 Byte, uint16 Address)
{
    switch (Address)
    {
    case 0x7ff0:
        obc1_ram[OBC1_BasePtr + (OBC1_Address << 2)] = Byte;
        break;
    case 0x7ff1:
        obc1_ram[OBC1_BasePtr + (OBC1_Address << 2) + 1] = Byte;
        break;
    case 0x7ff2:
        obc1_ram[OBC1_BasePtr + (OBC1_Address << 2) + 2] = Byte;
        break;
    case 0x7ff3:
        obc1_ram[OBC1_BasePtr + (OBC1_Address << 2) + 3] = Byte;
        break;
    case 0x7ff4:
    {
        uint8 temp = obc1_ram[OBC1_BasePtr + (OBC1_Address >> OBC1_Shift)];
        temp = (temp & ~(3 << ((OBC1_Address & 3) << 1))) |
               ((Byte & 3) << ((OBC1_Address & 3) << 1));
        obc1_ram[OBC1_BasePtr + (OBC1_Address >> OBC1_Shift)] = temp;
        break;
    }
    case 0x7ff5:
        if (Byte & 1)
        {
            OBC1_BasePtr = 0x1800;
            OBC1_Shift = 2;
        }
        else
        {
            OBC1_BasePtr = 0;
            OBC1_Shift = 2;
        }
        break;
    case 0x7ff6:
        OBC1_Address = Byte & 0x7f;
        break;
    default:
        if (Address >= OBC1_LOWER && Address <= OBC1_UPPER)
            obc1_ram[Address - OBC1_LOWER] = Byte;
        break;
    }
}

void S9xResetOBC1(void)
{
    OBC1RAM = obc1_ram;
    memset(obc1_ram, 0, sizeof(obc1_ram));
    OBC1_Address = 0;
    OBC1_BasePtr = 0;
    OBC1_Shift = 2;
}
