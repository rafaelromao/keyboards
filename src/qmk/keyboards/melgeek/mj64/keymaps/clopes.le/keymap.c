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
			_______,   MC_QUE ,  _______,  MC_ESCL,  MC_RESP,  TD_T   ,  _______,  _______,  MC_INFO,  _______,  TD_P   ,  _______,  _______,  _______,
            _______,   TD_A   ,  TD_S   ,  TD_D   ,  MC_APTE,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
		    _______,   _______,  _______,  MC_CONF,  TD_V   ,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
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

#define DECLARACOES "declara" SS_TAP(X_SCLN) SS_TAP(X_QUOT) SS_TAP(X_O) "es"
#define VITIMA "v" SS_TAP(X_LBRC) SS_TAP(X_I) "tima"
#define SILENCIO "sil" SS_LSFT(SS_TAP(X_QUOT)) SS_TAP(X_E) "ncio"

bool spacing = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record != NULL && !record->event.pressed) {
        return true;
    }
    // Deactivate OS Macros
    switch (keycode) {
        case KC_SPC:
            if (IS_LAYER_ON(2)) {
                if (spacing) {
                    clear_oneshot_layer_state(ONESHOT_PRESSED);
                    tap_code(KC_BSPC);
                } else {
                    spacing = true;
                    return true;
                }
            }
            break;
        case KC_ESC:
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            break;
    }

    spacing = false;

    // Activate OS Macros
    if (keycode == OS_MAC) {
        set_oneshot_layer(2, ONESHOT_START);
        return false;
    }

    // Process macros
    switch (keycode) {
        case MC_QUE:
            SEND_STRING("; QUE");
            return false;
        case MC_ESCL:
            SEND_STRING("esclarece");
            return false;
        case MC_RESP:
            SEND_STRING("; RESPONDEU QUE");
            return false;
        case MC_TEST:
            SEND_STRING("testemunha");
            return false;
        case MC_INFO:
            SEND_STRING("informante");
            return false;
        case MC_PESO:
            SEND_STRING("; PERGUNTADO sobre");
            return false;
        case MC_PESE:
            SEND_STRING("; PERGUNTADO se");
            return false;
        case MC_ACTA:
            SEND_STRING("acrescenta");
            return false;
        case MC_ACDI:
            SEND_STRING("acredita");
            return false;
        case MC_SALI:
            SEND_STRING("salienta");
            return false;
        case MC_DECL:
            SEND_STRING("declarante");
            return false;
        case MC_DEPO:
            SEND_STRING("depoente");
            return false;
        case MC_APTE:
            SEND_STRING("; QUE o declarante apresenta como testemunha(s)");
            return false;
        case MC_CONF:
            SEND_STRING(", conforme se expressa");
            return false;

        case MC_VESP:
            SEND_STRING("Que compareceu espontaneamente nesta unidade especializada (a), ");
            SEND_STRING("a fim de prestar " DECLARACOES " e ratificar o que foi relatado no Reds (xxxxxx), ");
            SEND_STRING("no qual figura como " VITIMA " do crime do art. (xxxxx); PERGUNTADO disse QUE:");
            return false;

        case MC_VINT:
            SEND_STRING("Que compareceu nesta unidade especializada devidamente intimado (a), a fim de ");
            SEND_STRING("prestar " DECLARACOES " sobre os fatos relatados no Reds (xxxxxx), no qual figura ");
            SEND_STRING("como " VITIMA " do crime do art. (xxxxx); PERGUNTADO disse QUE:");
            return false;

        case MC_TESP:
            SEND_STRING("Que compareceu nesta unidade especializada espontaneamente na qualidade de testemunha, ");
            SEND_STRING("a fim de prestar depoimento sobre os fatos relatados no Reds, ");
            SEND_STRING("QUE investiga o crime do art. (xxxxx) que vitimou (xxxxx); ");
            SEND_STRING("QUE foi cientificado (a) do dever legal de dizer a verdade de tudo que souber e ");
            SEND_STRING("lhe for perguntado, sob pena de incorrer no crime de falso testemunho; INQUIRIDO disse QUE: ");
            return false;

        case MC_TINT:
            SEND_STRING("Que compareceu nesta unidade especializada devidamente intimado (a), na qualidade ");
            SEND_STRING("de testemunha, a fim de prestar depoimento sobre os fatos relatados no Reds (xxxxxx), ");
            SEND_STRING("QUE investiga o crime do art. (xxxxx) que vitimou (xxxxx); ");
            SEND_STRING("QUE foi cientificado (a) do dever legal de dizer a verdade de tudo que souber e lhe for ");
            SEND_STRING("perguntado, sob pena de incorrer no crime de falso testemunho; INQUIRIDO disse QUE: ");
            return false;

        case MC_SINT:
            SEND_STRING("Que compareceu nesta unidade especializada devidamente intimado (a), a fim de prestar ");
            SEND_STRING(DECLARACOES " sobre os fatos relatados no Reds (xxxxxx), ");
            SEND_STRING("QUE investiga o crime do art. (xxxxx) que vitimou (xxxxx); ");
            SEND_STRING("QUE foi devidamente cientificado dos seus direitos legais, dentre eles o de permanecer em ");
            SEND_STRING(SILENCIO "; PERGUNTADO disse QUE: ");
            return false;

        case MC_SCON:
            SEND_STRING("Que compareceu nesta unidade especializada devidamente conduzido (a), a fim de prestar ");
            SEND_STRING(DECLARACOES " sobre os fatos relatados no Reds (xxxxxx), ");
            SEND_STRING("QUE investiga o crime do art. (xxxxx) que vitimou (xxxxx); ");
            SEND_STRING("QUE foi devidamente cientificado dos seus direitos legais, dentre eles o de permanecer em ");
            SEND_STRING(SILENCIO "; PERGUNTADO disse QUE: ");
            return false;
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

void tc_a(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_A);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_ACTA, NULL);
            break;
        case TD_TRIPLE_TAP:
            process_record_user(MC_ACDI, NULL);
            break;
        default:
            break;
    }
}

