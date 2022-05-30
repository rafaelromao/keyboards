#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// clang-format off

// Romak 6 = Romak - VTBZ

#define ___________________ROMAK_L1____________________ XXXXXXX , KC_R    , KC_Q    , KC_P    , KC_Z
#define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
#define ___________________ROMAK_L3____________________ KC_B    , KC_X    , KC_Y    , LGUIT_T , KC_V
#define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC

#define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , XXXXXXX
#define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MAC
#define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , KC_W
#define ____ROMAK_R4_____                               RAI_BSP , MED_SFT

// // Romak 5 - PWR;

// #define ___________________ROMAK_L1____________________ XXXXXXX , KC_R    , KC_Q   , KC_P    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , XXXXXXX
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , KC_W
// #define ____ROMAK_R4_____                               RAI_BSP , MED_SFT

// // Romak 4 - LUIO

// #define ___________________ROMAK_L1____________________ XXXXXXX , KC_W    , KC_Q    , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MED_SFT

// // Romak 3 - EDQ/

// #define ___________________ROMAK_L1____________________ XXXXXXX , KC_W    , KC_Q    , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________ROMAK_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MED_SFT

// // Romak 2 - KFA/

// #define ___________________ROMAK_L1____________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_D , LA_BSLS , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________ROMAK_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MED_SFT

// Romak 1 - NJYC/

// #define ___________________ROMAK_L1____________________ KC_Q    , KC_W    , KC_E , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCA_MAC , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________ROMAK_R1____________________ KC_BSLS , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_K , RSFTT_L , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MED_SFT

// Romak 0

// #define ___________________ROMAK_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________ROMAK_L2___________________ KCA_MAC , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________ROMAK_L3___________________ KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B
// #define ____ROMAK_L4____                                                             NAV_NG  , LOW_SPC

// #define ___________________ROMAK_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , BSL_MAC
// #define ___________________ROMAK_R3___________________ KC_N    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4____                               RAI_BSP , MED_SFT

// QWERTY

// #define ___________________ROMAK_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________ROMAK_L2___________________ KCA_MAC , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________ROMAK_L3___________________ KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B
// #define ____ROMAK_L4____                                                             NAV_NG  , LOW_SPC

// #define ___________________ROMAK_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , SCL_MAC
// #define ___________________ROMAK_R3___________________ KC_N    , RGUIT_M , TD_COML , TD_DOTD , KC_BSLS
// #define ____ROMAK_R4____                               RAI_BSP , MED_SFT

#define ___________________NGRAMS_L1___________________ XXXXXXX , MC_QU   , MC_LH   , MC_PH   , XXXXXXX
#define ___________________NGRAMS_L2___________________ XXXXXXX , MC_TH   , MC_CH   , MC_WH   , XXXXXXX
#define ___________________NGRAMS_L3___________________ XXXXXXX , MC_GH   , MC_NH   , MC_SH   , XXXXXXX
#define ____NGRAMS_L4____                                                             _______ , KC_SPC

#define ___________________NGRAMS_R1___________________ XXXXXXX , MC_CR_A , MC_SQ_U , MC_SQ_I , XXXXXXX
#define ___________________NGRAMS_R2___________________ MC_GV_A , MC_SQ_A , MC_TL_A , MC_TL_O , MC_SQ_C
#define ___________________NGRAMS_R3___________________ XXXXXXX , MC_SQ_E , MC_CR_E , MC_SQ_O , MC_CR_O
#define ____NGRAMS_R4____                               KC_BSPC , _______

#define ___________________NUMPAD_L1___________________ XXXXXXX , KC_F9   , KC_F8   , KC_F7   , KC_F12
#define ___________________NUMPAD_L2___________________ KC_F15  , SF_F6   , CT_F5   , AL_F4   , KC_F11
#define ___________________NUMPAD_L3___________________ KC_F14  , KC_F3   , KC_F2   , GU_F1   , KC_F10
#define ____NUMPAD_L4____                                                             _______ , LOW_SPC

#define ___________________NUMPAD_R1___________________ TG_NUM  , KC_7    , KC_8    , KC_9    , XXXXXXX
#define ___________________NUMPAD_R2___________________ KC_COMM , AL_4    , CT_5    , SF_6    , DOT_MAC
#define ___________________NUMPAD_R3___________________ MC_DEG  , GU_1    , KT_2    , KT_3    , KC_COLN
#define ____NUMPAD_R4____                               RAI_BSP , MED_0

#define ___________________MACROS_L1___________________ XXXXXXX , MC_SWLE , MC_SWRI , XXXXXXX , XXXXXXX
#define ___________________MACROS_L2___________________ XXXXXXX , KC_LSFT , XXXXXXX , MC_SELW , XXXXXXX
#define ___________________MACROS_L3___________________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ____MACROS_L4____                                                             TD_IJLE , RAI_BSP

