/* Copyright 2021 Rafael Romão @rafaelromao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "tapdance.h"

extern os_t os;

static td_tap_t tap_state = {
    .state = TD_NONE
};

__attribute__ ((weak)) td_state_t dance_state(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}

// Mouse buttons

void td_mou_b13_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_BTN1); break;
        case TD_DOUBLE_TAP: register_code(KC_BTN3); break;
        default: break;
    }
}

void td_mou_b13_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_BTN1); break;
        case TD_DOUBLE_TAP: unregister_code(KC_BTN3); break;
        default: break;
    }
}

void td_mou_b24_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_BTN2); break;
        case TD_DOUBLE_TAP: register_code(KC_BTN4); break;
        default: break;
    }
}

void td_mou_b24_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_BTN2); break;
        case TD_DOUBLE_TAP: unregister_code(KC_BTN4); break;
        default: break;
    }
}

// IntelliJ Most Common Shortcuts

void td_inj_lef(qk_tap_dance_state_t *state, void *user_data) {

    tap_state.state = dance_state(state);
    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                SEND_STRING(SS_LCTL("1"));
            } else {
                SEND_STRING(SS_LGUI("1"));
                break;
            }
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_LCTL);
            tap_code16(KC_LCTL);
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_LALT(SS_TAP(X_F7)));
            break;
        default: break;
    }
}

void td_inj_rig(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            SEND_STRING(SS_LALT(SS_TAP(X_ENT)));
            break;
        case TD_DOUBLE_TAP:
            tap_code16(KC_LSFT);
            tap_code16(KC_LSFT);
            break;
        case TD_SINGLE_HOLD:
            SEND_STRING(SS_TAP(X_F2));
            break;
        default: break;
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
        default: break;
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
        default: break;
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
        default: break;
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
        default: break;
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
        default: break;
    }
}

// Dot dot new sentence

void td_dot_dot(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_DOT);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            break;
        case TD_DOUBLE_TAP:
            tap_code(KC_DOT);
            tap_code(KC_SPC);
            add_oneshot_mods(MOD_LSFT);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code(KC_DOT);
            break;
        default: break;
    }
}

// Question Mark, Exclamation and Currencies

void td_question_mark(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_QUES);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code16(KC_QUES);
            tap_code16(KC_QUES);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(RALT(KC_QUES));
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_QUES);
            break;
        default: break;
    }
}

void td_exclamation(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_EXLM);
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code16(KC_EXLM);
            tap_code16(KC_EXLM);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(RALT(KC_1));
            break;
        case TD_SINGLE_HOLD:
            tap_code16(KC_END);
            tap_code16(KC_EXLM);
            break;
        default: break;
    }
}

void td_currencies(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(KC_DLR);
            break;
        case TD_DOUBLE_TAP:
            tap_code16(LSFT(RALT(KC_2)));
            break;
        case TD_SINGLE_HOLD:
        case TD_TRIPLE_TAP:
            tap_code16(RALT(KC_3));
            break;
        default: break;
    }
}

// Accents

void tap_accent_dead_key(uint16_t keycode) {
    switch (keycode) {
        case TD_SQ_C:
        case TD_SQ_E:
            tap_code(KC_QUOT);
            break;
        case TD_CR_A:
        case TD_CR_E:
            tap_code16(KC_CIRC);
            break;
        case TD_TL_A:
        case TD_TL_O:
            tap_code16(KC_TILD);
            break;
        case TD_GV_A:
        case TD_GV_E:
            tap_code16(KC_GRV);
            break;
        case TD_DQ_U:
        case TD_DQ_S:
            tap_code16(KC_DQUO);
            break;
    }
}

void tap_accent_tap_key(uint32_t keycode) {
    switch (keycode) {
        case TD_SQ_C:
            tap_code(KC_C);
            break;
        case TD_SQ_E:
        case TD_CR_E:
        case TD_GV_E:
            tap_code(KC_E);
            break;
        case TD_CR_A:
        case TD_TL_A:
        case TD_GV_A:
            tap_code(KC_A);
            break;
        case TD_TL_O:
            tap_code(KC_O);
            break;
        case TD_DQ_U:
            tap_code(KC_U);
            break;
        case TD_DQ_S:
            tap_code16(RALT(KC_S));
            break;
    }
}

void tap_accent_double_tap_key(uint32_t keycode) {
    switch (keycode) {
        case TD_SQ_C:
        case TD_DQ_S:
            tap_code(KC_A);
            break;
        case TD_GV_A:
        case TD_CR_A:
            tap_code(KC_I);
            break;
        case TD_GV_E:
        case TD_SQ_E:
        case TD_CR_E:
            tap_code(KC_O);
            break;
        case TD_DQ_U:
            tap_code(KC_E);
            break;
        case TD_TL_A:
            tap_code(KC_N);
            break;
    }
}

void tap_accent_triple_tap_key(uint32_t keycode) {
    switch (keycode) {
        case TD_GV_A:
        case TD_CR_A:
        case TD_SQ_C:
            tap_code(KC_U);
            break;
        case TD_DQ_S:
            tap_code(KC_O);
            break;
        case TD_DQ_U:
        case TD_SQ_E:
            tap_code(KC_I);
            break;
    }
}

void td_accents(qk_tap_dance_state_t *state, uint32_t keycode) {
    tap_state.state = dance_state(state);

    bool isShifted = get_oneshot_mods() & MOD_MASK_SHIFT;
    clear_locked_and_oneshot_mods();
    
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            if (keycode != TD_DQ_S) {
                tap_accent_dead_key(keycode);
            }
            if (isShifted) {
                register_mods(MOD_LSFT);
            }
            tap_accent_tap_key(keycode);
            if (isShifted) {
                unregister_mods(MOD_LSFT);
            }
            break;
        case TD_DOUBLE_TAP:
            tap_accent_dead_key(keycode);
            if (isShifted) {
                register_mods(MOD_LSFT);
            }
            tap_accent_double_tap_key(keycode);
            if (isShifted) {
                unregister_mods(MOD_LSFT);
            }
            break;
        case TD_SINGLE_HOLD:
        case TD_TRIPLE_TAP:
            tap_accent_dead_key(keycode);
            if (isShifted) {
                register_mods(MOD_LSFT);
            }
            tap_accent_triple_tap_key(keycode);
            if (isShifted) {
                unregister_mods(MOD_LSFT);
            }
            break;
        default: break;
    }
}

void td_gv_e(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_GV_E);
}

void td_gv_a(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_GV_A);
}

void td_cr_e(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_CR_E);
}

void td_cr_a(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_CR_A);
}

void td_tl_a(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_TL_A);
}

void td_tl_o(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_TL_O);
}

void td_sq_e(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_SQ_E);
}

void td_sq_c(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_SQ_C);
}

void td_dq_u(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_DQ_U);
}

void td_dq_s(qk_tap_dance_state_t *state, void *user_data) {
    td_accents(state, TD_DQ_S);
}

// Tap dance declarations

qk_tap_dance_action_t tap_dance_actions[] = {
    [MOU_B13] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mou_b13_finished, td_mou_b13_reset),
    [MOU_B24] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mou_b24_finished, td_mou_b24_reset),
    [INJ_LEF] = ACTION_TAP_DANCE_FN(td_inj_lef),
    [INJ_RIG] = ACTION_TAP_DANCE_FN(td_inj_rig),
    [SCL_END] = ACTION_TAP_DANCE_FN(td_semicolon),
    [BRT_CUR] = ACTION_TAP_DANCE_FN(td_curly_braces),
    [BRT_SQR] = ACTION_TAP_DANCE_FN(td_square_brackets),
    [BRT_PAR] = ACTION_TAP_DANCE_FN(td_parentesis),
    [BRT_ANG] = ACTION_TAP_DANCE_FN(td_angle_brackets),
    [DOT_DOT] = ACTION_TAP_DANCE_FN(td_dot_dot),
    [GRV_E] = ACTION_TAP_DANCE_FN(td_gv_e),
    [GRV_A] = ACTION_TAP_DANCE_FN(td_gv_a),
    [CIR_E] = ACTION_TAP_DANCE_FN(td_cr_e),
    [CIR_A] = ACTION_TAP_DANCE_FN(td_cr_a),
    [TIL_A] = ACTION_TAP_DANCE_FN(td_tl_a),
    [TIL_O] = ACTION_TAP_DANCE_FN(td_tl_o),
    [SQU_E] = ACTION_TAP_DANCE_FN(td_sq_e),
    [SQU_C] = ACTION_TAP_DANCE_FN(td_sq_c),
    [DQU_U] = ACTION_TAP_DANCE_FN(td_dq_u),
    [DQU_S] = ACTION_TAP_DANCE_FN(td_dq_s),
    [EXL_INV] = ACTION_TAP_DANCE_FN(td_exclamation),
    [QUE_INV] = ACTION_TAP_DANCE_FN(td_question_mark),
    [DLR_CUR] = ACTION_TAP_DANCE_FN(td_currencies)
};
