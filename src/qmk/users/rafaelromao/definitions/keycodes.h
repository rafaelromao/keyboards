#pragma once

#include "layers.h"

// clang-format off

// Tap dance codes

enum { 
    TD_CODE_START, 
    ENT_END, 
    SCL_END, 
    BRT_LCR, 
    BRT_RCR, 
    BRT_PAR, 
    BRT_OPA, 
    BRT_CPA, 
    BRT_OBR, 
    BRT_CBR, 
    DQU_FIN, 
    SQU_STR, 
    NOT_SWI, 
    AND_BOO, 
    REC_MAC, 
    COM_LEA, 
    DOT_DOT, 
    DLR_CUR, 
    COL_DEG,
    TIL_CIR,
    TD_CODE_END 
};

// Tap dance keycodes

#define TD_EENT TD(ENT_END)
#define TD_SCLE TD(SCL_END)
#define TD_LCRB TD(BRT_LCR)
#define TD_RCRB TD(BRT_RCR)
#define TD_PARN TD(BRT_PAR)
#define TD_OPAR TD(BRT_OPA)
#define TD_CPAR TD(BRT_CPA)
#define TD_OBR TD(BRT_OBR)
#define TD_CBR TD(BRT_CBR)
#define TD_DQUO TD(DQU_FIN)
#define TD_SQUO TD(SQU_STR)
#define TD_NOT TD(NOT_SWI)
#define TD_AND TD(AND_BOO)
#define TD_MACR TD(REC_MAC)
#define TD_COMM TD(COM_LEA)
#define TD_DOT TD(DOT_DOT)
#define TD_DLR TD(DLR_CUR)
#define TD_COLN TD(COL_DEG)
#define TD_TILD TD(TIL_CIR)

// Custom keycodes

enum {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    MC_SECRET_1, 

    // Toggle codes
    TG_MAC, TG_WIN, TG_CASE, OS_ACNT, 

    // Select Word/Line
    MC_SELW, MC_SELL, 
    
    // Swapper
    MC_MODP, MC_MODM, MC_SWLE, MC_SWRI, 
    
    // Begin macros that can be shifted
    SFT_MACRO_START,

    // Common shortcuts
    MC_SELC, MC_SAVE, MC_UNDO, MC_COPY, MC_CTAB, 
    MC_PAST, MC_LOCK, MC_FULL, MC_FIND, MC_REF,

    // IDE shortcuts
    MC_QUIK, MC_AUCO, 
    MC_QDOC, MC_FSYM, MC_RUN, MC_DBUG, MC_BUID,
    MC_PROJ, MC_RECE, MC_COMP, MC_FIUS, MC_REFC,
    MC_JOIN, MC_COMT, 

    // Begir macros used to write text
    STR_MACRO_START,
    
    MC_UNDS, MC_ENT, MC_TAB, MC_ESC, 
    MC_ESAV, MC_SENT, MC_CUR,  
    MC_DAND, MC_DPIP, 

    // End macros that can be shifted
    SFT_MACRO_END,

    // Accented letters
    MC_BTIC, MC_DQUO, MC_SQUO, 
    MC_GV_A, MC_CR_A, MC_TL_A, MC_SQ_A,
    MC_SQ_U, MC_CR_O, MC_SQ_O, MC_SQ_I,
    MC_CR_E, MC_TL_O, MC_SQ_C, MC_SQ_E,
    MC_AO, MC_CAO, MC_OES, MC_COES,
    
    // End macros used to write text
    STR_MACRO_END,

    CUSTOM_KEYCODE_END
};

// Mod-taps

#define LSFTT_N LSFT_T(KC_N)
#define RSFTT_E RSFT_T(KC_E)
#define SF_FSYM LSFT_T(MC_FSYM)
#define SF_MODP RSFT_T(MC_MODP)
#define SF_F6 LSFT_T(KC_F6)
#define SF_6 RSFT_T(KC_6)

#define LCTLT_S LCTL_T(KC_S)
#define RCTLT_A RCTL_T(KC_A)
#define CT_F5 LCTL_T(KC_F5)
#define CT_5 RCTL_T(KC_5)

#define LALTT_P LALT_T(KC_P)
#define LALTT_M LALT_T(KC_M)
#define RALTT_Q RALT_T(KC_Q)
#define RALTT_Y RALT_T(KC_Y)
#define AL_F1 LALT_T(KC_F1)
#define AL_1 LALT_T(KC_1)
#define AL_F14 RALT_T(KC_F14)
#define AL_COMM RALT_T(KC_COMM)

#define LGUIT_T LGUI_T(KC_T)
#define RGUIT_H RGUI_T(KC_H)
#define GU_F4 LGUI_T(KC_F4)
#define GU_4 RGUI_T(KC_4)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)

// Layer-taps

#define NAV_ACT  LT(_NAVIGATION, OS_ACNT)

#define MED_CAS LT(_MEDIA, TG_CASE)
#define MED_0   LT(_MEDIA, KC_0)

#define MAI_ACT LT(_MAINTENANCE, OS_ACNT)
#define MAI_CAS LT(_MAINTENANCE, TG_CASE)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_BSP LT(_RAISE, KC_BSPC)
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define RAI_SPC LT(_RAISE, KC_SPC)

#define KCR_MAC LT(_MACROS, KC_R)
#define KCI_MAC LT(_MACROS, KC_I)
#define DOT_MAC LT(_MACROS, KC_DOT)

// Layer transitions
#define OS_LOW OSL(_LOWER)
#define OS_RAI OSL(_RAISE)
#define MO_MED MO(_MEDIA)
#define TO_ROM TO(_ROMAK)
#define TG_NUM TG(_NUMPAD)
#define TG_NAV TG(_FIXED_NAV)
#define TG_LOCK TG(_LOCK)

// Custom Shortcuts

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

uint16_t extract_base_tapping_keycode(uint16_t keycode);
bool is_key_on_tap(uint16_t keycode);

// clang-format on