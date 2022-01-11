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

#include "leader.h"

LEADER_EXTERNS();

void process_leader_dictionary(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // Vim - Leader key + V + something

        // Vim - Select Whole Block
        SEQ_TWO_KEYS(KC_V, KC_B) {
            tap_code(KC_V);
            tap_code(KC_A);
            tap_code16(KC_LCBR);
            register_mods(MOD_LSFT);
            tap_code(KC_V);
            unregister_mods(MOD_LSFT);
            tap_code(KC_DOWN);
        }

        // Git - Leader key + G + something

        // Git - Commit
        SEQ_TWO_KEYS(KC_G, KC_C) {
            SEND_STRING("git commit -m \"\"");
            tap_code(KC_LEFT);
            tap_code(KC_LEFT);
        }

        // Process secret leader sequences
        process_leader_dictionary_secret();
    }
}

void leader_start(void) {
    leader_start_keymap();
}

void leader_end(void) {
    leader_end_keymap();
}

__attribute__ ((weak)) void leader_start_keymap(void) {}
__attribute__ ((weak)) void leader_end_keymap(void) {}
