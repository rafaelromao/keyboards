#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// // Romak 6 = Romak - VTBZ

// #define ___________________ROMAK_L1____________________ KC_UNDS , KC_R    , KC_Q    , KC_P    , KC_Z
// #define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________ROMAK_L3____________________ KC_B    , KC_X    , KC_Y    , LGUIT_T , KC_V
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , TD_SCLE
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , KC_W
// #define ____ROMAK_R4_____                               RAI_BSP , MED_CAP

// // Romak 5 - PWR;

// #define ___________________ROMAK_L1____________________ KC_UNDS , KC_R    , KC_Q    , KC_P    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , TD_SCLE
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , KC_W
// #define ____ROMAK_R4_____                               RAI_BSP , MED_CAP

// Romak 4 - LUIO

#define ___________________ROMAK_L1____________________ KC_UNDS , KC_W    , KC_Q    , KC_R    , KC_T
#define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
#define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
#define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC
                                                        
#define ___________________ROMAK_R1____________________ KC_K    , KC_L    , KC_U    , KC_I    , KC_P
#define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_O , KCC_MAC
#define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
#define ____ROMAK_R4_____                               RAI_BSP , MED_CAP

// // Romak 3 - EDQ_

// #define ___________________ROMAK_L1____________________ KC_UNDS , KC_W    , KC_Q    , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_E , LALTT_D , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MED_CAP

// // Romak 2 - KFA_

// #define ___________________ROMAK_L1____________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCF_MAC , LSFTT_S , LCTLT_D , LA_UNDS , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_K    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_A , RSFTT_L , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MED_CAP

// Romak 1 - NJYC_

// #define ___________________ROMAK_L1____________________ KC_Q    , KC_W    , KC_E , KC_R    , KC_T
// #define ___________________ROMAK_L2____________________ KCA_MAC , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________ROMAK_L3____________________ KC_Z    , KC_X    , KC_Y    , LGUIT_V , KC_B
// #define ____ROMAK_L4_____                                                             NAV_NG  , LOW_SPC
                                                        
// #define ___________________ROMAK_R1____________________ KC_UNDS , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2____________________ KC_H    , RALTT_N , RCTLT_K , RSFTT_L , KCC_MAC
// #define ___________________ROMAK_R3____________________ KC_J    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4_____                               RAI_BSP , MED_CAP

// Romak 0 = QWERTY

// #define ___________________ROMAK_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
// #define ___________________ROMAK_L2___________________ KCA_MAC , LSFTT_S , LCTLT_D , LALTT_F , KC_G
// #define ___________________ROMAK_L3___________________ KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B
// #define ____ROMAK_L4____                                                             NAV_NG  , LOW_SPC

// #define ___________________ROMAK_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
// #define ___________________ROMAK_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , UND_MAI
// #define ___________________ROMAK_R3___________________ KC_N    , RGUIT_M , TD_COML , TD_DOTD , TD_SCLE
// #define ____ROMAK_R4____                               RAI_BSP , MED_CAP

#define ___________________NGRAMS_L1___________________ XXXXXXX , SS_RS   , SS_RE   , SS_PH   , SS_LH
#define ___________________NGRAMS_L2___________________ SS_CH   , SS_SH   , SS_HE   , SS_NH   , SS_GH
#define ___________________NGRAMS_L3___________________ SS_WH   , SS_SR   , SS_ER   , SS_TH   , SS_ING
#define ____NGRAMS_L4____                                                             _______ , NUM_SPC
                                                        
#define ___________________NGRAMS_R1___________________ SS_CK   , SS_CR_A , SS_SQ_U , SS_SQ_I , XXXXXXX
#define ___________________NGRAMS_R2___________________ SS_GV_A , SS_SQ_A , SS_TL_A , SS_TL_O , SS_SQ_C
#define ___________________NGRAMS_R3___________________ SS_IO   , SS_SQ_E , SS_CR_E , SS_SQ_O , SS_CR_O
#define ____NGRAMS_R4____                               NUM_BSP , _______

#define ___________________NUMPAD_L1___________________ KC_NUM  , XXXXXXX , XXXXXXX , KC_RALT , XXXXXXX
#define ___________________NUMPAD_L2___________________ XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , XXXXXXX
#define ___________________NUMPAD_L3___________________ XXXXXXX , XXXXXXX , XXXXXXX , KC_LGUI , XXXXXXX
#define ____NUMPAD_L4____                                                             _______ , LOW_SPC

#define ___________________NUMPAD_R1___________________ XXXXXXX , KC_P7   , KC_P8   , KC_P9   , TG_NUM
#define ___________________NUMPAD_R2___________________ KC_COMM , KC_P4   , KC_P5   , KC_P6   , PDO_MAC
#define ___________________NUMPAD_R3___________________ SS_DEG  , KC_P1   , KC_P2   , KC_P3   , KC_COLN
#define ____NUMPAD_R4____                               RAI_BSP , MED_P0

