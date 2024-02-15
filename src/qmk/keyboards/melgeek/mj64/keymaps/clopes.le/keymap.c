/* Copyright 2020 MelGeek <melgeek001365@gmail.com>
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
#pragma once

#include QMK_KEYBOARD_H
#include "sendstring_brazilian_abnt2.h"
#include "keymap.h"

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_64_ansi(
			TD_ESC,    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,
		    KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     BR_ACUT,  TD_LBRC, BR_BSLS,
			KC_CAPS,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     BR_CCED,  BR_TILD,  KC_ENT,
		    KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   BR_SCLN,  SF_SLSH,  KC_UP,   KC_DEL,
		    KC_LCTL,   KC_LGUI,  KC_LALT,                      KC_SPC,                                 OS_MAC,   MO(1),    KC_LEFT,  KC_DOWN, KC_RIGHT
	),
	[1] = LAYOUT_64_ansi(
			KC_ESC,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,
			_______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  BR_RBRC,  _______,
            _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_F9,
		    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_SLSH,  KC_PGUP,  KC_INS,
			_______,   MO(3),    _______,                      _______,                                _______,  _______,  KC_HOME,  KC_PGDN,  KC_END
	),
    [2] = LAYOUT_64_ansi(
			_______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
			_______,   _______,  TD_W   ,  _______,  MC_R   ,  _______,  _______,  _______,  TD_I   ,  _______,  TD_P   ,  _______,  _______,  _______,
            _______,   _______,  TD_S   ,  TD_D   ,  MC_F   ,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		    _______,   _______,  _______,  MC_C   ,  _______,  _______,  TD_N   ,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
			_______,   _______,  _______,                      _______,                                _______,  _______,  _______,  _______,  _______
    ),
	[3] = LAYOUT_64_ansi(
			_______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
			_______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
            NK_TOGG,   RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  RGB_SPI,  RGB_SPD,  _______,  _______,
		    _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
			QK_BOOT,   _______,  EE_CLR ,                      _______,                                _______,  _______,  _______,  _______,  _______
	)
};

// clang-format on

// Custom Processing

#define RAZAO "raz" SS_TAP(X_QUOT) SS_TAP(X_A) "o"
#define INVESTIGACAO "investiga" SS_TAP(X_SCLN) SS_TAP(X_QUOT) SS_TAP(X_A) "o"
#define APURACAO "apura" SS_TAP(X_SCLN) SS_TAP(X_QUOT) SS_TAP(X_A) "o"
#define VITIMA "v" SS_TAP(X_LBRC) SS_TAP(X_I) "tima"
#define POLICIA "POL" SS_LSFT(SS_TAP(X_LBRC) SS_TAP(X_I)) "CIA"
#define SILENCIO "sil" SS_LSFT(SS_TAP(X_QUOT)) SS_TAP(X_E) "ncio"
#define CODIGO "c" SS_TAP(X_LBRC) SS_TAP(X_O) "digo"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record != NULL && !record->event.pressed) {
        return true;
    }

    if (keycode == OS_MAC) {
        set_oneshot_layer(2, ONESHOT_START);
        return false;
    }

    // Process macros
    switch (keycode) {
        case MC_R:
            SEND_STRING("RESPONDEU QUE:");
            return false;
        case MC_F:
            SEND_STRING("QUE o declarante apresenta como testemunha(s)");
            return false;
        case MC_C:
            SEND_STRING("conforme se expressa");
            return false;

        case MC_P1:
            SEND_STRING("PERGUNTADO DISSE QUE:");
            return false;
        case MC_P2:
            SEND_STRING("PERGUNTADO se");
            return false;

        case MC_D1:
            SEND_STRING("QUE o (a) DECLARANTE afirma que:");
            return false;
        case MC_D2:
            SEND_STRING("QUE o (a) DECLARANTE informa que:");
            return false;
        case MC_D3:
            SEND_STRING("QUE o (a) DECLARANTE acrescenta que:");
            return false;

        case MC_N1:
            SEND_STRING("QUE o (a) DEPOENTE afirma que:");
            return false;
        case MC_N2:
            SEND_STRING("QUE o (a) DEPOENTE informa que:");
            return false;
        case MC_N3:
            SEND_STRING("QUE o (a) DEPOENTE acrescenta que:");
            return false;

        case MC_S1:
            SEND_STRING("QUE o (a) DECLARANTE salienta que:");
            return false;
        case MC_S2:
            SEND_STRING("QUE o (a) DEPOENTE salienta que:");
            return false;

        case MC_W1:
            SEND_STRING("DECLARANTE");
            return false;
        case MC_W2:
            SEND_STRING("DEPOENTE");
            return false;

        case MC_I1:
            SEND_STRING("QUE compareceu nesta DELEGACIA DE " POLICIA " devidamente intimado(a) ________, ");
            SEND_STRING("na qualidade de " VITIMA ", em " RAZAO " da " INVESTIGACAO " que tramita nesta unidade ");
            SEND_STRING("sob o REDS ________ QUE INVESTIGA O CRIME DE ____________; QUE foi devidamente ");
            SEND_STRING("cientificado sobre o objeto em " APURACAO "; PERGUNTADO DISSE QUE:");
            return false;

        case MC_I2:
            SEND_STRING("QUE compareceu nesta DELEGACIA DE " POLICIA " devidamente intimado(a) ________, ");
            SEND_STRING("na qualidade de SUSPEITO, em " RAZAO " da " INVESTIGACAO " que tramita nesta unidade ");
            SEND_STRING("sob o REDS ________ QUE INVESTIGA O CRIME DE ____________; QUE foi devidamente ");
            SEND_STRING("cientificado sobre o objeto em " APURACAO " e informado pela Autoridade Policial ");
            SEND_STRING("de todos os seus direitos constitucionais, inclusive o de permanecer em " SILENCIO ", ");
            SEND_STRING("e optou espontaneamente por esclarecer os fatos; PERGUNTADO DISSE QUE:");
            return false;

        case MC_I3:
            SEND_STRING("QUE compareceu nesta DELEGACIA DE " POLICIA " devidamente intimado(a) ________, ");
            SEND_STRING("na qualidade de TESTEMUNHA, em " RAZAO " da " INVESTIGACAO " que tramita nesta unidade ");
            SEND_STRING("sob o REDS ________ QUE INVESTIGA O CRIME DE ____________; QUE foi devidamente ");
            SEND_STRING("cientificado sobre o objeto em " APURACAO " e informado pela Autoridade Policial ");
            SEND_STRING("de todos os seus direitos constitucionais, e cientificado do dever de dizer a verdade ");
            SEND_STRING("de tudo que souber e/ou lhe for perguntado, podendo responder pelo crime de falso ");
            SEND_STRING("testemunho artigo 342, caput, do " CODIGO " Penal; INQUERIDO DISSE QUE:");
            return false;
    }

    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            break;
        default:
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
    }

    return true;
}

// Tap dance

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

void td_esc_quot(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_ESC);
            break;
        case TD_SINGLE_HOLD:
            tap_code(BR_QUOT);
            break;
        default:
            break;
    }
}

void td_brackets(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(BR_LBRC);
            break;
        case TD_SINGLE_HOLD:
            tap_code16(BR_RBRC);
            break;
        default:
            break;
    }
}

void tc_d(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_D1, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_D2, NULL);
            break;
        case TD_TRIPLE_TAP:
            process_record_user(MC_D3, NULL);
            break;
        default:
            break;
    }
    clear_oneshot_layer_state(ONESHOT_PRESSED);
}

void tc_p(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_P1, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_P2, NULL);
            break;
        default:
            break;
    }
    clear_oneshot_layer_state(ONESHOT_PRESSED);
}

void tc_w(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_W1, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_W2, NULL);
            break;
        default:
            break;
    }
    clear_oneshot_layer_state(ONESHOT_PRESSED);
}

void tc_s(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_S1, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_S2, NULL);
            break;
        default:
            break;
    }
    clear_oneshot_layer_state(ONESHOT_PRESSED);
}

void tc_n(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_N1, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_N2, NULL);
            break;
        case TD_TRIPLE_TAP:
            process_record_user(MC_N3, NULL);
            break;
        default:
            break;
    }
    clear_oneshot_layer_state(ONESHOT_PRESSED);
}

void tc_i(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_I1, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_I2, NULL);
            break;
        case TD_TRIPLE_TAP:
            process_record_user(MC_I3, NULL);
            break;
        default:
            break;
    }
    clear_oneshot_layer_state(ONESHOT_PRESSED);
}

tap_dance_action_t tap_dance_actions[] = {[ESC_QUOT]  = ACTION_TAP_DANCE_FN(td_esc_quot),
                                          [TC_D]      = ACTION_TAP_DANCE_FN(tc_d),
                                          [TC_P]      = ACTION_TAP_DANCE_FN(tc_p),
                                          [TC_W]      = ACTION_TAP_DANCE_FN(tc_w),
                                          [TC_S]      = ACTION_TAP_DANCE_FN(tc_s),
                                          [TC_N]      = ACTION_TAP_DANCE_FN(tc_n),
                                          [TC_I]      = ACTION_TAP_DANCE_FN(tc_i),
                                          [LBRC_RBRC] = ACTION_TAP_DANCE_FN(td_brackets)};

// Led Indicators

bool rgb_matrix_indicators_user(void) {
    bool caps = host_keyboard_led_state().caps_lock;
    if (caps) {
        rgb_matrix_set_color(64, RGB_RED);
        rgb_matrix_set_color(65, RGB_RED);
        rgb_matrix_set_color(66, RGB_RED);
    }
    return false;
}