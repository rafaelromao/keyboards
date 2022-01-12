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

#include "os_toggle.h"

os_t os = {
    .type = MACOS
};

process_record_result_t process_os_toggle(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        // Change OS type

        case TG_MAC:
            if (record->event.pressed) {
                os.type = MACOS;
            }
            return false;

        case TG_WIN:
            if (record->event.pressed) {
                os.type = WINDOWS;
            }
            return false;

        case TG_LIN:
            if (record->event.pressed) {
                os.type = LINUX;
            }
            return false;

    }

    return PROCESS_RECORD_CONTINUE;
}
