# Snes9xTYL Mod (Revival Project)

[![Build Status](https://github.com/OniMock/snes9xTYL/actions/workflows/build.yml/badge.svg)](https://github.com/OniMock/snes9xTYL/actions/workflows/build.yml)
[![Latest Release](https://img.shields.io/github/v/release/OniMock/snes9xTYL)](https://github.com/OniMock/snes9xTYL/releases)
![Platform](https://img.shields.io/badge/platform-PSP%20%7C%20PSVita-blue)
![Downloads](https://img.shields.io/github/downloads/OniMock/snes9xTYL/total)

A modernized and performance-focused revival of Snes9xTYL for PSP and PS Vita, designed to handle large ROM collections and improve real hardware performance.

> [!CAUTION]
> **Backup your data!** Before updating, make sure to backup your `SAVES` and/or `S9XTYLSAVES` folders just in case something goes wrong.

Snes9xTYL Mod is a resurrected and modernized fork of the classic Super Nintendo emulator for the PlayStation Portable (PSP) and PS Vita. This version focuses on performance optimizations, user convenience, and broader accessibility.

## 📑 Table of Contents

- [🚀 Key Improvements](#-key-improvements)
- [💻 Verified Environment](#-verified-environment)
- [🛠️ Installation](#️-installation)
- [💡 Help and Tips](#-help-and-tips)
- [🎮 Features](#-features)
- [🕹️ Controls](#️-controls)
- [🎯 Project Goals](#-project-goals)
- [💬 Feedback](#-feedback)
- [🤝 Credits](#-credits)

---

## 🚀 Key Improvements

- **⚡ Ultra-Fast Directory Browser**
  - Before: ~20 seconds black screen to load ~1000 ROMs (hard limit)
  - Now: loads in a few seconds and supports up to ~4000 ROMs per folder
- **⭐ Favorites System**: Mark your most-played ROMs as favorites for instant access.
  - Press **L (Left Trigger)** to add/remove a ROM from favorites
- **🌍 Multi-Language Support**: Native runtime support for **Portuguese (PT-BR)**, **Spanish**, **English**, **Japanese**, and **Simplified Chinese**.
- **📦 Automated Releases**: Integrated CI/CD pipeline for stable, verified builds on every update.

[↑ Back to top](#snes9xtyl-mod-revival-project)

---

## 💻 Verified Environment

This mod is actively developed and verified on the following setup to ensure maximum stability:

- **Hardware**: PSP 3000
- **Firmware**: 6.61
- **CFW**: ARK-4

> [!NOTE]
> Also compatible with other PSP models (1000/2000/Go/E1000) and PS Vita via Adrenaline/eCFW.

[↑ Back to top](#snes9xtyl-mod-revival-project)

---

## 🛠️ Installation

1.  Download the latest build from the [Releases](https://github.com/OniMock/snes9xTYL/releases) page.
2.  Choose the variant that fits your needs:
    - **ME (Media Engine)**: Best for all PSP models. Uses the Media Engine for hardware-accelerated sound.
    - **CM (Compatible)**: Recommended for PS Vita (Adrenaline/eCFW) and legacy setups.
3.  Copy the folder to `ms0:/PSP/GAME/snes9xTYL/` (or any other folder).
4.  Ensure the following files are inside:
    - `EBOOT.PBP`
    - `logo.bmp` (Optional, for folder icon)
    - Required `.prx` modules (for ME variant)
5.  You can put ROM files anywhere. A `SAVES` subdirectory will be automatically created in your install directory to store savestates, SRAM files, and snapshots.

[↑ Back to top](#snes9xtyl-mod-revival-project)

---

## 💡 Help and Tips

- **⚡ Speed Boost**: Some games run faster if **"Ignore Palette writes"** and/or **"Simple Palette writes"** are enabled in the `MISC -> Hack/debug` menu.
- **⚫ Black Screen Fix**: If you get a black screen when loading a game, try disabling **"Speed hacks"** in the `MISC -> Hack/debug` menu and then reload the game.

[↑ Back to top](#snes9xtyl-mod-revival-project)

---

## 🎮 Features

- **Performance**: 5 distinct rendering modes (including hardware acceleration via PSP's GU).
- **Audio**: Multiple sampling rates (22kHz, 32kHz, 44kHz) and Media Engine utilization.
- **Convenience**: Standby/Sleep mode support, auto-save SRAM on exit, and small compressed savestates with screenshots.
- **Compatibility**: Supports SDD1 (Star Ocean), SA1, SuperFX, C4, and DSP chips.
- **Visuals**: Gamma correction, VSync, smoothing filters, and snapshot-based icons per game.
- **Extras**: Netplay (multiplayer), Zipped ROM support, and IPS patching.

[↑ Back to top](#snes9xtyl-mod-revival-project)

---

## 🕹️ Controls

| PSP Button         | SNES Function     |
| :----------------- | :---------------- |
| **D-Pad**          | D-Pad             |
| **Cross**          | A                 |
| **Circle**         | B                 |
| **Square**         | X                 |
| **Triangle**       | Y                 |
| **L / R**          | L / R             |
| **Start / Select** | Start / Select    |
| **L + R**          | Menu (CM version) |
| **Home/Note**      | Menu (ME version) |

[↑ Back to top](#snes9xtyl-mod-revival-project)

---

## 🎯 Project Goals

This project aims to go beyond maintenance and focus on:

- Improving compatibility for problematic SNES titles
- Optimizing performance on real PSP hardware
- Enhancing usability without breaking the original experience

Community feedback will help guide future improvements.

[↑ Back to top](#snes9xtyl-mod-revival-project)

## 💬 Feedback

Have suggestions or specific games that need improvements?
Feel free to open an issue or start a discussion — feedback is highly appreciated!

[↑ Back to top](#snes9xtyl-mod-revival-project)

## 🤝 Credits

### Project Resurrector

- **OniMock** (Current Maintainer & Refactoring)

### Original Authors & Modders

- **YoyoFR** & **Laxer3a** (Original Snes9xTYL)
- **esmjanus** (Major Mod legacy)
- **Ruka**, **33(76)**, **173210** (Mod contributors)

### Contributors

- **bubble2k16**: Optimizations from Snes9x3DS.
- **DraxTube**: PSPSDK modern refactoring.
- **Snes9x Team**: The foundation of it all.

### Special Thanks

- **psp2dev community**: For the PSPSDK.
- **smiths, chp, bifuteki**: Personal thanks by YoyoFR.

---

## 📜 Original Notes (YoyoFR)

> [!NOTE]
> The section below preserves original notes from the original Snes9xTYL author (YoyoFR).

Snes9xTYL is based on:

- Little John for PalmOS – SNES module
  http://yoyofr92.free.fr

- Which is based on Snes9x 1.39
  http://www.snes9x.com

- Unofficial PSPSDK from the psp2dev community
  http://www.ps2dev.org

Personal thanks to: smiths, chp, bifuteki.

— yoyofr

[↑ Back to top](#snes9xtyl-mod-revival-project)

---

_Built with ❤️ for the PSP community._
