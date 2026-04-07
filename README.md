
# Snes9xTYL Mod

Super Nintendo emulator for PlayStation Portable.

Download the latest compiled commit here: [Releases](https://github.com/OniMock/snes9xTYL/blob/mecm/Release/Releases.md)

***Before updating, make sure to backup your SAVES and/or S9XTYLSAVES folders just in case something goes wrong.***

---

## Help and Tips

- Some games run faster if "Ignore Palette writes" and/or "Simple Palette writes" are enabled on MISC -> Hack/debug menu.
- If you get a black screen at loading a game, try disabling "Speed hacks" on MISC -> Hack/debug menu and then reload the game.

---

## Features

- Standby/sleep mode on "me" version.
- Netplay (multiplayer) support.
- Zipped ROM support.
- IPS patch file (must have the same name as the game with `.IPS` extension: e.g., `SOE.ZIP` => `SOE.IPS`)
- Compressed Savestate with small screenshot.
- Auto save of SRAM on game change, exit & Snes reset.
- Autoskip.
- Gamma correction.
- VSync support.
- SDD1 encrypted ROMs (Star Ocean, Street Fighter Alpha 2, etc.).
- SA1 (slow), SuperFX (slow), C4, DSP1, DSP2, DSP3, DSP4 support.
- Multiple sound frequencies: 22kHz, 32kHz, 44kHz.
- Multiple stretching modes with or without smoothing.
- Detailed Battery information.
- 222, 266, 300 & 333MHz PSP frequency.
- Snapshot-based icon per game. Take a snapshot in-game (via GUI) to see it in the file browser.
- 5 Rendering modes:
  - **Mode0**: Optimized Snes9x
  - **Mode1**: Original Snes9x
  - **Mode2**: Hardware accelerated (using PSP's GU)
  - **Mode3**: Adaptive rendering Mode 2 + Mode 1 (default)
  - **Mode4**: Adaptive rendering Mode 2 + Mode 0

This version supports nearly all the graphics effects of the SNES accelerated with PSP hardware. Exceptions: offset mode & mode 7. Priority and blending are fully emulated. Some minor graphic glitches may remain.

---

## Install

Place the following in:

```
/PSP/GAME/snes9xTYL/  (or any other folder)
+ EBOOT.PBP
+ logo.bmp
```

You can put ROM files anywhere. A `SAVES` subdirectory will be created in your install directory. All savestate files, SRAM files & snapshots will be written in the `SAVES` folder.

---

## Play

Default controls:

| PSP | SNES |
|-----|------|
| pad | pad |
| LEFT TRIGGER + RIGHT TRIGGER | menu (cm version) |
| CROSS | A |
| CIRCLE | B |
| SQUARE | X |
| TRIANGLE | Y |
| START | START |
| SELECT | SELECT |
| LEFT TRIGGER | L |
| RIGHT TRIGGER | R |

---

## Credits

### Special Thanks to
- **Snes9x team** for the fantastic SNES emulator.
- **YoyoFR** and **Laxer3a** for official Snes9xTYL.
- **Ruka**, **33(76)** for mod of mecm.
- **173210** for mod of Snes9xTYLmecm 091127.
- **bubble2k16** for his work on Snes9x3DS. Many optimizations were ported from his version.
- **esmjanus** - for all mods made.
- **DraxTube** - for refactoring to use the latest version of PSPSDK.

### Notes by YoyoFR

snes9xTYL is based on:

- Little John for PalmOS - SNES module
  [LJP](http://yoyofr92.free.fr)

- which is based on Snes9x 1.39
  [SNES9X](http://www.snes9x.com)

- unofficial PSPSDK from psp2dev community
  www.ps2dev.org

Personal thanks to: smiths, chp, bifuteki.

Have fun!
http://yoyofr92.free.fr

yoyofr
