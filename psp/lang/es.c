[MSG_ES] = {
    // español
    // error
    [ERR_OUT_OF_MEM] = "Memoria insuficiente",
    [ERR_READ_MEMSTICK] = "Error al leer Memory Stick.\n"
                          "Verifica en el PC, puede estar corrupto.",

    [ERR_INIT_SNES] = "No fue posible iniciar SNES, problema de memoria",
    [ERR_LOADING_ROM] = "Error al cargar la ROM",
    [ERR_INIT_GFX] = "No fue posible inicializar los gráficos",

    [ERR_CANNOT_ALLOC_MEM] = "No fue posible asignar memoria",

    [ERR_USB_STARTING_USBBUS] = "Error al iniciar el driver USB Bus (0x%08X)\n",
    [ERR_USB_STARTING_USBMASS] =
        "Error al iniciar el driver USB Mass Storage (0x%08X)\n",
    [ERR_USB_SETTING_CAPACITY] =
        "Error al definir la capacidad con el driver USB Mass Storage (0x%08X)\n",
    // confirmar
    [ASK_EXIT] = "¿Salir de Snes9XTYL?",
    [ASK_DELETE] = "¿Eliminar archivo?",
    [ASK_SAVEDIR] =
        "No se encontró el directorio de guardado.\n"
        "Para crear el directorio en la carpeta donde está este emulador, "
        "presiona " SJIS_CIRCLE "\n"
        "Para crear el directorio en la carpeta SAVEDATA, presiona " SJIS_CROSS "\n",
    // info
    [INFO_USB_ON] = "USB activado",
    [INFO_USB_OFF] = "USB desactivado",
    [INFO_DELETING] = "Eliminando...",
    [INFO_EXITING] = "Saliendo, espera...",
    [INFO_LOADING_FILES] = "Cargando archivos: %d...",
    [INFO_FAV_ADDED] = "Añadido a Favoritos",
    [INFO_FAV_REMOVED] = "Eliminado de Favoritos",
    [INFO_NO_FAV_GAMES] = "¡Aún no hay juegos favoritos!",
    // filer
    [FILER_STATUS_CANEXIT1] =
        "%s Iniciar " SJIS_SQUARE " Usar config. por defecto " SJIS_STAR
        " %s Reanudar juego " SJIS_STAR " " SJIS_TRIANGLE " %s " SJIS_STAR
        " CRUZAR",
    [FILER_STATUS_NOEXIT1] =
        "%s Iniciar " SJIS_SQUARE " Usar config. por defecto  " SJIS_STAR
        "  " SJIS_TRIANGLE " %s  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT
        "," SJIS_RIGHT ", Mover",
    [FILER_STATUS_CANEXIT2] =
        "%s Iniciar %s Reanudar juego " SJIS_TRIANGLE " %s  " SJIS_UP
        "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", Mover",
    [FILER_STATUS_NOEXIT2] =
        "%s Iniciar " SJIS_TRIANGLE " %s                  " SJIS_UP
        "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", Mover",

    [FILER_STATUS_PARDIR] = "Directorio padre",

    [FILER_TITLE] = "[" PROJECT_NAME "] - Elige un archivo",

    [FILER_HELP_WINDOW1] = "Presiona:",
    [FILER_HELP_WINDOW2] = "START: Normal/Netplay",
#ifdef FW3X
    [FILER_HELP_WINDOW3] = "L: Favorito juego",
#ifdef HOME_HOOK
    [FILER_HELP_WINDOW4] = "HOME: salir",
#else
    [FILER_HELP_WINDOW4] = "L+R: salir",
#endif
#else
#ifdef HOME_HOOK
    [FILER_HELP_WINDOW3] = "HOME: salir",
#else
    [FILER_HELP_WINDOW3] = "L+R: salir",
#endif
    [FILER_HELP_WINDOW4] = "R: USB on/off",
#endif
    [FILER_HELP_WINDOW5] = "SELECT: eliminar archivo",

    [FILE_IPS_APPLYING] =
        "Parche IPS encontrado: %s\nTamaño: %dKB\nAplicando...",
    [FILE_IPS_PATCHSUCCESS] = "Parche IPS aplicado con éxito",

    [MENU_STATUS_GENERIC_MSG1] = "Presiona %s para volver",
    [MENU_STATUS_GENERIC_NEEDRELOAD] =
        "Los cambios pueden requerir RECARGAR para tener efecto",
    [MENU_STATUS_GENERIC_NEEDRESET] =
        "Los cambios pueden requerir REINICIAR para tener efecto",
    [MENU_STATUS_GENERIC_CHANGEMUSIC] = "SELECT para cambiar música",

    [MENU_TITLE_GENERIC_BAT] = "Bat.",
    [MENU_TITLE_GENERIC_BAT_TIME] = "(%02dh%02dm)",
    [MENU_TITLE_GENERIC_BAT_TEMP] = " Temp.%d℃",
    [MENU_TITLE_GENERIC_BAT_PLG] = "Con.",
    [MENU_TITLE_GENERIC_BAT_CHRG] = "Carg.",
    [MENU_TITLE_GENERIC_BAT_LOW] = "¡Baja!",

    [MENU_CHANGE_VALUE] = "  ,   cambiar valor",
    [MENU_CHANGE_VALUE_WITH_FAST] = "  ,   cambiar valor -  ,  rápido",
    [MENU_CANCEL_VALIDATE] = "  ,   cancelar   -      validar",
    [MENU_DEFAULT_VALUE] = "   valor por defecto",
    [MENU_YES] = "sí",
    [MENU_NO] = "no",
    [MENU_NOT_IMPLEMENTED] = "Aún no implementado.\n\n",

    [MENU_SOUND_MODE_NOTEMUL] = "no emulado",
    [MENU_SOUND_MODE_EMULOFF] = "emulado, sin salida",
    [MENU_SOUND_MODE_EMULON] = "emulado, con salida",

    [MENU_STATE_CHOOSEDEL] = "Elige un slot para ELIMINAR",
    [MENU_STATE_CHOOSELOAD] = "Elige un slot para CARGAR",
    [MENU_STATE_CHOOSESAVE] = "Elige un slot para GUARDAR",
    [MENU_STATE_FREESLOT] = "LIBRE",
    [MENU_STATE_SCANNING] = "Verificando slots usados...",

    [ERR_INIT_OSK] = "no fue posible iniciar el OSK",
    [ERR_ADD_CODE] =
        "No fue posible añadir código de truco, ¡demasiados ya insertados!",

    [MENU_CHEATS_ENTERGF] = "Introduce un código GoldFinger",
    [MENU_CHEATS_ENTERPAR] = "Introduce un código Pro Action Replay",
    [MENU_CHEATS_ENTERGG] = "Introduce un código Game Genie",
    [MENU_CHEATS_ENTERRAW] =
        "Introduce un código RAW\nEl formato es DIRECCIÓN - NUEVO VALOR",
    [MENU_CHEATS_CONFIRMREMALL] = "¿Eliminar todos los códigos?",
    [MENU_CHEATS_ENTERNAME] = "Introduce el Nombre",
    [MENU_CHEATS_PREVPAGE] = "L - Pág. Anterior",
    [MENU_CHEATS_NEXTPAGE] = "R - Sig. Página",

    [MENU_STATE_CONFIRMLOAD] =
        "El progreso actual del juego se perderá.\n¿Continuar?",
    [MENU_STATE_CONFIRMDELETE] = "¿Eliminar progreso actual?",
    [MENU_STATE_CONFIRMSAVE] = "¿Sobrescribir progreso guardado actual?",
    [MENU_STATE_ISLOADING] = "Cargando progreso...",
    [MENU_STATE_ISSAVING] = "Guardando progreso...",
    [MENU_STATE_ISDELETING] = "Eliminando...",
    [MENU_STATE_ISIMPORTING] = "Importando progreso...",
    [MENU_STATE_ISEXPORTINGS9X] = "Exportando progreso SNES9X...",
    [MENU_STATE_NOSTATE] = "No hay progreso disponible...",
    [MENU_STATE_AUTOSAVETIMER] = "cada %dmin.",
    [MENU_STATE_AUTOSAVETIMER_OFF] = "desactivado",
    [MENU_STATE_WARNING_LOWBAT] =
        "Batería baja.\nSi el PSP se apaga durante el guardado, el Memory "
        "Stick puede dañarse.\n¿Continuar?",
    [MENU_GAME_SAVINGDEFAULTSETTINGS] =
        "Guardando configuración actual como perfil por defecto",
    [MENU_GAME_CONFIRMRESET] = "¿Reiniciar el SNES?",
    [MENU_MISC_SAVINGJPEG] = "Guardando captura JPEG...",

    [MENU_MISC_BGMUSIC_RAND] = "Reproducir aleatorio",
    [MENU_MISC_BGMUSIC_ORDER] = "Reproducir en orden",

    [MENU_MISC_BGMUSIC_UNKNOWN] = "desconocido",
    [MENU_MISC_BGMUSIC_GAMETITLE] = "Reproduciendo: ",
    [MENU_MISC_BGMUSIC_TITLE] = "Título: ",
    [MENU_MISC_BGMUSIC_AUTHOR] = "Autor: ",

    // JUEGO
    [MENU_ICONS_GAME] = "JUEGO",
    [MENU_ICONS_GAME_RESET] = "Reiniciar SNES",
    [MENU_ICONS_GAME_NEW] = "Cargar nuevo juego",
    [MENU_ICONS_GAME_FAVORITES] = "Lista de favoritos",
    [MENU_ICONS_GAME_DEFAULTSETTINGS] = "Hacer Configuración POR DEFECTO",
    [MENU_ICONS_GAME_DEFAULTSETTINGS_HELP] = "Hacer la config. actual la\n"
                                             "predeterminada para todas las\n"
                                             "ROMs si no hay una específica",
    [MENU_ICONS_GAME_EXIT] = "Salir de Snes9xTYL",
    // CARGAR/GUARDAR
    [MENU_ICONS_LOADSAVE] = "CARGAR/GUARDAR",
    [MENU_ICONS_LOADSAVE_LOADSTATE] = "Cargar progreso",
    [MENU_ICONS_LOADSAVE_LOADSTATE_HELP] = "Cargar progreso guardado.\n"
                                           "Es como una foto del\n"
                                           "progreso del SNES.\n"
                                           "Todo se guarda.",
    [MENU_ICONS_LOADSAVE_SAVESTATE] = "Guardar progreso",
    [MENU_ICONS_LOADSAVE_SAVESTATE_HELP] = "Guardar progreso",
    [MENU_ICONS_LOADSAVE_DELETESTATE] = "Eliminar progreso",
    [MENU_ICONS_LOADSAVE_DELETESTATE_HELP] = "Eliminar progreso",
    [MENU_ICONS_LOADSAVE_IMPORTSTATE] = "Importar progreso",
    [MENU_ICONS_LOADSAVE_IMPORTSTATE_HELP] =
        "Importar un progreso de una\nversión anterior o de\nuosnes9x.",

    [MENU_ICONS_LOADSAVE_EXPORTS9XSTATE] = "Exportar progreso SNES9X",
    [MENU_ICONS_LOADSAVE_EXPORTS9XSTATE_HELP] =
        "Exportar un progreso usando el\nformato SNES9X.",

    [MENU_ICONS_LOADSAVE_AUTOSAVETIMER] = "Tiempo autoguardado",
    [MENU_ICONS_LOADSAVE_AUTOSAVETIMER_HELP] =
        "Permite tener un autoguardado\nrealizado periódicamente.",
    [MENU_ICONS_LOADSAVE_AUTOSRAM] = "Autoguardar SRAM actualizada",
    [MENU_ICONS_LOADSAVE_AUTOSRAM_HELP] =
        "Permite guardar la SRAM\ndespués de cada cambio.",
    // CONTROLES
    [MENU_ICONS_CONTROLS] = "CONTROLES",
    [MENU_ICONS_CONTROLS_REDEFINE] = "Redefinir",
    [MENU_ICONS_CONTROLS_REDEFINE_HELP] = "Redefinir la asignación de los\nbotones.",
    [MENU_ICONS_CONTROLS_INPUT] = "Entrada emulada",
    [MENU_ICONS_CONTROLS_INPUT_HELP] =
        "Elegir el mando de SNES\nactivo actualmente.",

    [MENU_CONTROLS_INPUT] = "Joypad #%d",
    [MENU_CONTROLS_INPUT_PRESS] = "Presiona un botón para %s",
    [MENU_CONTROLS_INPUT_NOFORMENU] =
        "¡Ningún botón definido para Acceso al MENÚ!\nPor favor, elige uno",
#ifdef HOME_HOOK
    [MENU_CONTROLS_INPUT_DEFAULT] =
        "Elige un perfil por defecto : \n\n" SJIS_CROSS
        " - Por defecto, botones SNES mapeados en el PSP.\n\n" SJIS_CIRCLE
        " - Por defecto, botones SNES mapeados en el analógico del PSP.\n\n" SJIS_SQUARE
        " - Por defecto, botones SNES mapeados en el PSP y analógico.\n\n" SJIS_TRIANGLE
        " Cancelar\n",
#else
    [MENU_CONTROLS_INPUT_DEFAULT] =
        "Elige un perfil por defecto : \n\n" SJIS_CROSS
        " - Por defecto, botones SNES mapeados en el PSP. GUI en el analógico "
        "izquierdo.\n\n" SJIS_CIRCLE
        " - Por defecto, botones SNES mapeados en el analógico del PSP. GUI en el "
        "direccional izquierdo.\n\n" SJIS_SQUARE
        " - Por defecto, botones SNES mapeados en el PSP y analógico. GUI en "
        "LTrg.+RTrg.\n\n" SJIS_TRIANGLE " Cancelar\n",
#endif

    [MENU_STATUS_CONTROLS_INPUT] = "%s Modo de detección " SJIS_STAR " %s Menú ",
    [MENU_STATUS_CONTROLS_INPUT_0] = SJIS_STAR
    " " SJIS_UP "," SJIS_DOWN " Seleccionar " SJIS_LEFT "," SJIS_RIGHT
    " " SJIS_STAR " SELECT perfiles por defecto",
    [MENU_STATUS_CONTROLS_INPUT_HELP_0] = SJIS_STAR
    " " SJIS_TRIANGLE " Ayuda  " SJIS_STAR "  " SJIS_UP
    "," SJIS_DOWN " Mover " SJIS_LEFT "," SJIS_RIGHT " Ajustar",
    [MENU_STATUS_CONTROLS_INPUT_HELP_1] = SJIS_STAR
    " " SJIS_TRIANGLE " Ayuda  " SJIS_STAR "  " SJIS_UP
    "," SJIS_DOWN " Mover " SJIS_LEFT "," SJIS_RIGHT " Ajustar",
    [MENU_STATUS_CONTROLS_INPUT_HELP_2] = SJIS_STAR
    " " SJIS_TRIANGLE " Ayuda  " SJIS_STAR "  " SJIS_UP
    "," SJIS_DOWN " Mover " SJIS_LEFT "," SJIS_RIGHT " Ajustar",
    [MENU_STATUS_CONTROLS_INPUT_HELP_3] = SJIS_STAR
    " " SJIS_TRIANGLE " Ayuda  " SJIS_STAR "  " SJIS_UP
    "," SJIS_DOWN " Mover " SJIS_LEFT "," SJIS_RIGHT " Ajustar",

    [MENU_TITLE_CONTROLS_INPUT] =
        "[" PROJECT_NAME "] - Configuración de Entradas",

    // OPCIONES DE VÍDEO
    [MENU_ICONS_VIDEO] = "VÍDEO",
    [MENU_ICONS_VIDEO_MODE] = "Modo de vídeo",
    [MENU_ICONS_VIDEO_MODE_HELP] =
        "Cambiar la proporción de la\npantalla.\nSe recomienda 4:3",
    [MENU_ICONS_VIDEO_ENGINE] = "Motor",
    [MENU_ICONS_VIDEO_ENGINE_HELP] =
        "El modo acelerado por hardware\nno siempre es el más rápido",
    [MENU_ICONS_VIDEO_SLIMITONOFF] = "Activar límite de velocidad",
    [MENU_ICONS_VIDEO_SLIMITONOFF_HELP] =
        "Activar para limitar la\nvelocidad del juego.",
    [MENU_ICONS_VIDEO_SLIMITVALUE] = "Límite de velocidad (fps)",
    [MENU_ICONS_VIDEO_SLIMITVALUE_HELP] =
        "Se usa solo si el límite de\nvelocidad está activado.",
    [MENU_ICONS_VIDEO_FSKIP] = "Salto de cuadros",
    [MENU_ICONS_VIDEO_FSKIP_HELP] =
        "Elige un valor fijo si tienes\nsprites que desaparecen.",
    [MENU_ICONS_VIDEO_SMOOTHING] = "Suavizado",
    [MENU_ICONS_VIDEO_SMOOTHING_HELP] =
        "Debería estar activado porque\nno cuesta nada.",
    [MENU_ICONS_VIDEO_VSYNC] = "VSync",
    [MENU_ICONS_VIDEO_VSYNC_HELP] =
        "Esto cuesta muchos fps y\ndebería desactivarse.",
    [MENU_ICONS_VIDEO_PALASNTSC] = "Renderizar PAL como NTSC",
    [MENU_ICONS_VIDEO_PALASNTSC_HELP] =
        "Fuerza a los juegos PAL a\nfuncionar como\nNTSC: 224 líneas en lugar de 240.",
    [MENU_ICONS_VIDEO_GAMMA] = "Corrección gamma",
    [MENU_ICONS_VIDEO_GAMMA_HELP] = "Permite un renderizado más\nbrillante",
    [MENU_ICONS_VIDEO_SCRCALIB] = "Calibración de pantalla",
    [MENU_ICONS_VIDEO_SCRCALIB_HELP] =
        "Ayuda a deshacerse de los\nmolestos bordes negros.",
    [MENU_ICONS_VIDEO_SHOWFPS] = "Mostrar FPS",
    [MENU_ICONS_VIDEO_SHOWFPS_HELP] =
        "Primera línea: cuadros\nSegunda: FPS real.",

    [MENU_VIDEO_MODE_1_1] = "1:1",
    [MENU_VIDEO_MODE_ZOOM_FIT] = "zoom ajustar",
    [MENU_VIDEO_MODE_ZOOM_4_3RD] = "zoom 4/3",
    [MENU_VIDEO_MODE_ZOOM_WIDE] = "zoom ancho",
    [MENU_VIDEO_MODE_FULLSCREEN] = "pantalla completa",
    [MENU_VIDEO_MODE_FULLSCREEN_CLIPPED] = "pantalla completa recortada",
    [MENU_VIDEO_ENGINE_APPROX] = "software aproximado",
    [MENU_VIDEO_ENGINE_ACCUR] = "software preciso",
    [MENU_VIDEO_ENGINE_ACCEL] = "acelerado por PSP",
    [MENU_VIDEO_ENGINE_ACCEL_ACCUR] = "acel. PSP + soft. preciso",
    [MENU_VIDEO_ENGINE_ACCEL_APPROX] = "acel. PSP + soft. aproximado",
    [MENU_VIDEO_SLIMITVALUE_AUTO] = "AUTO (detectar PAL/NTSC)",
    [MENU_VIDEO_FSKIP_MODE_AUTO] = "cambiar auto por debajo de %d",
    [MENU_VIDEO_FSKIP_CHANGEAUTO_AUTO] =
        "   cambiar auto valor definido abajo",
    [MENU_VIDEO_FSKIP_CHANGEAUTO_FIXED] = "   fijo",

    [MENU_STATUS_VIDEO_SCRCALIB] =
        "PAD: POSICIÓN DE LA PANTALLA " SJIS_STAR
        " ANALÓGICO: TAMAÑO DE LA PANTALLA " SJIS_STAR " " SJIS_TRIANGLE
        " por defecto " SJIS_STAR " %s Salir",

    // OPCIONES DE SONIDO
    [MENU_ICONS_SOUND] = "SONIDO",
    [MENU_ICONS_SOUND_MODE] = "Modo de sonido",
    [MENU_ICONS_SOUND_MODE_HELP] =
        "No emulado es más rápido,\npero algunos juegos no funcionan.",
    [MENU_ICONS_SOUND_FREQ] = "Frecuencia de salida",
    [MENU_ICONS_SOUND_FREQ_HELP] =
        "Cuanto más baja, más rápido.\nCuanto más alta, mejor la\ncalidad del sonido.",
    [MENU_ICONS_SOUND_VOLADJUST] = "Nivel de volumen",
    [MENU_ICONS_SOUND_VOLADJUST_HELP] = "Aumentar el nivel de volumen\ndel sonido",
    [MENU_ICONS_SOUND_APURATIO] = "Proporción de ciclos de la APU",
    [MENU_ICONS_SOUND_APURATIO_HELP] =
        "Para usuarios avanzados que\nsaben lo que hacen.",
    // OPCIONES DIVERSAS
    [MENU_ICONS_MISC] = "DIVERSAS",
    [MENU_ICONS_MISC_FILEVIEWER] = "Ver archivo",
    [MENU_ICONS_MISC_FILEVIEWER_HELP] = "Visor de archivo\nminimalista",
    [MENU_ICONS_MISC_PSPCLOCK] = "Velocidad del Clock del PSP",
    [MENU_ICONS_MISC_PSPCLOCK_HELP] =
        "valor>222Mhz NO es overclock.\nEs seguro, pero la batería\ndura menos",
    [MENU_ICONS_MISC_HACKDEBUG] = "Menú Hack/debug",
    [MENU_ICONS_MISC_HACKDEBUG_HELP] =
        "Para usuarios avanzados.\nAyuda a ajustar el renderizado\ny ganar "
        "velocidad.",
    [MENU_ICONS_MISC_SNAPSHOT] = "Captura de pantalla",
    [MENU_ICONS_MISC_SNAPSHOT_HELP] = "Tomar una captura de la\npantalla actual del "
                                      "juego.\nUsado en el navegador de\narchivos.",
    [MENU_ICONS_MISC_SWAPBG] = "Cambiar BG",
    [MENU_ICONS_MISC_SWAPBG_HELP] = "Cambiar BG del archivo:\nDATA/logo.zip.",
    [MENU_ICONS_MISC_BGMUSIC] = "Música de fondo del menú",
    [MENU_ICONS_MISC_BGMUSIC_HELP] = "La música del menú requiere\n"
                                     "PSP a 300 MHz.\n"
                                     "Músicas en DATA/music.zip\n"
                                     "Formato: SPC.",
    [MENU_ICONS_MISC_BGFX] = "Efectos de fondo del menú",
    [MENU_ICONS_MISC_BGFX_HELP] =
        "Efectos geniales del ejemplo\nspline de PS2DEV.",
    [MENU_ICONS_MISC_PADBEEP] = "Pitido del mando",
    [MENU_ICONS_MISC_PADBEEP_HELP] =
        "El pitido suena al navegar por el\nmenú y archivos.",
    [MENU_ICONS_MISC_AUTOSTART] = "Auto última ROM",
    [MENU_ICONS_MISC_AUTOSTART_HELP] = "Si se establece como [sí], la\n"
                                       "última ROM cargada se\n"
                                       "iniciará automáticamente\n"
                                       "al abrir el emulador.",
    [MENU_ICONS_MISC_OSK] = "OSK",
    [MENU_ICONS_MISC_OSK_HELP] =
        "OSK es el Teclado en Pantalla.\nDanzeff es útil para escribir\nalfabeto en el "
        "PSP. El OSK oficial\nde SCE es útil en ePSP.",
    [MENU_ICONS_MISC_LANGUAGE] = "Idioma",
    [MENU_ICONS_MISC_LANGUAGE_HELP] = "Cambia el idioma del emulador",

    [MENU_MUSIC_SWAPBG_NODATA] = "Sin Datos",
    [MENU_MISC_SWAPBG_RAND] = "   Aleatorio",

    [MENU_MISC_OSK_DANZEFF] = "Danzeff",
    [MENU_MISC_OSK_OFFICIAL] = "Oficial",

    [MENU_STATUS_MISC_HACKDEBUG] = "%s Volver ",
    [MENU_STATUS_MISC_HACKDEBUG_FUNC] =
        "%s OK " SJIS_STAR " %s Menú Principal ",
    [MENU_STATUS_MISC_HACKDEBUG_0] =
        SJIS_STAR " " SJIS_UP "," SJIS_DOWN " Mover " SJIS_LEFT
                  "," SJIS_RIGHT " Ajustar",

    [MENU_STATUS_MISC_HACKDEBUG_HELP_0] = SJIS_STAR
    "  " SJIS_TRIANGLE " Ayuda  " SJIS_STAR "  " SJIS_UP
    "," SJIS_DOWN " Mover " SJIS_LEFT "," SJIS_RIGHT " Ajustar",
    [MENU_STATUS_MISC_HACKDEBUG_HELP_1] = SJIS_STAR
    "  " SJIS_TRIANGLE " Ayuda  " SJIS_STAR "  " SJIS_UP
    "," SJIS_DOWN " Mover " SJIS_LEFT "," SJIS_RIGHT " Ajustar",
    [MENU_STATUS_MISC_HACKDEBUG_HELP_2] = SJIS_STAR
    "  " SJIS_TRIANGLE " Ayuda  " SJIS_STAR "  " SJIS_UP
    "," SJIS_DOWN " Mover " SJIS_LEFT "," SJIS_RIGHT " Ajustar",
    [MENU_STATUS_MISC_HACKDEBUG_HELP_3] = SJIS_STAR
    "   " SJIS_TRIANGLE " Ayuda    " SJIS_STAR "  " SJIS_UP
    "," SJIS_DOWN " Mover " SJIS_LEFT "," SJIS_RIGHT " Ajustar",

    [MENU_TITLE_MISC_HACKDEBUG] = "[" PROJECT_NAME "] - Menú",

    // TRUCOS
    [MENU_ICONS_CHEATS] = "TRUCOS",
    [MENU_ICONS_CHEATS_ADDRAW] = "Añadir código RAW",
    [MENU_ICONS_CHEATS_ADDRAW_HELP] = "Añadir un código RAW",
    [MENU_ICONS_CHEATS_ADDGG] = "Añadir código Game Genie",
    [MENU_ICONS_CHEATS_ADDGG_HELP] = "Añadir un código Game Genie",
    [MENU_ICONS_CHEATS_ADDPAR] = "Añadir código Pro Action Replay",
    [MENU_ICONS_CHEATS_ADDPAR_HELP] = "Añadir un código Pro Action\nReplay",
    [MENU_ICONS_CHEATS_ADDGF] = "Añadir código GoldFinger",
    [MENU_ICONS_CHEATS_ADDGF_HELP] = "Añadir un código GoldFinger",
    [MENU_ICONS_CHEATS_DISABLE] = "Desactivar código",
    [MENU_ICONS_CHEATS_DISABLE_HELP] = "Desactivar código",
    [MENU_ICONS_CHEATS_DISABLEALL] = "Desactivar todos los códigos",
    [MENU_ICONS_CHEATS_DISABLEALL_HELP] = "Desactivar todos los códigos",
    [MENU_ICONS_CHEATS_ENABLE] = "Activar código",
    [MENU_ICONS_CHEATS_ENABLE_HELP] = "Activar código",
    [MENU_ICONS_CHEATS_ENABLEALL] = "Activar todos los códigos",
    [MENU_ICONS_CHEATS_ENABLEALL_HELP] = "Activar todos los códigos",
    [MENU_ICONS_CHEATS_REMOVE] = "Eliminar código",
    [MENU_ICONS_CHEATS_REMOVE_HELP] = "Eliminar código",
    [MENU_ICONS_CHEATS_REMOVEALL] = "Eliminar todos los códigos",
    [MENU_ICONS_CHEATS_REMOVEALL_HELP] = "Eliminar todos los códigos",
    // ACERCA DE
    [MENU_ICONS_ABOUT] = "ACERCA DE",
    [MENU_ICONS_ABOUT_CREDITS] = "Créditos",
    [MENU_ICONS_ABOUT_SUPPORT] = "Soporte",
    [MENU_ABOUT_SUPPORT_FOLLOW] = "Sigue el proyecto en:",
    [MENU_ABOUT_SUPPORT_URL] = "github.com/OniMock/snes9xTYL",
    [MENU_ABOUT_SUPPORT_TITLE] = "Soporte & Donaciones:",
    [MENU_ABOUT_SUPPORT_MSG1] = "Si te gusta mi trabajo,",
    [MENU_ABOUT_SUPPORT_MSG2] = "¡considera apoyar el proyecto!",
    [MENU_ABOUT_SUPPORT_QR_COFFEE] = "Invítame un Café",
    [MENU_ABOUT_SUPPORT_QR_WALLET] = "Monedero EVM",
    [MENU_ICONS_ABOUT_VERSION] = "Información de la versión",

    [MENU_ABOUT_VERSION_TIMESTAMP] = "Compilado el %s",
    [MENU_ABOUT_VERSION_GCCVER] = "Con GCC %s",

    // Otros
    //  Adhoc
    [ADHOC_CONNECTING] = "Conectando...\n",
    [ADHOC_SELECTORRETURN] =
        "Selecciona un servidor para conectar, o triángulo para volver",
    [ADHOC_WAITING] =
        "Esperando que %s acepte la conexión\nPara cancelar presiona O\n",
    [ADHOC_REQUESTED] = "%s solicitó una conexión\nPara aceptar la conexión "
                        "presiona X, para cancelar presiona O\n",
    [ADHOC_CONNECTED] = "Conectado",
    [ADHOC_STATE] = "  progreso de la conexión %d de 1\n",
    [ADHOC_UNKNOWNCOMMAND] = "¡Comando desconocido %02X!",
    [ADHOC_SYNCLOST_SERVER] = "SERVIDOR Perdió sincronía: ¡¡¡resincronizar!!!",
    [ADHOC_SYNCLOST_CLIENT] = "CLIENTE Perdió sincronía: ¡¡¡resincronizar!!!",
    [ADHOC_CLOSING] = "cerrando conexión",
    [ADHOC_DRIVERLOAD_ERR] = "Error al cargar el driver de red",
    [ADHOC_INIT_ERR] = "Problema al iniciar juego adhoc\n",
    [ADHOC_LOST_CONNECTION] = "¡Conexión perdida!",
    [ADHOC_CORRUPTED_PKT] = "paquete corrupto",
    [ADHOC_STATE_SIZE] = "tamaño del progreso: %d",
    [ADHOC_FILE_ERR_RECEIVING] = "¡error de archivo al recibir progreso!",
    [ADHOC_FILE_ERR_SENDING] = "¡error de archivo al enviar progreso!",
    [ADHOC_STILL] = "aún: %d",
    [ADHOC_WAITING_OTHER] =
        "Esperando a otro jugador\n\nPresiona " SJIS_TRIANGLE
        " para cerrar conexión y salir del netplay\n",
    [ADHOC_NETWORKERR_1] = "error de red 1",
    [ADHOC_CANNOTFIND] = "¡no se pudo encontrar el progreso guardado!",
    [ADHOC_FLUSHING] = "limpiando red, espera unos segundos",
    // CARGAR/GUARDAR
    [LOADSAVE_AUTOSAVETIMER] = "Autoguardando...",
    [LOADSAVE_EXPORTS9XSTATE] = "Archivo snes9xTYL encontrado",
    // VÍDEO
    [VIDEO_ENGINE_APPROX] = "Modo simple: software preciso",
    [VIDEO_ENGINE_ACCUR] = "Modo simple: software aproximado",
    [VIDEO_ENGINE_ACCEL] = "Modo simple: acelerado por PSP",
    [VIDEO_ENGINE_ACCEL_ACCUR] =
        "Modos mixtos: acelerado PSP + software preciso",
    [VIDEO_ENGINE_ACCEL_APPROX] =
        "Modos mixtos: acelerado PSP + software aproximado",
    [VIDEO_FSKIP_AUTO] = "Salto de cuadros: AUTO",
    [VIDEO_FSKIP_MANUAL] = "Salto de cuadros: %d",
    // Mensaje de Desplazamiento
    [SCROLL_HELP_MOVE] = "mover",
    [SCROLL_HELP_FAST] = "rápido",
    [SCROLL_STATUS_0] = "Línea %d/%d  -  Página %d/%d",
    [SCROLL_STATUS_1] = "   salir,        ayuda  ",
    [SCROLL_HELP] =
        "Snes9xTYL - visor de archivos\n\n" SJIS_TRIANGLE
        " Buscar, luego %s Siguiente búsqueda, " SJIS_SQUARE
        " Búsqueda anterior\n" SJIS_UP "," SJIS_DOWN
        " desplazar texto, L,R desplazar más rápido\n%s salir\n\n"
        "La última posición se mantiene si se reabre el mismo archivo.\nSin "
        "embargo, se reiniciará si se abre otro archivo.\n\n"
        "Presiona %s",
    [SCROLL_SEARCHING] = "Buscando...",
    [SCROLL_STRNOTFOUND] = "¡Cadena no encontrada!",
    [SCROLL_DISCLAIMER] = "Aviso Legal",
    [SCROLL_OSK_DESC] = "Introduce la cadena a buscar",
    // Configuraciones
    [SETTINGS_NOTCOMPLETE] =
        "¡¡Archivo de configuración incompleto!!\n\nProbablemente proviene de una "
        "versión anterior.\n\nLas nuevas configuraciones se establecerán con valores "
        "por defecto",
    [SETTINGS_NOTFOUND] = "No se encontró configuración, usando por defecto",
    [SETTINGS_FORCING_DEFAULT] = "Forzando configuración por defecto",
    [SETTINGS_IGNORED] =
        "¡archivo ini de una versión anterior incompatible, ignorado!",
    [SETTINGS_FOUND] = "¡Configuración encontrada!\n\n"
                       "%s"
                       "",
    [SETTINGS_DIFF] = "archivo ini de una versión diferente.",
    // Otros
    [APU_DEBUGGING] = "DEPURACIÓN DE LA APU",
    [BGMUSIC_PLAYING] = "Reproduciendo archivo spc...",
    [FOUND_SRAM] = "Archivo SRAM encontrado",
    [CANCEL] = "CANCELAR",
    [INPUTBOX_OK] = "\n\n      Cerrar",
#ifdef ME_SOUND
    [BAT_ISLOW] = "Batería baja, guardado ahora deshabilitado (SRAM, estados "
                  "y configuraciones).\n\nEsta ventana se cerrará en 3 segundos.",
#else
    [BAT_ISLOW] =
        "Batería baja, guardado ahora deshabilitado (SRAM, estados y "
        "configuraciones).\n\nAún puedes poner tu PSP en modo de espera "
        "y cargar la batería después.\n\nEsta ventana se cerrará en 3 segundos.",
#endif
    [CONV_DONE] = "conversión completada",
    [ROM_LIED] = "¡La ROM mintió sobre su tipo! Intentando de nuevo.",
    [LOADING_ROM] = "Cargando %dKB...",
    [TYPE] = "Tipo",
    [MODE] = "Modo",
    [COMPANY] = "Compañía",
#ifdef _BSX_151_
    [SRAM_NOTFOUND] =
        "No se encontró el archivo SRAM: se leyó BS-X.srm en su lugar.",
    [SRAM_BSX_NOTFOUND] = "No se encontró el archivo SRAM, tampoco se encontró BS-X.srm.",
#endif
    [CORRUPT] = "Corrupto",
    [ROM_ONLY] = "Solo ROM",
    [EXTENDING] = "Expandiendo",
    [EXTENDING_TARGET] = "Expandiendo objetivo de %d a %d\n",
    [INIT_OSK] = "Inicializando OSK...",

    // Datos de ayuda
    [HELP_SHOWPASS] = "Muestra cuántas llamadas de renderizado fueron necesarias\npara dibujar la pantalla. Cuanto más bajo, más rápido.\nÚtil para evaluar el impacto de los hacks (abajo).",
    [HELP_APPLYHACKS] = "Aplica speed hacks de SNESAdvance si están en base de datos.\nSe usa solo durante la carga de la ROM.",
    [HELP_IGNORE_FIXCOL] = "Ignora cambios de color fijo.\nEstos cambios no activarán la actualización de la pantalla.\nLos gráficos pueden verse afectados (gradientes, etc).",
    [HELP_IGNORE_WINCLIP] = "Ignora cambios de recorte de ventana.\nEstos cambios no activarán la actualización de la pantalla.\nLos gráficos pueden verse afectados (las áreas pueden desaparecer, etc).",
    [HELP_IGNORE_ADDSUB] = "Ignora cambios en los modos de adición/sustracción (transparencia).\nEstos cambios no activarán la actualización de la pantalla.\nPosible impacto gráfico (píxeles opacos).",
    [HELP_IGNORE_PALWRITE] = "Ignora cambios en la paleta de colores durante el frame.\nEstos cambios no activarán la actualización de la pantalla.\nLos gráficos pueden verse afectados (colores incorrectos, etc).",
    [HELP_OBJ] = "OBJ (sprites) Activado/Desactivado.\nÚsalo para desactivar el renderizado de sprites.",
    [HELP_BG0] = "BG0 Activado/Desactivado.\nÚsalo para desactivar el renderizado del fondo 0.",
    [HELP_BG1] = "BG1 Activado/Desactivado.\nÚsalo para desactivar el renderizado del fondo 1.",
    [HELP_BG2] = "BG2 Activado/Desactivado.\nÚsalo para desactivar el renderizado del fondo 2.",
    [HELP_BG3] = "BG3 Activado/Desactivado.\nÚsalo para desactivar el renderizado del fondo 3.",
    [HELP_EASY] = "Sin transparencia.\nFuerza el renderizado sin efectos de transparencia.\nPosible impacto gráfico (píxeles opacos).",
    [HELP_FASTSPRITE] = "Sprites rápidos.\nDesactiva el tratamiento de prioridad entre sprites.\nLos gráficos pueden verse afectados.",

    // Etiquetas del Menú Hack/Debug
    [DEBUG_MENU_SHOW_PASS] = "Mostrar pases de render.: ",
    [DEBUG_MENU_SPEED_HACKS] = "Speed hacks : ",
    [DEBUG_MENU_IGNORE_FIXED_COL] = "Ignorar Color Fijo : ",
    [DEBUG_MENU_IGNORE_WINDOW] = "Ignorar Recorte Ventana : ",
    [DEBUG_MENU_IGNORE_ADDSUB] = "Ignorar Modos Add/Sub : ",
    [DEBUG_MENU_IGNORE_PALETTE] = "Ignorar Escritura Paleta : ",
    [DEBUG_MENU_SIMPLE_PALETTE] = "Escritura Paleta Simple : ",
    [DEBUG_MENU_OLD_ACCEL] = "Acel. PSP Antigua : ",
    [DEBUG_MENU_NO_TRANSPARENCY] = "Sin Transparencia : ",
    [DEBUG_MENU_FAST_SPRITES] = "Sprites Rápidos : ",
    [DEBUG_MENU_OBJ] = "OBJ : ",
    [DEBUG_MENU_BG0] = "BG0 : ",
    [DEBUG_MENU_BG1] = "BG1 : ",
    [DEBUG_MENU_BG2] = "BG2 : ",
    [DEBUG_MENU_BG3] = "BG3 : ",
    [DEBUG_MENU_SFX_OVERCLOCK] = "Overclock SFX : ",
    [MENU_ON] = "Activado",
    [MENU_OFF] = "Desactivado",

    // Etiquetas del Menú de Entrada
    [INPUT_MENU_ANALOG_MAPPED] = "Analógico mapeado a direccional : ",
    [INPUT_MENU_UP] = "ARRIBA : ",
    [INPUT_MENU_DOWN] = "ABAJO : ",
    [INPUT_MENU_LEFT] = "IZQUIERDA : ",
    [INPUT_MENU_RIGHT] = "DERECHA : ",
    [INPUT_MENU_A] = "A : ",
    [INPUT_MENU_B] = "B : ",
    [INPUT_MENU_X] = "X : ",
    [INPUT_MENU_Y] = "Y : ",
    [INPUT_MENU_L] = "L : ",
    [INPUT_MENU_R] = "R : ",
    [INPUT_MENU_START] = "START : ",
    [INPUT_MENU_SELECT] = "SELECT : ",
    [INPUT_MENU_MENU] = "MENÚ : ",
    [INPUT_MENU_TURBO] = "TURBO : ",
    [INPUT_MENU_FSKIPINC] = "SALTAR CUADROS + : ",
    [INPUT_MENU_FSKIPDEC] = "SALTAR CUADROS - : ",
    [INPUT_MENU_GFXENGINE] = "CAMBIAR MOTOR GRÁFICO : ",
    [INPUT_MENU_SAVE_STATE] = "GUARDAR ESTADO : ",
    [INPUT_MENU_LOAD_STATE] = "CARGAR ESTADO : ",
},
