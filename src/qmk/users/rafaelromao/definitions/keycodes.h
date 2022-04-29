#pragma once

#include "layers.h"

// clang-format off

// Custom keycodes

enum {
    MC_SECRET_1 = SAFE_RANGE,
    MC_SECRET_2, MC_SECRET_3,

    MC_BTIC, MC_DQUO, MC_SQUO,
    MC_CIRC, MC_TILD, MC_DEG,

    TG_MAC, TG_WIN, TG_LIN,

    SP_CAP, SP_MOD, SP_NG, SP_ALT,

    MC_MODP, MC_MODM,

    MC_GV_A, MC_CR_A, MC_TL_A, MC_SQ_A,
    MC_SQ_U, MC_CR_O, MC_SQ_O, MC_SQ_I,
    MC_CR_E, MC_TL_O, MC_SQ_C, MC_SQ_E,

    MC_JOIN, MC_SELW, MC_SWIN, 

    MC_CAPS, MC_WORD, MC_CAML, MC_SNAK, MC_KBAB,

            MC_RS,  MC_EY,  MC_PH,          MC_CK,        MC_IO,
    MC_CH,  MC_SH,  MC_HE,  MC_THE, MC_GH,         MC_NH,
    MC_WH,  MC_SR,  MC_YE,  MC_TH,          MC_LH,

    MC_DAND, MC_DPIP,
    MC_EQU, MC_NEQ,
    MC_ARR, MC_DDS,
    MC_CPR,

    MC_AO, MC_CAO, MC_OES, MC_COES
};

// Mod-taps

#define SFT_CML LSFT_T(MC_CAML)

#define LSFTT_S LSFT_T(KC_S)
#define RSFTT_L RSFT_T(KC_L)
#define RSFTT_O RSFT_T(KC_O)
#define SF_F6 LSFT_T(KC_F6)
#define SF_P6 RSFT_T(KC_P6)

#define LCTLT_D LCTL_T(KC_D)
#define LCTLT_E LCTL_T(KC_E)
#define RCTLT_K RCTL_T(KC_K)
#define RCTLT_A RCTL_T(KC_A)
#define CT_F5 LCTL_T(KC_F5)
#define CT_P5 RCTL_T(KC_P5)

#define LALTT_F LALT_T(KC_F)
#define LALTT_D LALT_T(KC_D)
#define RALTT_J RALT_T(KC_J)
#define RALTT_N RALT_T(KC_N)
#define AL_F4 LALT_T(KC_F4)
#define AL_P4 RALT_T(KC_P4)
#define LA_BSLS LALT_T(KC_BSLS)

#define LGUIT_V LGUI_T(KC_V)
#define LGUIT_T LGUI_T(KC_T)
#define RGUIT_M RGUI_T(KC_M)
#define GU_F1 LGUI_T(KC_F1)
#define GU_P1 RGUI_T(KC_P1)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

// Layer-taps

#define MED_SFT LT(_MEDIA, SP_CAP)
#define MED_0   LT(_MEDIA, KC_0)
#define MED_P0  LT(_MEDIA, KC_P0)

#define NAV_NG  LT(_NAVIGATION, SP_NG)
#define MAI_MOD LT(_MAINTENANCE, SP_MOD)
#define MAI_ALT LT(_MAINTENANCE, SP_ALT)
#define MED_ALT LT(_MEDIA, SP_ALT)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_BSP LT(_RAISE, KC_BSPC)

#define KCA_MAC LT(_MACROS, KC_A)
#define KCF_MAC LT(_MACROS, KC_F)
#define KCC_MAC LT(_MACROS, KC_C)
#define SCL_MAC LT(_MACROS, KC_SCLN)
#define BSL_MAC LT(_MACROS, KC_UNDS)
#define DOT_MAC LT(_MACROS, KC_DOT)
#define PDO_MAC LT(_MACROS, KC_PDOT)

#define PER_LOW LT(_LOWER_OVER, KC_PERC)
#define BTI_RAI LT(_RAISE, MC_BTIC)

#define KT_2 LT(_ROMAK, KC_2)
#define KT_P2 LT(_ROMAK, KC_P2)
#define KT_3 LT(_ROMAK, KC_3)
#define KT_P3 LT(_ROMAK, KC_P3)

// Layer transitions

#define TO_ROM TO(_ROMAK)
#define TG_NUM TG(_NUMPAD)
#define TG_NAV TG(_FIXED_NAV)

// Custom Shortcuts

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

#define MC_SELC LGUI(KC_A)
#define MC_SAVE LGUI(KC_S)
#define MC_UNDO LGUI(KC_Z)
#define MC_COPY LGUI(KC_C)
#define MC_PAST LGUI(KC_V)
#define MC_LOCK LGUI(LCTL(KC_Q))
#define MC_FULL LGUI(LCTL(KC_F))
#define MC_FIND LGUI(KC_F)

uint16_t extract_base_tapping_keycode(uint16_t keycode);

// clang-format on