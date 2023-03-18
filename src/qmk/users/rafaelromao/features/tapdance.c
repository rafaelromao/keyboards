#include QMK_KEYBOARD_H

#include "tapdance.h"

extern os_t os;

static td_tap_t tap_state = {.state = TD_NONE};

__attribute__((weak)) td_state_t dance_state(tap_dance_state_t *state) {
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

bool is_shifted(void) {
    return get_mods() & MOD_MASK_SHIFT || get_oneshot_mods() & MOD_MASK_SHIFT ||
           get_oneshot_locked_mods() & MOD_MASK_SHIFT;
}

bool is_macos(void) {
    return os.type == MACOS;
}

void td_enter_end(tap_dance_state_t *state, void *user_data) {
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

void td_open_curly_braces(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LCBR);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_LCBR);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("var ");
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("final ");
            break;
        default:
            break;
    }
}

void td_close_curly_braces(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_RCBR);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_RCBR);
            break;
        default:
            break;
    }
}

void td_parentesis(tap_dance_state_t *state, void *user_data) {
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

void td_open_parentesis(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LPRN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_LPRN);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("for(");
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("while(");
            break;
        default:
            break;
    }
}

void td_close_parentesis(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_RPRN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_RPRN);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("if(");
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("else ");
            break;
        default:
            break;
    }
}

void td_open_brackets(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LBRC);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_LBRC);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("float ");
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("double ");
            break;
        default:
            break;
    }
}

void td_close_brackets(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_RBRC);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_RBRC);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("short ");
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("long ");
            break;
        default:
            break;
    }
}

void td_and(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_AMPR);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_RIGHT);
            process_macros(MC_DAND, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_macros(MC_DAND, NULL);
            break;
        default:
            break;
    }
}

void td_or(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_PIPE);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_RIGHT);
            process_macros(MC_DPIP, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_macros(MC_DPIP, NULL);
            break;
        default:
            break;
    }
}

void td_plus(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_PLUS);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            tap_code16(KC_PLUS);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("return ");
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("throw ");
            break;
        default:
            break;
    }
}

void td_not(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_EXLM);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            tap_code16(KC_EXLM);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("case ");
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("switch(");
            break;
        default:
            break;
    }
}

void td_dquo(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_macros(MC_DQUO, NULL);
            break;
        case TD_SINGLE_HOLD:
            process_macros(MC_DQUO, NULL);
            process_macros(MC_DQUO, NULL);
            tap_code(KC_LEFT);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("void ");
            break;
        case TD_TRIPLE_TAP:
            SEND_STRING("null");
            break;
        default:
            break;
    }
}

void td_perc(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);

    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_PERC);
            break;
        case TD_SINGLE_HOLD:
            if (is_macos()) {
                tap_code16(LSFT(RALT(KC_8)));
            } else {
                tap_code16(LSFT(LCTL(KC_2)));
            }
            break;
        default:
            break;
    }
}

void td_colon(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);

    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            if (is_shifted()) {
                clear_shift();
                tap_code(KC_SCLN);
            } else {
                tap_code16(KC_COLN);
            }
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_COLN);
            tap_code16(KC_COLN);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_COLN);
            break;
        default:
            break;
    }
}

void td_semicolon(tap_dance_state_t *state, void *user_data) {
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

void td_currencies(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_DLR);
            break;
        case TD_DOUBLE_TAP:
            if (is_macos()) {
                tap_code16(LSFT(RALT(KC_2)));
            } else {
                tap_code16(LCTL(LALT(KC_5)));
            }
            break;
        case TD_TRIPLE_TAP:
            if (is_macos()) {
                tap_code16(RALT(KC_3));
            } else {
                tap_code16(LSFT(RALT(KC_4)));
            }
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_CIRC);
            tap_code(KC_SPC);
            break;
        default:
            break;
    }
}

void td_macro(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_DOUBLE_TAP:
            dyn_macro_toggle(is_shifted() ? QK_DYNAMIC_MACRO_RECORD_START_2 : QK_DYNAMIC_MACRO_RECORD_START_1);
            break;
        case TD_SINGLE_TAP:
            dyn_macro_play(is_shifted() ? QK_DYNAMIC_MACRO_PLAY_2 : QK_DYNAMIC_MACRO_PLAY_1);
            break;
        default:
            break;
    }
}

