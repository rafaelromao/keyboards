#pragma once

#include QMK_KEYBOARD_H

// Custom Keycodes

enum {
    OS_MAC = SAFE_RANGE,
    MC_QUE,
    MC_ESCL,
    MC_RESP,
    MC_TEST,
    MC_INFO,
    MC_PESO,
    MC_PESE,
    MC_ACTA,
    MC_ACDI,
    MC_SALI,
    MC_DECL,
    MC_DEPO,
    MC_APTE,
    MC_CONF,
    MC_VESP,
    MC_VINT,
    MC_TESP,
    MC_TINT,
    MC_SINT,
    MC_SCON,
};

// Tap dance

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    td_state_t state;
    bool       recording;
} td_tap_t;

td_state_t dance_state(tap_dance_state_t *state);

enum { ESC_QUOT, LBRC_RBRC, TC_A, TC_D, TC_P, TC_S, TC_T, TC_V };

#define TD_A TD(TC_A)
#define TD_D TD(TC_D)
#define TD_P TD(TC_P)
#define TD_V TD(TC_V)
#define TD_S TD(TC_S)
#define TD_T TD(TC_T)

#define TD_ESC TD(ESC_QUOT)
#define TD_LBRC TD(LBRC_RBRC)

// Mod taps

#define SF_SLSH LSFT_T(BR_SLSH)
