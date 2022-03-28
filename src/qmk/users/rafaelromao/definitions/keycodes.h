#pragma once

#include "layers.h"

// Custom keycodes

enum {
    SS_SECRET_1 = SAFE_RANGE,
    SS_SECRET_2, SS_SECRET_3,

    SS_BTIC, SS_DQUO, SS_SQUO,
    SS_CIRC, SS_TILD, SS_DEG,

    TG_MAC, TG_WIN, TG_LIN,

    SP_CAP, SP_MOD, SP_NG, SP_ALT,

    SS_MODP, SS_MODM,

    SS_GV_A, SS_CR_A, SS_TL_A, SS_SQ_A,
    SS_SQ_U, SS_CR_O, SS_SQ_O, SS_SQ_I,
    SS_CR_E, SS_TL_O, SS_SQ_C, SS_SQ_E,

    SS_SELW, SS_SWIN, SS_CAPS,

    SS_RS,  SS_RE,  SS_PH,  SS_LH,  SS_CK,
    SS_CH,  SS_SH,  SS_HE,  SS_NH,  SS_GH,
    SS_WH,  SS_SR,  SS_ER,  SS_TH,  SS_ING, SS_IO,

    SS_SPA, SS_OCP, SS_SCU, SS_OCC,
    SS_SSQ, SS_OCS, SS_DAND, SS_DPIP,
    SS_SAR, SS_DAR, SS_DDS, 

    SS_AO, SS_CAO, SS_OES, SS_COES
};

// Mod-taps

#define LSFTT_S LSFT_T(KC_S)
#define RSFTT_L RSFT_T(KC_L)
#define RSFTT_O RSFT_T(KC_O)

#define LCTLT_D LCTL_T(KC_D)
#define LCTLT_E LCTL_T(KC_E)
#define RCTLT_K RCTL_T(KC_K)
#define RCTLT_A RCTL_T(KC_A)

#define LALTT_F LALT_T(KC_F)
#define LALTT_D LALT_T(KC_D)
#define RALTT_J RALT_T(KC_J)
#define RALTT_N RALT_T(KC_N)
#define LA_UNDS LALT_T(KC_UNDS)

#define LGUIT_V LGUI_T(KC_V)
#define LGUIT_T LGUI_T(KC_T)
#define RGUIT_M RGUI_T(KC_M)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)

// Layer-taps

#define MED_CAP LT(_MEDIA, SP_CAP)
#define MED_0   LT(_MEDIA, KC_0)
#define MED_P0  LT(_MEDIA, KC_P0)

#define NAV_NG  LT(_NAVIGATION, SP_NG)
#define MAI_MOD LT(_MAINTENANCE, SP_MOD)
#define MAI_ALT LT(_MAINTENANCE, SP_ALT)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_BSP LT(_RAISE, KC_BSPC)

#define NUM_SPC LT(_NUMPAD, KC_SPC)
#define NUM_BSP LT(_NUMPAD, KC_BSPC)

#define KCA_MAC LT(_MACROS, KC_A)
#define KCF_MAC LT(_MACROS, KC_F)
#define KCC_MAC LT(_MACROS, KC_C)
#define UND_MAC LT(_MACROS, KC_UNDS)
#define DOT_MAC LT(_MACROS, KC_DOT)
#define PDO_MAC LT(_MACROS, KC_PDOT)

// Layer transitions

#define TO_ROM TO(_ROMAK)
#define TT_NUM TT(_NUMPAD)
#define TG_NUM TG(_NUMPAD)
#define TT_NAV TT(_NAVIGATION)
#define TG_NAV TG(_NAVIGATION)

// Custom Shortcuts

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

#define CB_SELC LGUI(KC_A)
#define CB_SAVE LGUI(KC_S)
#define CB_UNDO LGUI(KC_Z)
#define CB_COPY LGUI(KC_C)
#define CB_PAST LGUI(KC_V)
#define CB_LOCK LGUI(KC_L)

uint16_t extract_base_tapping_keycode(uint16_t keycode);