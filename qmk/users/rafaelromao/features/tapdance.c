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
        if (state->interrupted || !state->pressed)
            return TD_SINGLE_TAP;
         else
            return TD_SINGLE_HOLD;
    } else if (state->count > 1) {
        if (state->interrupted)
            return TD_SINGLE_TAP;
        if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }
    return TD_SINGLE_TAP;
}

// Decimal Separators

void td_dot_com_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_DOT); break;
        case TD_DOUBLE_TAP: register_code(KC_COMM); break;
        case TD_SINGLE_HOLD: layer_on(_MEDIA);
        default: break;
    }
}

void td_dot_com_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_DOT); break;
        case TD_DOUBLE_TAP: unregister_code(KC_COMM); break;
        case TD_SINGLE_HOLD: layer_off(_MEDIA);
        default: break;
    }
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

// Tap dance declarations

qk_tap_dance_action_t tap_dance_actions[] = {
    [DOT_COM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_dot_com_finished, td_dot_com_reset),
    [MOU_B13] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mou_b13_finished, td_mou_b13_reset),
    [MOU_B24] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mou_b24_finished, td_mou_b24_reset),
    [INJ_LEF] = ACTION_TAP_DANCE_FN(td_inj_lef),
    [INJ_RIG] = ACTION_TAP_DANCE_FN(td_inj_rig),
    [SCL_END] = ACTION_TAP_DANCE_FN(td_semicolon),
    [BRT_CUR] = ACTION_TAP_DANCE_FN(td_curly_braces),
    [BRT_SQR] = ACTION_TAP_DANCE_FN(td_square_brackets),
    [BRT_PAR] = ACTION_TAP_DANCE_FN(td_parentesis),
    [BRT_ANG] = ACTION_TAP_DANCE_FN(td_angle_brackets),
    [DOT_DOT] = ACTION_TAP_DANCE_FN(td_dot_dot)
};
