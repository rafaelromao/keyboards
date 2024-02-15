#pragma once

#include QMK_KEYBOARD_H

// Custom Keycodes

enum {
    OS_MAC = SAFE_RANGE,
    MC_R,
    MC_W1,
    MC_W2,
    MC_P1,
    MC_P2,
    MC_S1,
    MC_S2,
    MC_D1,
    MC_D2,
    MC_D3,
    MC_F,
    MC_C,
    MC_N1,
    MC_N2,
    MC_N3,
    MC_I1,
    MC_I2,
    MC_I3,
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

enum { ESC_QUOT, LBRC_RBRC, TC_D, TC_P, TC_S, TC_W, TC_I, TC_N };

#define TD_D TD(TC_D)
#define TD_P TD(TC_P)
#define TD_I TD(TC_I)
#define TD_S TD(TC_S)
#define TD_W TD(TC_W)
#define TD_N TD(TC_N)

#define TD_ESC TD(ESC_QUOT)
#define TD_LBRC TD(LBRC_RBRC)

// Mod taps

#define SF_SLSH LSFT_T(BR_SLSH)
