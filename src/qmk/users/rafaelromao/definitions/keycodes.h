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
    DQU_SQU, 
    EXL_EEX, 
    LET_EUR, 
    GRT_PIP,
#ifdef DYNAMIC_MACRO_ENABLE
    REC_MAC, 
#endif
    DOT_DOT, 
    LEA_COM,
    MIN_CIR, 
    COL_ECO,
    HAS_PER,
    SLS_BSL,
    QUE_EXC,
    EQL_EEQ,
    PLU_DOL,
    TIL_LTE,
    DOR_GTE,
    CIR_SAR,
    DAN_DAR,
    DLR_BSL,
    TD_CODE_END 
};

// Tap dance keycodes

#define TD_EENT TD(ENT_END)
#define TD_SCLE TD(SCL_END)
#define TD_LCBR TD(BRT_LCR)
#define TD_RCBR TD(BRT_RCR)
#define TD_PARN TD(BRT_PAR)
#define TD_LPRN TD(BRT_OPA)
#define TD_RPRN TD(BRT_CPA)
#define TD_LBRC TD(BRT_OBR)
#define TD_RBRC TD(BRT_CBR)
#define TD_DQUO TD(DQU_SQU)
#define TD_EXLM TD(EXL_EEX)
#define TD_LT TD(LET_EUR)
#define TD_GT TD(GRT_PIP)
#ifdef DYNAMIC_MACRO_ENABLE
#define TD_MACR TD(REC_MAC)
#else
#define TD_MACR XXXXXXX
#endif
#define TD_DOT TD(DOT_DOT)
#define TD_COMM TD(LEA_COM)
#define TD_MINS TD(MIN_CIR)
#define TD_COLN TD(COL_ECO)
#define TD_HASH TD(HAS_PER)
#define TD_QUES TD(QUE_EXC)
#define TD_SLSH TD(SLS_BSL)
#define TD_EQL TD(EQL_EEQ)
#define TD_PLUS TD(PLU_DOL)
#define TD_TIL TD(TIL_LTE)
#define TD_DOR TD(DOR_GTE)
#define TD_CIRC TD(CIR_SAR)
#define TD_DAND TD(DAN_DAR)
#define TD_DLR TD(DLR_BSL)

// Custom keycodes

enum {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    MC_SECRET_1,

    // Toggle codes
    OS_ACNT, TG_WIN, TG_MAC, TG_CASE, TG_ACNT, 

    // Select Word/Line
    MC_SELW, MC_SELL,
    
    // Swapper
    MC_MODP, MC_MODM, MC_SWLE, MC_SWRI, 
    
    // Begin macros that can be shifted
    SFT_MACRO_START,

    // Common shortcuts
    MC_SELC, MC_SAVE, MC_UNDO, MC_COPY, MC_SCOP, MC_CLOS, 
    MC_PAST, MC_SPAS, MC_LOCK, MC_FULL, MC_FIND, MC_Z0R,

    // App Shortcuts
    MC_PREV, MC_TABS, MC_CALC, MC_MIC, MC_CAM,

    // IDE shortcuts
    MC_QUIK, MC_AUCO, MC_COMT, MC_STIN, MC_STOV, MC_DOWN,
    MC_QDOC, MC_FSYM, MC_RUN, MC_DBUG, MC_BUID, MC_BREK,
    MC_PROJ, MC_RECE, MC_SWAP, MC_FIUS, MC_REFC, 

    // Begin macros used to write text
    STR_MACRO_START,

    MC_NG, MC_EY, MC_HY, MC_OU, MC_COM, MC_AO, MC_ES, MC_OES, MC_FIX_I,
    MC_BTIC, MC_DQUO, MC_SQUO, MC_CIRC, MC_TILD, MC_ORDO, MC_ORDA,
    MC_EUR, MC_LTE, MC_GTE, MC_DDS, MC_ENT, MC_TAB, MC_ESC, MC_ESCC, 
    TG_NUMC, MC_EXLM, MC_QUES, MC_ESAV, MC_SENT, MC_DEG, MC_DELW, 
    MC_CUR, MC_CURS, MC_DAR, MC_SAR, MC_DEQ, MC_NEQ, MC_BRAC, MC_SEC, 
    MC_DAND, MC_DPIP, MC_OESC, MC_SOES, MC_TISL, MC_SVI, MC_CVI, MC_0P,
    REPEAT, MC_JOIN, 

