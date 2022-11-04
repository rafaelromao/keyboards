#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// clang-format off

#define ___________________ROMAK_L1____________________ XXXXXXX , KC_F    , KC_D    , KC_W    , XXXXXXX
#define ___________________ROMAK_L2____________________ KCR_MAC , LSFTT_N , LCTLT_S , LGUIT_T , KC_G
#define ___________________ROMAK_L3____________________ RALTT_Q , KC_B    , KC_C    , LALTT_P , KC_K
#define ____ROMAK_L4_____                                                             NAV_ACT , LOW_SPC

#define ___________________ROMAK_R1____________________ XXXXXXX , KC_L    , KC_O    , KC_U    , XXXXXXX
#define ___________________ROMAK_R2____________________ KC_V    , RGUIT_H , RCTLT_A , RSFTT_E , KCI_MAC
#define ___________________ROMAK_R3____________________ KC_J    , LALTT_M , TD_COMM , TD_DOT  , RALTT_Y
#define ____ROMAK_R4_____                               RAI_BSP , MED_CAS

#define ___________________ACCENT_L1___________________ XXXXXXX , XXXXXXX , KC_X    , XXXXXXX , XXXXXXX
#define ___________________ACCENT_L2___________________ XXXXXXX , KC_Z    , TD_SQUO , XXXXXXX , XXXXXXX
#define ___________________ACCENT_L3___________________ XXXXXXX , XXXXXXX , MC_SQ_C , XXXXXXX , XXXXXXX
#define ____ACCENT_L4____                                                             _______ , KC_SPC

#define ___________________ACCENT_R1___________________ XXXXXXX , MC_TL_O , MC_SQ_O , MC_SQ_U , XXXXXXX
#define ___________________ACCENT_R2___________________ MC_GV_A , MC_TL_A , MC_SQ_A , MC_SQ_E , MC_SQ_I
#define ___________________ACCENT_R3___________________ XXXXXXX , MC_CR_A , MC_CR_O , MC_CR_E , XXXXXXX
#define ____ACCENT_R4____                               KC_BSPC , _______

#define ___________________NUMPAD_L1___________________ XXXXXXX , KC_F9   , KC_F8   , KC_F7   , XXXXXXX
#define ___________________NUMPAD_L2___________________ KC_F15  , SF_F6   , CT_F5   , GU_F4   , KC_F11
#define ___________________NUMPAD_L3___________________ AL_F14  , KC_F3   , KC_F2   , AL_F1   , KC_F10
#define ____NUMPAD_L4____                                                             NAV_F12 , LOW_SPC

#define ___________________NUMPAD_R1___________________ XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX
#define ___________________NUMPAD_R2___________________ TD_COLN , GU_4    , CT_5    , SF_6    , DOT_MAC
#define ___________________NUMPAD_R3___________________ TG_NUM  , AL_1    , KC_2    , KC_3    , AL_COMM
#define ____NUMPAD_R4____                               RAI_BSP , MED_0

#define ___________________MACROS_L1___________________ XXXXXXX , MC_ESC  , MC_QUIK , MC_AUCO , XXXXXXX
#define ___________________MACROS_L2___________________ MC_QDOC , SF_FSYM , MC_RUN  , MC_DBUG , MC_BUID
#define ___________________MACROS_L3___________________ MC_PROJ , MC_RECE , MC_COMP , MC_FIUS , MC_REFC
#define ____MACROS_L4____                                                             _______ , LOW_BSP

#define ___________________MACROS_R1___________________ XXXXXXX , MC_SELW , MC_ENT  , MC_TAB  , XXXXXXX
#define ___________________MACROS_R2___________________ TD_MACR , MC_SELL , MC_MODM , SF_MODP , XXXXXXX
#define ___________________MACROS_R3___________________ MC_JOIN , MC_COMT , MC_SWLE , MC_SWRI , XXXXXXX
#define ____MACROS_R4____                               RAI_SPC , _______

#define ___________________LOWER_L1____________________ XXXXXXX , TD_OPAR , TD_CPAR , KC_BSLS , XXXXXXX
#define ___________________LOWER_L2____________________ NAV_BTI , TD_DQUO , TD_SQUO , TD_AND  , TD_TILD
#define ___________________LOWER_L3____________________ KC_AT   , TD_OBR  , TD_CBR  , KC_QUES , KC_HASH
#define ____LOWER_L4_____                                                             _______ , _______

