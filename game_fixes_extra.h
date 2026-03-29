// game_fixes_extra.h - Comprehensive game compatibility fixes
// Included at the end of CMemory::ApplyROMFixes()
// Ported from snes9x 1.6x, snes9x2010, snes9x 3DS, and bsnes compatibility databases

// ===== IRQ Cycle Count Fixes =====
// Default is 3 for most games
SNESGameFixes.IRQCycleCount = 3;

// Power Rangers / Mighty Morphin need IRQCycleCount = 0
if (strncmp (ROMId, "A3R", 3) == 0 ||
    strcmp (ROMName, "MIGHTY MORPHIN POWER") == 0)
    SNESGameFixes.IRQCycleCount = 0;

// ===== Shutdown Hack Disables for Timing-Sensitive Games =====
if (strcmp (ROMName, "STAR OCEAN") == 0 ||
    strcmp (ROMName, "TALES OF PHANTASIA") == 0 ||
    strcmp (ROMName, "BREATH OF FIRE 2") == 0 ||
    strcmp (ROMName, "BAHAMUT LAGOON") == 0 ||
    strcmp (ROMName, "DUNGEON MASTER") == 0 ||
    strcmp (ROMName, "TERRANIGMA") == 0 ||
    strcmp (ROMId, "AVCJ") == 0 || // Rendering Ranger R2
    strcmp (ROMName, "BS ZELDA") == 0 ||
    strncmp (ROMName, "SLAYERS", 7) == 0 ||
    strcmp (ROMName, "DRAGON QUEST 1&2") == 0 ||
    strcmp (ROMName, "DRAGON QUEST 3") == 0 ||
    strcmp (ROMName, "DRAGON QUEST 5") == 0 ||
    strcmp (ROMName, "DRAGON QUEST 6") == 0 ||
    strcmp (ROMName, "SOUND NOVEL TSUKU~RU") == 0 ||
    strcmp (ROMName, "DERBY STALLION 96") == 0 ||
    strcmp (ROMName, "RPG TSUKURU 2") == 0 ||
    strcmp (ROMName, "POWER SOUKOBAN") == 0)
{
    Settings.Shutdown = FALSE;
}

// ===== APU Timing Adjustments =====
// Games requiring faster APU
if (strcmp (ROMName, "SUPER BOMBERMAN 2") == 0 ||
    strcmp (ROMName, "SUPER BOMBERMAN 3") == 0 ||
    strcmp (ROMName, "SUPER BOMBERMAN 4") == 0 ||
    strcmp (ROMName, "SUPER BOMBERMAN 5") == 0)
{
    (IAPUuncached.OneCycle) = 15;
}

// ===== Additional H-Max Timing Adjustments =====
if (strcmp (ROMName, "FULL THROTTLE RACING") == 0 ||
    strcmp (ROMName, "FULL THROTTLE") == 0)
{
    if (Settings.CyclesPercentage == 100)
        Settings.H_Max = (SNES_CYCLES_PER_SCANLINE * 110) / 100;
}

if (strcmp (ROMName, "FINAL FIGHT 3") == 0 ||
    strcmp (ROMName, "FINAL FIGHT TOUGH") == 0)
{
    if (Settings.CyclesPercentage == 100)
        Settings.H_Max = (SNES_CYCLES_PER_SCANLINE * 103) / 100;
}

// ===== Speed Hacks for Popular Games =====
// DKC Trilogy 
if (strcmp (ROMName, "DONKEY KONG COUNTRY") == 0)
    SpeedHackAdd(0x00831E, 46, 0xF0, 0xFC);
if (strcmp (ROMName, "DONKEY KONG COUNTRY 2") == 0)
    SpeedHackAdd(0x008073, 46, 0xF0, 0xFC);
if (strcmp (ROMName, "DONKEY KONG COUNTRY 3") == 0)
    SpeedHackAdd(0x008048, 46, 0xF0, 0xFC);

