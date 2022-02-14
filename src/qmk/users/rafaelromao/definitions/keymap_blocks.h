#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// // Romak 6 - PRW;

// #define ___________________ROMAK_L1____________________ KC_UNDS , KC_R    , KC_Q    , KC_P    , KC_V
// #define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LCTLT_E , LALTT_T , KC_G
// #define ___________________ROMAK_L3____________________ KC_B    , KC_X    , KC_Y    , LGUIT_D , KC_Z
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , TD_SCLE
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , KC_W
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// // Romak 5 - LUIO

// #define ___________________ROMAK_L1____________________ KC_UNDS , KC_W    , KC_Q    , KC_R    , KC_V
// #define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LCTLT_E , LALTT_T , KC_G
// #define ___________________ROMAK_L3____________________ KC_B    , KC_X    , KC_Y    , LGUIT_D , KC_Z
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// // Romak 4 - EQZB_

// #define ___________________ROMAK_L1____________________ KC_UNDS , KC_W    , KC_Q    , KC_R    , KC_V
// #define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LCTLT_E , LALTT_T , KC_G
// #define ___________________ROMAK_L3____________________ KC_B    , KC_X    , KC_Y    , LGUIT_D , KC_Z
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// // Romak 3 - DVT_

// #define ___________________ROMAK_L1____________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_V
// #define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LC_UNDS , LALTT_T , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_D , KC_B
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// Romak 2 - KFA_

#define ___________________ROMAK_L1____________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
#define ___________________ROMAK_L2____________________ KCF_FUN , LSFTT_S , LCTLT_D , LA_UNDS , KC_G
#define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
#define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
#define ___________________ROMAK_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
#define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MED
#define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
#define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

// Romak 1 - NJYC_

// #define ___________________ROMAK_L1____________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCA_FUN , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_MOD , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_UNDS , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_K , RSFTT_L , KCC_MED
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MOU_CAP

#define ___________________QWERTY_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
#define ___________________QWERTY_L2___________________ KCA_FUN , LSFTT_S , LCTLT_D , LALTT_F , KC_G
#define ___________________QWERTY_L3___________________ KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B
#define ____QWERTY_L4____                                                             NAV_MOD , LOW_SPC

#define ___________________QWERTY_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
#define ___________________QWERTY_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , UND_MED
#define ___________________QWERTY_R3___________________ KC_N    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
#define ____QWERTY_R4____                               RAI_BSP , MOU_CAP

#define ___________________LOWER_L1____________________ XXXXXXX , TD_PARB , KC_RPRN , KC_BSLS , SS_TILD
#define ___________________LOWER_L2____________________ SS_BTIC , SS_DQUO , SS_SQUO , KC_AMPR , KC_PIPE
#define ___________________LOWER_L3____________________ KC_AT   , TD_SQRB , KC_RBRC , KC_QUES , KC_HASH
#define ____LOWER_L4_____                                                             _______ , _______

#define ___________________LOWER_R1____________________ XXXXXXX , KC_7    , KC_8    , KC_9    , XXXXXXX
#define ___________________LOWER_R2____________________ KC_COMM , KC_4    , KC_5    , KC_6    , DOT_MED
#define ___________________LOWER_R3____________________ SS_DEG  , KC_1    , KC_2    , KC_3    , XXXXXXX
#define ____LOWER_R4_____                               _______ , MOU_0

#define ___________________RAISE_L1____________________ SS_GV_A , SS_CR_A , SS_TL_A , SS_SQ_A , SS_SQ_U
#define ___________________RAISE_L2____________________ SS_SQ_C , KC_CIRC , KC_TILD , TD_QUOT , SS_SQ_I
#define ___________________RAISE_L3____________________ SS_CR_O , SS_CR_E , SS_TL_O , SS_SQ_E , SS_SQ_O
#define ____RAISE_L4_____                                                             _______ , _______

#define ___________________RAISE_R1____________________ SS_CIRC , TD_DLR  , TD_CURB , KC_RCBR , KC_COLN
#define ___________________RAISE_R2____________________ KC_PLUS , KC_MINS , KC_EQL  , KC_EXLM , KC_PERC
#define ___________________RAISE_R3____________________ KC_ASTR , KC_SLSH , TD_ANGB , KC_GT   , KC_COLN
#define ____RAISE_R4_____                               _______ , _______

