#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// clang-format off
// Layout 9 = Colemak DH 

#define _________________LAYOUT_L0________________ KC_1  , KC_2 , KC_3 , KC_4 , KC_5
#define _________________LAYOUT_L1________________ KC_Q , KC_W , KC_F , KC_P , KC_B
#define _________________LAYOUT_L2________________ KC_A , KC_R , KC_S , KC_T , KC_G
#define _________________LAYOUT_L3________________ KC_Z , KC_X , KC_C , KC_D , KC_V
#define ____LAYOUT_L4_____                                                KC_LGUI, LSFT_T(KC_DEL),LT(_RAISE, KC_BSPC)

#define ________LAYOUT_M0________                                KC_F6, KC_F7, KC_F8
#define ________LAYOUT_M1________                                 KC_F6, KC_F7, KC_F8
#define ________LAYOUT_M2________                                KC_LBRC, KC_QUOT, KC_RBRC
#define ________LAYOUT_M3________                                KC_EQL, RGB_TOG, KC_MINS
#define ________LAYOUT_M4________                                KC_VOLD, KC_MPLY, KC_VOLU

#define ________________LAYOUT_R0________________ KC_6  , KC_7 , KC_8        , KC_9       , KC_0
#define ________________LAYOUT_R1________________ KC_J  , KC_L  , KC_U         , KC_Y       , KC_SCLN
#define ________________LAYOUT_R2________________ KC_M, KC_N ,  KC_E ,          KC_I ,        KC_O
#define ________________LAYOUT_R3________________ KC_K , KC_H , KC_COMM , KC_DOT , KC_SLSH
#define ______LAYOUT_R4______                                        LT(_LOWER, KC_SPC) , LT(_MAINTENANCE, KC_ENT), KC_RGUI
 // |_______________________________________________________________________________________________________________________________|

#define __________________LOWER_L0________________ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define __________________LOWER_L1________________ RESET, LSFT(KC_LEFT), LCTL(KC_LEFT), LCTL(KC_RGHT), LSFT(KC_RGHT)
#define __________________LOWER_L2________________ KC_NO, KC_LEFT, KC_HOME, KC_END, KC_RGHT
#define __________________LOWER_L3________________ KC_NO, KC_NO, KC_BSLS, KC_QUOT, KC_EQL
#define _____LOWER_L4_____                                                                              KC_LGUI,  _______ , MED_0

#define ________LOWER_M0_________                                KC_F6, KC_F7, KC_F8

#define _________________LOWER_R0________________ KC_F9, KC_F10, KC_F11, KC_F12, RGB_TOG
#define _________________LOWER_R1________________  LSFT(KC_LEFT), LCTL(KC_LEFT), LCTL(KC_RGHT), LSFT(KC_RGHT), KC_NO
#define _________________LOWER_R2________________ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO
#define _________________LOWER_R3________________ KC_LBRC, KC_COLN, KC_RBRC, KC_NO, KC_NO
#define _______LOWER_R4______                                        _______ , _______ , KC_RGUI
 // |_______________________________________________________________________________________________________________________________|

#define _________________RAISE_L0___________________ XXXXXXX , KC_F9   , KC_F8   , KC_F7   , KC_F12
#define _________________RAISE_L1___________________ XXXXXXX , KC_F9   , KC_F8   , KC_F7   , KC_F12
#define _________________RAISE_L2___________________ KC_F15  , KC_F6   , KC_F5   , KC_F4   , KC_F11
#define _________________RAISE_L3___________________ KC_F14  , KC_F3   , KC_F2   , KC_F1   , KC_F10
#define _____RAISE_L4_______                                                                             KC_LGUI,  _______ , _______

#define _________________RAISE_R0_________________ MC_CIRC , TD_DLR  , TD_CURB , KC_RCBR , XXXXXXX
#define _________________RAISE_R1_________________ MC_CIRC , TD_DLR  , TD_CURB , KC_RCBR , XXXXXXX
#define _________________RAISE_R2_________________ KC_PLUS , KC_MINS , KC_EQL  , KC_EXLM , PER_LOW
#define _________________RAISE_R3_________________ KC_ASTR , KC_SLSH , TD_ANGB , KC_GT   , KC_COLN
#define _______RAISE_R4_______                                        _______ , _______, KC_RGUI
 // |_______________________________________________________________________________________________________________________________|

#define ______________MAINTENANCE_L0_____________ XXXXXXX , RGB_VAD , RGB_VAI , RGB_RMOD , EEP_RST
#define ______________MAINTENANCE_L1_____________ XXXXXXX , RGB_VAD , RGB_VAI , RGB_MOD , EEP_RST
#define ______________MAINTENANCE_L2_____________ RGB_TOG , RGB_HUD , RGB_HUI , XXXXXXX , XXXXXXX
#define ______________MAINTENANCE_L3_____________ XXXXXXX , RGB_SAD , RGB_SAI , XXXXXXX , XXXXXXX
#define __MAINTENANCE_L4_                                                                                             KC_LGUI,  _______ , _______