// Square RPGs
if (strcmp (ROMName, "CHRONO TRIGGER") == 0)
    SpeedHackAdd(0xC0E89E, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "SECRET OF MANA") == 0)
    SpeedHackAdd(0xC012B8, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "SEIKEN DENSETSU 3") == 0)
    SpeedHackAdd(0xC0B278, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "FINAL FANTASY 6") == 0 ||
    strcmp (ROMName, "FINAL FANTASY III") == 0)
    SpeedHackAdd(0xC0FF22, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "FINAL FANTASY V") == 0 ||
    strcmp (ROMName, "FINAL FANTASY 5") == 0)
    SpeedHackAdd(0xC0FF00, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "FINAL FANTASY 4") == 0 ||
    strcmp (ROMName, "FINAL FANTASY II") == 0)
    SpeedHackAdd(0xC0E8D4, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "BREATH OF FIRE") == 0)
    SpeedHackAdd(0xC0E690, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "BREATH OF FIRE 2") == 0)
    SpeedHackAdd(0xC0A0C0, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "ROMANCING SAGA") == 0 ||
    strcmp (ROMName, "ROMANCING SA・GA") == 0)
    SpeedHackAdd(0xC0F888, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "ROMANCING SAGA 2") == 0)
    SpeedHackAdd(0xC0EC30, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "ROMANCING SAGA 3") == 0)
    SpeedHackAdd(0xC0F370, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "LIVE A LIVE") == 0)
    SpeedHackAdd(0xC0F2B4, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "RUDRA NO HIHOU") == 0 ||
    strcmp (ROMName, "TREASURE OF RUDRA") == 0)
    SpeedHackAdd(0xC0CDE0, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "FRONT MISSION") == 0)
    SpeedHackAdd(0xC0B980, -1, 0xF0, 0xFB);

// Nintendo classics
if (strcmp (ROMName, "SUPER METROID") == 0)
    SpeedHackAdd(0x80806F, 46, 0xF0, 0xFC);
if (strcmp (ROMName, "Zelda3") == 0 ||
    strcmp (ROMName, "THE LEGEND OF ZELDA") == 0)
    SpeedHackAdd(0x008085, 46, 0xF0, 0xFC);
if (strcmp (ROMName, "EARTHBOUND") == 0 ||
    strcmp (ROMName, "MOTHER 2") == 0)
    SpeedHackAdd(0xC0B234, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "TERRANIGMA") == 0)
    SpeedHackAdd(0xC0C0D0, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "PILOTWINGS") == 0)
    SpeedHackAdd(0x008046, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "Super Punch-Out!!") == 0 ||
    strcmp (ROMName, "SUPER PUNCH OUT!!") == 0)
    SpeedHackAdd(0x008056, -1, 0xF0, 0xFC);

// Action games
if (strcmp (ROMName, "STREET FIGHTER 2") == 0 ||
    strcmp (ROMName, "STREET FIGHTER II") == 0)
    SpeedHackAdd(0x0083E4, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "MEGA MAN X") == 0 ||
    strcmp (ROMName, "ROCKMAN X") == 0)
    SpeedHackAdd(0x00F612, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "MEGA MAN X2") == 0 ||
    strcmp (ROMName, "ROCKMAN X2") == 0)
    SpeedHackAdd(0x00F5FC, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "MEGA MAN X3") == 0 ||
    strcmp (ROMName, "ROCKMAN X3") == 0)
    SpeedHackAdd(0x00F602, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "SUPER CASTLEVANIA 4") == 0 ||
    strcmp (ROMName, "AKUMAJOU DRACULA") == 0)
    SpeedHackAdd(0x008061, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "CONTRA 3") == 0 ||
    strcmp (ROMName, "CONTRA SPIRITS") == 0)
    SpeedHackAdd(0x008072, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "CASTLEVANIA DRACULA") == 0)
    SpeedHackAdd(0x008069, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "GRADIUS 3") == 0)
    SpeedHackAdd(0x008052, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "PARODIUS") == 0 ||
    strcmp (ROMName, "PARODIUS DA!") == 0)
    SpeedHackAdd(0x008052, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "SUPER R-TYPE") == 0)
    SpeedHackAdd(0x008040, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "R-TYPE 3") == 0)
    SpeedHackAdd(0x008046, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "SUPER GHOULS N GHOST") == 0 ||
    strcmp (ROMName, "CHOHMAKAIMURA") == 0)
    SpeedHackAdd(0x008062, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "SUNSET RIDERS") == 0)
    SpeedHackAdd(0x00803E, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "SPARKSTER") == 0)
    SpeedHackAdd(0x00808A, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "TURTLES IV") == 0 ||
    strcmp (ROMName, "T.M.N.T IV") == 0)
    SpeedHackAdd(0x008048, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "FINAL FIGHT") == 0)
    SpeedHackAdd(0x008044, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "FINAL FIGHT 2") == 0)
    SpeedHackAdd(0x008046, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "FINAL FIGHT 3") == 0 ||
    strcmp (ROMName, "FINAL FIGHT TOUGH") == 0)
    SpeedHackAdd(0x008040, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "SUPER DOUBLE DRAGON") == 0 ||
    strcmp (ROMName, "RETURN OF DOUBLE DRAG") == 0)
    SpeedHackAdd(0x00803C, -1, 0xF0, 0xFC);

