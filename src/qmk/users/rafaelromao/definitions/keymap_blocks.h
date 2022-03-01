#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// // Romak 6 = Romak - VTBZ

// #define ___________________ROMAK_L1____________________ KC_UNDS , KC_R    , KC_Q    , KC_P    , KC_Z
// #define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________ROMAK_L3____________________ KC_B    , KC_X    , KC_Y    , LGUIT_T , KC_V
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , TD_SCLE
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , KC_W
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// // Romak 5 - PWR;

// #define ___________________ROMAK_L1____________________ KC_UNDS , KC_R    , KC_Q    , KC_P    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , TD_SCLE
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , KC_W
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// // Romak 4 - LUIO

// #define ___________________ROMAK_L1____________________ KC_UNDS , KC_W    , KC_Q    , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// Romak 3 - EDQ_

#define ___________________ROMAK_L1____________________ KC_UNDS , KC_W    , KC_Q    , KC_R    , KC_T
#define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LCTLT_E , LALTT_D , KC_G
#define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
#define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
#define ___________________ROMAK_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
#define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MED
#define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
#define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// // Romak 2 - KFA_

// #define ___________________ROMAK_L1____________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LCTLT_D , LA_UNDS , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// Romak 1 - NJYC_

// #define ___________________ROMAK_L1____________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCA_FUN , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_UNDS , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_K , RSFTT_L , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// Romak 0 = QWERTY

// #define ___________________ROMAK_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________ROMAK_L2___________________ KCA_FUN , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________ROMAK_L3___________________ KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B
// #define ____ROMAK_L4____                                                             NAV_MOD , LOW_SPC

// #define ___________________ROMAK_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , UND_MED
// #define ___________________ROMAK_R3___________________ KC_N    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4____                               RAI_BSP , MOU_CAP

#define ___________________NUMPAD_L1___________________ KC_NUM  , XXXXXXX , XXXXXXX , KC_RALT , XXXXXXX
#define ___________________NUMPAD_L2___________________ XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , XXXXXXX
#define ___________________NUMPAD_L3___________________ XXXXXXX , XXXXXXX , XXXXXXX , KC_LGUI , XXXXXXX
#define ____NUMPAD_L4____                                                             _______ , LOW_SPC

#define ___________________NUMPAD_R1___________________ KC_TAB  , KC_P7   , KC_P8   , KC_P9   , KC_ENT
#define ___________________NUMPAD_R2___________________ KC_COMM , KC_P4   , KC_P5   , KC_P6   , PDO_MED
#define ___________________NUMPAD_R3___________________ SS_DEG  , KC_P1   , KC_P2   , KC_P3   , KC_COLN
#define ____NUMPAD_R4____                               RAI_BSP , MOU_P0

#define ___________________LOWER_L1____________________ XXXXXXX , TD_PARB , KC_RPRN , KC_BSLS , SS_TILD
#define ___________________LOWER_L2____________________ SS_BTIC , SS_DQUO , SS_SQUO , KC_AMPR , KC_PIPE
#define ___________________LOWER_L3____________________ KC_AT   , TD_SQRB , KC_RBRC , KC_QUES , KC_HASH
#define ____LOWER_L4_____                                                             _______ , _______

#define ___________________LOWER_R1____________________ KC_TAB  , KC_7    , KC_8    , KC_9    , KC_ENT
#define ___________________LOWER_R2____________________ KC_COMM , KC_4    , KC_5    , KC_6    , DOT_MED
#define ___________________LOWER_R3____________________ SS_DEG  , KC_1    , KC_2    , KC_3    , KC_COLN
#define ____LOWER_R4_____                               _______ , MOU_0

#define ___________________RAISE_L1____________________ SS_GV_A , SS_CR_A , SS_TL_A , SS_SQ_A , SS_SQ_U
#define ___________________RAISE_L2____________________ SS_SQ_C , KC_CIRC , KC_TILD , TD_QUOT , SS_SQ_I
#define ___________________RAISE_L3____________________ SS_CR_O , SS_CR_E , SS_TL_O , SS_SQ_E , SS_SQ_O
#define ____RAISE_L4_____                                                             _______ , _______

#define ___________________RAISE_R1____________________ SS_CIRC , TD_DLR  , TD_CURB , KC_RCBR , XXXXXXX
#define ___________________RAISE_R2____________________ KC_PLUS , KC_MINS , KC_EQL  , KC_EXLM , KC_PERC
#define ___________________RAISE_R3____________________ KC_ASTR , KC_SLSH , TD_ANGB , KC_GT   , KC_COLN
#define ____RAISE_R4_____                               _______ , _______

