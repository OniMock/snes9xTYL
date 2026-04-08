	[MSG_EN] = {
	//english
		//error
		[ERR_OUT_OF_MEM] = "Out of memory",
		[ERR_READ_MEMSTICK] = "Error reading memstick.\nPlease verify it (using a PC card reader), it may be corrupted.",

		[ERR_INIT_SNES] = "Cannot init snes, memory issue",
		[ERR_LOADING_ROM] = "Error while loading rom",
		[ERR_INIT_GFX] = "Cannot initialize graphics",

		[ERR_CANNOT_ALLOC_MEM] = "Cannot allocate memory",

		[ERR_USB_STARTING_USBBUS] = "Error starting USB Bus driver (0x%08X)\n",
		[ERR_USB_STARTING_USBMASS] = "Error starting USB Mass Storage driver (0x%08X)\n",
		[ERR_USB_SETTING_CAPACITY] = "Error setting capacity with USB Mass Storage driver (0x%08X)\n",
		//confirm
		[ASK_EXIT] = "Exit Snes9XTYL ?",
		[ASK_DELETE] = "Delete file ?",
		[ASK_SAVEDIR] = "The save directory is not found.\n"
			"To make the directory in the directory where this emulator is, Press " SJIS_CIRCLE  "\n"
			"To make the directory in SAVEDATA directory, Press " SJIS_CROSS "\n",
		//info
		[INFO_USB_ON] = "USB activated",
		[INFO_USB_OFF] = "USB disabled",
		[INFO_DELETING] = "Deleting...",
		[INFO_EXITING] = "Exiting, please wait...",
		[INFO_LOADING_FILES] = "Loading files: %d...",
		[INFO_FAV_ADDED] = "Added to Favorites",
		[INFO_FAV_REMOVED] = "Removed from Favorites",
		//filer
		[FILER_STATUS_CANEXIT1] = "%s RUN " SJIS_SQUARE " RUN default settings " SJIS_STAR " %s TO GAME "  SJIS_STAR " " SJIS_TRIANGLE " %s "  SJIS_STAR " PAD BROWSE",
		[FILER_STATUS_NOEXIT1] = "%s RUN " SJIS_SQUARE " RUN default settings  "  SJIS_STAR "  " SJIS_TRIANGLE " %s  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", to browse list",
		[FILER_STATUS_CANEXIT2] = "%s RUN %s BACK TO GAME " SJIS_TRIANGLE " %s  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", to browse list",
		[FILER_STATUS_NOEXIT2] = "%s RUN " SJIS_TRIANGLE " %s                  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", to browse list",

		[FILER_STATUS_PARDIR] = "Parent dir.",

		[FILER_TITLE] = "[" PROJECT_NAME "] - Choose a file",

		[FILER_HELP_WINDOW1] = "Press START to switch between",
		[FILER_HELP_WINDOW2] = "NORMAL and NETPLAY mode.",
#ifdef FW3X
		[FILER_HELP_WINDOW3] = " ",
#ifdef HOME_HOOK
		[FILER_HELP_WINDOW4] = "Press HOME to exit.",
#else
		[FILER_HELP_WINDOW4] = "Press L+R to exit.",
#endif
#else
#ifdef HOME_HOOK
		[FILER_HELP_WINDOW3] = "Press HOME to exit.",
#else
		[FILER_HELP_WINDOW3] = "Press L+R to exit.",
#endif
		[FILER_HELP_WINDOW4 = "Press R to switch USB on/off.",
#endif


		[FILER_HELP_WINDOW5] = "Press SELECT to delete file.",

		[FILE_IPS_APPLYING] = "Found IPS patch : %s\nSize is : %dKo\nApplying ....",
		[FILE_IPS_PATCHSUCCESS] = "IPS Patch applied successfully",

		[MENU_STATUS_GENERIC_MSG1] = "Press %s to return",
		[MENU_STATUS_GENERIC_NEEDRELOAD] = "Changes may require a RELOAD to take effect",
		[MENU_STATUS_GENERIC_NEEDRESET] = "Changes may require a RESET to take effect",
		[MENU_STATUS_GENERIC_CHANGEMUSIC] = "SELECT to change music",

		[MENU_TITLE_GENERIC_BAT] = "Bat.",
		[MENU_TITLE_GENERIC_BAT_TIME] = "(%02dh%02dm)",
		[MENU_TITLE_GENERIC_BAT_TEMP] = " Tmp.%d℃",
		[MENU_TITLE_GENERIC_BAT_PLG] = "Plg.",
		[MENU_TITLE_GENERIC_BAT_CHRG] = "Chrg.",
		[MENU_TITLE_GENERIC_BAT_LOW] = "Low!",

		[MENU_CHANGE_VALUE] = "  ,   change value",
		[MENU_CHANGE_VALUE_WITH_FAST] = "  ,   change value -  ,  fast",
		[MENU_CANCEL_VALIDATE] = "  ,   cancel   -      validate",
		[MENU_DEFAULT_VALUE] = "   default value",
		[MENU_YES] = "yes",
		[MENU_NO] = "no",
		[MENU_NOT_IMPLEMENTED] = "Not yet implemented.\n\n",

		[MENU_SOUND_MODE_NOTEMUL] = "not emulated",
		[MENU_SOUND_MODE_EMULOFF] = "emulated, no output",
		[MENU_SOUND_MODE_EMULON] = "emulated, output",

		[MENU_STATE_CHOOSEDEL] = "Choose a slot to DELETE",
		[MENU_STATE_CHOOSELOAD] = "Choose a slot to LOAD",
		[MENU_STATE_CHOOSESAVE] = "Choose a slot to SAVE",
		[MENU_STATE_FREESLOT] = "FREE",
		[MENU_STATE_SCANNING] = "Scanning used slots...",


		[ERR_INIT_OSK] = "cannot init OSK",
		[ERR_ADD_CODE] = "Cannot add cheat code, too many already enterred!",

		[MENU_CHEATS_ENTERGF] = "Enter a GoldFinger code",
		[MENU_CHEATS_ENTERPAR] = "Enter a Pro Action Replay code",
		[MENU_CHEATS_ENTERGG] = "Enter a Game Genie code",
		[MENU_CHEATS_ENTERRAW] = "Enter a RAW code\nFormat is ADDRESS - NEW VALUE",
		[MENU_CHEATS_CONFIRMREMALL] = "Remove all codes ?",
		[MENU_CHEATS_ENTERNAME] = "Enter Name",
		[MENU_CHEATS_PREVPAGE] = "L - Prev. Page",
		[MENU_CHEATS_NEXTPAGE] = "R - Next Page",

		[MENU_STATE_CONFIRMLOAD] = "Current game progress will be lost.\nContinue ?",
		[MENU_STATE_CONFIRMDELETE] = "Delete current state ?",
		[MENU_STATE_CONFIRMSAVE] = "Overwrite current savestate ?",
		[MENU_STATE_ISLOADING] = "Loading state...",
		[MENU_STATE_ISSAVING] = "Saving state...",
		[MENU_STATE_ISDELETING] = "Deleting...",
		[MENU_STATE_ISIMPORTING] = "Importing state...",
		[MENU_STATE_ISEXPORTINGS9X] = "Exporting SNES9X state...",
		[MENU_STATE_NOSTATE] = "No state available...",
		[MENU_STATE_AUTOSAVETIMER] = "every %dmin.",
		[MENU_STATE_AUTOSAVETIMER_OFF] = "off",
		[MENU_STATE_WARNING_LOWBAT] = "Battery is low.\nIf PSP turns off while saving, Memory Stick may be broken.\nContinue?",
		[MENU_GAME_SAVINGDEFAULTSETTINGS] = "Saving current settings as default profile",
		[MENU_GAME_CONFIRMRESET] = "Reset Snes ?",
		[MENU_MISC_SAVINGJPEG] = "Saving JPEG snapshot...",

		[MENU_MISC_BGMUSIC_RAND] = "Play randomly",
		[MENU_MISC_BGMUSIC_ORDER] = "Play in order",

		[MENU_MISC_BGMUSIC_UNKNOWN] = "unknown",
		[MENU_MISC_BGMUSIC_GAMETITLE] = "Playing : ",
		[MENU_MISC_BGMUSIC_TITLE] = "Title : ",
		[MENU_MISC_BGMUSIC_AUTHOR] = "Author : ",


		// GAME
		[MENU_ICONS_GAME] = "GAME",
		[MENU_ICONS_GAME_RESET] = "Reset SNES",
		[MENU_ICONS_GAME_NEW] = "Load new game",
		[MENU_ICONS_GAME_FAVORITES] = "Favorites list",
		[MENU_ICONS_GAME_DEFAULTSETTINGS] = "Make Settings DEFAULT",
		[MENU_ICONS_GAME_DEFAULTSETTINGS_HELP] = "Make current settings the\ndefault\nfor all roms when no\nspecific one exists",
		[MENU_ICONS_GAME_EXIT] = "Exit Snes9xTYL",
		// LOAD/SAVE
		[MENU_ICONS_LOADSAVE] = "LOAD/SAVE",
		[MENU_ICONS_LOADSAVE_LOADSTATE] = "Load state",
		[MENU_ICONS_LOADSAVE_LOADSTATE_HELP] = "Load a previously saved state.\nSavestate is like a snapshot\nof the snes state, everything\nis saved.",
		[MENU_ICONS_LOADSAVE_SAVESTATE] = "Save state",
		[MENU_ICONS_LOADSAVE_SAVESTATE_HELP] = "Save state",
		[MENU_ICONS_LOADSAVE_DELETESTATE] = "Delete state",
		[MENU_ICONS_LOADSAVE_DELETESTATE_HELP] = "Delete state",
		[MENU_ICONS_LOADSAVE_IMPORTSTATE] = "Import state",
		[MENU_ICONS_LOADSAVE_IMPORTSTATE_HELP] = "Import a state from a previous\nversion or from uosnes9x.",

		[MENU_ICONS_LOADSAVE_EXPORTS9XSTATE] = "Export SNES9X state",
		[MENU_ICONS_LOADSAVE_EXPORTS9XSTATE_HELP] = "Export a state using SNES9X\nformat.",

		[MENU_ICONS_LOADSAVE_AUTOSAVETIMER] = "Autosavestate timer",
		[MENU_ICONS_LOADSAVE_AUTOSAVETIMER_HELP] = "Allows to have an auto\nsavestate performed regularly.",
		[MENU_ICONS_LOADSAVE_AUTOSRAM] = "Autosave updated SRAM",
		[MENU_ICONS_LOADSAVE_AUTOSRAM_HELP] = "Allows to have SRAM saved\nafter each change.",
		// CONTROLS
		[MENU_ICONS_CONTROLS] = "CONTROLS",
		[MENU_ICONS_CONTROLS_REDEFINE] = "Redefine",
		[MENU_ICONS_CONTROLS_REDEFINE_HELP] = "Redefine buttons mapping.",
		[MENU_ICONS_CONTROLS_INPUT] = "Emulated input",
		[MENU_ICONS_CONTROLS_INPUT_HELP] = "Choose current active\nsnes controller.",

		[MENU_CONTROLS_INPUT] = "Joypad #%d",
		[MENU_CONTROLS_INPUT_PRESS] = "Press a button for %s",
		[MENU_CONTROLS_INPUT_NOFORMENU] = "No button defined for MENU Access!\nPlease choose one",
#ifdef HOME_HOOK
		[MENU_CONTROLS_INPUT_DEFAULT] = "Choose a default profile : \n\n"
			SJIS_CROSS " - Default, SNES pad mapped to PSP pad.\n\n"
			SJIS_CIRCLE " - Default, SNES pad mapped to PSP stick.\n\n"
			SJIS_SQUARE " - Default, SNES pad mapped to PSP pad&stick.\n\n"
			SJIS_TRIANGLE " Cancel\n",
#else
		[MENU_CONTROLS_INPUT_DEFAULT] = "Choose a default profile : \n\n"
			SJIS_CROSS " - Default, SNES pad mapped to PSP pad. GUI on stick left.\n\n"
			SJIS_CIRCLE " - Default, SNES pad mapped to PSP stick. GUI on pad left.\n\n"
			SJIS_SQUARE " - Default, SNES pad mapped to PSP pad&stick. GUI on LTrg.+RTrg.\n\n"
			SJIS_TRIANGLE " Cancel\n",
#endif

		[MENU_STATUS_CONTROLS_INPUT] = "%s Detect mode " SJIS_STAR " %s Menu ",
		[MENU_STATUS_CONTROLS_INPUT_0] = SJIS_STAR " " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value " SJIS_STAR " SELECT default profiles",
		[MENU_STATUS_CONTROLS_INPUT_HELP_0] = SJIS_STAR "      " SJIS_TRIANGLE " Help       " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value",
		[MENU_STATUS_CONTROLS_INPUT_HELP_1] = SJIS_STAR "     " SJIS_TRIANGLE "   Help      " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value",
		[MENU_STATUS_CONTROLS_INPUT_HELP_2] = SJIS_STAR "    " SJIS_TRIANGLE "     Help     " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value",
		[MENU_STATUS_CONTROLS_INPUT_HELP_3] = SJIS_STAR "   " SJIS_TRIANGLE "       Help    " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value",

		[MENU_TITLE_CONTROLS_INPUT] = "[" PROJECT_NAME "] - Inputs Config",

		// VIDEO OPTIONS
		[MENU_ICONS_VIDEO] = "VIDEO",
		[MENU_ICONS_VIDEO_MODE] = "Video mode",
		[MENU_ICONS_VIDEO_MODE_HELP] = "Change the aspect ratio\n4:3 is adviced",
		[MENU_ICONS_VIDEO_ENGINE] = "Engine",
		[MENU_ICONS_VIDEO_ENGINE_HELP] = "Hardware accelerated mode\nis not always the fastest",
		[MENU_ICONS_VIDEO_SLIMITONOFF] = "Speed limit switch",
		[MENU_ICONS_VIDEO_SLIMITONOFF_HELP] = "Turn on to limit the speed\nof the game.",
		[MENU_ICONS_VIDEO_SLIMITVALUE] = "Speed limit fps",
		[MENU_ICONS_VIDEO_SLIMITVALUE_HELP] = "Only used if speed limit\nhas been turned on.",
		[MENU_ICONS_VIDEO_FSKIP] = "Frameskip",
		[MENU_ICONS_VIDEO_FSKIP_HELP] = "Choose a fixed value if you\nhave some sprites\ndisappearing.",
		[MENU_ICONS_VIDEO_SMOOTHING] = "Smoothing",
		[MENU_ICONS_VIDEO_SMOOTHING_HELP] = "Should be on since it costs\nnothing.",
		[MENU_ICONS_VIDEO_VSYNC] = "VSync",
		[MENU_ICONS_VIDEO_VSYNC_HELP] = "This costs lots of fps\nand should be turned off.",
		[MENU_ICONS_VIDEO_PALASNTSC] = "Render PAL as NTSC",
		[MENU_ICONS_VIDEO_PALASNTSC_HELP] = "Force PAL games to be emulated\nlike NTSC ones : 224 lines\ninstead of 240.",
		[MENU_ICONS_VIDEO_GAMMA] = "Gamma correction",
		[MENU_ICONS_VIDEO_GAMMA_HELP] = "Allows brighter rendering",
		[MENU_ICONS_VIDEO_SCRCALIB] = "Screen calibration",
		[MENU_ICONS_VIDEO_SCRCALIB_HELP] = "Help to get rid of the nasty\nblack borders.",
		[MENU_ICONS_VIDEO_SHOWFPS] = "Show FPS",
		[MENU_ICONS_VIDEO_SHOWFPS_HELP] = "First line is emulated frames\nSecond one is real fps.",

		[MENU_VIDEO_MODE_1_1] = "1:1",
		[MENU_VIDEO_MODE_ZOOM_FIT] = "zoom fit",
		[MENU_VIDEO_MODE_ZOOM_4_3RD] = "zoom 4/3",
		[MENU_VIDEO_MODE_ZOOM_WIDE] = "zoom wide",
		[MENU_VIDEO_MODE_FULLSCREEN] = "fullscreen",
		[MENU_VIDEO_MODE_FULLSCREEN_CLIPPED] = "fullscreen clipped",
		[MENU_VIDEO_ENGINE_APPROX] = "approx. software",
		[MENU_VIDEO_ENGINE_ACCUR] = "accur. software",
		[MENU_VIDEO_ENGINE_ACCEL] = "PSP accelerated",
		[MENU_VIDEO_ENGINE_ACCEL_ACCUR] = "PSP accel. + accur. soft.",
		[MENU_VIDEO_ENGINE_ACCEL_APPROX] = "PSP accel. + approx. soft.",
		[MENU_VIDEO_SLIMITVALUE_AUTO] = "AUTO (detect PAL/NTSC)",
		[MENU_VIDEO_FSKIP_MODE_AUTO] = "auto change below %d",
		[MENU_VIDEO_FSKIP_CHANGEAUTO_AUTO] = "   auto change below set value",
		[MENU_VIDEO_FSKIP_CHANGEAUTO_FIXED] = "   fixed",

		[MENU_STATUS_VIDEO_SCRCALIB] = "PAD : SCREEN POSITION " SJIS_STAR " ANALOG STICK : SCREEN SIZE " SJIS_STAR " " SJIS_TRIANGLE " default " SJIS_STAR " %s Exit",

		// SOUND OPTIONS
		[MENU_ICONS_SOUND] = "SOUND",
		[MENU_ICONS_SOUND_MODE] = "Sound mode",
		[MENU_ICONS_SOUND_MODE_HELP] = "not emulated is the fastest\nbut some games won't run.",
		[MENU_ICONS_SOUND_FREQ] = "Output frequency",
		[MENU_ICONS_SOUND_FREQ_HELP] = "The lower the faster.\nThe higher the best sound\nquality.",
		[MENU_ICONS_SOUND_VOLADJUST] = "Sound volume level",
		[MENU_ICONS_SOUND_VOLADJUST_HELP] = "Increase sound volume level",
		[MENU_ICONS_SOUND_APURATIO] = "APU Cycles ratio",
		[MENU_ICONS_SOUND_APURATIO_HELP] = "For advanced users knowing\nwhat they do.",
		// MISC OPTIONS
		[MENU_ICONS_MISC] = "MISC",
		[MENU_ICONS_MISC_FILEVIEWER] = "View file",
		[MENU_ICONS_MISC_FILEVIEWER_HELP] = "Minimalist file viewer",
		[MENU_ICONS_MISC_PSPCLOCK] = "PSP Clockspeed",
		[MENU_ICONS_MISC_PSPCLOCK_HELP] = "value>222Mhz is NOT\noverclocking. It's safe but\nbatter runs out faster.",
		[MENU_ICONS_MISC_HACKDEBUG] = "Hack/debug menu",
		[MENU_ICONS_MISC_HACKDEBUG_HELP] = "For advanced users.\nHelp to tune the rendering and\ngain some speed.",
		[MENU_ICONS_MISC_SNAPSHOT] = "Snapshot",
		[MENU_ICONS_MISC_SNAPSHOT_HELP] = "Take a snapshot of the current\ngame screen.\nUsed in file browser.",
		[MENU_ICONS_MISC_SWAPBG] = "Swap BG",
		[MENU_ICONS_MISC_SWAPBG_HELP] = "Swap BG from the DATA/logo.zip\nfile.",
		[MENU_ICONS_MISC_BGMUSIC] = "Menu background music",
		[MENU_ICONS_MISC_BGMUSIC_HELP] = "Menu background music requires\nmake PSP running at 300Mhz\nMusic are from DATA/music.zip file.\nSPC format only.",
		[MENU_ICONS_MISC_BGFX] = "Menu background fx",
		[MENU_ICONS_MISC_BGFX_HELP] = "Nice FX from PS2DEV spline\nsample.",
		[MENU_ICONS_MISC_PADBEEP] = "Pad beep",
		[MENU_ICONS_MISC_PADBEEP_HELP] = "The beep sounds when browsing\nmenu and files.",
		[MENU_ICONS_MISC_AUTOSTART] = "Last ROM Auto-Start",
		[MENU_ICONS_MISC_AUTOSTART_HELP] = "If you set to [yes],the ROM\nwhich was loaded at last\n will start automatically\nwhen the emulator started.",
		[MENU_ICONS_MISC_OSK] = "OSK",
		[MENU_ICONS_MISC_OSK_HELP] = "OSK is On-Screen Keyboard.\nDanzeff is useful for typing\nalphabet on PSP. SCE official\nOSK is useful on ePSP.",
		[MENU_ICONS_MISC_LANGUAGE] = "Language",
		[MENU_ICONS_MISC_LANGUAGE_HELP] = "Change the emulator language.",

		[MENU_MUSIC_SWAPBG_NODATA] = "No Data",
		[MENU_MISC_SWAPBG_RAND] = "   Random",

		[MENU_MISC_OSK_DANZEFF] = "Danzeff",
		[MENU_MISC_OSK_OFFICIAL] = "Official",

		[MENU_STATUS_MISC_HACKDEBUG] = "%s Main Menu   ",
		[MENU_STATUS_MISC_HACKDEBUG_FUNC] = "%s OK     " SJIS_STAR "    %s Main Menu   ",
		[MENU_STATUS_MISC_HACKDEBUG_0] = SJIS_STAR "    " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value",

		[MENU_STATUS_MISC_HACKDEBUG_HELP_0] = SJIS_STAR "      " SJIS_TRIANGLE " Help       " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value",
		[MENU_STATUS_MISC_HACKDEBUG_HELP_1] = SJIS_STAR "     " SJIS_TRIANGLE "   Help      " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value",
		[MENU_STATUS_MISC_HACKDEBUG_HELP_2] = SJIS_STAR "    " SJIS_TRIANGLE "     Help     " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value",
		[MENU_STATUS_MISC_HACKDEBUG_HELP_3] = SJIS_STAR "   " SJIS_TRIANGLE "       Help    " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " Select " SJIS_LEFT "," SJIS_RIGHT " Change value",

		[MENU_TITLE_MISC_HACKDEBUG] = "[" PROJECT_NAME "] - Menu",

		// CHEATS
		[MENU_ICONS_CHEATS] = "CHEATS",
		[MENU_ICONS_CHEATS_ADDRAW] = "Add a RAW code",
		[MENU_ICONS_CHEATS_ADDRAW_HELP] = "Add a RAW code",
		[MENU_ICONS_CHEATS_ADDGG] = "Add a Game Genie code",
		[MENU_ICONS_CHEATS_ADDGG_HELP] = "Add a Game Genie code",
		[MENU_ICONS_CHEATS_ADDPAR] = "Add a Pro Action Replay code",
		[MENU_ICONS_CHEATS_ADDPAR_HELP] = "Add a Pro Action Replay code",
		[MENU_ICONS_CHEATS_ADDGF] = "Add a GoldFinger code",
		[MENU_ICONS_CHEATS_ADDGF_HELP] = "Add a GoldFinger code",
		[MENU_ICONS_CHEATS_DISABLE] = "Disable code",
		[MENU_ICONS_CHEATS_DISABLE_HELP] = "Disable code",
		[MENU_ICONS_CHEATS_DISABLEALL] = "Disable all codes",
		[MENU_ICONS_CHEATS_DISABLEALL_HELP] = "Disable all codes",
		[MENU_ICONS_CHEATS_ENABLE] = "Enable code",
		[MENU_ICONS_CHEATS_ENABLE_HELP] = "Enable code",
		[MENU_ICONS_CHEATS_ENABLEALL] = "Enable all codes",
		[MENU_ICONS_CHEATS_ENABLEALL_HELP] = "Enable all codes",
		[MENU_ICONS_CHEATS_REMOVE] = "Remove code",
		[MENU_ICONS_CHEATS_REMOVE_HELP] = "Remove code",
		[MENU_ICONS_CHEATS_REMOVEALL] = "Remove all codes",
		[MENU_ICONS_CHEATS_REMOVEALL_HELP] = "Remove all codes",
		// ABOUT
		[MENU_ICONS_ABOUT] = "ABOUT",
		[MENU_ICONS_ABOUT_CREDITS] = "Credits",
		[MENU_ICONS_ABOUT_VERSION] = "Version infos",

		[MENU_ABOUT_VERSION_TIMESTAMP] = "Build on %s",
		[MENU_ABOUT_VERSION_GCCVER] = "With GCC %s",

		//Others
		// Adhoc
		[ADHOC_CONNECTING] = "Connecting...\n",
		[ADHOC_SELECTORRETURN] = "Select a server to connect to, or triangle to return",
		[ADHOC_WAITING] = "Waiting for %s to accept the connection\nTo cancel press O\n",
		[ADHOC_REQUESTED] = "%s has requested a connection\nTo accept the connection press X, to cancel press O\n",
		[ADHOC_CONNECTED] = "Connected",
		[ADHOC_STATE] = "  connection state %d of 1\n",
		[ADHOC_UNKNOWNCOMMAND] = "Unknown command %02X !",
		[ADHOC_SYNCLOST_SERVER] = "SERVER Lost sync : resync!!!",
		[ADHOC_SYNCLOST_CLIENT] = "CLIENT Lost sync : resync!!!",
		[ADHOC_CLOSING] = "closing connection",
		[ADHOC_DRIVERLOAD_ERR] = "Net driver load error",
		[ADHOC_INIT_ERR] = "Issue with init adhoc game\n",
		[ADHOC_LOST_CONNECTION] = "Lost connection!",
		[ADHOC_CORRUPTED_PKT] = "corrupted pkt",
		[ADHOC_STATE_SIZE] = "state size : %d",
		[ADHOC_FILE_ERR_RECEIVING] = "file error while receiving state!",
		[ADHOC_FILE_ERR_SENDING] = "file error while sending state!",
		[ADHOC_STILL] = "still : %d",
		[ADHOC_WAITING_OTHER] = "Waiting for other player\n\nPress " SJIS_TRIANGLE " to close connection and quit netplay\n",
		[ADHOC_NETWORKERR_1] = "network error 1",
		[ADHOC_CANNOTFIND] = "cannot find save state!",
		[ADHOC_FLUSHING] = "flushing network, please wait a few seconds",
		// LOAD/SAVE
		[LOADSAVE_AUTOSAVETIMER] = "Autosaving...",
		[LOADSAVE_EXPORTS9XSTATE] = "Found a snes9xTYL file",
		// VIDEO
		[VIDEO_ENGINE_APPROX] = "Simple mode : accurate software",
		[VIDEO_ENGINE_ACCUR] = "Simple mode : approx. software",
		[VIDEO_ENGINE_ACCEL] = "Simple mode : PSP accelerated",
		[VIDEO_ENGINE_ACCEL_ACCUR] = "Mixed modes : PSP accelerated + accurate software",
		[VIDEO_ENGINE_ACCEL_APPROX] = "Mixed modes : PSP accelerated + approx. software",
		[VIDEO_FSKIP_AUTO] = "Frameskip : AUTO",
		[VIDEO_FSKIP_MANUAL] = "Frameskip : %d",
		// Scroll Message
		[SCROLL_HELP_MOVE] = "to move",
		[SCROLL_HELP_FAST] = "fast mode",
		[SCROLL_STATUS_0] = "Line %d/%d  -  Page %d/%d",
		[SCROLL_STATUS_1] = "   exit,        help  ",
		[SCROLL_HELP] = "Snes9xTYL - fileviewer\n\n"
			SJIS_TRIANGLE " Find, then %s Find next, " SJIS_SQUARE " Find previous\n"
			SJIS_UP "," SJIS_DOWN " scroll text, L,R scroll faster\n%s exit\n\n"
			"Last position is keeped if same file is reopened.\nHowever it will be reset if another file is opened.\n\n"
			"Press %s",
		[SCROLL_SEARCHING] = "Searching...",
		[SCROLL_STRNOTFOUND] = "String not found!",
		[SCROLL_DISCLAIMER] = "Disclaimer",
		[SCROLL_OSK_DESC] = "Enter String to find",
		//Settings
		[SETTINGS_NOTCOMPLETE] = "!!Settings file not complete!!\n\nProbably coming from a previous version.\n\nNew settings will be set with default values",
		[SETTINGS_NOTFOUND] = "No settings found, using default",
		[SETTINGS_FORCING_DEFAULT] = "Forcing default settings",
		[SETTINGS_IGNORED] = "ini file from a previous incompatible version, ignored!",
		[SETTINGS_FOUND] = "Settings found!\n\n""%s""",
		[SETTINGS_DIFF] = "ini file from a different version.",
		//Others
		[APU_DEBUGGING] = "APU DEBUGGING",
		[BGMUSIC_PLAYING] = "Playing spc file...",
		[FOUND_SRAM] = "Found an SRAM file",
		[CANCEL] = "CANCEL",
		[INPUTBOX_OK] = "\n\n      Close",
#ifdef ME_SOUND
		[BAT_ISLOW] = "Battery is low, saving is now disabled (SRAM,states and settings).\n\nThis window will close in 3 seconds.",
#else
		[BAT_ISLOW] = "Battery is low, saving is now disabled (SRAM,states and settings).\n\nYou can still put your PSP in sleep mode and charge battery later.\n\nThis window will close in 3 seconds.",
#endif
		[CONV_DONE] = "conversion done",
		[ROM_LIED] = "ROM lied about its type! Trying again.",
		[LOADING_ROM] = "Loading %dKo...",
		[TYPE] = "Type",
		[MODE] = "Mode",
		[COMPANY] = "Company",
#ifdef _BSX_151_
		[SRAM_NOTFOUND] = "The SRAM file wasn't found: BS-X.srm was read instead.",
		[SRAM_BSX_NOTFOUND] = "The SRAM file wasn't found, BS-X.srm wasn't found either.",
#endif
		[CORRUPT] = "Corrupt",
		[ROM_ONLY] = "ROM only",
		[EXTENDING] = "Extending",
		[EXTENDING_TARGET] = "Extending target from %d to %d\n",
		[INIT_OSK] = "Initializing OSK...",
	},