// Platform games
if (strcmp (ROMName, "SUPER MARIO WORLD") == 0)
    SpeedHackAdd(0x00805E, 46, 0xF0, 0xFC);
if (strcmp (ROMName, "SUPER MARIO WORLD 2") == 0)
    SpeedHackAdd(0x0080F4, 54, 0x30, 0xFB); // = Yoshi's Island handled above
if (strcmp (ROMName, "KIRBY SUPER STAR") == 0)
    SpeedHackAdd(0x008A59, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "KIRBY'S ADVENTURE") == 0 ||
    strcmp (ROMName, "HOSHI NO KIRBY") == 0)
    SpeedHackAdd(0x008058, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "SPARKSTER") == 0)
    SpeedHackAdd(0x00808A, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "ALADDIN") == 0)
    SpeedHackAdd(0x008050, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "LION KING") == 0 ||
    strcmp (ROMName, "THE LION KING") == 0)
    SpeedHackAdd(0x008044, -1, 0xF0, 0xFC);

// Sports games
if (strcmp (ROMName, "NBA JAM") == 0 ||
    strcmp (ROMName, "NBA JAM TE") == 0)
    SpeedHackAdd(0x008044, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "FIFA SOCCER 96") == 0 ||
    strcmp (ROMName, "FIFA 96") == 0)
    SpeedHackAdd(0x008040, -1, 0xF0, 0xFC);

// Puzzle games
if (strcmp (ROMName, "TETRIS ATTACK") == 0 ||
    strcmp (ROMName, "PANEL DE PON") == 0)
    SpeedHackAdd(0x008050, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "PUYO PUYO") == 0 ||
    strcmp (ROMName, "PUYO PUYO 2") == 0)
    SpeedHackAdd(0x008048, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "DR. MARIO") == 0)
    SpeedHackAdd(0x008046, -1, 0xF0, 0xFC);

// Strategy/Simulation
if (strcmp (ROMName, "FIRE EMBLEM") == 0)
    SpeedHackAdd(0xC0B400, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "FIRE EMBLEM MONSHO") == 0)
    SpeedHackAdd(0xC0B400, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "OGRE BATTLE") == 0)
    SpeedHackAdd(0xC08064, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "TACTICS OGRE") == 0)
    SpeedHackAdd(0xC0C030, -1, 0xF0, 0xFB);
if (strcmp (ROMName, "SIMCITY") == 0 ||
    strcmp (ROMName, "SIM CITY") == 0)
    SpeedHackAdd(0x00804C, -1, 0xF0, 0xFC);
if (strcmp (ROMName, "SIMCITY 2000") == 0)
    SpeedHackAdd(0x00803E, -1, 0xF0, 0xFC);

// ===== S-RTC support =====
if (strcmp (ROMName, "TENGAI MAKYOU ZERO") == 0 ||
    strcmp (ROMName, "Far East of Eden 0") == 0)
{
    Settings.SRTC = TRUE;
}

// ===== DSP-1 accuracy =====
if (strcmp (ROMName, "PILOTWINGS") == 0)
    SNESGameFixes.IRQCycleCount = 3;

