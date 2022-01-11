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

#include "default_mod_key.h"

extern os_t os;

void clear_locked_and_oneshot_mods(void) {
    uint8_t locked_oneshot_mods = 0;
    uint8_t oneshot_mods = 0;
    if ((locked_oneshot_mods = get_oneshot_locked_mods())) {
        clear_oneshot_locked_mods();
    }
    if ((oneshot_mods = get_oneshot_mods())) {
        clear_oneshot_mods();
    }
    unregister_mods(locked_oneshot_mods);
    unregister_mods(oneshot_mods);
}

bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift) {
    return (isWindowsOrLinux && !isOneShotShift) || (!isWindowsOrLinux && isOneShotShift);
}

process_record_result_t process_default_mod_key(uint16_t keycode, keyrecord_t *record) {

    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotDefaultMod = (!isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_GUI)) || (isWindowsOrLinux && (get_oneshot_mods() & MOD_MASK_CTRL)) ;
    bool isLockedOneShotShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || isLockedOneShotShift;
    bool isOneShotCtrl = get_oneshot_mods() & MOD_MASK_CTRL || get_oneshot_locked_mods() & MOD_MASK_CTRL;
    bool isOneShotAlt = get_oneshot_mods() & MOD_MASK_ALT || get_oneshot_locked_mods() & MOD_MASK_ALT;
    bool isOneShotGui = get_oneshot_mods() & MOD_MASK_GUI || get_oneshot_locked_mods() & MOD_MASK_GUI;
    bool isAnyOneShotButShift = isOneShotCtrl || isOneShotAlt || isOneShotGui;

    switch (keycode) {

        case NAV_MOD:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (isAnyOneShotButShift || isLockedOneShotShift) {
                        clear_locked_and_oneshot_mods();
                    } else if (!isOneShotDefaultMod) {
                        if (isOneShotShift) {
                            clear_locked_and_oneshot_mods();
                        }
                        if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                            add_oneshot_mods(MOD_BIT(KC_LCTL));
                        } else {
                            add_oneshot_mods(MOD_BIT(KC_LGUI));
                        }
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_RETURN_TRUE;

    }

    return PROCESS_RECORD_CONTINUE;
}