void tc_d(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_DECL, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_DEPO, NULL);
            break;
        default:
            break;
    }
}

void tc_p(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_PESE, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_PESO, NULL);
            break;
        default:
            break;
    }
}

void tc_v(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_V);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_VINT, NULL);
            break;
        case TD_TRIPLE_TAP:
            process_record_user(MC_VESP, NULL);
            break;
        default:
            break;
    }
}

void tc_t(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_TEST, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_TINT, NULL);
            break;
        case TD_TRIPLE_TAP:
            process_record_user(MC_TESP, NULL);
            break;
        default:
            break;
    }
}

void tc_s(tap_dance_state_t *state, void *user_data) {
    tap_state.state = dance_state(state);
    switch (tap_state.state) {
        case TD_SINGLE_TAP:
            process_record_user(MC_SALI, NULL);
            break;
        case TD_DOUBLE_TAP:
            process_record_user(MC_SINT, NULL);
            break;
        case TD_TRIPLE_TAP:
            process_record_user(MC_SCON, NULL);
            break;
        default:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {[ESC_QUOT]  = ACTION_TAP_DANCE_FN(td_esc_quot),
                                          [TC_A]      = ACTION_TAP_DANCE_FN(tc_a),
                                          [TC_D]      = ACTION_TAP_DANCE_FN(tc_d),
                                          [TC_P]      = ACTION_TAP_DANCE_FN(tc_p),
                                          [TC_V]      = ACTION_TAP_DANCE_FN(tc_v),
                                          [TC_T]      = ACTION_TAP_DANCE_FN(tc_t),
                                          [TC_S]      = ACTION_TAP_DANCE_FN(tc_s),
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