#define ___________________NAVIGATION_L1_______________ KC_ESC  , KC_LEAD , SS_SELW , OS_RALT , XXXXXXX
#define ___________________NAVIGATION_L2_______________ SS_SWIN , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX
#define ___________________NAVIGATION_L3_______________ KC_TAB  , XXXXXXX , TD_MACR , OS_LGUI , XXXXXXX
#define __NAVIGATION_L4__                                                             MO_MAI  , KC_SPC

#define ___________________NAVIGATION_R1_______________ XXXXXXX , KC_APP  , KC_PGDN , KC_PGUP , KC_ENT
#define ___________________NAVIGATION_R2_______________ XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_______________ XXXXXXX , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define __NAVIGATION_R4__                               KC_BSPC , MO_MAI

#define ___________________MOUSE_L1____________________ KC_ESC  , KC_LEAD , SS_SELW , OS_RALT , XXXXXXX
#define ___________________MOUSE_L2____________________ SS_SWIN , OS_LSFT , OS_LCTL , OS_LALT , KC_BTN1
#define ___________________MOUSE_L3____________________ KC_TAB  , XXXXXXX , TD_MACR , OS_LGUI , KC_BTN2
#define ____MOUSE_L4_____                                                             MO_MAI  , KC_SPC

#define ___________________MOUSE_R1____________________ XXXXXXX , KC_APP  , KC_WH_D , KC_WH_U , KC_ENT
#define ___________________MOUSE_R2____________________ KC_BTN1 , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R
#define ___________________MOUSE_R3____________________ KC_BTN2 , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define ____MOUSE_R4_____                               KC_BSPC , MO_MAI

#define ___________________FUNCTIONS_L1________________ XXXXXXX , XXXXXXX , XXXXXXX , KC_RALT , KC_SCRL
#define ___________________FUNCTIONS_L2________________ _______ , KC_LSFT , KC_LCTL , KC_LALT , KC_PSCR
#define ___________________FUNCTIONS_L3________________ XXXXXXX , XXXXXXX , XXXXXXX , KC_LGUI , KC_PAUS
#define ____FUNCTIONS_L4_                                                             TD_IJLE , NUM_BSP

#define ___________________FUNCTIONS_R1________________ KC_F12  , KC_F7   , KC_F8   , KC_F9   , SS_CAPS
#define ___________________FUNCTIONS_R2________________ KC_F11  , KC_F4   , KC_F5   , KC_F6   , KC_F15
#define ___________________FUNCTIONS_R3________________ KC_F10  , KC_F1   , KC_F2   , KC_F3   , KC_F14
#define ____FUNCTIONS_R4_                               NUM_SPC , TD_IJRI

#define ___________________MEDIA_L1____________________ XXXXXXX , KC_MPRV , KC_MNXT , KC_MPLY , XXXXXXX
#define ___________________MEDIA_L2____________________ XXXXXXX , KC_VOLD , KC_VOLU , KC_MUTE , XXXXXXX 
#define ___________________MEDIA_L3____________________ XXXXXXX , SS_MODM , SS_MODP , HYPR_A  , HYPR_V 
#define ____MEDIA_L4_____                                                             TD_IJLE , NUM_BSP

#define ___________________MEDIA_R1____________________ XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , XXXXXXX
#define ___________________MEDIA_R2____________________ XXXXXXX , KC_MUTE , KC_VOLD , KC_VOLU , _______
#define ___________________MEDIA_R3____________________ HYPR_V  , HYPR_A  , SS_MODM , SS_MODP , XXXXXXX
#define ____MEDIA_R4_____                               NUM_SPC , TD_IJRI

#define ___________________MAINTENANCE_L1______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define ___________________MAINTENANCE_L2______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ___________________MAINTENANCE_L3______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define __MAINTENANCE_L4_                                                             _______ , XXXXXXX

#define ___________________MAINTENANCE_R1______________ RESET   , XXXXXXX , KC_SLEP , XXXXXXX , KC_PWR
#define ___________________MAINTENANCE_R2______________ EEP_RST , TG_MAC  , TG_WIN  , TG_LIN  , RGB_TOG
#define ___________________MAINTENANCE_R3______________ TO_ROM  , XXXXXXX , MOU_ON  , MOU_OFF , XXXXXXX
#define __MAINTENANCE_R4_                               XXXXXXX , _______
