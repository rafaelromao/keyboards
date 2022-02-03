// Copyright 2021 Google LLC
// Copyright 2022 Rafael Romão @rafaelromao
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//
// For full documentation, see
// https://getreuer.info/posts/keyboards/select-word

#include "select_word.h"

extern os_t os;

enum { STATE_NONE, STATE_SELECTED, STATE_WORD, STATE_FIRST_LINE, STATE_LINE };

static uint8_t state = STATE_NONE;

bool process_select_word(uint16_t keycode, keyrecord_t* record, uint16_t sel_keycode) {

    if (keycode == KC_LSFT || keycode == KC_RSFT) { return true; }
    
    if (keycode == sel_keycode && record->event.pressed) {
        const uint8_t mods = get_mods();
        if ((mods & MOD_MASK_SHIFT) == 0) {
            // Select Word
            if (os.type == MACOS) {
                register_code(KC_LALT);
            } else {
                register_code(KC_LCTL);
            }
            if (state == STATE_NONE) {
                SEND_STRING(SS_TAP(X_RGHT) SS_TAP(X_LEFT));
            }
            register_code(KC_LSFT);
            register_code(KC_RGHT);
            state = STATE_WORD;
        } else {
            // Select Line
            if (state == STATE_NONE) {
                clear_mods();
                SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
                set_mods(mods);
                state = STATE_FIRST_LINE;
            } else {
                register_code(KC_DOWN);
                state = STATE_LINE;
            }
        }
        return false;
    }

    switch (state) {
        case STATE_WORD:
            unregister_code(KC_RGHT);
            unregister_code(KC_LSFT);
            if (os.type == MACOS) {
                unregister_code(KC_LALT);
            } else {
                unregister_code(KC_LCTL);
            }
            state = STATE_SELECTED;
            break;

        case STATE_FIRST_LINE:
            state = STATE_SELECTED;
            break;

        case STATE_LINE:
            unregister_code(KC_DOWN);
            state = STATE_SELECTED;
            break;

        case STATE_SELECTED:
            if (keycode == KC_ESC) {
                tap_code(KC_RGHT);
                state = STATE_NONE;
                return false;
            }
        default:
            state = STATE_NONE;
    }

    return true;
}
