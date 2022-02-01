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

#include "window_swapper.h"

extern os_t os;

static bool swapping = false;

process_record_result_t process_window_swapper(uint16_t keycode, keyrecord_t *record) {

    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;

    if (swapping && keycode != SS_SWIN) {
        swapping = false;
        if (isWindowsOrLinux) {
            unregister_mods(MOD_LALT);
        } else {
            unregister_mods(MOD_LGUI);
        }
    }

    switch (keycode) {

        // Swap Windows
        case SS_SWIN:
            if (record->event.pressed) {
                if (!swapping) {
                    swapping = true;
                    if (isWindowsOrLinux) {
                        register_mods(MOD_LALT);
                    } else {
                        register_mods(MOD_LGUI);
                    }
                }
                tap_code(KC_TAB);
            }
            return PROCESS_RECORD_RETURN_FALSE;

    }

    return PROCESS_RECORD_CONTINUE;
}