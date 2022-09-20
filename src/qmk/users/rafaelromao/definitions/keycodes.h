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
    COM_MAC, 
    DOT_DOT, 
    DLR_CUR, 
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
#define TD_COMM TD(COM_MAC)
#define TD_DOT TD(DOT_DOT)
#define TD_DLR TD(DLR_CUR)

// Custom keycodes

enum {
    CUSTOM_KEYCODE_START = SAFE_RANGE,

    MC_SECRET_1, 

    MC_REFC, MC_QUIK, MC_PROJ, 
    MC_SEEV, MC_RUAN, MC_BUID, MC_COMP,
    MC_AUCO, MC_NEER, MC_FIUS,
    MC_SELW, MC_SWLE, MC_SWRI, 
    MC_SELL, MC_REFI, MC_REF,
    MC_JOIN, MC_COMT, MC_VIMR,
    MC_SENT, MC_CUR,
    
    MC_CAPS, MC_WORD, MC_CAML, MC_SNAK, MC_KBAB,

    TG_MAC, TG_WIN, 
    SP_CAP, SP_MOD, SP_NG, SP_ALT,

    STR_MACRO_START,

    MC_BTIC, MC_DQUO, MC_SQUO,
    MC_CIRC, MC_TILD, MC_DEG, MC_DAND, MC_DPIP,

    MC_GV_A, MC_CR_A, MC_TL_A, MC_SQ_A,
    MC_SQ_U, MC_CR_O, MC_SQ_O, MC_SQ_I,
    MC_CR_E, MC_TL_O, MC_SQ_C, MC_SQ_E,

    MC_QU,  MC_LH,  MC_PH,  
    MC_CH,  MC_TH,  MC_WH, 
    MC_GH,  MC_NH,  MC_SH,
    MC_I,   MC_NT,  MC_BY,
    MC_CK,  MC_ING, 

    MC_AO, MC_CAO, MC_OES, MC_COES,
    
    STR_MACRO_END,

    CUSTOM_KEYCODE_END
};

// Mod-taps

#define LSFTT_N LSFT_T(KC_N)
#define RSFTT_E RSFT_T(KC_E)
#define SF_SE LSFT_T(MC_SEEV)
#define SF_F6 LSFT_T(KC_F6)
#define SF_6 RSFT_T(KC_6)

#define LCTLT_S LCTL_T(KC_S)
#define RCTLT_A RCTL_T(KC_A)
#define CT_F5 LCTL_T(KC_F5)
#define CT_5 RCTL_T(KC_5)

#define LALTT_T LALT_T(KC_T)
#define RALTT_R RALT_T(KC_R)
#define AL_F4 LALT_T(KC_F4)
#define AL_4 RALT_T(KC_4)

#define LGUIT_P LGUI_T(KC_P)
#define RGUIT_M RGUI_T(KC_M)
#define GU_F1 LGUI_T(KC_F1)
#define GU_1 RGUI_T(KC_1)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

// Layer-taps

#define MED_SFT LT(_MEDIA, SP_CAP)
#define MED_0   LT(_MEDIA, KC_0)

#define NAV_NG  LT(_NAVIGATION, SP_NG)
#define MAI_MOD LT(_MAINTENANCE, SP_MOD)
#define MAI_ALT LT(_MAINTENANCE, SP_ALT)
#define MED_ALT LT(_MEDIA, SP_ALT)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_BSP LT(_RAISE, KC_BSPC)
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define RAI_SPC LT(_RAISE, KC_SPC)

#define KCL_MAC LT(_MACROS, KC_L)
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

#define MC_MODP LGUI(KC_PLUS)
#define MC_MODM LGUI(KC_MINS)
#define MC_SELC LGUI(KC_A)
#define MC_SAVE LGUI(KC_S)
#define MC_UNDO LGUI(KC_Z)
#define MC_COPY LGUI(KC_C)
#define MC_PAST LGUI(KC_V)
#define MC_LOCK LGUI(LCTL(KC_Q))
#define MC_FULL LGUI(LCTL(KC_F))
#define MC_FIND LGUI(KC_F)

uint16_t extract_base_tapping_keycode(uint16_t keycode);
bool is_key_on_tap(uint16_t keycode);
bool start_long_press(keyrecord_t *record);
bool is_long_press(void);

// clang-format on