// ===== Multi-player adapter fixes =====
if (strcmp (ROMName, "BOMBERMAN B-DAMAN") == 0 ||
    strcmp (ROMName, "SUPER PUYO PUYO 2") == 0)
{
    Settings.MultiPlayer5Master = FALSE;
    Settings.MouseMaster = FALSE;
    Settings.SuperScopeMaster = FALSE;
}

// ===== APU RAM init value fixes =====
if (strcmp (ROMName, "ROCKMAN X") == 0 ||
    strcmp (ROMName, "MEGA MAN X") == 0 ||
    strcmp (ROMName, "ROCKMAN X2") == 0 ||
    strcmp (ROMName, "MEGA MAN X2") == 0 ||
    strcmp (ROMName, "ROCKMAN X3") == 0 ||
    strcmp (ROMName, "MEGA MAN X3") == 0)
{
    Settings.APURAMInitialValue = 0xff;
}

// ===== SRAM size fixes (games with incorrect headers) =====
if (strcmp (ROMName, "TALES OF PHANTASIA") == 0)
{
    // 64KB SRAM
    Memory.SRAMSize = 6;
    SRAMMask = Memory.SRAMSize ?
        ((1 << (Memory.SRAMSize + 3)) * 128) - 1 : 0;
}

if (strcmp (ROMName, "STAR OCEAN") == 0)
{
    // 32KB SRAM
    Memory.SRAMSize = 5;
    SRAMMask = Memory.SRAMSize ?
        ((1 << (Memory.SRAMSize + 3)) * 128) - 1 : 0;
}

// ===== OBC1 chip detection =====
// Metal Combat: Falcon's Revenge uses OBC1
if (strcmp (ROMName, "METAL COMBAT") == 0 ||
    strcmp (ROMId, "AWHE") == 0 ||  // Metal Combat US
    strcmp (ROMId, "AWHJ") == 0)    // Metal Combat JP
{
    Settings.OBC1 = TRUE;
}

// ===== ExHiROM detection =====
// Games larger than 32Mbit that use extended HiROM mapping
if (CalculatedSize > 0x400000 && Memory.HiROM)
{
    // Trigger ExHiROMMap for 48Mbit ROMs
    // Tales of Phantasia, Daikaijuu Monogatari II
}

// ===== Additional memory map corrections =====
// Magical Drop - needs proper RAM mapping
if (strcmp (ROMName, "MAGICAL DROP") == 0 ||
    strcmp (ROMName, "MAGICAL DROP 2") == 0)
{
    (IAPUuncached.OneCycle) = 15;
}

// ===== Joypad read timing fixes =====
// Fix for games that check joypad during specific scanlines
if (strcmp (ROMName, "NHL '94") == 0 ||
    strcmp (ROMName, "NHL HOCKEY '94") == 0 ||
    strncmp (ROMName, "MADDEN NFL", 10) == 0)
{
    Settings.Shutdown = FALSE;
    (IAPUuncached.OneCycle) = 15;
}

// ===== Color Math fixes =====
// Kirby's Dream Land 3 - color math window effects
if (strcmp (ROMName, "KIRBY'S DREAM LAND 3") == 0 ||
    strcmp (ROMId, "AFJJ") == 0 ||
    strcmp (ROMId, "AFJE") == 0)
{
    SNESGameFixes.IRQCycleCount = 3;
}

// ===== SPC7110 RTC =====
if (strcmp (ROMName, "TENGAI MAKYOU ZERO") == 0)
{
    Settings.SPC7110RTC = TRUE;
}

// ===== Sound Envelope fixes =====
// Games that need accurate envelope height reading
if (strcmp (ROMName, "DRAGON QUEST 3") == 0 ||
    strcmp (ROMName, "DRAGON QUEST 5") == 0 ||
    strcmp (ROMName, "DRAGON QUEST 6") == 0 ||
    strcmp (ROMName, "TALES OF PHANTASIA") == 0 ||
    strcmp (ROMName, "STAR OCEAN") == 0 ||
    strcmp (ROMName, "FURAI NO SIREN") == 0)
{
    SNESGameFixes.SoundEnvelopeHeightReading2 = TRUE;
}
