#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// clang-format off

#define __________________ALPHA1_L1__________           MC_ESCC , KC_B    , KC_M    , KC_G    
#define __________________ALPHA1_L2____________________ SHO_KCD , LSFTT_N , LCTLT_S , LGUIT_T , KC_W
#define           ________ALPHA1_L3____________________           RALTT_F , KC_C    , LALTT_P , KC_V
#define                               ___ALPHA1_L4_____                               NAV_REP , LOW_SPC

#define           ________ALPHA1_R1____________________           KC_L    , KC_O    , KC_U    , KC_BSPC
#define __________________ALPHA1_R2____________________ KC_Z    , RGUIT_R , RCTLT_A , RSFTT_E , SHO_KCI
#define __________________ALPHA1_R3__________           KC_J    , RALTT_H , TD_COMM , TD_DOT  
#define ___ALPHA1_R4_____                               RAI_A2  , MED_CAS 

#define ___________________NUMPAD_L1_________           _______ , KC_F9   , KC_F8   , KC_F7   
#define ___________________NUMPAD_L2___________________ NAV_F12 , SF_F6   , CT_F5   , GU_F4   , KC_F11
#define           _________NUMPAD_L3___________________           AL_F3   , KC_F2   , AL_F1   , KC_F10
#define                               ____NUMPAD_L4____                               _______ , LOW_SPC

#define           _________NUMPAD_R1___________________           KC_7    , KC_8    , KC_9    , _______
#define ___________________NUMPAD_R2___________________ KC_COMM , GU_4    , CT_5    , SF_6    , SHO_DOT
#define ___________________NUMPAD_R3_________           MC_SEC  , AL_1    , KC_2    , KC_3    
#define ____NUMPAD_R4____                               RAI_SPC , MED_0

#define ________________SHORTCUTS_L1_________           _______ , MC_ESC  , MC_QUIK , MC_AUCO 
#define ________________SHORTCUTS_L2___________________ XXXXXXX , SF_FSYM , MC_RUN  , MC_DBUG , MC_BUID
#define           ______SHORTCUTS_L3___________________           MC_RECE , MC_COMP , MC_FIUS , MC_REFC
#define                               _SHORTCUTS_L4____                               NAV_PRJ , NMO_DOC

#define           ______SHORTCUTS_R1___________________           MC_SELW , MC_ENT  , MC_TAB  , _______
#define ________________SHORTCUTS_R2___________________ TD_MACR , MC_SELL , MC_MODM , SF_MODP , XXXXXXX
#define ________________SHORTCUTS_R3_________           MC_JOIN , MC_COMT , MC_SWLE , MC_SWRI 
#define _SHORTCUTS_R4____                               ACT_SPC , TT_NAV

#define ___________________NOMOD_L1__________           KC_ESC  , KC_B    , KC_M    , KC_G    
#define ___________________NOMOD_L2____________________ KC_D    , KC_N    , KC_S    , KC_T    , KC_W
#define           _________NOMOD_L3____________________           KC_F    , KC_C    , KC_P    , KC_V
#define                               ____NOMOD_L4_____                               QK_REP  , _______

#define           _________NOMOD_R1____________________           KC_L    , KC_O    , KC_U    , KC_BSPC
#define ___________________NOMOD_R2____________________ KC_Z    , KC_R    , KC_A    , KC_E    , KC_I
#define ___________________NOMOD_R3__________           KC_J    , KC_H    , KC_COMM , KC_DOT  
#define ____NOMOD_R4_____                               MO_A2   , OS_LSFT

#define ___________________ALPHA2_L1_________           _______ , KC_Q    , MC_QU   , KC_K
#define ___________________ALPHA2_L2___________________ KC_Y    , KC_Z    , KC_X    , KC_W    , XXXXXXX
#define           _________ALPHA2_L3___________________           KC_J    , MC_SQ_C , KC_V    , XXXXXXX 
#define                               ____ALPHA2_L4____                               TH_QUOT , OS_SYM

#define           _________ALPHA2_R1___________________           MC_GV_A , MC_SQ_O , MC_SQ_U , _______
#define ___________________ALPHA2_R2___________________ XXXXXXX , MC_TL_A , MC_SQ_A , MC_SQ_E , MC_SQ_I
#define ___________________ALPHA2_R3_________           XXXXXXX , MC_CR_A , MC_CR_O , MC_CR_E 
#define ____ALPHA2_R4____                               _______ , _______

#define ___________________LOWER_L1__________           _______ , TD_LCRB , TD_RCRB , TD_HASH 
#define ___________________LOWER_L2____________________ NAV_AT  , TD_OPAR , TD_CPAR , TD_DQUO , MC_SQUO
#define           _________LOWER_L3____________________           TD_OBR  , TD_CBR  , TD_QUES , MC_BTIC
#define                               ____LOWER_L4_____                               KC_CAPS , _______