#define ______________MAINTENANCE_R0____________ RESET   , KC_PWR  , KC_SLEP , MC_LOCK , XXXXXXX
#define ______________MAINTENANCE_R1____________ RESET   , KC_PWR  , KC_SLEP , MC_LOCK , XXXXXXX
#define ______________MAINTENANCE_R2____________ XXXXXXX , TG_MAC  , TG_WIN  , TG_LIN  , KC_NUM
#define ______________MAINTENANCE_R3____________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ___MAINTENANCE_R4___                                       _______ , _______, KC_RGUI

 // |_______________________________________________________________________________________________________________________________|

// Layout 8 = Romak - VTBZ

// #define ___________________LAYOUT_L1____________________ XXXXXXX , KC_R    , KC_Q    , KC_P    , KC_Z
// #define ___________________LAYOUT_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________LAYOUT_L3____________________ KC_B    , KC_X    , KC_Y    , LGUIT_T , KC_V
// #define ____LAYOUT_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________LAYOUT_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , XXXXXXX
// #define ___________________LAYOUT_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MAC
// #define ___________________LAYOUT_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , KC_W
// #define ____LAYOUT_R4_____                               RAI_BSP , MED_SFT

// Layout 7 = QWERTY

// #define ___________________LAYOUT_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________LAYOUT_L2___________________ KCA_MAC , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________LAYOUT_L3___________________ KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B
// #define ____LAYOUT_L4____                                                             NAV_NG  , LOW_SPC

// #define ___________________LAYOUT_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________LAYOUT_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , SCL_MAC
// #define ___________________LAYOUT_R3___________________ KC_N    , RGUIT_M , TD_COML , TD_DOTD , KC_BSLS
// #define ____LAYOUT_R4____                               RAI_BSP , MED_SFT

// // Layout 5 - PWR;

// #define ___________________LAYOUT_L1____________________ XXXXXXX , KC_R    , KC_Q   , KC_P    , KC_T
// #define ___________________LAYOUT_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________LAYOUT_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____LAYOUT_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________LAYOUT_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , XXXXXXX
// #define ___________________LAYOUT_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MAC
// #define ___________________LAYOUT_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , KC_W
// #define ____LAYOUT_R4_____                               RAI_BSP , MED_SFT

// // Layout 4 - LUIO

// #define ___________________LAYOUT_L1____________________ XXXXXXX , KC_W    , KC_Q    , KC_R    , KC_T
// #define ___________________LAYOUT_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________LAYOUT_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____LAYOUT_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________LAYOUT_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , KC_P
// #define ___________________LAYOUT_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MAC
// #define ___________________LAYOUT_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , TD_SCLE
// #define ____LAYOUT_R4_____                               RAI_BSP , MED_SFT

// // Layout 3 - EDQ/

// #define ___________________LAYOUT_L1____________________ XXXXXXX , KC_W    , KC_Q    , KC_R    , KC_T
// #define ___________________LAYOUT_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________LAYOUT_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____LAYOUT_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________LAYOUT_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________LAYOUT_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MAC
// #define ___________________LAYOUT_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , TD_SCLE
// #define ____LAYOUT_R4_____                               RAI_BSP , MED_SFT

// // Layout 2 - KFA/

// #define ___________________LAYOUT_L1____________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________LAYOUT_L2____________________ KCF_MAC , LSFTT_S , LCTLT_D , LA_BSLS , KC_G
// #define ___________________LAYOUT_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____LAYOUT_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________LAYOUT_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________LAYOUT_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MAC
// #define ___________________LAYOUT_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , TD_SCLE
// #define ____LAYOUT_R4_____                               RAI_BSP , MED_SFT

// Layout 1 - NJYC/

// #define ___________________LAYOUT_L1____________________ KC_Q    , KC_W    , KC_E , KC_R    , KC_T
// #define ___________________LAYOUT_L2____________________ KCA_MAC , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________LAYOUT_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____LAYOUT_L4_____                                                             NAV_NG  , LOW_SPC

// #define ___________________LAYOUT_R1____________________ KC_BSLS , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________LAYOUT_R2____________________ KC_H    , RALTT_N , RCTLT_K , RSFTT_L , KCC_MAC
// #define ___________________LAYOUT_R3____________________ KC_J    , RGUIT_M , TD_COMM , TD_DOTD , TD_SCLE
// #define ____LAYOUT_R4_____                               RAI_BSP , MED_SFT

// Layout 0

// #define ___________________LAYOUT_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________LAYOUT_L2___________________ KCA_MAC , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________LAYOUT_L3___________________ KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B
// #define ____LAYOUT_L4____                                                             NAV_NG  , LOW_SPC

// #define ___________________LAYOUT_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________LAYOUT_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , BSL_MAC
// #define ___________________LAYOUT_R3___________________ KC_N    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____LAYOUT_R4____                               RAI_BSP , MED_SFT

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


// clang-format on