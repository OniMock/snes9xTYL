/*
 * ExtendedHiROMMap - Support for 48Mbit+ ExHiROM games
 * Used by: Tales of Phantasia, Daikaijuu Monogatari II
 * 
 * Include this file at the end of memmap.cpp (before IPS patch code)
 * and call ExtendedHiROMMap() from InitROM when ExHiROM is detected.
 */

void CMemory::ExtendedHiROMMap ()
{
    int c;
    int i;

    // Initialize speed map
    ResetSpeedMap();

    // Banks 00->3f and 80->bf
    for (c = 0; c < 0x400; c += 16)
    {
        Map [c + 0] = Map [c + 0x800] = RAM;
        Map [c + 1] = Map [c + 0x801] = RAM;
        BlockIsRAM [c + 0] = BlockIsRAM [c + 0x800] = TRUE;
        BlockIsRAM [c + 1] = BlockIsRAM [c + 0x801] = TRUE;
        
        Map [c + 2] = Map [c + 0x802] = (uint8 *) MAP_PPU;
        Map [c + 3] = Map [c + 0x803] = (uint8 *) MAP_PPU;
        Map [c + 4] = Map [c + 0x804] = (uint8 *) MAP_CPU;
        Map [c + 5] = Map [c + 0x805] = (uint8 *) MAP_CPU;

        // HiROM SRAM in banks 20-3f and a0-bf
        if (c >= 0x200)
        {
            Map [c + 6] = Map [c + 0x806] = (uint8 *) MAP_HIROM_SRAM;
            Map [c + 7] = Map [c + 0x807] = (uint8 *) MAP_HIROM_SRAM;
            BlockIsRAM [c + 6] = BlockIsRAM [c + 0x806] = TRUE;
            BlockIsRAM [c + 7] = BlockIsRAM [c + 0x807] = TRUE;
        }
        else
        {
            Map [c + 6] = Map [c + 0x806] = (uint8 *) MAP_NONE;
            Map [c + 7] = Map [c + 0x807] = (uint8 *) MAP_NONE;
        }

        for (i = c + 8; i < c + 16; i++)
        {
            uint32 bank = (c >> 4);
            uint32 offset = 0;
            
            if (bank < 0x20)
                offset = bank * 0x10000;
            else
                offset = (bank - 0x20) * 0x10000;
                
            // Map to ROM with proper mirroring for ExHiROM
            if (CalculatedSize > 0x300000 && bank >= 0x20 && bank < 0x40)
            {
                // Upper 16MBit: banks 20-3f map to second half of ROM
                Map [i] = ROM + offset + 0x300000;
                Map [i + 0x800] = ROM + offset;
            }
            else
            {
                Map [i] = Map [i + 0x800] = ROM + offset;
            }
            BlockIsROM [i] = BlockIsROM [i + 0x800] = TRUE;
        }
    }

    // Banks 40->7f and c0->ff
    for (c = 0; c < 0x400; c += 16)
    {
        for (i = c; i < c + 16; i++)
        {
            uint32 bank = (c >> 4) + 0x40;
            uint32 offset;
            
            if (bank >= 0xc0)
                offset = ((bank - 0xc0) * 0x10000) % CalculatedSize;
            else
                offset = ((bank - 0x40) * 0x10000) % CalculatedSize;
            
            Map [i + 0x400] = Map [i + 0xc00] = ROM + offset;
            BlockIsROM [i + 0x400] = BlockIsROM [i + 0xc00] = TRUE;
        }
    }

    // Banks 7e->7f WRAM
    for (c = 0; c < 16; c++)
    {
        Map [c + 0x7e0] = RAM;
        Map [c + 0x7f0] = RAM + 0x10000;
        BlockIsRAM [c + 0x7e0] = TRUE;
        BlockIsRAM [c + 0x7f0] = TRUE;
        BlockIsROM [c + 0x7e0] = FALSE;
        BlockIsROM [c + 0x7f0] = FALSE;
    }

    // SRAM mapping for banks 20-3f at 6000-7fff
    for (c = 0x200; c < 0x400; c += 16)
    {
        Map [c + 6] = Map [c + 0x806] = (uint8 *) MAP_HIROM_SRAM;
        Map [c + 7] = Map [c + 0x807] = (uint8 *) MAP_HIROM_SRAM;
        BlockIsRAM [c + 6] = BlockIsRAM [c + 0x806] = TRUE;
        BlockIsRAM [c + 7] = BlockIsRAM [c + 0x807] = TRUE;
        BlockIsROM [c + 6] = BlockIsROM [c + 0x806] = FALSE;
        BlockIsROM [c + 7] = BlockIsROM [c + 0x807] = FALSE;
    }

    MapRAM ();
    WriteProtectROM ();
}
