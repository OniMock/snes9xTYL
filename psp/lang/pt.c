[MSG_PT] = {
    // português
    // erro
    [ERR_OUT_OF_MEM] = "Memória insuficiente",
    [ERR_READ_MEMSTICK] = "Erro ao ler Memory Stick.\n"
                          "Verifique no PC, pode estar corrompido.",

    [ERR_INIT_SNES] = "Não foi possível iniciar o SNES, problema de memória",
    [ERR_LOADING_ROM] = "Erro ao carregar a ROM",
    [ERR_INIT_GFX] = "Não foi possível inicializar os gráficos",

    [ERR_CANNOT_ALLOC_MEM] = "Não foi possível alocar memória",

    [ERR_USB_STARTING_USBBUS] = "Erro ao iniciar o driver USB Bus (0x%08X)\n",
    [ERR_USB_STARTING_USBMASS] =
        "Erro ao iniciar o driver USB Mass Storage (0x%08X)\n",
    [ERR_USB_SETTING_CAPACITY] =
        "Erro ao definir capacidade com o driver USB Mass Storage (0x%08X)\n",
    // confirmar
    [ASK_EXIT] = "Sair do Snes9XTYL?",
    [ASK_DELETE] = "Excluir arquivo?",
    [ASK_SAVEDIR] =
        "O diretório de save não foi encontrado.\n"
        "Para criar o diretório na pasta onde este emulador está, "
        "Pressione " SJIS_CIRCLE "\n"
        "Para criar o diretório na pasta SAVEDATA, Pressione " SJIS_CROSS "\n",
    // info
    [INFO_USB_ON] = "USB ativado",
    [INFO_USB_OFF] = "USB desativado",
    [INFO_DELETING] = "Excluindo...",
    [INFO_EXITING] = "Saindo, aguarde...",
    [INFO_LOADING_FILES] = "Carregando arquivos: %d...",
    // filer
    [FILER_STATUS_CANEXIT1] =
        "%s Iniciar " SJIS_SQUARE " Usar config. padrão " SJIS_STAR
        " %s Retomar jogo " SJIS_STAR " " SJIS_TRIANGLE " %s " SJIS_STAR
        " PAD NAVEGAR",
    [FILER_STATUS_NOEXIT1] =
        "%s Iniciar " SJIS_SQUARE " Usar config. padrão  " SJIS_STAR
        "  " SJIS_TRIANGLE " %s  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT
        "," SJIS_RIGHT ", Mover",
    [FILER_STATUS_CANEXIT2] =
        "%s Iniciar %s Retomar jogo " SJIS_TRIANGLE " %s  " SJIS_UP
        "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", Mover",
    [FILER_STATUS_NOEXIT2] =
        "%s Iniciar " SJIS_TRIANGLE " %s                  " SJIS_UP
        "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", Mover",

    [FILER_STATUS_PARDIR] = "Pasta pai",

    [FILER_TITLE] = "[" EMUNAME_VERSION "] - Escolha um arquivo",

    [FILER_HELP_WINDOW1] = "Pressione:",
    [FILER_HELP_WINDOW2] = "START: Normal/Netplay",
#ifdef FW3X
    [FILER_HELP_WINDOW3] = " ",
#ifdef HOME_HOOK
    [FILER_HELP_WINDOW4] = "HOME: sair",
#else
    [FILER_HELP_WINDOW4] = "L+R: sair",
#endif
#else
#ifdef HOME_HOOK
    [FILER_HELP_WINDOW3] = "HOME: sair",
#else
    [FILER_HELP_WINDOW3] = "L+R: sair",
#endif
    [FILER_HELP_WINDOW4] = "R: USB on/off",
#endif
    [FILER_HELP_WINDOW5] = "SELECT: excluir arquivo",

    [FILE_IPS_APPLYING] =
        "Patch IPS encontrado: %s\nTamanho: %dKB\nAplicando...",
    [FILE_IPS_PATCHSUCCESS] = "Patch IPS aplicado com sucesso",

    [MENU_STATUS_GENERIC_MSG1] = "Pressione %s para voltar",
    [MENU_STATUS_GENERIC_NEEDRELOAD] =
        "Alterações podem exigir RECARREGAR para ter efeito",
    [MENU_STATUS_GENERIC_NEEDRESET] =
        "Alterações podem exigir RESET para ter efeito",
    [MENU_STATUS_GENERIC_CHANGEMUSIC] = "SELECT para trocar música",

    [MENU_TITLE_GENERIC_BAT] = "Bat.",
    [MENU_TITLE_GENERIC_BAT_TIME] = "(%02dh%02dm)",
    [MENU_TITLE_GENERIC_BAT_TEMP] = " Temp.%d℃",
    [MENU_TITLE_GENERIC_BAT_PLG] = "Con.",
    [MENU_TITLE_GENERIC_BAT_CHRG] = "Carreg.",
    [MENU_TITLE_GENERIC_BAT_LOW] = "Baixa!",

    [MENU_CHANGE_VALUE] = "  ,   alterar valor",
    [MENU_CHANGE_VALUE_WITH_FAST] = "  ,   alterar valor -  ,  rápido",
    [MENU_CANCEL_VALIDATE] = "  ,   cancelar   -      validar",
    [MENU_DEFAULT_VALUE] = "   valor padrão",
    [MENU_YES] = "sim",
    [MENU_NO] = "não",
    [MENU_NOT_IMPLEMENTED] = "Ainda não implementado.\n\n",

    [MENU_SOUND_MODE_NOTEMUL] = "não emulado",
    [MENU_SOUND_MODE_EMULOFF] = "emulado, sem saída",
    [MENU_SOUND_MODE_EMULON] = "emulado, com saída",

    [MENU_STATE_CHOOSEDEL] = "Escolha um slot para EXCLUIR",
    [MENU_STATE_CHOOSELOAD] = "Escolha um slot para CARREGAR",
    [MENU_STATE_CHOOSESAVE] = "Escolha um slot para SALVAR",
    [MENU_STATE_FREESLOT] = "LIVRE",
    [MENU_STATE_SCANNING] = "Verificando slots usados...",

    [ERR_INIT_OSK] = "não foi possível iniciar o OSK",
    [ERR_ADD_CODE] =
        "Não foi possível adicionar código de trapaça, muitos já inseridos!",

    [MENU_CHEATS_ENTERGF] = "Digite um código GoldFinger",
    [MENU_CHEATS_ENTERPAR] = "Digite um código Pro Action Replay",
    [MENU_CHEATS_ENTERGG] = "Digite um código Game Genie",
    [MENU_CHEATS_ENTERRAW] =
        "Digite um código RAW\nFormato é ENDEREÇO - NOVO VALOR",
    [MENU_CHEATS_CONFIRMREMALL] = "Remover todos os códigos?",
    [MENU_CHEATS_ENTERNAME] = "Digite o Nome",
    [MENU_CHEATS_PREVPAGE] = "L - Pág. Anterior",
    [MENU_CHEATS_NEXTPAGE] = "R - Próx. Página",

    [MENU_STATE_CONFIRMLOAD] =
        "O progresso atual do jogo será perdido.\nContinuar?",
    [MENU_STATE_CONFIRMDELETE] = "Excluir progresso atual?",
    [MENU_STATE_CONFIRMSAVE] = "Sobrescrever progresso salvo atual?",
    [MENU_STATE_ISLOADING] = "Carregando progresso...",
    [MENU_STATE_ISSAVING] = "Salvando progresso...",
    [MENU_STATE_ISDELETING] = "Excluindo...",
    [MENU_STATE_ISIMPORTING] = "Importando progresso...",
    [MENU_STATE_ISEXPORTINGS9X] = "Exportando progresso SNES9X...",
    [MENU_STATE_NOSTATE] = "Nenhum progresso disponível...",
    [MENU_STATE_AUTOSAVETIMER] = "a cada %dmin.",
    [MENU_STATE_AUTOSAVETIMER_OFF] = "desligado",
    [MENU_STATE_WARNING_LOWBAT] =
        "Bateria fraca.\nSe o PSP desligar durante o salvamento, o Memory "
        "Stick pode ser danificado.\nContinuar?",
    [MENU_GAME_SAVINGDEFAULTSETTINGS] =
        "Salvando configurações atuais como perfil padrão",
    [MENU_GAME_CONFIRMRESET] = "Resetar o SNES?",
    [MENU_MISC_SAVINGJPEG] = "Salvando captura JPEG...",

    [MENU_MISC_BGMUSIC_RAND] = "Reproduzir aleatório",
    [MENU_MISC_BGMUSIC_ORDER] = "Reproduzir em ordem",

    [MENU_MISC_BGMUSIC_UNKNOWN] = "desconhecido",
    [MENU_MISC_BGMUSIC_GAMETITLE] = "Reproduzindo: ",
    [MENU_MISC_BGMUSIC_TITLE] = "Título: ",
    [MENU_MISC_BGMUSIC_AUTHOR] = "Autor: ",

    // JOGO
    [MENU_ICONS_GAME] = "JOGO",
    [MENU_ICONS_GAME_RESET] = "Reiniciar SNES",
    [MENU_ICONS_GAME_NEW] = "Carregar novo jogo",
    [MENU_ICONS_GAME_DEFAULTSETTINGS] = "Tornar Configurações PADRÃO",
    [MENU_ICONS_GAME_DEFAULTSETTINGS_HELP] = "Tornar config atual o padrão\n"
                                             "para todas as ROMs se não\n"
                                             "houver específica",
    [MENU_ICONS_GAME_EXIT] = "Sair do Snes9xTYL",
    // CARREGAR/SALVAR
    [MENU_ICONS_LOADSAVE] = "CARREGAR/SALVAR",
    [MENU_ICONS_LOADSAVE_LOADSTATE] = "Carregar progresso",
    [MENU_ICONS_LOADSAVE_LOADSTATE_HELP] = "Carregar progresso salvo.\n"
                                           "É como uma foto do\n"
                                           "progresso do SNES.\n"
                                           "Tudo é salvo.",
    [MENU_ICONS_LOADSAVE_SAVESTATE] = "Salvar progresso",
    [MENU_ICONS_LOADSAVE_SAVESTATE_HELP] = "Salvar progresso",
    [MENU_ICONS_LOADSAVE_DELETESTATE] = "Excluir progresso",
    [MENU_ICONS_LOADSAVE_DELETESTATE_HELP] = "Excluir progresso",
    [MENU_ICONS_LOADSAVE_IMPORTSTATE] = "Importar progresso",
    [MENU_ICONS_LOADSAVE_IMPORTSTATE_HELP] =
        "Importar um progresso de uma\nversão anterior ou do\nuosnes9x.",

    [MENU_ICONS_LOADSAVE_EXPORTS9XSTATE] = "Exportar progresso SNES9X",
    [MENU_ICONS_LOADSAVE_EXPORTS9XSTATE_HELP] =
        "Exportar um progresso usando o\nformato SNES9X.",

    [MENU_ICONS_LOADSAVE_AUTOSAVETIMER] = "Tempo auto-save",
    [MENU_ICONS_LOADSAVE_AUTOSAVETIMER_HELP] =
        "Permite ter um auto-salvamento\nrealizado periodicamente.",
    [MENU_ICONS_LOADSAVE_AUTOSRAM] = "Auto-salvar SRAM atualizada",
    [MENU_ICONS_LOADSAVE_AUTOSRAM_HELP] =
        "Permite ter a SRAM salva\napós cada alteração.",
    // CONTROLES
    [MENU_ICONS_CONTROLS] = "CONTROLES",
    [MENU_ICONS_CONTROLS_REDEFINE] = "Redefinir",
    [MENU_ICONS_CONTROLS_REDEFINE_HELP] = "Redefinir o mapeamento dos\nbotões.",
    [MENU_ICONS_CONTROLS_INPUT] = "Entrada emulada",
    [MENU_ICONS_CONTROLS_INPUT_HELP] =
        "Escolher o controle de SNES\nativo atualmente.",

    [MENU_CONTROLS_INPUT] = "Joypad #%d",
    [MENU_CONTROLS_INPUT_PRESS] = "Pressione um botão para %s",
    [MENU_CONTROLS_INPUT_NOFORMENU] =
        "Nenhum botão definido para Acesso ao MENU!\nPor favor, escolha um",
#ifdef HOME_HOOK
    [MENU_CONTROLS_INPUT_DEFAULT] =
        "Escolha um perfil padrão : \n\n" SJIS_CROSS
        " - Padrão, botões SNES mapeados no PSP.\n\n" SJIS_CIRCLE
        " - Padrão, botões SNES mapeados no analógico do PSP.\n\n" SJIS_SQUARE
        " - Padrão, botões SNES mapeados no PSP e analógico.\n\n" SJIS_TRIANGLE
        " Cancelar\n",
#else
    [MENU_CONTROLS_INPUT_DEFAULT] =
        "Escolha um perfil padrão : \n\n" SJIS_CROSS
        " - Padrão, botões SNES mapeados no PSP. GUI no analógico "
        "esquerdo.\n\n" SJIS_CIRCLE
        " - Padrão, botões SNES mapeados no analógico do PSP. GUI no "
        "direcional esquerdo.\n\n" SJIS_SQUARE
        " - Padrão, botões SNES mapeados no PSP e analógico. GUI em "
        "LTrg.+RTrg.\n\n" SJIS_TRIANGLE " Cancelar\n",
#endif

    [MENU_STATUS_CONTROLS_INPUT] = "%s Modo de detecção " SJIS_STAR " %s Menu ",
    [MENU_STATUS_CONTROLS_INPUT_0] = SJIS_STAR
    " " SJIS_UP "," SJIS_DOWN " Selecionar " SJIS_LEFT "," SJIS_RIGHT
    " Alterar valor " SJIS_STAR " SELECT perfis padrão",
    [MENU_STATUS_CONTROLS_INPUT_HELP_0] = SJIS_STAR
    "      " SJIS_TRIANGLE " Ajuda       " SJIS_STAR "      " SJIS_UP
    "," SJIS_DOWN " Selecionar " SJIS_LEFT "," SJIS_RIGHT " Alterar valor",
    [MENU_STATUS_CONTROLS_INPUT_HELP_1] = SJIS_STAR
    "     " SJIS_TRIANGLE "   Ajuda      " SJIS_STAR "      " SJIS_UP
    "," SJIS_DOWN " Selecionar " SJIS_LEFT "," SJIS_RIGHT " Alterar valor",
    [MENU_STATUS_CONTROLS_INPUT_HELP_2] = SJIS_STAR
    "    " SJIS_TRIANGLE "     Ajuda     " SJIS_STAR "      " SJIS_UP
    "," SJIS_DOWN " Selecionar " SJIS_LEFT "," SJIS_RIGHT " Alterar valor",
    [MENU_STATUS_CONTROLS_INPUT_HELP_3] = SJIS_STAR
    "   " SJIS_TRIANGLE "       Ajuda    " SJIS_STAR "      " SJIS_UP
    "," SJIS_DOWN " Selecionar " SJIS_LEFT "," SJIS_RIGHT " Alterar valor",

    [MENU_TITLE_CONTROLS_INPUT] =
        "[" EMUNAME_VERSION "] - Configuração de Entradas",

    // OPÇÕES DE VÍDEO
    [MENU_ICONS_VIDEO] = "VÍDEO",
    [MENU_ICONS_VIDEO_MODE] = "Modo de vídeo",
    [MENU_ICONS_VIDEO_MODE_HELP] =
        "Alterar a proporção da tela.\n4:3 é recomendado",
    [MENU_ICONS_VIDEO_ENGINE] = "Mecanismo",
    [MENU_ICONS_VIDEO_ENGINE_HELP] =
        "Modo acelerado por hardware\nnem sempre é o mais rápido",
    [MENU_ICONS_VIDEO_SLIMITONOFF] = "Ativar limite de velocidade",
    [MENU_ICONS_VIDEO_SLIMITONOFF_HELP] =
        "Ative para limitar a velocidade\ndo jogo.",
    [MENU_ICONS_VIDEO_SLIMITVALUE] = "Limite de velocidade (fps)",
    [MENU_ICONS_VIDEO_SLIMITVALUE_HELP] =
        "Usado apenas se o limite de\nvelocidade estiver ativado.",
    [MENU_ICONS_VIDEO_FSKIP] = "Pulo de quadros",
    [MENU_ICONS_VIDEO_FSKIP_HELP] =
        "Escolha um valor fixo se você\ntiver sprites sumindo.",
    [MENU_ICONS_VIDEO_SMOOTHING] = "Suavização",
    [MENU_ICONS_VIDEO_SMOOTHING_HELP] =
        "Deve ficar ligado pois não\ncusta nada.",
    [MENU_ICONS_VIDEO_VSYNC] = "VSync",
    [MENU_ICONS_VIDEO_VSYNC_HELP] =
        "Isso custa muitos fps e deve\nser desligado.",
    [MENU_ICONS_VIDEO_PALASNTSC] = "Renderizar PAL como NTSC",
    [MENU_ICONS_VIDEO_PALASNTSC_HELP] =
        "Força jogos PAL a rodar\ncomo NTSC: 224 linhas\nem vez de 240.",
    [MENU_ICONS_VIDEO_GAMMA] = "Correção gama",
    [MENU_ICONS_VIDEO_GAMMA_HELP] = "Permite renderização mais\nbrilhante",
    [MENU_ICONS_VIDEO_SCRCALIB] = "Calibração da tela",
    [MENU_ICONS_VIDEO_SCRCALIB_HELP] =
        "Ajuda a se livrar das chatas\nbordas pretas.",
    [MENU_ICONS_VIDEO_SHOWFPS] = "Mostrar FPS",
    [MENU_ICONS_VIDEO_SHOWFPS_HELP] =
        "Primeira linha: quadros\nSegunda: FPS real.",

    [MENU_VIDEO_MODE_1_1] = "1:1",
    [MENU_VIDEO_MODE_ZOOM_FIT] = "zoom ajustar",
    [MENU_VIDEO_MODE_ZOOM_4_3RD] = "zoom 4/3",
    [MENU_VIDEO_MODE_ZOOM_WIDE] = "zoom largo",
    [MENU_VIDEO_MODE_FULLSCREEN] = "tela cheia",
    [MENU_VIDEO_MODE_FULLSCREEN_CLIPPED] = "tela cheia cortada",
    [MENU_VIDEO_ENGINE_APPROX] = "software aproximado",
    [MENU_VIDEO_ENGINE_ACCUR] = "software preciso",
    [MENU_VIDEO_ENGINE_ACCEL] = "acelerado por PSP",
    [MENU_VIDEO_ENGINE_ACCEL_ACCUR] = "acel. PSP + soft. preciso",
    [MENU_VIDEO_ENGINE_ACCEL_APPROX] = "acel. PSP + soft. aproximado",
    [MENU_VIDEO_SLIMITVALUE_AUTO] = "AUTO (detectar PAL/NTSC)",
    [MENU_VIDEO_FSKIP_MODE_AUTO] = "auto alterar abaixo de %d",
    [MENU_VIDEO_FSKIP_CHANGEAUTO_AUTO] =
        "   auto alterar valor definido abaixo",
    [MENU_VIDEO_FSKIP_CHANGEAUTO_FIXED] = "   fixo",

    [MENU_STATUS_VIDEO_SCRCALIB] =
        "PAD: POSIÇÃO DA TELA " SJIS_STAR
        " ANALÓGICO: TAMANHO DA TELA " SJIS_STAR " " SJIS_TRIANGLE
        " padrão " SJIS_STAR " %s Sair",

    // OPÇÕES DE SOM
    [MENU_ICONS_SOUND] = "SOM",
    [MENU_ICONS_SOUND_MODE] = "Modo de som",
    [MENU_ICONS_SOUND_MODE_HELP] =
        "Não emulado é mais rápido,\nmas alguns jogos não rodam.",
    [MENU_ICONS_SOUND_FREQ] = "Frequência de saída",
    [MENU_ICONS_SOUND_FREQ_HELP] =
        "Quanto menor, mais rápido.\nQuanto maior, melhor a\nqualidade do som.",
    [MENU_ICONS_SOUND_VOLADJUST] = "Nível de volume",
    [MENU_ICONS_SOUND_VOLADJUST_HELP] = "Aumentar o nível do volume do\nsom",
    [MENU_ICONS_SOUND_APURATIO] = "Proporção de ciclos da APU",
    [MENU_ICONS_SOUND_APURATIO_HELP] =
        "Para usuários avançados que\nsabem o que estão fazendo.",
    // OPÇÕES DIVERSAS
    [MENU_ICONS_MISC] = "DIVERSOS",
    [MENU_ICONS_MISC_FILEVIEWER] = "Ver arquivo",
    [MENU_ICONS_MISC_FILEVIEWER_HELP] = "Visualizador de arquivo\nminimalista",
    [MENU_ICONS_MISC_PSPCLOCK] = "Velocidade do Clock do PSP",
    [MENU_ICONS_MISC_PSPCLOCK_HELP] =
        "valor>222Mhz NÃO é overclock.\nÉ seguro, mas a bateria\nacaba mais "
        "rápido",
    [MENU_ICONS_MISC_HACKDEBUG] = "Menu Hack/debug",
    [MENU_ICONS_MISC_HACKDEBUG_HELP] =
        "Para usuários avançados.\nAjuda a ajustar a renderização\ne ganhar "
        "velocidade.",
    [MENU_ICONS_MISC_SNAPSHOT] = "Captura de tela",
    [MENU_ICONS_MISC_SNAPSHOT_HELP] = "Tirar uma captura da tela\natual do "
                                      "jogo.\nUsado no navegador de arquivos.",
    [MENU_ICONS_MISC_SWAPBG] = "Trocar BG",
    [MENU_ICONS_MISC_SWAPBG_HELP] = "Trocar BG do arquivo:\nDATA/logo.zip.",
    [MENU_ICONS_MISC_BGMUSIC] = "Música de fundo do menu",
    [MENU_ICONS_MISC_BGMUSIC_HELP] = "Música do menu requer\n"
                                     "PSP a 300 MHz.\n"
                                     "Músicas em DATA/music.zip\n"
                                     "Formato: SPC.",
    [MENU_ICONS_MISC_BGFX] = "Efeitos de fundo do menu",
    [MENU_ICONS_MISC_BGFX_HELP] =
        "Efeitos legais do exemplo\nspline do PS2DEV.",
    [MENU_ICONS_MISC_PADBEEP] = "Bipe do controle",
    [MENU_ICONS_MISC_PADBEEP_HELP] =
        "O bipe soa ao navegar pelo\nmenu e arquivos.",
    [MENU_ICONS_MISC_AUTOSTART] = "Auto última ROM",
    [MENU_ICONS_MISC_AUTOSTART_HELP] = "Se definir como [sim], a\n"
                                       "última ROM carregada será\n"
                                       "iniciada automaticamente\n"
                                       "ao abrir o emulador.",
    [MENU_ICONS_MISC_OSK] = "OSK",
    [MENU_ICONS_MISC_OSK_HELP] =
        "OSK é o Teclado na Tela.\nDanzeff é útil para digitar\nalfabeto no "
        "PSP. O OSK oficial\nda SCE é útil no ePSP.",
    [MENU_ICONS_MISC_LANGUAGE] = "Language",
    [MENU_ICONS_MISC_LANGUAGE_HELP] = "Troca o idioma do emulador",

    [MENU_MUSIC_SWAPBG_NODATA] = "Sem Dados",
    [MENU_MISC_SWAPBG_RAND] = "   Aleatório",

    [MENU_MISC_OSK_DANZEFF] = "Danzeff",
    [MENU_MISC_OSK_OFFICIAL] = "Oficial",

    [MENU_STATUS_MISC_HACKDEBUG] = "%s Menu Principal   ",
    [MENU_STATUS_MISC_HACKDEBUG_FUNC] =
        "%s OK     " SJIS_STAR "    %s Menu Principal   ",
    [MENU_STATUS_MISC_HACKDEBUG_0] =
        SJIS_STAR "    " SJIS_UP "," SJIS_DOWN " Selecionar " SJIS_LEFT
                  "," SJIS_RIGHT " Alterar valor",

    [MENU_STATUS_MISC_HACKDEBUG_HELP_0] = SJIS_STAR
    "      " SJIS_TRIANGLE " Ajuda       " SJIS_STAR "      " SJIS_UP
    "," SJIS_DOWN " Selecionar " SJIS_LEFT "," SJIS_RIGHT " Alterar valor",
    [MENU_STATUS_MISC_HACKDEBUG_HELP_1] = SJIS_STAR
    "     " SJIS_TRIANGLE "   Ajuda      " SJIS_STAR "      " SJIS_UP
    "," SJIS_DOWN " Selecionar " SJIS_LEFT "," SJIS_RIGHT " Alterar valor",
    [MENU_STATUS_MISC_HACKDEBUG_HELP_2] = SJIS_STAR
    "    " SJIS_TRIANGLE "     Ajuda     " SJIS_STAR "      " SJIS_UP
    "," SJIS_DOWN " Selecionar " SJIS_LEFT "," SJIS_RIGHT " Alterar valor",
    [MENU_STATUS_MISC_HACKDEBUG_HELP_3] = SJIS_STAR
    "   " SJIS_TRIANGLE "       Ajuda    " SJIS_STAR "      " SJIS_UP
    "," SJIS_DOWN " Selecionar " SJIS_LEFT "," SJIS_RIGHT " Alterar valor",

    [MENU_TITLE_MISC_HACKDEBUG] = "[" EMUNAME_VERSION "] - Menu",

    // TRAPACEAS
    [MENU_ICONS_CHEATS] = "TRAPAÇAS",
    [MENU_ICONS_CHEATS_ADDRAW] = "Adicionar código RAW",
    [MENU_ICONS_CHEATS_ADDRAW_HELP] = "Adicionar um código RAW",
    [MENU_ICONS_CHEATS_ADDGG] = "Adicionar código Game Genie",
    [MENU_ICONS_CHEATS_ADDGG_HELP] = "Adicionar um código Game Genie",
    [MENU_ICONS_CHEATS_ADDPAR] = "Adicionar código Pro ActionReplay",
    [MENU_ICONS_CHEATS_ADDPAR_HELP] = "Adicionar um código Pro Action\nReplay",
    [MENU_ICONS_CHEATS_ADDGF] = "Adicionar código GoldFinger",
    [MENU_ICONS_CHEATS_ADDGF_HELP] = "Adicionar um código GoldFinger",
    [MENU_ICONS_CHEATS_DISABLE] = "Desativar código",
    [MENU_ICONS_CHEATS_DISABLE_HELP] = "Desativar código",
    [MENU_ICONS_CHEATS_DISABLEALL] = "Desativar todos os códigos",
    [MENU_ICONS_CHEATS_DISABLEALL_HELP] = "Desativar todos os códigos",
    [MENU_ICONS_CHEATS_ENABLE] = "Ativar código",
    [MENU_ICONS_CHEATS_ENABLE_HELP] = "Ativar código",
    [MENU_ICONS_CHEATS_ENABLEALL] = "Ativar todos os códigos",
    [MENU_ICONS_CHEATS_ENABLEALL_HELP] = "Ativar todos os códigos",
    [MENU_ICONS_CHEATS_REMOVE] = "Remover código",
    [MENU_ICONS_CHEATS_REMOVE_HELP] = "Remover código",
    [MENU_ICONS_CHEATS_REMOVEALL] = "Remover todos os códigos",
    [MENU_ICONS_CHEATS_REMOVEALL_HELP] = "Remover todos os códigos",
    // SOBRE
    [MENU_ICONS_ABOUT] = "SOBRE",
    [MENU_ICONS_ABOUT_CREDITS] = "Créditos",
    [MENU_ICONS_ABOUT_VERSION] = "Informações da versão",

    [MENU_ABOUT_VERSION_TIMESTAMP] = "Compilado em %s",
    [MENU_ABOUT_VERSION_GCCVER] = "Com GCC %s",

    // Outros
    //  Adhoc
    [ADHOC_CONNECTING] = "Conectando...\n",
    [ADHOC_SELECTORRETURN] =
        "Selecione um servidor para conectar, ou triângulo para voltar",
    [ADHOC_WAITING] =
        "Aguardando %s aceitar a conexão\nPara cancelar pressione O\n",
    [ADHOC_REQUESTED] = "%s solicitou uma conexão\nPara aceitar a conexão "
                        "pressione X, para cancelar pressione O\n",
    [ADHOC_CONNECTED] = "Conectado",
    [ADHOC_STATE] = "  progresso da conexão %d de 1\n",
    [ADHOC_UNKNOWNCOMMAND] = "Comando desconhecido %02X!",
    [ADHOC_SYNCLOST_SERVER] = "SERVIDOR Perdeu sincronia: ressincronizar!!!",
    [ADHOC_SYNCLOST_CLIENT] = "CLIENTE Perdeu sincronia: ressincronizar!!!",
    [ADHOC_CLOSING] = "fechando conexão",
    [ADHOC_DRIVERLOAD_ERR] = "Erro ao carregar driver de rede",
    [ADHOC_INIT_ERR] = "Problema ao iniciar jogo adhoc\n",
    [ADHOC_LOST_CONNECTION] = "Conexão perdida!",
    [ADHOC_CORRUPTED_PKT] = "pacote corrompido",
    [ADHOC_STATE_SIZE] = "tamanho do progresso: %d",
    [ADHOC_FILE_ERR_RECEIVING] = "erro de arquivo ao receber progresso!",
    [ADHOC_FILE_ERR_SENDING] = "erro de arquivo ao enviar progresso!",
    [ADHOC_STILL] = "ainda: %d",
    [ADHOC_WAITING_OTHER] =
        "Aguardando outro jogador\n\nPressione " SJIS_TRIANGLE
        " para fechar conexão e sair do netplay\n",
    [ADHOC_NETWORKERR_1] = "erro de rede 1",
    [ADHOC_CANNOTFIND] = "não foi possível encontrar o progresso salvo!",
    [ADHOC_FLUSHING] = "liberando rede, aguarde alguns segundos",
    // CARREGAR/SALVAR
    [LOADSAVE_AUTOSAVETIMER] = "Auto-salvando...",
    [LOADSAVE_EXPORTS9XSTATE] = "Arquivo snes9xTYL encontrado",
    // VÍDEO
    [VIDEO_ENGINE_APPROX] = "Modo simples: software preciso",
    [VIDEO_ENGINE_ACCUR] = "Modo simples: software aproximado",
    [VIDEO_ENGINE_ACCEL] = "Modo simples: acelerado por PSP",
    [VIDEO_ENGINE_ACCEL_ACCUR] =
        "Modos mistos: acelerado PSP + software preciso",
    [VIDEO_ENGINE_ACCEL_APPROX] =
        "Modos mistos: acelerado PSP + software aproximado",
    [VIDEO_FSKIP_AUTO] = "Pulo de quadros: AUTO",
    [VIDEO_FSKIP_MANUAL] = "Pulo de quadros: %d",
    // Mensagem de Rolagem
    [SCROLL_HELP_MOVE] = "mover",
    [SCROLL_HELP_FAST] = "rápido",
    [SCROLL_STATUS_0] = "Linha %d/%d  -  Página %d/%d",
    [SCROLL_STATUS_1] = "   sair,        ajuda  ",
    [SCROLL_HELP] =
        "Snes9xTYL - visualizador de arquivos\n\n" SJIS_TRIANGLE
        " Buscar, depois %s Próxima busca, " SJIS_SQUARE
        " Busca anterior\n" SJIS_UP "," SJIS_DOWN
        " rolar texto, L,R rolar mais rápido\n%s sair\n\n"
        "A última posição é mantida se o mesmo arquivo for reaberto.\nNo "
        "entanto, será redefinido se outro arquivo for aberto.\n\n"
        "Pressione %s",
    [SCROLL_SEARCHING] = "Buscando...",
    [SCROLL_STRNOTFOUND] = "String não encontrada!",
    [SCROLL_DISCLAIMER] = "Aviso Legal",
    [SCROLL_OSK_DESC] = "Digite a string para buscar",
    // Configurações
    [SETTINGS_NOTCOMPLETE] =
        "!!Arquivo de configurações incompleto!!\n\nProvavelmente vindo de uma "
        "versão anterior.\n\nNovas configurações serão definidas com valores "
        "padrão",
    [SETTINGS_NOTFOUND] = "Nenhuma configuração encontrada, usando padrão",
    [SETTINGS_FORCING_DEFAULT] = "Forçando configurações padrão",
    [SETTINGS_IGNORED] =
        "arquivo ini de uma versão anterior incompatível, ignorado!",
    [SETTINGS_FOUND] = "Configurações encontradas!\n\n"
                       "%s"
                       "",
    [SETTINGS_DIFF] = "arquivo ini de uma versão diferente.",
    // Outros
    [APU_DEBUGGING] = "DEPURAÇÃO DA APU",
    [BGMUSIC_PLAYING] = "Reproduzindo arquivo spc...",
    [FOUND_SRAM] = "Arquivo SRAM encontrado",
    [CANCEL] = "CANCELAR",
    [INPUTBOX_OK] = "\n\n      Fechar",
#ifdef ME_SOUND
    [BAT_ISLOW] = "Bateria fraca, salvamento agora desabilitado (SRAM, estados "
                  "e configurações).\n\nEsta janela fechará em 3 segundos.",
#else
    [BAT_ISLOW] =
        "Bateria fraca, salvamento agora desabilitado (SRAM, estados e "
        "configurações).\n\nVocê ainda pode colocar seu PSP em modo de espera "
        "e carregar a bateria depois.\n\nEsta janela fechará em 3 segundos.",
#endif
    [CONV_DONE] = "conversão concluída",
    [ROM_LIED] = "A ROM mentiu sobre seu tipo! Tentando novamente.",
    [LOADING_ROM] = "Carregando %dKB...",
    [TYPE] = "Tipo",
    [MODE] = "Modo",
    [COMPANY] = "Empresa",
#ifdef _BSX_151_
    [SRAM_NOTFOUND] =
        "O arquivo SRAM não foi encontrado: BS-X.srm foi lido no lugar.",
    [SRAM_BSX_NOTFOUND] = "O arquivo SRAM não foi encontrado, BS-X.srm também "
                          "não foi encontrado.",
#endif
    [CORRUPT] = "Corrompido",
    [ROM_ONLY] = "Apenas ROM",
    [EXTENDING] = "Expandindo",
    [EXTENDING_TARGET] = "Expandindo alvo de %d para %d\n",
    [INIT_OSK] = "Inicializando OSK...",
},