#define ___________________LOWER_R1____________________ XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX
#define ___________________LOWER_R2____________________ TD_COLN , KC_4    , KC_5    , KC_6    , DOT_MAC
#define ___________________LOWER_R3____________________ TG_NUM  , KC_1    , KC_2    , KC_3    , KC_COMM
#define ____LOWER_R4_____                               _______ , MED_0

#define ___________________RAISE_L1____________________ XXXXXXX , KC_F9   , KC_F8   , KC_F7   , XXXXXXX
#define ___________________RAISE_L2____________________ KC_F15  , KC_F6   , KC_F5   , KC_F4   , KC_F11
#define ___________________RAISE_L3____________________ KC_F14  , KC_F3   , KC_F2   , KC_F1   , KC_F10
#define ____RAISE_L4_____                                                             NAV_F12 , _______

#define ___________________RAISE_R1____________________ KC_CIRC , TD_DLR  , TD_LCRB , TD_RCRB , XXXXXXX
#define ___________________RAISE_R2____________________ TD_COLN , KC_MINS , KC_EQL  , TD_NOT  , KC_PLUS
#define ___________________RAISE_R3____________________ TD_PERC , KC_SLSH , KC_LT   , KC_GT   , KC_ASTR
#define ____RAISE_R4_____                               _______ , _______

#define ___________________MEDIA_L1____________________ XXXXXXX , MC_ESC  , MC_SAVE , KC_RALT , XXXXXXX
#define ___________________MEDIA_L2____________________ XXXXXXX , KC_LSFT , KC_LCTL , KC_LGUI , KC_LGUI
#define ___________________MEDIA_L3____________________ KC_RALT , XXXXXXX , XXXXXXX , KC_LALT , XXXXXXX
#define ____MEDIA_L4_____                                                             MAI_ACT , KC_SPC

#define ___________________MEDIA_R1____________________ XXXXXXX , XXXXXXX , KC_ENT  , KC_TAB  , XXXXXXX
#define ___________________MEDIA_R2____________________ TG_NAV  , KC_MUTE , KC_VOLD , KC_VOLU , HYPR_A
#define ___________________MEDIA_R3____________________ TG_NUM  , KC_MPLY , KC_MPRV , KC_MNXT , HYPR_V
#define ____MEDIA_R4_____                               KC_BSPC , _______

#define ___________________NAVIGATION_L1_______________ XXXXXXX , MC_ESC  , MC_SAVE , OS_RALT , XXXXXXX
#define ___________________NAVIGATION_L2_______________ XXXXXXX , OS_LSFT , OS_LCTL , OS_LGUI , XXXXXXX
#define ___________________NAVIGATION_L3_______________ OS_RALT , XXXXXXX , XXXXXXX , OS_LALT , XXXXXXX
#define __NAVIGATION_L4__                                                             _______ , KC_SPC

#define ___________________NAVIGATION_R1_______________ XXXXXXX , KC_APP  , KC_PGDN , KC_PGUP , XXXXXXX
#define ___________________NAVIGATION_R2_______________ TG_NAV  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_______________ XXXXXXX , KC_DEL  , KC_HOME , KC_END  , KC_INS
#define __NAVIGATION_R4__                               KC_BSPC , MAI_CAS
#define __FIXED_NAV__R4__                               KC_BSPC , MED_CAS

#define ___________________MAINTENANCE_L1______________ XXXXXXX , RGB_VAD , RGB_VAI , EEP_RST , XXXXXXX
#define ___________________MAINTENANCE_L2______________ RGB_TOG , RGB_HUD , RGB_HUI , XXXXXXX , QK_BOOT
#define ___________________MAINTENANCE_L3______________ XXXXXXX , RGB_SAD , RGB_SAI , XXXXXXX , KC_NUM
#define __MAINTENANCE_L4_                                                             XXXXXXX , XXXXXXX

#define ___________________MAINTENANCE_R1______________ XXXXXXX , EEP_RST , MC_LOCK , KC_SLEP , XXXXXXX
#define ___________________MAINTENANCE_R2______________ QK_BOOT , TG_MAC  , TG_WIN  , TG_LOCK , KC_PWR
#define ___________________MAINTENANCE_R3______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define __MAINTENANCE_R4_                               XXXXXXX , XXXXXXX

#define _______________________LOCK____L1______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define _______________________LOCK____L2______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define _______________________LOCK____L3______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ______LOCK____L4_                                                             _______ , XXXXXXX

#define _______________________LOCK____R1______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define _______________________LOCK____R2______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define _______________________LOCK____R3______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ______LOCK____R4_                               XXXXXXX , _______

// clang-format on