    // End macros that can be shifted
    SFT_MACRO_END,

    // Start macros for accented letters
    ACCENT_MACRO_START,

    MC_GV_A, MC_CR_A, MC_SQ_A, MC_QU,
    MC_SQ_U, MC_CR_O, MC_SQ_O, MC_SQ_I,
    MC_CR_E, MC_SQ_C, MC_SQ_E, MC_TL_A, MC_TL_O,

    // End macros for accented letters
    ACCENT_MACRO_END,
    
    // End macros used to write text
    STR_MACRO_END,

#ifndef MOUSE_ENABLE
    OM_U,
    OM_D,
    OM_L,
    OM_R,
    OM_BTNS,
    OM_HLDS,
    OM_RELS,
    OM_W_U,
    OM_W_D,
    OM_BTN1,
    OM_BTN2,
#endif

    CUSTOM_KEYCODE_END
};

// Mod-taps

#define LSFTT_N LSFT_T(KC_N)
#define RSFTT_E RSFT_T(KC_E)
#define SF_FSYM LSFT_T(MC_FSYM)
#define SF_MODM RSFT_T(MC_MODM)
#define SF_UP RSFT_T(KC_UP)

#define LCTLT_S LCTL_T(KC_S)
#define RCTLT_A RCTL_T(KC_A)

#define LALTT_P LALT_T(KC_P)
#define RALTT_H RALT_T(KC_H)
#define RALTT_F RALT_T(KC_F)

#define LGUIT_T LGUI_T(KC_T)
#define RGUIT_R RGUI_T(KC_R)

#define HYP_KCJ HYPR_T(KC_J)
#define HYP_KCV HYPR_T(KC_V)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)

// Layer-taps

#define NAV_F12 LT(_NAVIGATION, KC_F12)
#define NAV_AT  LT(_NAVIGATION, KC_AT)
#define NAV_CAS LT(_NAVIGATION, TG_CASE)
#define NAV_STI LT(_NAVIGATION, MC_STIN) // Hold behavior is implemented in intercepted code
#define NAV_FCA LT(_FIXED_NAV, TG_CASE)

#define MED_CAS LT(_MEDIA, TG_CASE)
#define MED_0   LT(_MEDIA, KC_0)

#define NAV_COD LT(_NAVIGATION, _CODING)
#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_TA2 LT(_RAISE, TG_ACNT)
#define RAI_SPC LT(_RAISE, KC_SPC)
#define SYM_SPC LT(_SYMBOLS, KC_SPC)
#define LEA_KCC LT(_SYMBOLS, KC_C) // Hold behavior is implemented in intercepted code
#define RAI_A2  OSL(_ALPHA2) // Hold behavior is implemented in intercepted code
#define OSL_A2  OSL(_FIXED_ALPHA2) // We need the fixed alpha to distinguish from the intercepted RAI_A2
#define SLE_LOC LT(_FIXED_NAV, _FIXED_ALPHA2) // Hold and tap are implemented in intercepted code

#define SHO_KCD LT(_SHORTCUTS, KC_D)
#define SHO_KCI LT(_SHORTCUTS, KC_I)
#define SHO_DOT LT(_SHORTCUTS, KC_DOT)
#define COD_SPC LT(_CODING, KC_SPC)
#define COD_AST LT(_CODING, KC_ASTR)

// Layer transitions
#define MO_MED  MO(_MEDIA)
#define MO_SYS  MO(_SYSTEM)
#define TO_A1   TO(_ALPHA1)
#define TT_NAV  TT(_FIXED_NAV)
#define TT_NMO  TT(_NOMOD)
#define TG_LOCK TG(_LOCK)
#define TG_NUM  TG(_NUMPAD)
#define OS_SYM  OSL(_SYMBOLS)

uint16_t extract_tapping_keycode(uint16_t keycode);
bool is_string_macro_keycode(uint16_t keycode);
bool is_shift_macro_keycode(uint16_t keycode);
bool is_accent_macro_keycode(uint16_t keycode);

// clang-format on