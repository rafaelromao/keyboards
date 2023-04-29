#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// clang-format off

#define ___________________ROMAK_L1__________           MC_ESCC , KC_B    , KC_D    , KC_W    
#define ___________________ROMAK_L2____________________ MAC_KCR , LSFTT_N , LCTLT_S , LGUIT_T , KC_G
#define           _________ROMAK_L3____________________           RALTT_F , KC_C    , LALTT_P , KC_K
#define                               ____ROMAK_L4_____                               NAV_BSP , LOW_SPC

#define           _________ROMAK_R1____________________           KC_L    , KC_O    , KC_U    , KC_BSPC
#define ___________________ROMAK_R2____________________ KC_V    , RGUIT_H , RCTLT_A , RSFTT_E , MAC_KCI
#define ___________________ROMAK_R3__________           KC_J    , LALTT_M , TD_COMM , TD_DOT  
#define ____ROMAK_R4_____                               RAI_ACT , MED_CAS 

#define ___________________NUMPAD_L1_________           _______ , KC_F9   , KC_F8   , KC_F7   
#define ___________________NUMPAD_L2___________________ NAV_F12 , SF_F6   , CT_F5   , GU_F4   , KC_F11
#define           _________NUMPAD_L3___________________           AL_F3   , KC_F2   , AL_F1   , KC_F10
#define                               ____NUMPAD_L4____                               NAV_BSP , KC_SPC

#define           _________NUMPAD_R1___________________           KC_7    , KC_8    , KC_9    , _______
#define ___________________NUMPAD_R2___________________ KC_COMM , GU_4    , CT_5    , SF_6    , MAC_DOT
#define ___________________NUMPAD_R3_________           TG_NUM  , AL_1    , KC_2    , KC_3    
#define ____NUMPAD_R4____                               RAI_SPC , MED_0

#define ___________________ACCENT_L1_________           _______ , _______ , REPEAT  , KC_TILD
#define ___________________ACCENT_L2___________________ KC_QUOT , MC_QU   , KC_X    , KC_Z    , KC_GRV
#define           _________ACCENT_L3___________________           KC_Q    , MC_SQ_C , _______ , KC_CIRC
#define                               ____ACCENT_L4____                               KC_BSPC , KC_SPC

#define           _________ACCENT_R1___________________           MC_GV_A , MC_SQ_O , MC_SQ_U , _______
#define ___________________ACCENT_R2___________________ MC_TL_A , KC_Y    , MC_SQ_A , MC_SQ_E , MC_SQ_I
#define ___________________ACCENT_R3_________           MC_TL_O , MC_CR_A , MC_CR_O , MC_CR_E 
#define ____ACCENT_R4____                               RAI_TAC , _______

#define ___________________MACROS_L1_________           _______ , MC_ESC  , MC_QUIK , MC_AUCO 
#define ___________________MACROS_L2___________________ MC_QDOC , SF_FSYM , MC_RUN  , MC_DBUG , MC_BUID
#define           _________MACROS_L3___________________           MC_RECE , MC_COMP , MC_FIUS , MC_REFC
#define                               ____MACROS_L4____                               NAV_PRJ , KC_SPC

#define           _________MACROS_R1___________________           MC_SELW , MC_ENT  , MC_TAB  , _______
#define ___________________MACROS_R2___________________ TD_MACR , MC_SELL , MC_MODM , SF_MODP , XXXXXXX
#define ___________________MACROS_R3_________           MC_JOIN , MC_COMT , MC_SWLE , MC_SWRI 
#define ____MACROS_R4____                               KC_SPC  , _______

#define ___________________LOWER_L1__________           _______ , TD_OPAR , TD_CPAR , TD_TILD 
#define ___________________LOWER_L2____________________ NAV_SQO , TD_DQUO , TD_AND  , TD_OR   , MC_BTIC
#define           _________LOWER_L3____________________           TD_OBR  , TD_CBR  , TD_QUES , KC_HASH
#define                               ____LOWER_L4_____                               _______ , _______

