#include QMK_KEYBOARD_H

#include "tapdance.h"

extern os_t os;

static td_tap_t tap_state = {.state = TD_NONE};

__attribute__((weak)) td_state_t dance_state(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}

// IntelliJ Most Common Shortcuts

void td_inj_lef(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state       = dance_state(state);
    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift   = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LCTL(SS_TAP(X_F9)));
            } else {
                SEND_STRING(SS_LGUI(SS_TAP(X_F9)));
                break;
            }
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_LCTL);
            tap_code16(KC_LCTL);
            break;
        case TD_TRIPLE_TAP:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LCTL("1"));
            } else {
                SEND_STRING(SS_LGUI("1"));
                break;
            }
            break;
        case TD_SINGLE_HOLD:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_ENT))));
            } else {
                SEND_STRING(SS_LSFT(SS_LGUI(SS_TAP(X_ENT))));
                break;
            }
            break;
        default:
            break;
    }
}

void td_inj_rig(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state       = dance_state(state);
    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift   = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_LSFT);
            tap_code16(KC_LSFT);
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_F7)));
            break;
        case TD_SINGLE_HOLD:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT(SS_TAP(X_T)))));
            } else {
                SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_T)))));
                break;
            }
            break;
        default:
            break;
    }
}

// Dancing brackets

void td_curly_braces(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LCBR);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_RCBR);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_SPC);
            tap_code16(KC_LCBR);
            break;
        default:
            break;
    }
}

void td_square_brackets(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LBRC);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_RBRC);
            break;
        default:
            break;
    }
}

void td_parentesis(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LPRN);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_RPRN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
            tap_code(KC_SCLN);
            break;
        default:
            break;
    }
}

void td_angle_brackets(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LT);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_GT);
            break;
        default:
            break;
    }
}

// Semicolon at the end

void td_semicolon(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_SCLN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_SCLN);
            break;
        default:
            break;
    }
}

// Dot dot new sentence

void td_dot_dot(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isShifted  = get_mods() & MOD_MASK_SHIFT || get_oneshot_mods() & MOD_MASK_SHIFT ||
                     get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_DOT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            break;
        case TD_DOUBLE_TAP:
            if (!isShifted) {
                tap_code(KC_DOT);
                tap_code(KC_SPC);
                add_oneshot_mods(MOD_LSFT);
            } else {
                tap_code(KC_DOT);
                tap_code(KC_DOT);
            }
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_DOT);
            break;
        default:
            break;
    }
}

// Currencies

void td_currencies(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_DLR);
            break;
        case TD_DOUBLE_TAP:
            switch (os.type) {
                case MACOS:
                    tap_code16(LSFT(RALT(KC_2)));
                    break;
                default:
                    tap_code16(LCTL(LALT(KC_5)));
                    break;
            }
            break;
        case TD_TRIPLE_TAP:
            switch (os.type) {
                case MACOS:
                    tap_code16(RALT(KC_3));
                    break;
                default:
                    tap_code16(LSFT(RALT(KC_4)));
                    break;
            }
            break;
        default:
            break;
    }
}

// Quotes

void td_quotes(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_QUOT);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_GRV);
            break;
        case TD_TRIPLE_TAP:
            tap_code16(KC_DQUO);
            break;
        default:
            break;
    }
}

// Dynamic Macro

void td_macro(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isShifted  = get_mods() & MOD_MASK_SHIFT || get_oneshot_mods() & MOD_MASK_SHIFT ||
                     get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    switch (tap_state.state) {
        case TD_DOUBLE_TAP:
            dyn_macro_toggle(isShifted ? DYN_REC_START2 : DYN_REC_START1);
            break;
        case TD_SINGLE_TAP:
            dyn_macro_play(isShifted ? DYN_MACRO_PLAY2 : DYN_MACRO_PLAY1);
            break;
        default:
            break;
    }
}

void td_comm_macro(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    bool isShifted  = get_mods() & MOD_MASK_SHIFT || get_oneshot_mods() & MOD_MASK_SHIFT ||
                     get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_COMM);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_COMM);
            tap_code(KC_COMM);
            break;
        case TD_DOUBLE_TAP:
            if (!isShifted) {
                qk_leader_start();
            } else {
                tap_code(KC_COMM);
                tap_code(KC_COMM);
            }
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_COMM);
            break;
        default:
            break;
    }
}

// clang-format off

// Tap dance declarations

qk_tap_dance_action_t tap_dance_actions[] = {
    [INJ_LEF] = ACTION_TAP_DANCE_FN(td_inj_lef),
    [INJ_RIG] = ACTION_TAP_DANCE_FN(td_inj_rig),
    [SCL_END] = ACTION_TAP_DANCE_FN(td_semicolon),
    [BRT_CUR] = ACTION_TAP_DANCE_FN(td_curly_braces),
    [BRT_SQR] = ACTION_TAP_DANCE_FN(td_square_brackets),
    [BRT_PAR] = ACTION_TAP_DANCE_FN(td_parentesis),
    [BRT_ANG] = ACTION_TAP_DANCE_FN(td_angle_brackets),
    [REC_MAC] = ACTION_TAP_DANCE_FN(td_macro),
    [COM_MAC] = ACTION_TAP_DANCE_FN(td_comm_macro),
    [DOT_DOT] = ACTION_TAP_DANCE_FN(td_dot_dot),
    [SDB_QUO] = ACTION_TAP_DANCE_FN(td_quotes),
    [DLR_CUR] = ACTION_TAP_DANCE_FN(td_currencies)};

// clang-format on
