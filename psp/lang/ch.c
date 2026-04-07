	[MSG_CH] = {
	//Chinese
		//error
		[ERR_OUT_OF_MEM] = "内存溢出",
		[ERR_READ_MEMSTICK] = "Error reading memstick.\nPlease verify it (using a PC card reader), it may be corrupted.",

		[ERR_INIT_SNES] = "内存問題導致SFC無法初始化",
		[ERR_LOADING_ROM] = "讀取ROM出錯",
		[ERR_INIT_GFX] = "無法初始化圖像",

		[ERR_CANNOT_ALLOC_MEM] = "無法分配内存",

		[ERR_USB_STARTING_USBBUS] = "USB驅動錯誤 (0x%08X)\n",
		[ERR_USB_STARTING_USBMASS] = "USB大容量記憶設備驅動錯誤 (0x%08X)\n",
		[ERR_USB_SETTING_CAPACITY] = "USB大容量記憶設備驅動配置錯誤 (0x%08X)\n",
		//confirm
		[ASK_EXIT] = "是否退出Snes9XTYL?",
		[ASK_DELETE] = "是否刪除文件?",
		[ASK_SAVEDIR] = "保存目録不存在\n"
			"保存在模擬器目録請按" SJIS_CIRCLE  "鍵。\n"
			"保存在SAVEDATA目録請按 " SJIS_CROSS "鍵。\n",
		//info
		[INFO_USB_ON] = "USB連接中",
		[INFO_USB_OFF] = "USB已断開",
		[INFO_DELETING] = "刪除中...",
		[INFO_EXITING] = "退出中，請稍等...",
		//filer
		[FILER_STATUS_CANEXIT1] = "%s 運行 " SJIS_SQUARE " 用默認設置運行  " SJIS_STAR "  %s 返回遊戲  "  SJIS_STAR "  " SJIS_TRIANGLE " %s  "  SJIS_STAR "  " SJIS_UP "" SJIS_DOWN "" SJIS_LEFT "" SJIS_RIGHT " 移動",
		[FILER_STATUS_NOEXIT1] = "%s 運行 " SJIS_SQUARE " 用默認設置運行  "  SJIS_STAR "  " SJIS_TRIANGLE " %s          " SJIS_UP "" SJIS_DOWN "" SJIS_LEFT "" SJIS_RIGHT " 移動",
		[FILER_STATUS_CANEXIT2] = "%s 運行 %s 返回遊戲 " SJIS_TRIANGLE " %s  " SJIS_UP "" SJIS_DOWN "" SJIS_LEFT "" SJIS_RIGHT ", 移動",
		[FILER_STATUS_NOEXIT2] = "%s 運行 " SJIS_TRIANGLE " %s                  " SJIS_UP "" SJIS_DOWN "" SJIS_LEFT "" SJIS_RIGHT ", 移動",

		[FILER_STATUS_PARDIR] = "上級目録",

		[FILER_TITLE] = "[" EMUNAME_VERSION "] - 文件選擇",

		[FILER_HELP_WINDOW1] = "按START鍵切換",
		[FILER_HELP_WINDOW2] = "聯機模式",
#ifdef FW3X
		[FILER_HELP_WINDOW3] = " ",
#ifdef HOME_HOOK
		[FILER_HELP_WINDOW4] = "按HOME鍵退出",
#else
		[FILER_HELP_WINDOW4] = "按L+R鍵退出",
#endif
#else
#ifdef HOME_HOOK
		[FILER_HELP_WINDOW3] = "按HOME鍵退出",
#else
		[FILER_HELP_WINDOW3] = "按L+R鍵退出",
#endif
		[FILER_HELP_WINDOW4] = "按R鍵連接/断開USB",
#endif


		[FILER_HELP_WINDOW5] = "按SELECT鍵刪除文件",

		[FILE_IPS_APPLYING] = "發現IPS補丁: %s\n大小: %dKb\n執行中...",
		[FILE_IPS_PATCHSUCCESS] = "IPS補丁使用成功",

		[MENU_STATUS_GENERIC_MSG1] = "請按%s鍵返回",
		[MENU_STATUS_GENERIC_NEEDRELOAD] = "重新讀取遊戲后有效",
		[MENU_STATUS_GENERIC_NEEDRESET] = "重啓遊戲后有效",
		[MENU_STATUS_GENERIC_CHANGEMUSIC] = "按SELECT鍵切換音樂",

		[MENU_TITLE_GENERIC_BAT] = "電量",
		[MENU_TITLE_GENERIC_BAT_TIME] = "(%02d小時%02d分)",
		[MENU_TITLE_GENERIC_BAT_TEMP] = " 温度:%d℃",
		[MENU_TITLE_GENERIC_BAT_PLG] = "電源",
		[MENU_TITLE_GENERIC_BAT_CHRG] = "充電中",
		[MENU_TITLE_GENERIC_BAT_LOW] = "電量低",

		[MENU_CHANGE_VALUE] = "  ,   更改",
		[MENU_CHANGE_VALUE_WITH_FAST] = "  ,   更改 -  ,  快速",
		[MENU_CANCEL_VALIDATE] = "  ,   取消 -          確定",
		[MENU_DEFAULT_VALUE] = "   默認",
		[MENU_YES] = "是",
		[MENU_NO] = "否",
		[MENU_NOT_IMPLEMENTED] = "Not yet implemented.\n\n",

		[MENU_SOUND_MODE_NOTEMUL] = "沒有模擬",
		[MENU_SOUND_MODE_EMULOFF] = "關閉聲音",
		[MENU_SOUND_MODE_EMULON] = "輸出聲音",

		[MENU_STATE_CHOOSEDEL] = "選擇要刪除的存档",
		[MENU_STATE_CHOOSELOAD] = "選擇要讀取的存档",
		[MENU_STATE_CHOOSESAVE] = "選擇要保存的存档",
		[MENU_STATE_FREESLOT] = "可用",
		[MENU_STATE_SCANNING] = "正在搜索可用的存档...",


		[ERR_INIT_OSK] = "無法初始化OSK",
		[ERR_ADD_CODE] = "無法添加更多的金手指代碼",

		[MENU_CHEATS_ENTERGF] = "輸入GoldFinger代碼",
		[MENU_CHEATS_ENTERPAR] = "輸入Pro Action Replay代碼",
		[MENU_CHEATS_ENTERGG] = "輸入Game Genie代碼",
		[MENU_CHEATS_ENTERRAW] = "輸入RAW代碼\n格式: 地址 - 新値",
		[MENU_CHEATS_CONFIRMREMALL] = "是否刪除所有代碼?",
		[MENU_CHEATS_ENTERNAME] = "輸入名字",
		[MENU_CHEATS_PREVPAGE] = "L - 上頁",
		[MENU_CHEATS_NEXTPAGE] = "R - 下頁",

		[MENU_STATE_CONFIRMLOAD] = "当前的遊戲進度會消失\n是否繼續?",
		[MENU_STATE_CONFIRMDELETE] = "是否刪除当前存档?",
		[MENU_STATE_CONFIRMSAVE] = "是否要覆蓋当前存档?",
		[MENU_STATE_ISLOADING] = "正在讀取即時存档...",
		[MENU_STATE_ISSAVING] = "正在保存即時存档...",
		[MENU_STATE_ISDELETING] = "正在刪除...",
		[MENU_STATE_ISIMPORTING] = "正在導入存档...",
		[MENU_STATE_ISEXPORTINGS9X] = "正在導出SNES9X存档...",
		[MENU_STATE_NOSTATE] = "沒有可用的存档...",
		[MENU_STATE_AUTOSAVETIMER] = "毎%d分鐘.",
		[MENU_STATE_AUTOSAVETIMER_OFF] = "關",
		[MENU_STATE_WARNING_LOWBAT] = "電量低\n如果存档中途斷電，會破壞記憶棒\n是否繼續?",
		[MENU_GAME_SAVINGDEFAULTSETTINGS] = "保存当前設置為默認設置",
		[MENU_GAME_CONFIRMRESET] = "重啓SNES?",
		[MENU_MISC_SAVINGJPEG] = "正在保存JPEG截圖...",

		[MENU_MISC_BGMUSIC_RAND] = "隨機播放",
		[MENU_MISC_BGMUSIC_ORDER] = "順序播放",

		[MENU_MISC_BGMUSIC_UNKNOWN] = "未知",
		[MENU_MISC_BGMUSIC_GAMETITLE] = "遊戲: ",
		[MENU_MISC_BGMUSIC_TITLE] = "標題: ",
		[MENU_MISC_BGMUSIC_AUTHOR] = "作者: ",


		// GAME
		[MENU_ICONS_GAME] = "遊戲",
		[MENU_ICONS_GAME_RESET] = "重啓SNES",
		[MENU_ICONS_GAME_NEW] = "讀取新遊戲",
		[MENU_ICONS_GAME_DEFAULTSETTINGS] = "作成默認設置",
		[MENU_ICONS_GAME_DEFAULTSETTINGS_HELP] = "如果沒有特殊設置，将當前設置作\n為所有遊戲的默認設置。",
		[MENU_ICONS_GAME_EXIT] = "退出Snes9xTYL",
		// LOAD/SAVE
		[MENU_ICONS_LOADSAVE] = "即時讀档/存档",
		[MENU_ICONS_LOADSAVE_LOADSTATE] = "即時讀档",
		[MENU_ICONS_LOADSAVE_LOADSTATE_HELP] = "讀取上一次的即時存档。\n即時存档保存了SFC的所有數據，\n包括截圖。",
		[MENU_ICONS_LOADSAVE_SAVESTATE] = "即時存档",
		[MENU_ICONS_LOADSAVE_SAVESTATE_HELP] = "即時存档",
		[MENU_ICONS_LOADSAVE_DELETESTATE] = "刪除存档",
		[MENU_ICONS_LOADSAVE_DELETESTATE_HELP] = "刪除存档",
		[MENU_ICONS_LOADSAVE_IMPORTSTATE] = "導入存档",
		[MENU_ICONS_LOADSAVE_IMPORTSTATE_HELP] = "導入旧版或非官方版的存档數據。",

		[MENU_ICONS_LOADSAVE_EXPORTS9XSTATE] = "導出SNES9X存档",
		[MENU_ICONS_LOADSAVE_EXPORTS9XSTATE_HELP] = "導出SNES9X格式的存档數據。",

		[MENU_ICONS_LOADSAVE_AUTOSAVETIMER] = "自動存档計時器",
		[MENU_ICONS_LOADSAVE_AUTOSAVETIMER_HELP] = "定時保存即時存档。",
		[MENU_ICONS_LOADSAVE_AUTOSRAM] = "自動更新SRAM",
		[MENU_ICONS_LOADSAVE_AUTOSRAM_HELP] = "允許毎次更改后保存SRAM。",
		// CONTROLS
		[MENU_ICONS_CONTROLS] = "手柄",
		[MENU_ICONS_CONTROLS_REDEFINE] = "設置",
		[MENU_ICONS_CONTROLS_REDEFINE_HELP] = "設置操作的按鍵",
		[MENU_ICONS_CONTROLS_INPUT] = "模擬輸入",
		[MENU_ICONS_CONTROLS_INPUT_HELP] = "選擇当前使用的手柄。",

		[MENU_CONTROLS_INPUT] = "%d號手柄",
		[MENU_CONTROLS_INPUT_PRESS] = "%s請輸入按鍵",
		[MENU_CONTROLS_INPUT_NOFORMENU] = "請選擇模擬器菜單的按鍵",
#ifdef HOME_HOOK
		[MENU_CONTROLS_INPUT_DEFAULT] = "請選默認配置文件: \n\n"
			SJIS_CROSS " - 默認, 使用PSP的十\字鍵作為SFC的十\字鍵。\n\n"
			SJIS_CIRCLE " - 默認, 使用PSP的搖杆作為SFC的十\字鍵。\n\n"
			SJIS_SQUARE " - 默認, 使用PSP的十\字鍵/搖杆作為SFC的十\字鍵。\n\n"
			SJIS_TRIANGLE " 取消\n",
#else
		[MENU_CONTROLS_INPUT_DEFAULT] = "選擇默認設置: \n\n"
			SJIS_CROSS " - 默認, 使用PSP的十\字鍵作為SFC的十\字鍵，搖杆左打開菜單。\n\n"
			SJIS_CIRCLE " - 默認, 使用PSP的搖杆作為SFC的十\字鍵，十\字鍵左打開菜單。\n\n"
			SJIS_SQUARE " - 默認, 使用PSP的十\字鍵/搖杆作為SFC的十\字鍵，L+R打開菜單。\n\n"
			SJIS_TRIANGLE " 取消\n",
#endif

		[MENU_STATUS_CONTROLS_INPUT] = "%s 檢測模式   " SJIS_STAR "  %s 返回  ",
		[MENU_STATUS_CONTROLS_INPUT_0] = SJIS_STAR "  " SJIS_UP "," SJIS_DOWN " 移動 " SJIS_LEFT "," SJIS_RIGHT " 更改  " SJIS_STAR "  SELECT 默認設置",
		[MENU_STATUS_CONTROLS_INPUT_HELP_0] = SJIS_STAR "      " SJIS_TRIANGLE " 幇助       " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " 選擇 " SJIS_LEFT "," SJIS_RIGHT " 更改",
		[MENU_STATUS_CONTROLS_INPUT_HELP_1] = SJIS_STAR "     " SJIS_TRIANGLE "   幇助      " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " 選擇 " SJIS_LEFT "," SJIS_RIGHT " 更改",
		[MENU_STATUS_CONTROLS_INPUT_HELP_2] = SJIS_STAR "    " SJIS_TRIANGLE "     幇助     " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " 選擇 " SJIS_LEFT "," SJIS_RIGHT " 更改",
		[MENU_STATUS_CONTROLS_INPUT_HELP_3] = SJIS_STAR "   " SJIS_TRIANGLE "       幇助    " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " 選擇 " SJIS_LEFT "," SJIS_RIGHT " 更改",

		[MENU_TITLE_CONTROLS_INPUT] = "[" EMUNAME_VERSION "] - 輸入控制",

		// VIDEO OPTIONS
		[MENU_ICONS_VIDEO] = "視頻",
		[MENU_ICONS_VIDEO_MODE] = "輸出模式",
		[MENU_ICONS_VIDEO_MODE_HELP] = "更改畫面比例。\n推薦4:3。",
		[MENU_ICONS_VIDEO_ENGINE] = "設備",
		[MENU_ICONS_VIDEO_ENGINE_HELP] = "硬件加速模式不一定總是最快的。",
		[MENU_ICONS_VIDEO_SLIMITONOFF] = "速度限制切換",
		[MENU_ICONS_VIDEO_SLIMITONOFF_HELP] = "限制遊戲的速度。",
		[MENU_ICONS_VIDEO_SLIMITVALUE] = "FPS速度限制",
		[MENU_ICONS_VIDEO_SLIMITVALUE_HELP] = "僅使用速度限制。",
		[MENU_ICONS_VIDEO_FSKIP] = "跳幀",
		[MENU_ICONS_VIDEO_FSKIP_HELP] = "如果出現圖像消失的情況，請選擇\n一個數値。",
		[MENU_ICONS_VIDEO_SMOOTHING] = "平滑",
		[MENU_ICONS_VIDEO_SMOOTHING_HELP] = "打開不會降低速度。",
		[MENU_ICONS_VIDEO_VSYNC] = "垂直同歩",
		[MENU_ICONS_VIDEO_VSYNC_HELP] = "會降低FPS，應該關閉。",
		[MENU_ICONS_VIDEO_PALASNTSC] = "PAL顯示為NTSC",
		[MENU_ICONS_VIDEO_PALASNTSC_HELP] = "強制使PAL遊戲的清晰高度顯示為\n240。",
		[MENU_ICONS_VIDEO_GAMMA] = "畫面修正",
		[MENU_ICONS_VIDEO_GAMMA_HELP] = "可調節顯示的亮度。",
		[MENU_ICONS_VIDEO_SCRCALIB] = "畫面位置修正",
		[MENU_ICONS_VIDEO_SCRCALIB_HELP] = "調節屏幕顯示的畫面位置。",
		[MENU_ICONS_VIDEO_SHOWFPS] = "顯示FPS",
		[MENU_ICONS_VIDEO_SHOWFPS_HELP] = "第一行顯示FPS，\n第二行顯示實際的FPS。",

		[MENU_VIDEO_MODE_1_1] = "原始",
		[MENU_VIDEO_MODE_ZOOM_FIT] = "縮放",
		[MENU_VIDEO_MODE_ZOOM_4_3RD] = "4:3",
		[MENU_VIDEO_MODE_ZOOM_WIDE] = "14:9",
		[MENU_VIDEO_MODE_FULLSCREEN] = "全屏",
		[MENU_VIDEO_MODE_FULLSCREEN_CLIPPED] = "全屏裁剪",
		[MENU_VIDEO_ENGINE_APPROX] = "接近軟件顯示",
		[MENU_VIDEO_ENGINE_ACCUR] = "精確軟件顯示",
		[MENU_VIDEO_ENGINE_ACCEL] = "PSP硬件加速",
		[MENU_VIDEO_ENGINE_ACCEL_ACCUR] = "PSP硬件加速+精確軟件顯示",
		[MENU_VIDEO_ENGINE_ACCEL_APPROX] = "PSP硬件加速+接近軟件顯示",
		[MENU_VIDEO_SLIMITVALUE_AUTO] = "自動(檢測PAL/NTSC)",
		[MENU_VIDEO_FSKIP_MODE_AUTO] = "低於%d時自動更改",
		[MENU_VIDEO_FSKIP_CHANGEAUTO_AUTO] = "   低於設定値時自動更改",
		[MENU_VIDEO_FSKIP_CHANGEAUTO_FIXED] = "   固定",

		[MENU_STATUS_VIDEO_SCRCALIB] = "十\字鍵 : 畫面位置  " SJIS_STAR "  搖杆 : 畫面尺寸  " SJIS_STAR "  " SJIS_TRIANGLE " 默認  " SJIS_STAR "  %s 退出",

		// SOUND OPTIONS
		[MENU_ICONS_SOUND] = "音頻",
		[MENU_ICONS_SOUND_MODE] = "音頻模式",
		[MENU_ICONS_SOUND_MODE_HELP] = "關閉聲音是最快的，\n但是某些遊戲也許無法運行",
		[MENU_ICONS_SOUND_FREQ] = "聲音頻率",
		[MENU_ICONS_SOUND_FREQ_HELP] = "越低越快，越高音質越好。",
		[MENU_ICONS_SOUND_VOLADJUST] = "音量級別",
		[MENU_ICONS_SOUND_VOLADJUST_HELP] = "揄ﾁ音量級別",
		[MENU_ICONS_SOUND_APURATIO] = "APU周期比率",
		[MENU_ICONS_SOUND_APURATIO_HELP] = "高級用戸知道這是幹什麼用的。",
		// MISC OPTIONS
		[MENU_ICONS_MISC] = "其他",
		[MENU_ICONS_MISC_FILEVIEWER] = "査看文件",
		[MENU_ICONS_MISC_FILEVIEWER_HELP] = "簡易文件査看器",
		[MENU_ICONS_MISC_PSPCLOCK] = "PSP CPU速率",
		[MENU_ICONS_MISC_PSPCLOCK_HELP] = "222MHz以上速度穩定，但是電池消\n耗會更快。",
		[MENU_ICONS_MISC_HACKDEBUG] = "Hack/debug菜單",
		[MENU_ICONS_MISC_HACKDEBUG_HELP] = "高級用戸使用。\n針對速度調整顯示。",
		[MENU_ICONS_MISC_SNAPSHOT] = "截圖",
		[MENU_ICONS_MISC_SNAPSHOT_HELP] = "保存当前截圖作為瀏覽圖。",
		[MENU_ICONS_MISC_SWAPBG] = "背景圖片",
		[MENU_ICONS_MISC_SWAPBG_HELP] = "選擇DATA/logo.zip中的背景圖。",
		[MENU_ICONS_MISC_BGMUSIC] = "背景音樂",
		[MENU_ICONS_MISC_BGMUSIC_HELP] = "背景音樂需要CPU在300MHz以上，\n音樂文件在DATA/music.zip，\n只支持SPC格式。",
		[MENU_ICONS_MISC_BGFX] = "背景動畫",
		[MENU_ICONS_MISC_BGFX_HELP] = "PS2DEV spline sample的動畫。",
		[MENU_ICONS_MISC_PADBEEP] = "按鍵音",
		[MENU_ICONS_MISC_PADBEEP_HELP] = "移動光標時的按鍵聲音。",
		[MENU_ICONS_MISC_AUTOSTART] = "自動讀取上次遊戲",
		[MENU_ICONS_MISC_AUTOSTART_HELP] = "設置為「是」将在運行模擬器后自\n動讀取上一次的遊戲。",
		[MENU_ICONS_MISC_OSK] = "OSK",
		[MENU_ICONS_MISC_OSK_HELP] = "OSK是畫面上的鍵盤。\nDanzeff OSK可在PSP輸入字母。\nSCE官方OSK可在PSP/PSV輸入日文。",
		[MENU_ICONS_MISC_LANGUAGE] = "Language",
		[MENU_ICONS_MISC_LANGUAGE_HELP] = "更改模拟器语言。",

		[MENU_MUSIC_SWAPBG_NODATA] = "沒有數據",
		[MENU_MISC_SWAPBG_RAND] = "   隨機",

		[MENU_MISC_OSK_DANZEFF] = "Danzeff",
		[MENU_MISC_OSK_OFFICIAL] = "官方",

		[MENU_STATUS_MISC_HACKDEBUG] = "%s 主菜單   ",
		[MENU_STATUS_MISC_HACKDEBUG_FUNC] = "%s 確定     " SJIS_STAR "    %s 主菜單   ",
		[MENU_STATUS_MISC_HACKDEBUG_0] = SJIS_STAR "    " SJIS_UP "," SJIS_DOWN " 選擇 " SJIS_LEFT "," SJIS_RIGHT " 更改",

		[MENU_STATUS_MISC_HACKDEBUG_HELP_0] = SJIS_STAR "      " SJIS_TRIANGLE " 幇助       " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " 選擇 " SJIS_LEFT "," SJIS_RIGHT " 更改",
		[MENU_STATUS_MISC_HACKDEBUG_HELP_1] = SJIS_STAR "     " SJIS_TRIANGLE "   幇助      " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " 選擇 " SJIS_LEFT "," SJIS_RIGHT " 更改",
		[MENU_STATUS_MISC_HACKDEBUG_HELP_2] = SJIS_STAR "    " SJIS_TRIANGLE "     幇助     " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " 選擇 " SJIS_LEFT "," SJIS_RIGHT " 更改",
		[MENU_STATUS_MISC_HACKDEBUG_HELP_3] = SJIS_STAR "   " SJIS_TRIANGLE "       幇助    " SJIS_STAR "      " SJIS_UP "," SJIS_DOWN " 選擇 " SJIS_LEFT "," SJIS_RIGHT " 更改",

		[MENU_TITLE_MISC_HACKDEBUG] = "[" EMUNAME_VERSION "] - Hack/debug菜單",

		// CHEATS
		[MENU_ICONS_CHEATS] = "金手指",
		[MENU_ICONS_CHEATS_ADDRAW] = "添加RAW代碼",
		[MENU_ICONS_CHEATS_ADDRAW_HELP] = "添加RAW代碼",
		[MENU_ICONS_CHEATS_ADDGG] = "添加Game Genie代碼",
		[MENU_ICONS_CHEATS_ADDGG_HELP] = "添加Game Genie代碼",
		[MENU_ICONS_CHEATS_ADDPAR] = "添加Pro Action Replay代碼",
		[MENU_ICONS_CHEATS_ADDPAR_HELP] = "添加Pro Action Replay代碼",
		[MENU_ICONS_CHEATS_ADDGF] = "添加GoldFinger代碼",
		[MENU_ICONS_CHEATS_ADDGF_HELP] = "添加GoldFinger代碼",
		[MENU_ICONS_CHEATS_DISABLE] = "禁用代碼",
		[MENU_ICONS_CHEATS_DISABLE_HELP] = "禁用代碼",
		[MENU_ICONS_CHEATS_DISABLEALL] = "禁用所有代碼",
		[MENU_ICONS_CHEATS_DISABLEALL_HELP] = "禁用所有代碼",
		[MENU_ICONS_CHEATS_ENABLE] = "使用代碼",
		[MENU_ICONS_CHEATS_ENABLE_HELP] = "使用代碼",
		[MENU_ICONS_CHEATS_ENABLEALL] = "使用所有代碼",
		[MENU_ICONS_CHEATS_ENABLEALL_HELP] = "使用所有代碼",
		[MENU_ICONS_CHEATS_REMOVE] = "刪除代碼",
		[MENU_ICONS_CHEATS_REMOVE_HELP] = "刪除代碼",
		[MENU_ICONS_CHEATS_REMOVEALL] = "刪除所有代碼",
		[MENU_ICONS_CHEATS_REMOVEALL_HELP] = "刪除所有代碼",
		// ABOUT
		[MENU_ICONS_ABOUT] = "關於",
		[MENU_ICONS_ABOUT_CREDITS] = "開發人員",
		[MENU_ICONS_ABOUT_VERSION] = "版本信息",

		[MENU_ABOUT_VERSION_TIMESTAMP] = "創建日期 %s",
		[MENU_ABOUT_VERSION_GCCVER] = "GCC版本 %s",

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
		[ADHOC_CANNOTFIND] = "沒有即時存档!",
		[ADHOC_FLUSHING] = "flushing network, please wait a few seconds",
		// LOAD/SAVE
		[LOADSAVE_AUTOSAVETIMER] = "自動保存中...",
		[LOADSAVE_EXPORTS9XSTATE] = "發現snes9xTYL文件",
		// VIDEO
		[VIDEO_ENGINE_APPROX] = "Simple mode : accurate software",
		[VIDEO_ENGINE_ACCUR] = "Simple mode : approx. software",
		[VIDEO_ENGINE_ACCEL] = "Simple mode : PSP accelerated",
		[VIDEO_ENGINE_ACCEL_ACCUR] = "Mixed modes : PSP accelerated + accurate software",
		[VIDEO_ENGINE_ACCEL_APPROX] = "Mixed modes : PSP accelerated + approx. software",
		[VIDEO_FSKIP_AUTO] = "跳幀: 自動",
		[VIDEO_FSKIP_MANUAL] = "跳幀: %d",
		// Scroll Message
		[SCROLL_HELP_MOVE] = "移動",
		[SCROLL_HELP_FAST] = "快速模式",
		[SCROLL_STATUS_0] = "行 %d/%d  -  頁 %d/%d",
		[SCROLL_STATUS_1] = "   退出,        幇助  ",
		[SCROLL_HELP] = "Snes9xTYL - 文件査看器\n\n"
			SJIS_TRIANGLE " Find, then %s Find next, " SJIS_SQUARE " Find previous\n"
			SJIS_UP "," SJIS_DOWN " scroll text, L,R scroll faster\n%s exit\n\n"
			"Last position is keeped if same file is reopened.\nHowever it will be reset if another file is opened.\n\n"
			"Press %s",
		[SCROLL_SEARCHING] = "正在搜索...",
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
		[BGMUSIC_PLAYING] = "正在播放spc文件...",
		[FOUND_SRAM] = "發現SRAM文件",
		[CANCEL] = "取消",
		[INPUTBOX_OK] = "\n\n      關閉",
#ifdef ME_SOUND
		[BAT_ISLOW] = "Battery is low, saving is now disabled (SRAM,states and settings).\n\nThis window will close in 3 seconds.",
#else
		[BAT_ISLOW] = "Battery is low, saving is now disabled (SRAM,states and settings).\n\nYou can still put your PSP in sleep mode and charge battery later.\n\nThis window will close in 3 seconds.",
#endif
		[CONV_DONE] = "conversion done",
		[ROM_LIED] = "ROM lied about its type! Trying again.",
		[LOADING_ROM] = "正在讀取%dK...",
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
		[INIT_OSK] = "正在初始化OSK...",
	},
