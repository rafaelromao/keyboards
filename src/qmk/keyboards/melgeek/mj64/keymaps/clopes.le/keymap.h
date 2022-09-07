#pragma once

#include QMK_KEYBOARD_H

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

td_state_t dance_state(qk_tap_dance_state_t *state);

enum { ESC_QUOT, LBRC_RBRC };

#define TD_ESC TD(ESC_QUOT)
#define TD_LBRC TD(LBRC_RBRC)

// Mod taps

#define SF_SLSH LSFT_T(KC_SLSH)
