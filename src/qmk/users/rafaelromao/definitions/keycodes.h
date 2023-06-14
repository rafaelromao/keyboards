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
    NOT_SWI, 
    AND_EAN, 
    REC_MAC, 
    COM_LEA, 
    DOT_DOT, 
    DLR_CUR, 
    COL_ECO,
    TIL_DEG,
    SLS_BSL,
    QUE_EXC,
    EQL_EEQ,
    PLU_RET,
    LET_ELT,
    GRT_EGT,
    OR_EOR,
    SAR_ESA,
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
#define TD_NOT TD(NOT_SWI)
#define TD_AND TD(AND_EAN)
#define TD_MACR TD(REC_MAC)
#define TD_COMM TD(COM_LEA)
#define TD_DOT TD(DOT_DOT)
#define TD_DLR TD(DLR_CUR)
#define TD_COLN TD(COL_ECO)
#define TD_TILD TD(TIL_DEG)
#define TD_QUES TD(QUE_EXC)
#define TD_SLSH TD(SLS_BSL)
#define TD_EQL TD(EQL_EEQ)
#define TD_PLUS TD(PLU_RET)
#define TD_LT TD(LET_ELT)
#define TD_GT TD(GRT_EGT)
#define TD_OR TD(OR_EOR)
#define TD_SARR TD(SAR_ESA)

// Custom keycodes

enum {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    MC_SECRET_1, 

    // Toggle codes
    OS_ACNT, TG_MAC, TG_WIN, TG_CASE, TG_ACNT, REPEAT,

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
    MC_QUIK, MC_AUCO, 
    MC_QDOC, MC_FSYM, MC_RUN, MC_DBUG, MC_BUID,
    MC_PROJ, MC_RECE, MC_COMP, MC_FIUS, MC_REFC,
    MC_JOIN, MC_COMT, 

    // Begin macros used to write text
    STR_MACRO_START,
    
    MC_BTIC, MC_DQUO, MC_SQUO, MC_CIRC, MC_TILD,
    MC_ENT, MC_TAB, MC_ESC, MC_ESCC, MC_NSEN, 
    MC_ESAV, MC_SENT, MC_CUR, MC_SAR, MC_DEQ, MC_NEQ, 
    MC_DAND, MC_DPIP, MC_OESC, MC_SOES, MC_LTGT, 

    // End macros that can be shifted
    SFT_MACRO_END,

    // Accented letters
    MC_GV_A, MC_CR_A, MC_TL_A, MC_SQ_A,
    MC_SQ_U, MC_CR_O, MC_SQ_O, MC_SQ_I,
    MC_CR_E, MC_TL_O, MC_SQ_C, MC_SQ_E,
    MC_AE, MC_AO, MC_OE, MC_CAO, MC_COES, MC_QU, 
    
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
#define LALTT_H LALT_T(KC_H)
#define RALTT_F RALT_T(KC_F)
#define AL_F1 LALT_T(KC_F1)
#define AL_1 LALT_T(KC_1)
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

// Layer-taps

#define NAV_CAS LT(_NAVIGATION, TG_CASE)
#define NAV_F12 LT(_NAVIGATION, KC_F12)
#define NAV_AT  LT(_NAVIGATION, KC_AT)
#define NAV_PRJ LT(_NAVIGATION, MC_PROJ)
#define NAV_MUT LT(_NAVIGATION, KC_MUTE)

#define MED_CAS LT(_MEDIA, TG_CASE)
#define MED_0   LT(_MEDIA, KC_0)

#define MAI_CAS LT(_MAINTENANCE, TG_CASE)

#define ACT_SPC LT(_ACCENT, KC_SPC)
#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_TAC LT(_RAISE, TG_ACNT)
#define RAI_SPC LT(_RAISE, KC_SPC)
#define RAI_ACT OSL(_ACCENT)

#define MAC_KCD LT(_MACROS, KC_D)
#define MAC_KCI LT(_MACROS, KC_I)
#define MAC_DOT LT(_MACROS, KC_DOT)

// Layer transitions
#define MO_MED MO(_MEDIA)
#define TO_ROM TO(_ROMAK)
#define TG_NUM TG(_NUMPAD)
#define TG_NAV TG(_FIXED_NAV)
#define TG_LOCK TG(_LOCK)

// Custom Shortcuts

#define HYPR_D HYPR(KC_D)
#define HYPR_R HYPR(KC_R)
#define HYPR_W HYPR(KC_W)
#define HYPR_G HYPR(KC_G)
#define HYPR_V HYPR(KC_V)
#define HYPR_C HYPR(KC_C)
#define HYPR_L HYPR(KC_L)
#define MEH_D  MEH(KC_D)
#define MEH_W  MEH(KC_W)
#define MEH_G  MEH(KC_G)
#define MEH_V  MEH(KC_V)
#define MEH_C  MEH(KC_C)
#define MEH_L  MEH(KC_L)

uint16_t extract_base_tapping_keycode(uint16_t keycode);
bool is_key_on_tap(uint16_t keycode);
bool is_shift_macro_keycode(uint16_t keycode);

// clang-format on