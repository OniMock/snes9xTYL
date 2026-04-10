#include "psp.h"
#include "psp_msg.h"

extern int os9x_language;
extern int os9x_force_language;

const char *s9xTYL_msg_ml[MSG_TOTAL_LANG][MSG_TOTAL_ENTRIES] = {
#include "lang/en.c"
#include "lang/ja.c"
#include "lang/ch.c"
#include "lang/pt.c"
#include "lang/es.c"
};

const char **s9xTYL_msg = s9xTYL_msg_ml[MSG_EN];

void psp_msg_init() {
	int msg_lang = MSG_EN;

	if (os9x_force_language != -1) {
		msg_lang = os9x_force_language;
	} else {
		switch(os9x_language) {
			case PSP_SYSTEMPARAM_LANGUAGE_JAPANESE:
				msg_lang = MSG_JA;
				break;
			case PSP_SYSTEMPARAM_LANGUAGE_CHINESE_SIMPLIFIED:
			case PSP_SYSTEMPARAM_LANGUAGE_CHINESE_TRADITIONAL:
				msg_lang = MSG_CH;
				break;
			case PSP_SYSTEMPARAM_LANGUAGE_PORTUGUESE:
				msg_lang = MSG_PT;
				break;
			case PSP_SYSTEMPARAM_LANGUAGE_SPANISH:
				msg_lang = MSG_ES;
				break;
			default:
				msg_lang = MSG_EN;
				break;
		}
	}

	if (msg_lang < 0 || msg_lang >= MSG_TOTAL_LANG) msg_lang = MSG_EN;
	s9xTYL_msg = s9xTYL_msg_ml[msg_lang];
}