#define ___________________LOWER_L1____________________ XXXXXXX , TD_PARB , KC_RPRN , KC_BSLS , SS_TILD
#define ___________________LOWER_L2____________________ SS_BTIC , SS_DQUO , SS_SQUO , KC_AMPR , KC_PIPE
#define ___________________LOWER_L3____________________ KC_AT   , TD_SQRB , KC_RBRC , KC_QUES , KC_HASH
#define ____LOWER_L4_____                                                             _______ , _______

#define ___________________LOWER_R1____________________ XXXXXXX , KC_7    , KC_8    , KC_9    , TG_NUM
#define ___________________LOWER_R2____________________ KC_COMM , KC_4    , KC_5    , KC_6    , DOT_MAC
#define ___________________LOWER_R3____________________ SS_DEG  , KC_1    , KC_2    , KC_3    , KC_COLN
#define ____LOWER_R4_____                               _______ , MED_0

#define ___________________RAISE_L1____________________ SS_CAPS , KC_F9   , KC_F8   , KC_F7   , KC_F12
#define ___________________RAISE_L2____________________ KC_F15  , KC_F6   , KC_F5   , KC_F4   , KC_F11
#define ___________________RAISE_L3____________________ KC_F14  , KC_F3   , KC_F2   , KC_F1   , KC_F10
#define ____RAISE_L4_____                                                             _______ , _______

#define ___________________RAISE_R1____________________ SS_CIRC , TD_DLR  , TD_CURB , KC_RCBR , TG_NUM
#define ___________________RAISE_R2____________________ KC_PLUS , KC_MINS , KC_EQL  , KC_EXLM , KC_PERC
#define ___________________RAISE_R3____________________ KC_ASTR , KC_SLSH , TD_ANGB , KC_GT   , KC_COLN
#define ____RAISE_R4_____                               _______ , _______

#define ___________________MACROS_L1___________________ XXXXXXX , XXXXXXX , TD_MAC2 , XXXXXXX , XXXXXXX
#define ___________________MACROS_L2___________________ XXXXXXX , XXXXXXX , XXXXXXX , SS_DAND , SS_DPIP
#define ___________________MACROS_L3___________________ XXXXXXX , XXXXXXX , TD_MAC1 , XXXXXXX , XXXXXXX
#define ____MACROS_L4____                                                             TD_IJLE , KC_BSPC

#define ___________________MACROS_R1___________________ XXXXXXX , XXXXXXX , SS_SELW , XXXXXXX , XXXXXXX
#define ___________________MACROS_R2___________________ XXXXXXX , SS_ARR  , SS_EQU  , SS_NEQ  , XXXXXXX
#define ___________________MACROS_R3___________________ XXXXXXX , XXXXXXX , KC_LEAD , SS_DDS  , XXXXXXX
#define ____MACROS_R4____                               KC_SPC  , TD_IJRI

#define ___________________MEDIA_L1____________________ KC_ESC  , XXXXXXX , KC_TAB  , OS_RALT , XXXXXXX
#define ___________________MEDIA_L2____________________ SS_SWIN , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX
#define ___________________MEDIA_L3____________________ XXXXXXX , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX
#define ____MEDIA_L4_____                                                             MAI_MOD , KC_SPC

#define ___________________MEDIA_R1____________________ XXXXXXX , KC_APP  , SS_MODM , SS_MODP , KC_ENT 
#define ___________________MEDIA_R2____________________ TG_NAV  , KC_MUTE , KC_VOLD , KC_VOLU , HYPR_A 
#define ___________________MEDIA_R3____________________ XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , HYPR_V
#define ____MEDIA_R4_____                               KC_BSPC , _______

#define ___________________NAVIGATION_L1_______________ KC_ESC  , XXXXXXX , KC_TAB  , OS_RALT , XXXXXXX
#define ___________________NAVIGATION_L2_______________ SS_SWIN , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX
#define ___________________NAVIGATION_L3_______________ XXXXXXX , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX
#define __NAVIGATION_L4__                                                             _______ , KC_SPC

#define ___________________NAVIGATION_R1_______________ XXXXXXX , KC_APP  , KC_PGDN , KC_PGUP , KC_ENT
#define ___________________NAVIGATION_R2_______________ TG_NAV  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_______________ XXXXXXX , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define __NAVIGATION_R4__                               KC_BSPC , MAI_ALT

#define ___________________MAINTENANCE_L1______________ XXXXXXX , XXXXXXX , KC_PWR  , XXXXXXX , EEP_RST    
#define ___________________MAINTENANCE_L2______________ RGB_TOG , XXXXXXX , XXXXXXX , TO_ROM  , XXXXXXX 
#define ___________________MAINTENANCE_L3______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define __MAINTENANCE_L4_                                                             _______ , _______

#define ___________________MAINTENANCE_R1______________ RESET   , XXXXXXX , KC_SLEP , XXXXXXX , XXXXXXX 
#define ___________________MAINTENANCE_R2______________ TG_NAV  , TG_MAC  , TG_WIN  , TG_LIN  , XXXXXXX 
#define ___________________MAINTENANCE_R3______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define __MAINTENANCE_R4_                               _______ , _______