void td_comm(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_COMM);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_COMM);
            tap_code(KC_COMM);
            break;
        case TD_DOUBLE_TAP:
            if (!is_shifted()) {
                leader_start();
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

void td_dot(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_HOLD:
            tap_code(KC_DOT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_DOT);
            break;
        default:
            break;
    }
}

void td_ques(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_QUES);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code16(KC_QUES);
            tap_code16(KC_QUES);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            tap_code16(KC_QUES);
            break;
        default:
            break;
    }
}

void td_lt(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_LT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code16(KC_LT);
            tap_code16(KC_LT);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            tap_code16(KC_LT);
            break;
        default:
            break;
    }
}

void td_gt(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_GT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code16(KC_GT);
            tap_code16(KC_GT);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            tap_code16(KC_GT);
            break;
        default:
            break;
    }
}

void td_eql(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_EQL);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code(KC_EQL);
            tap_code(KC_EQL);
            break;
        case TD_TRIPLE_TAP:
            tap_code(KC_EQL);
            tap_code(KC_EQL);
            tap_code(KC_EQL);
            break;
        case TD_SINGLE_HOLD:
            tap_code(KC_END);
            tap_code(KC_EQL);
            break;
        default:
            break;
    }
}

void td_slash(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_SLSH);
            break;
        case TD_DOUBLE_SINGLE_TAP:
        case TD_DOUBLE_TAP:
            tap_code(KC_SLSH);
            tap_code(KC_SLSH);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_BSLS);
            break;
        default:
            break;
    }
}

// clang-format off

// Tap dance declarations

tap_dance_action_t tap_dance_actions[] = {
    [ENT_END] = ACTION_TAP_DANCE_FN(td_enter_end),
    [SCL_END] = ACTION_TAP_DANCE_FN(td_semicolon),
    [BRT_LCR] = ACTION_TAP_DANCE_FN(td_open_curly_braces),
    [BRT_RCR] = ACTION_TAP_DANCE_FN(td_close_curly_braces),
    [BRT_OPA] = ACTION_TAP_DANCE_FN(td_open_parentesis),
    [BRT_CPA] = ACTION_TAP_DANCE_FN(td_close_parentesis),
    [BRT_OBR] = ACTION_TAP_DANCE_FN(td_open_brackets),
    [BRT_CBR] = ACTION_TAP_DANCE_FN(td_close_brackets),
    [BRT_PAR] = ACTION_TAP_DANCE_FN(td_parentesis),
    [DQU_FIN] = ACTION_TAP_DANCE_FN(td_dquo),
    [NOT_SWI] = ACTION_TAP_DANCE_FN(td_not),
    [AND_EAN] = ACTION_TAP_DANCE_FN(td_and),
    [OR_EOR]  = ACTION_TAP_DANCE_FN(td_or),
    [REC_MAC] = ACTION_TAP_DANCE_FN(td_macro),
    [COM_LEA] = ACTION_TAP_DANCE_FN(td_comm),
    [DLR_CUR] = ACTION_TAP_DANCE_FN(td_currencies),
    [COL_ECO] = ACTION_TAP_DANCE_FN(td_colon),
    [PER_DEG] = ACTION_TAP_DANCE_FN(td_perc),
    [QUE_EXC] = ACTION_TAP_DANCE_FN(td_ques),
    [EQL_EEQ] = ACTION_TAP_DANCE_FN(td_eql),
    [PLU_RET] = ACTION_TAP_DANCE_FN(td_plus),
    [LET_ELT] = ACTION_TAP_DANCE_FN(td_lt),
    [GRT_EGT] = ACTION_TAP_DANCE_FN(td_gt),
    [SLS_BSL] = ACTION_TAP_DANCE_FN(td_slash),
    [DOT_DOT] = ACTION_TAP_DANCE_FN(td_dot)};

// clang-format on
