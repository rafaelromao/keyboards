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

void tap_accent_dead_key(uint16_t keycode) {
    switch (keycode) {
        case SS_GV_A:
            tap_code16(KC_GRV);
            break;
        case SS_CR_A:
        case SS_CR_E:
        case SS_CR_O:
            tap_code16(KC_CIRC);
            break;
        case SS_TL_A:
        case SS_TL_O:
            tap_code16(KC_TILD);
            break;
        case SS_SQ_C:
        case SS_SQ_A:
        case SS_SQ_E:
        case SS_SQ_I:
        case SS_SQ_O:
        case SS_SQ_U:
            tap_code(KC_QUOT);
            break;
    }
}

void tap_accent_tap_key(uint32_t keycode) {
    switch (keycode) {
        case SS_GV_A:
        case SS_CR_A:
        case SS_TL_A:
        case SS_SQ_A:
            tap_code(KC_A);
            break;
        case SS_CR_E:
        case SS_SQ_E:
            tap_code(KC_E);
            break;
        case SS_TL_O:
        case SS_CR_O:
        case SS_SQ_O:
            tap_code(KC_O);
            break;
        case SS_SQ_I:
            tap_code(KC_I);
            break;
        case SS_SQ_U:
            tap_code(KC_U);
            break;
        case SS_SQ_C:
            tap_code(KC_C);
            break;
    }
}

bool is_accentuated_keycode(uint16_t keycode) {
    switch (keycode) {
        case SS_GV_A:
        case SS_CR_A:
        case SS_TL_A:
        case SS_SQ_A:
        case SS_CR_E:
        case SS_SQ_E:
        case SS_SQ_I:
        case SS_TL_O:
        case SS_CR_O:
        case SS_SQ_O:
        case SS_SQ_U:
        case SS_SQ_C:
            return true;
    }
    return false;
}

process_record_result_t process_accentuated_characters(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    if (!is_accentuated_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isShifted = get_oneshot_mods() & MOD_MASK_SHIFT;

    clear_locked_and_oneshot_mods();

    tap_accent_dead_key(keycode);
    if (isShifted) {
        register_mods(MOD_LSFT);
    }
    tap_accent_tap_key(keycode);
    if (isShifted) {
        unregister_mods(MOD_LSFT);
    }

    return PROCESS_RECORD_RETURN_FALSE;
}

static bool swapping = false;

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {

    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;

    if (swapping && keycode != SS_SWIN) {
        swapping = false;
        if (isWindowsOrLinux) {
            unregister_mods(MOD_LALT);
        } else {
            unregister_mods(MOD_LGUI);
        }
    }

    switch (process_accentuated_characters(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {

        // Shift+Backspace for Delete (when not one-shot)

        case KC_BSPC:
        case RAI_BSP:
            if (record->event.pressed) {
                if (isShifted && !isOneShotShift) {
                    tap_code(KC_DEL);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            return PROCESS_RECORD_RETURN_TRUE;

        // Ignore space for one-shot shift
        case LOW_SPC:
        case KC_SPC:
            if (record->event.pressed) {
                if (isOneShotShift) {
                    tap_code(KC_SPC);
                    add_oneshot_mods(MOD_LSFT);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            return PROCESS_RECORD_CONTINUE;

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
            
        // Zoom shortcuts

        case SS_MODP:
            if (record->event.pressed) {
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("+"));
                } else {
                    SEND_STRING(SS_LGUI("+"));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_MODM:
            if (record->event.pressed) {
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("-"));
                } else {
                    SEND_STRING(SS_LGUI("-"));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

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

        // Fix layer-tap using Underscore
        case UND_MED:
        case UND_FUN:
        case LG_UNDS:
        case LA_UNDS:
        case LC_UNDS:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    tap_code16(KC_UNDS);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
    }

    return PROCESS_RECORD_CONTINUE;
}
