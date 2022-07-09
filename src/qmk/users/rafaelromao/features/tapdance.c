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

// Enter end

void td_enter_end(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_END);
            tap_code(KC_ENT);
            break;
        case TD_DOUBLE_TAP:
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_TAP(X_DOWN) SS_DELAY(100) SS_TAP(X_END));
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

void td_open_parentesis(qk_tap_dance_state_t *state, void *user_data) {
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
            break;
        default:
            break;
    }
}

void td_close_parentesis(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_RPRN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_RPRN);
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
            tap_code16(KC_RPRN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
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
            tap_code(KC_ENT);
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

// Dot

void td_dot_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_HOLD:
            register_code(KC_DOT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            register_code(KC_DOT);
            register_code(KC_DOT);
            break;
        case TD_TRIPLE_TAP:
            register_code(KC_DOT);
            register_code(KC_DOT);
            register_code(KC_DOT);
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_END);
            register_code(KC_DOT);
            break;
        default:
            break;
    }
}

void td_dot_reset(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_HOLD:
            unregister_code(KC_DOT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            unregister_code(KC_DOT);
            unregister_code(KC_DOT);
            break;
        case TD_TRIPLE_TAP:
            unregister_code(KC_DOT);
            unregister_code(KC_DOT);
            unregister_code(KC_DOT);
            break;
        case TD_SINGLE_HOLD:
            unregister_code16(KC_END);
            unregister_code(KC_DOT);
            break;
        default:
            break;
    }
}

// clang-format off

// Tap dance declarations

qk_tap_dance_action_t tap_dance_actions[] = {
    [ENT_END] = ACTION_TAP_DANCE_FN(td_enter_end),
    [SCL_END] = ACTION_TAP_DANCE_FN(td_semicolon),
    [BRT_CUR] = ACTION_TAP_DANCE_FN(td_curly_braces),
    [BRT_SQR] = ACTION_TAP_DANCE_FN(td_square_brackets),
    [BRT_OPA] = ACTION_TAP_DANCE_FN(td_open_parentesis),
    [BRT_CPA] = ACTION_TAP_DANCE_FN(td_close_parentesis),
    [BRT_PAR] = ACTION_TAP_DANCE_FN(td_parentesis),
    [BRT_ANG] = ACTION_TAP_DANCE_FN(td_angle_brackets),
    [REC_MAC] = ACTION_TAP_DANCE_FN(td_macro),
    [COM_MAC] = ACTION_TAP_DANCE_FN(td_comm_macro),
    [SDB_QUO] = ACTION_TAP_DANCE_FN(td_quotes),
    [DLR_CUR] = ACTION_TAP_DANCE_FN(td_currencies),
    [DOT_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dot_finished, td_dot_reset)};

// clang-format on
