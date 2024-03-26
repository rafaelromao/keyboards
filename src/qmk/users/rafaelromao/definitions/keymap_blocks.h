#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// clang-format off

#define __________________ALPHA1_L1__________           KC_Q    , KC_B    , KC_M    , KC_G    
#define __________________ALPHA1_L2____________________ SHO_KCD , LSFTT_N , LCTLT_S , LGUIT_T , KC_W
#define           ________ALPHA1_L3____________________           RALTT_F , LEA_KCC , LALTT_P , KC_V
#define                               ___ALPHA1_L4_____                               NAV_REP , LOW_SPC

#define           ________ALPHA1_R1____________________           KC_L    , KC_O    , KC_U    , KC_Y
#define __________________ALPHA1_R2____________________ KC_Z    , RGUIT_R , RCTLT_A , RSFTT_E , SHO_KCI
#define __________________ALPHA1_R3__________           KC_J    , RALTT_H , TD_COMM , TD_DOT  
#define ___ALPHA1_R4_____                               RAI_A2  , MED_CAS 

#define ___________________LOWER_L1__________           XXXXXXX , TD_LCBR , TD_RCBR , TD_DLR 
#define ___________________LOWER_L2____________________ NAV_AT  , TD_LPRN , TD_RPRN , TD_DQUO , XXXXXXX
#define           _________LOWER_L3____________________           TD_LBRC , TD_RBRC , TD_QUES , XXXXXXX
#define                               ____LOWER_L4_____                               KC_CAPS , _______

#define           _________LOWER_R1____________________           KC_7    , KC_8    , KC_9    , XXXXXXX
#define ___________________LOWER_R2____________________ XXXXXXX , KC_4    , KC_5    , KC_6    , KC_DOT
#define ___________________LOWER_R3__________           XXXXXXX , KC_1    , KC_2    , KC_3    
#define ____LOWER_R4_____                               RAI_SPC , MED_0

#define ___________________RAISE_L1__________           XXXXXXX , KC_F9   , KC_F8   , KC_F7   
#define ___________________RAISE_L2____________________ XXXXXXX , KC_F6   , KC_F5   , KC_F4   , XXXXXXX
#define           _________RAISE_L3____________________           KC_F3   , KC_F2   , KC_F1   , XXXXXXX
#define                               ____RAISE_L4_____                               QK_REP  , SYM_SPC

#define           _________RAISE_R1____________________           TD_COLN , TD_EQL  , TD_HASH , XXXXXXX
#define ___________________RAISE_R2____________________ XXXXXXX , TD_MINS , TD_PLUS , TD_SLSH , COD_AST
#define ___________________RAISE_R3__________           XXXXXXX , TD_EXLM , TD_LT   , TD_GT     
#define ____RAISE_R4_____                               _______ , TG_NUM

#define ___________________NUMPAD_L1_________           XXXXXXX , KC_ESC  , OM_BTN1 , OM_BTN2  
#define ___________________NUMPAD_L2___________________ XXXXXXX , OM_L    , OM_U    , OM_R    , XXXXXXX
#define           _________NUMPAD_L3___________________           OM_W_D  , OM_D    , OM_W_U  , XXXXXXX
#define                               ____NUMPAD_L4____                               NAV_REP , _______

#define           _________NUMPAD_R1___________________           KC_7    , KC_8    , KC_9    , XXXXXXX
#define ___________________NUMPAD_R2___________________ XXXXXXX , KC_4    , KC_5    , KC_6    , SHO_DOT
#define ___________________NUMPAD_R3_________           XXXXXXX , KC_1    , KC_2    , KC_3    
#define ____NUMPAD_R4____                               RAI_SPC , MED_0

#define ________________SHORTCUTS_L1_________           XXXXXXX , MC_CLOS , MC_Z0R  , MC_PREV 
#define ________________SHORTCUTS_L2___________________ MO_SYS  , SF_MODM , MC_MODP , MC_TABS , XXXXXXX
#define           ______SHORTCUTS_L3___________________           MC_SWLE , MC_SWRI , MC_CALC , XXXXXXX
#define                               _SHORTCUTS_L4____                               NAV_COD , TT_NMO

#define           ______SHORTCUTS_R1___________________           MC_SELW , MC_ENT  , MC_ESC  , XXXXXXX
#define ________________SHORTCUTS_R2___________________ XXXXXXX , MC_SELL , KC_DOWN , SF_UP   , MO_SYS
#define ________________SHORTCUTS_R3_________           XXXXXXX , MC_JOIN , TD_MACR , SLE_LOC
#define _SHORTCUTS_R4____                               COD_SPC , TT_NAV

#define ___________________CODING_L1_________           XXXXXXX , MC_CLOS , MC_BREK , MC_BUID 
#define ___________________CODING_L2___________________ MC_PROJ , SF_FSYM , MC_RUN  , MC_DBUG , XXXXXXX
#define           _________CODING_L3___________________           MC_RECE , MC_SWAP , MC_FIUS , XXXXXXX
#define                               ____CODING_L4____                               NAV_STI , MC_STOV

#define           _________CODING_R1___________________           MC_AUCO , MC_ENT  , MC_ESC  , XXXXXXX
#define ___________________CODING_R2___________________ XXXXXXX , MC_QUIK , MC_DOWN , SF_UP   , XXXXXXX
#define ___________________CODING_R3_________           XXXXXXX , MC_QDOC , MC_REFC , MC_COMT 
#define ____CODING_R4____                               _______ , _______