#define           _________LOWER_R1____________________           KC_7    , KC_8    , KC_9    , _______
#define ___________________LOWER_R2____________________ KC_COMM , KC_4    , KC_5    , KC_6    , KC_DOT
#define ___________________LOWER_R3__________           MC_SEC  , KC_1    , KC_2    , KC_3    
#define ____LOWER_R4_____                               SYM_SPC , MED_0

#define ___________________RAISE_L1__________           _______ , KC_F9   , KC_F8   , KC_F7   
#define ___________________RAISE_L2____________________ KC_F12  , KC_F6   , KC_F5   , KC_F4   , KC_F11
#define           _________RAISE_L3____________________           KC_F3   , KC_F2   , KC_F1   , KC_F10
#define                               ____RAISE_L4_____                               QK_REP  , SYM_SPC

#define           _________RAISE_R1____________________           TD_COLN , TD_EQL  , TD_PERC , _______
#define ___________________RAISE_R2____________________ MC_CIRC , TD_MINS , TD_PLUS , TD_SLSH , MED_AST
#define ___________________RAISE_R3__________           MC_TILD , TD_EXLM , TD_AND  , TD_OR     
#define ____RAISE_R4_____                               _______ , TG_NUM

#define _________________SYMBOLS_L1__________           _______ , KC_LCBR , KC_RCBR , KC_HASH 
#define _________________SYMBOLS_L2____________________ KC_AT   , KC_LPRN , KC_RPRN , KC_DQUO , KC_QUOT
#define           _______SYMBOLS_L3____________________           KC_LBRC , KC_RBRC , KC_QUES , KC_GRV
#define                               __SYMBOLS_L4_____                               KC_CAPS , KC_SPC 

#define           _______SYMBOLS_R1____________________           KC_COLN , KC_EQL  , KC_PERC , _______
#define _________________SYMBOLS_R2____________________ KC_CIRC , KC_MINS , KC_PLUS , KC_SLSH , KC_ASTR
#define _________________SYMBOLS_R3__________           KC_TILD , KC_EXLM , KC_AMPR , KC_PIPE     
#define __SYMBOLS_R4_____                               KC_SPC  , TG_NUM

#define ___________________MEDIA_L1__________           _______ , MC_ESC  , HYPR_M  , HYPR_G  
#define ___________________MEDIA_L2____________________ HYPR_D  , KC_LSFT , KC_LCTL , KC_LGUI , XXXXXXX 
#define           _________MEDIA_L3____________________           KC_RALT , HYPR_C  , KC_LALT , XXXXXXX 
#define                               ____MEDIA_L4_____                               MAI_CAS , KC_SPC

#define           _________MEDIA_R1____________________           HYPR_L  , KC_ENT  , KC_TAB  , _______
#define ___________________MEDIA_R2____________________ XXXXXXX , HYPR_R  , KC_VOLD , KC_VOLU , KC_MUTE
#define ___________________MEDIA_R3__________           XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT 
#define ____MEDIA_R4_____                               _______ , _______

#define ___________________NAVIGATION_L1_____           _______ , MC_ESC  , MEH_M   , MEH_G 
#define ___________________NAVIGATION_L2_______________ MEH_D   , OS_LSFT , OS_LCTL , OS_LGUI , XXXXXXX
#define           _________NAVIGATION_L3_______________           OS_RALT , MEH_C   , OS_LALT , XXXXXXX
#define                               __NAVIGATION_L4__                               _______ , _______

#define           _________NAVIGATION_R1_______________           KC_INS  , KC_ENT  , KC_TAB  , _______
#define ___________________NAVIGATION_R2_______________ XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_____           XXXXXXX , KC_DEL  , KC_HOME , KC_END  
#define __NAVIGATION_R4__                               KC_SPC  , MAI_CAS
#define __FIXED_NAV__R4__                               KC_SPC  , MED_A1

#define _______________________LOCK____L1____           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define _______________________LOCK____L2______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define           _____________LOCK____L3______________           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define                               ______LOCK____L4_                               _______ , XXXXXXX

#define           _____________LOCK____R1______________           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define _______________________LOCK____R2______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define _______________________LOCK____R3____           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define ______LOCK____R4_                               XXXXXXX , _______

#define ______________________SYSTEM___L1____           _______ , RGB_VAD , RGB_VAI , KC_NUM
#define ______________________SYSTEM___L2______________ RGB_TOG , RGB_HUD , RGB_HUI , QK_BOOT , XXXXXXX
#define           ____________SYSTEM___L3______________           RGB_SAD , RGB_SAI , EE_CLR  , XXXXXXX
#define                               _____SYSTEM___L4_                               XXXXXXX , XXXXXXX

#define           ____________SYSTEM___R1______________           TG_OS   , KC_ENT  , KC_TAB  , _______
#define ______________________SYSTEM___R2______________ XXXXXXX , QK_BOOT , KC_SLEP , MC_LOCK , TG_LOCK
#define ______________________SYSTEM___R3____           XXXXXXX , EE_CLR  , XXXXXXX , XXXXXXX 
#define _____SYSTEM___R4_                               XXXXXXX , XXXXXXX

// clang-format on