#define ___________________MACROS_R1___________________ XXXXXXX , XXXXXXX , MC_MODM , MC_MODP , XXXXXXX
#define ___________________MACROS_R2___________________ XXXXXXX , MC_ARR  , MC_EQU  , MC_NEQ  , XXXXXXX
#define ___________________MACROS_R3___________________ MC_JOIN , MC_COMT , TD_MACR , MC_DDS  , MC_CPR
#define ____MACROS_R4____                               LOW_SPC , TD_IJRI

#define ___________________LOWER_L1____________________ XXXXXXX , TD_PARB , KC_RPRN , MC_TILD , KC_BSLS
#define ___________________LOWER_L2____________________ BTI_RAI , MC_DQUO , MC_SQUO , MC_DAND , MC_DPIP
#define ___________________LOWER_L3____________________ KC_AT   , TD_SQRB , KC_RBRC , KC_QUES , KC_HASH
#define ____LOWER_L4_____                                                             _______ , _______

#define ___________________LOWER_R1____________________ TG_NUM  , KC_7    , KC_8    , KC_9    , XXXXXXX
#define ___________________LOWER_R2____________________ KC_COMM , KC_4    , KC_5    , KC_6    , DOT_MAC
#define ___________________LOWER_R3____________________ MC_DEG  , KC_1    , KT_2    , KT_3    , KC_COLN
#define ____LOWER_R4_____                               _______ , MED_0

#define ___________________RAISE_L1____________________ XXXXXXX , KC_F9   , KC_F8   , KC_F7   , KC_F12
#define ___________________RAISE_L2____________________ KC_F15  , KC_F6   , KC_F5   , KC_F4   , KC_F11
#define ___________________RAISE_L3____________________ KC_F14  , KC_F3   , KC_F2   , KC_F1   , KC_F10
#define ____RAISE_L4_____                                                             _______ , _______

#define ___________________RAISE_R1____________________ MC_CIRC , TD_DLR  , TD_CURB , KC_RCBR , XXXXXXX
#define ___________________RAISE_R2____________________ KC_PLUS , KC_MINS , KC_EQL  , KC_EXLM , PER_LOW
#define ___________________RAISE_R3____________________ KC_ASTR , KC_SLSH , TD_ANGB , KC_GT   , KC_COLN
#define ____RAISE_R4_____                               _______ , _______

#define ___________________MEDIA_L1____________________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ___________________MEDIA_L2____________________ XXXXXXX , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX
#define ___________________MEDIA_L3____________________ XXXXXXX , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX
#define ____MEDIA_L4_____                                                             MAI_MOD , KC_SPC

#define ___________________MEDIA_R1____________________ TG_NUM  , XXXXXXX , KC_ENT  , KC_TAB  , XXXXXXX
#define ___________________MEDIA_R2____________________ TG_NAV  , KC_MUTE , KC_VOLD , KC_VOLU , HYPR_A
#define ___________________MEDIA_R3____________________ TO_ROM  , KC_MPLY , KC_MPRV , KC_MNXT , HYPR_V
#define ____MEDIA_R4_____                               KC_BSPC , _______

#define ___________________NAVIGATION_L1_______________ XXXXXXX , KC_TAB  , KC_ESC  , XXXXXXX , XXXXXXX
#define ___________________NAVIGATION_L2_______________ XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , XXXXXXX
#define ___________________NAVIGATION_L3_______________ XXXXXXX , XXXXXXX , XXXXXXX , KC_LGUI , XXXXXXX
#define __NAVIGATION_L4__                                                             _______ , KC_SPC

#define ___________________NAVIGATION_R1_______________ XXXXXXX , KC_APP  , KC_PGDN , KC_PGUP , XXXXXXX
#define ___________________NAVIGATION_R2_______________ TG_NAV  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_______________ XXXXXXX , KC_DEL  , KC_HOME , KC_END  , KC_INS
#define __NAVIGATION_R4__                               KC_BSPC , MAI_ALT
#define __FIXED_NAV__R4__                               KC_BSPC , MED_ALT

#define ___________________MAINTENANCE_L1______________ XXXXXXX , RGB_VAD , RGB_VAI , XXXXXXX , EEP_RST
#define ___________________MAINTENANCE_L2______________ RGB_TOG , RGB_HUD , RGB_HUI , XXXXXXX , XXXXXXX
#define ___________________MAINTENANCE_L3______________ XXXXXXX , RGB_SAD , RGB_SAI , XXXXXXX , XXXXXXX
#define __MAINTENANCE_L4_                                                             _______ , _______

#define ___________________MAINTENANCE_R1______________ RESET   , KC_PWR  , KC_SLEP , MC_LOCK , XXXXXXX
#define ___________________MAINTENANCE_R2______________ XXXXXXX , TG_MAC  , TG_WIN  , TG_LIN  , KC_NUM
#define ___________________MAINTENANCE_R3______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define __MAINTENANCE_R4_                               _______ , _______

// clang-format on