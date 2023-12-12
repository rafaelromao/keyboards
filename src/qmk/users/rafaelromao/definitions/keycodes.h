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
    COM_LEA, 
    DOT_DOT, 
    MIN_CIR, 
    COL_ECO,
    PER_DEG,
    SLS_BSL,
    QUE_EXC,
    EQL_EEQ,
    PLU_DOL,
    TIL_LTE,
    DOR_GTE,
    CIR_SAR,
    DAN_DAR,
    HAS_SEC,
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
#define TD_COMM TD(COM_LEA)
#define TD_DOT TD(DOT_DOT)
#define TD_MINS TD(MIN_CIR)
#define TD_COLN TD(COL_ECO)
#define TD_PERC TD(PER_DEG)
#define TD_QUES TD(QUE_EXC)
#define TD_SLSH TD(SLS_BSL)
#define TD_EQL TD(EQL_EEQ)
#define TD_PLUS TD(PLU_DOL)
#define TD_TIL TD(TIL_LTE)
#define TD_DOR TD(DOR_GTE)
#define TD_CIRC TD(CIR_SAR)
#define TD_DAND TD(DAN_DAR)
#define TD_HASH TD(HAS_SEC)

// Custom keycodes

enum {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    MC_SECRET_1,

    // Toggle codes
    OS_ACNT, TG_OS, TG_CASE, TG_ACNT, TG_CAPS,

    // Select Word/Line
    MC_SELW, MC_SELL,
    
    // Swapper
    MC_MODP, MC_MODM, MC_SWLE, MC_SWRI, 
    
    // Begin macros that can be shifted
    SFT_MACRO_START,

    // Common shortcuts
    MC_SELC, MC_SAVE, MC_UNDO, MC_COPY, MC_SCOP, MC_CLOS, 
    MC_PAST, MC_SPAS, MC_LOCK, MC_FULL, MC_FIND, MC_Z0R,

    // IDE shortcuts
    MC_QUIK, MC_AUCO, MC_COMT, MC_JOIN, 
    MC_QDOC, MC_FSYM, MC_RUN, MC_DBUG, MC_BUID,
    MC_PROJ, MC_RECE, MC_COMP, MC_FIUS, MC_REFC,

    // Begin macros used to write text
    STR_MACRO_START,

    MC_BTIC, MC_DQUO, MC_SQUO, MC_CIRC, MC_TILD, REPEAT,
    MC_EUR, MC_LTE, MC_GTE, MC_DDS, MC_ENT, MC_TAB, MC_ESC, MC_ESCC, 
    MC_NSEN, MC_CANC, TG_NUMC, MC_EXLM, MC_QUES, MC_ESAV, MC_SENT, 
    MC_CUR, MC_CURS, MC_DAR, MC_SAR, MC_DEQ, MC_NEQ, MC_BRAC,
    MC_DAND, MC_DPIP, MC_OESC, MC_SOES, MC_TISL, MC_SVI, MC_CVI, MC_ESCP,

    // End macros that can be shifted
    SFT_MACRO_END,

    // Start macros for accented letters
    ALPHA_MACRO_START,

    MC_GV_A, MC_CR_A, MC_TL_A, MC_SQ_A,
    MC_SQ_U, MC_CR_O, MC_SQ_O, MC_SQ_I,
    MC_CR_E, MC_TL_O, MC_SQ_C, MC_SQ_E,
    MC_AO, MC_OE, MC_CAO, MC_COES, MC_QU, MC_ZZ,

    // End macros for accented letters
    ALPHA_MACRO_END,
    
    // End macros used to write text
    STR_MACRO_END,

    CUSTOM_KEYCODE_END
};

// Custom hold-taps

#define TH_QUOT LT(MC_DQUO, MC_SQUO) // Intercepted for both tap and hold

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
#define RALTT_H RALT_T(KC_H)
#define RALTT_F RALT_T(KC_F)
#define AL_F1 LALT_T(KC_F1)
#define AL_1 RALT_T(KC_1)
#define AL_F3 RALT_T(KC_F3)

#define LGUIT_T LGUI_T(KC_T)
#define RGUIT_R RGUI_T(KC_R)
#define GU_F4 LGUI_T(KC_F4)
#define GU_4 RGUI_T(KC_4)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)

// Custom Shortcuts

#define HYPR_D HYPR(KC_D)
#define HYPR_R HYPR(KC_R)
#define HYPR_G HYPR(KC_G)
#define HYPR_C HYPR(KC_C)
#define HYPR_L HYPR(KC_L)
#define HYPR_M HYPR(KC_M)
#define MEH_D  MEH(KC_D)
#define MEH_G  MEH(KC_G)
#define MEH_C  MEH(KC_C)
#define MEH_M  MEH(KC_M)

// Layer-taps

#define NAV_REP LT(_NAVIGATION, QK_REP)
#define NAV_F12 LT(_NAVIGATION, KC_F12)
#define NAV_AT  LT(_NAVIGATION, KC_AT)
#define NAV_PRJ LT(_NAVIGATION, MC_PROJ)
#define NAV_CAS LT(_NAVIGATION, TG_CASE)
#define NAV_CAN LT(_NAVIGATION, MC_CANC)

#define MED_CAS LT(_MEDIA, TG_CASE)
#define MED_A1  LT(_MEDIA, TO_A1)
#define MED_0   LT(_MEDIA, KC_0)

#define MAI_CAS LT(_SYSTEM, TG_CASE)

#define NMO_DOC LT(_NOMOD, MC_QDOC)
#define ACT_SPC LT(_FIXED_ALPHA2, KC_SPC)
#define LOW_SPC LT(_LOWER, KC_SPC)
#define LOW_NSE LT(_LOWER, MC_NSEN)
#define RAI_TA2 LT(_RAISE, TG_ACNT)
#define RAI_SPC LT(_RAISE, KC_SPC)
#define SYM_SPC LT(_SYMBOLS, KC_SPC)
#define RAI_A2  OSL(_ALPHA2) // Hold behavior is implemented in intercepted code

#define SHO_KCD LT(_SHORTCUTS, KC_D)
#define SHO_KCI LT(_SHORTCUTS, KC_I)
#define SHO_DOT LT(_SHORTCUTS, KC_DOT)

// Layer transitions
#define MO_A2   MO(_FIXED_ALPHA2)
#define MO_MED  MO(_MEDIA)
#define TO_A1   TO(_ALPHA1)
#define TT_NAV  TT(_FIXED_NAV)
#define TG_LOCK TG(_LOCK)
#define TG_NUM  TG(_NUMPAD)
#define OS_SYM  OSL(_SYMBOLS)

uint16_t extract_tapping_keycode(uint16_t keycode);
bool is_string_macro_keycode(uint16_t keycode);
bool is_shift_macro_keycode(uint16_t keycode);

// clang-format on