#define           _________LOWER_R1____________________           KC_7    , KC_8    , KC_9    , _______
#define ___________________LOWER_R2____________________ KC_COMM , KC_4    , KC_5    , KC_6    , MAC_DOT
#define ___________________LOWER_R3__________           TG_NUM  , KC_1    , KC_2    , KC_3    
#define ____LOWER_R4_____                               RAI_SPC , MED_0

#define ___________________RAISE_L1__________           _______ , KC_F9   , KC_F8   , KC_F7   
#define ___________________RAISE_L2____________________ KC_F12  , KC_F6   , KC_F5   , KC_F4   , KC_F11
#define           _________RAISE_L3____________________           KC_F3   , KC_F2   , KC_F1   , KC_F10
#define                               ____RAISE_L4_____                               KC_BSPC , KC_SPC

#define           _________RAISE_R1____________________           TD_DLR  , TD_LCRB , TD_RCRB , _______
#define ___________________RAISE_R2____________________ TD_COLN , KC_MINS , TD_PLUS , TD_EQL  , KC_AT
#define ___________________RAISE_R3__________           TD_PERC , TD_SLSH , KC_ASTR , TD_NOT   
#define ____RAISE_R4_____                               _______ , _______

#define ___________________MEDIA_L1__________           _______ , MC_ESC  , MC_SAVE , HYPR_W  
#define ___________________MEDIA_L2____________________ HYPR_R  , KC_LSFT , KC_LCTL , KC_LGUI , HYPR_G 
#define           _________MEDIA_L3____________________           KC_RALT , HYPR_C  , KC_LALT , HYPR_K 
#define                               ____MEDIA_L4_____                               MAI_BSP , _______

#define           _________MEDIA_R1____________________           HYPR_L  , KC_ENT  , KC_TAB  , _______
#define ___________________MEDIA_R2____________________ TG_NAV  , HYPR_H  , KC_VOLD , KC_VOLU , KC_MUTE
#define ___________________MEDIA_R3__________           TG_NUM  , KC_MPLY , KC_MPRV , KC_MNXT 
#define ____MEDIA_R4_____                               _______ , _______

#define ___________________NAVIGATION_L1_____           _______ , MC_ESC  , MC_SAVE , MEH_W 
#define ___________________NAVIGATION_L2_______________ MEH_R   , OS_LSFT , OS_LCTL , OS_LGUI , MEH_G
#define           _________NAVIGATION_L3_______________           OS_RALT , MEH_C   , OS_LALT , MEH_K
#define                               __NAVIGATION_L4__                               _______ , _______

#define           _________NAVIGATION_R1_______________           MEH_L   , KC_PGDN , KC_PGUP , _______
#define ___________________NAVIGATION_R2_______________ TG_NAV  , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_____           KC_INS  , KC_DEL  , KC_HOME , KC_END  
#define __NAVIGATION_R4__                               _______ , MAI_CAS
#define __FIXED_NAV__R4__                               _______ , MED_CAS

#define _______________________LOCK____L1____           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define _______________________LOCK____L2______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define           _____________LOCK____L3______________           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define                               ______LOCK____L4_                               _______ , XXXXXXX

#define           _____________LOCK____R1______________           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define _______________________LOCK____R2______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define _______________________LOCK____R3____           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define ______LOCK____R4_                               XXXXXXX , _______

#define ___________________MAINTENANCE_L1____           _______ , RGB_VAD , RGB_VAI , EE_CLR 
#define ___________________MAINTENANCE_L2______________ RGB_TOG , RGB_HUD , RGB_HUI , KC_CAPS , QK_BOOT
#define           _________MAINTENANCE_L3______________           RGB_SAD , RGB_SAI , KC_SCRL , KC_NUM
#define                               __MAINTENANCE_L4_                               XXXXXXX , XXXXXXX

#define           _________MAINTENANCE_R1______________           EE_CLR  , MC_LOCK , KC_SLEP , _______
#define ___________________MAINTENANCE_R2______________ QK_BOOT , TG_MAC  , TG_WIN  , TG_LOCK , KC_PWR
#define ___________________MAINTENANCE_R3____           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define __MAINTENANCE_R4_                               XXXXXXX , XXXXXXX

// clang-format on