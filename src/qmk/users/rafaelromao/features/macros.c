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

#include "macros.h"

extern os_t os;

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        // Standalone accent characters

        case SS_BTIC:
            if (record->event.pressed) {
                SEND_STRING("` ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_DQUO:
            if (record->event.pressed) {
                SEND_STRING("\" ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_SQUO:
            if (record->event.pressed) {
                SEND_STRING("' ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_CIRC:
            if (record->event.pressed) {
                SEND_STRING("^ ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_TILD:
            if (record->event.pressed) {
                SEND_STRING("~ ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_DEG:
            if (record->event.pressed) {
                if (os.type == MACOS) {
                    tap_code16(LSFT(RALT(KC_8)));
                } else {
                    tap_code16(LSFT(LCTL(KC_2)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;
            
    }

    return PROCESS_RECORD_CONTINUE;
}