#define ___________________NOMOD_L1__________           KC_Q    , KC_B    , KC_M    , KC_G    
#define ___________________NOMOD_L2____________________ KC_D    , KC_N    , KC_S    , KC_T    , KC_W
#define           _________NOMOD_L3____________________           KC_F    , KC_C    , KC_P    , KC_V
#define                               ____NOMOD_L4_____                               QK_REP  , _______

#define           _________NOMOD_R1____________________           KC_L    , KC_O    , KC_U    , KC_Y
#define ___________________NOMOD_R2____________________ KC_Z    , KC_R    , KC_A    , KC_E    , KC_I
#define ___________________NOMOD_R3__________           KC_J    , KC_H    , KC_COMM , KC_DOT  
#define ____NOMOD_R4_____                               OSL_A2  , OS_LSFT

#define ___________________ALPHA2_L1_________           XXXXXXX , KC_Q    , MC_QU   , KC_K
#define ___________________ALPHA2_L2___________________ KC_Y    , KC_Z    , KC_X    , KC_W    , XXXXXXX
#define           _________ALPHA2_L3___________________           KC_J    , MC_SQ_C , KC_V    , XXXXXXX 
#define                               ____ALPHA2_L4____                               NAV_MAG , OS_SYM

#define           _________ALPHA2_R1___________________           MC_CR_O , MC_SQ_O , MC_SQ_U , XXXXXXX
#define ___________________ALPHA2_R2___________________ XXXXXXX , MC_TL_A , MC_SQ_A , MC_SQ_E , MC_SQ_I
#define ___________________ALPHA2_R3_________           XXXXXXX , MC_TL_O , MC_CR_A , MC_CR_E 
#define ____ALPHA2_R4____                               _______ , MC_SQUO

#define _________________SYMBOLS_L1__________           XXXXXXX , KC_LCBR , KC_RCBR , KC_DLR 
#define _________________SYMBOLS_L2____________________ KC_AT   , KC_LPRN , KC_RPRN , MC_DQUO , XXXXXXX
#define           _______SYMBOLS_L3____________________           KC_LBRC , KC_RBRC , KC_QUES , XXXXXXX
#define                               __SYMBOLS_L4_____                               KC_CAPS , KC_SPC 

#define           _______SYMBOLS_R1____________________           KC_COLN , KC_EQL  , KC_HASH , XXXXXXX
#define _________________SYMBOLS_R2____________________ XXXXXXX , KC_MINS , KC_PLUS , KC_SLSH , KC_ASTR
#define _________________SYMBOLS_R3__________           XXXXXXX , KC_EXLM , KC_LT   , KC_GT     
#define __SYMBOLS_R4_____                               KC_SPC  , TG_NUM

#define ___________________NAVIGATION_L1_____           XXXXXXX , MC_ESC  , KC_PGUP , KC_INS 
#define ___________________NAVIGATION_L2_______________ XXXXXXX , KC_LSFT , KC_LCTL , KC_LGUI , XXXXXXX
#define           _________NAVIGATION_L3_______________           KC_RALT , KC_PGDN , KC_LALT , XXXXXXX
#define                               __NAVIGATION_L4__                               _______ , _______
#define                               __FIXED_NAV__L4__                               _______ , KC_SPC

#define           _________NAVIGATION_R1_______________           KC_TAB  , KC_ENT  , MC_DELW , XXXXXXX
#define ___________________NAVIGATION_R2_______________ XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_____           XXXXXXX , KC_DEL  , KC_HOME , KC_END  
#define __NAVIGATION_R4__                               KC_SPC  , MED_CAS
#define __FIXED_NAV__R4__                               KC_SPC  , TO_A1

#define ___________________MEDIA_L1__________           XXXXXXX , KC_ESC  , OM_BTN1 , OM_BTN2  
#define ___________________MEDIA_L2____________________ XXXXXXX , OM_L    , OM_U    , OM_R    , XXXXXXX 
#define           _________MEDIA_L3____________________           OM_W_D  , OM_D    , OM_W_U  , XXXXXXX 
#define                               ____MEDIA_L4_____                               FNA_REP , _______

#define           _________MEDIA_R1____________________           KC_TAB  , KC_ENT  , KC_BSPC , XXXXXXX
#define ___________________MEDIA_R2____________________ XXXXXXX , MC_MIC  , KC_VOLD , KC_VOLU , MC_CAM
#define ___________________MEDIA_R3__________           XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT 
#define ____MEDIA_R4_____                               _______ , _______

#define _______________________LOCK____L1____           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define _______________________LOCK____L2______________ _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define           _____________LOCK____L3______________           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define                               ______LOCK____L4_                               XXXXXXX , XXXXXXX

#define           _____________LOCK____R1______________           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define _______________________LOCK____R2______________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______
#define _______________________LOCK____R3____           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define ______LOCK____R4_                               XXXXXXX , XXXXXXX

#define ______________________SYSTEM___L1____           XXXXXXX , RGB_VAD , RGB_VAI , EE_CLR
#define ______________________SYSTEM___L2______________ XXXXXXX , RGB_HUD , RGB_HUI , QK_BOOT , XXXXXXX
#define           ____________SYSTEM___L3______________           RGB_SAD , RGB_SAI , RGB_TOG , XXXXXXX
#define                               _____SYSTEM___L4_                               XXXXXXX , XXXXXXX

#define           ____________SYSTEM___R1______________           EE_CLR  , TG_WIN  , KC_NUM  , XXXXXXX
#define ______________________SYSTEM___R2______________ XXXXXXX , QK_BOOT , TG_MAC  , TG_LOCK , XXXXXXX
#define ______________________SYSTEM___R3____           XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX 
#define _____SYSTEM___R4_                               XXXXXXX , XXXXXXX

// clang-format on