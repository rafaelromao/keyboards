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

#include "capitalize_key.h"

extern os_t os;

process_record_result_t process_capitalize_key(uint16_t keycode, keyrecord_t *record) {

    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isCapsLocked = host_keyboard_led_state().caps_lock;

    switch (keycode) {

        case MOU_CAP:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isCapsLocked) {
                        tap_code(KC_CAPS); // Disable capslock
                    } else {
                        if (!isOneShotShift) {
                            add_oneshot_mods(MOD_BIT(KC_LSFT));
                        } else {
                            del_oneshot_mods(MOD_BIT(KC_LSFT));
                            unregister_mods(MOD_BIT(KC_LSFT));
                            tap_code(KC_CAPS); // Enable capslock
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }

    }

    return PROCESS_RECORD_CONTINUE;
}