#define ___________________NAVIGATION_L1_______________ KC_ESC  , XXXXXXX , SS_SELW , OS_RALT , XXXXXXX
#define ___________________NAVIGATION_L2_______________ SS_SWIN , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX
#define ___________________NAVIGATION_L3_______________ KC_TAB  , XXXXXXX , TD_MACR , OS_LGUI , XXXXXXX
#define __NAVIGATION_L4__                                                             MO_MAI  , _______

#define ___________________NAVIGATION_R1_______________ XXXXXXX , XXXXXXX , KC_PGDN , KC_PGUP , KC_ENT
#define ___________________NAVIGATION_R2_______________ XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_______________ XXXXXXX , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define __NAVIGATION_R4__                               _______ , MO_MAI

#define ___________________MOUSE_L1____________________ KC_ESC  , XXXXXXX , SS_SELW , OS_RALT , XXXXXXX
#define ___________________MOUSE_L2____________________ SS_SWIN , OS_LSFT , OS_LCTL , OS_LALT , KC_BTN1
#define ___________________MOUSE_L3____________________ KC_TAB  , XXXXXXX , TD_MACR , OS_LGUI , KC_BTN2
#define ____MOUSE_L4_____                                                             MO_MAI  , _______

#define ___________________MOUSE_R1____________________ XXXXXXX , XXXXXXX , KC_WH_D , KC_WH_U , KC_ENT
#define ___________________MOUSE_R2____________________ KC_BTN1 , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R
#define ___________________MOUSE_R3____________________ KC_BTN2 , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define ____MOUSE_R4_____                               _______ , MO_MAI

#define ___________________FUNCTIONS_L1________________ KC_CAPS , KC_LEAD , KC_APP  , KC_RALT , KC_SCRL
#define ___________________FUNCTIONS_L2________________ _______ , KC_LSFT , KC_LCTL , KC_LALT , KC_PSCR
#define ___________________FUNCTIONS_L3________________ XXXXXXX , XXXXXXX , XXXXXXX , KC_LGUI , KC_PAUS
#define ____FUNCTIONS_L4_                                                             TD_IJLE , KC_BSPC

#define ___________________FUNCTIONS_R1________________ KC_F15  , KC_F7   , KC_F8   , KC_F9   , KC_F12
#define ___________________FUNCTIONS_R2________________ KC_F14  , KC_F4   , KC_F5   , KC_F6   , KC_F11
#define ___________________FUNCTIONS_R3________________ KC_F13  , KC_F1   , KC_F2   , KC_F3   , KC_F10
#define ____FUNCTIONS_R4_                               KC_SPC  , TD_IJRI

#define ___________________MEDIA_L1____________________ KC_CAPS , RGB_HUD , RGB_HUI , RGB_MOD , XXXXXXX
#define ___________________MEDIA_L2____________________ XXXXXXX , RGB_VAD , RGB_VAI , RGB_TOG , XXXXXXX 
#define ___________________MEDIA_L3____________________ XXXXXXX , RGB_SAD , RGB_SAI , XXXXXXX , XXXXXXX
#define ____MEDIA_L4_____                                                             TD_IJLE , KC_BSPC

#define ___________________MEDIA_R1____________________ XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , KC_MSTP
#define ___________________MEDIA_R2____________________ XXXXXXX , KC_MUTE , KC_VOLD , KC_VOLU , _______
#define ___________________MEDIA_R3____________________ HYPR_V  , HYPR_A  , SS_MODM , SS_MODP , XXXXXXX
#define ____MEDIA_R4_____                               KC_SPC  , TD_IJRI

#define ___________________MAINTENANCE_L1______________ XXXXXXX , XXXXXXX , KC_PWR  , XXXXXXX , EEP_RST
#define ___________________MAINTENANCE_L2______________ XXXXXXX , XXXXXXX , DF_ROM  , DF_QWE  , XXXXXXX
#define ___________________MAINTENANCE_L3______________ TO_FUN  , XXXXXXX , XXXXXXX , TO_NAV  , TO_LOW
#define __MAINTENANCE_L4_                                                             _______ , XXXXXXX

#define ___________________MAINTENANCE_R1______________ RESET   , XXXXXXX , KC_SLEP , XXXXXXX , XXXXXXX
#define ___________________MAINTENANCE_R2______________ XXXXXXX , TG_MAC  , TG_WIN  , TG_LIN  , XXXXXXX
#define ___________________MAINTENANCE_R3______________ TO_RAI  , TO_MOU  , MOU_ON  , MOU_OFF , TO_MED
#define __MAINTENANCE_R4_                               XXXXXXX , _______
