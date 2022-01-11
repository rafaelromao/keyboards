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

#include "rafaelromao.h"

extern os_t os;

// Led update

__attribute__ ((weak)) bool led_update_user(led_t led_state) {
    check_start_capslock_timer(led_state.caps_lock);
    return true;
}

// Matrix scan

__attribute__ ((weak)) void matrix_scan_keymap(void) {
}

__attribute__ ((weak)) void matrix_scan_user(void) {
    check_disable_capslock();
    process_leader_dictionary();
    matrix_scan_keymap();
}

// Process record

__attribute__ ((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // Extend capslock timer
    process_capslock_timer_extension(keycode, record);

    // Process combos
    switch (process_combos(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process macros
    switch (process_macros(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process default modifier key
    switch (process_default_mod_key(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process capitalize key
    switch (process_capitalize_key(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process persistent layers
    switch (process_persistent_layers(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process mouse layer
    switch (process_mouselayer(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process OS toggle
    switch (process_os_toggle(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    return true;
}

// Tap-hold configuration

__attribute__ ((weak)) bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return get_hold_on_other_key_press_result(keycode);
}

__attribute__ ((weak)) bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return get_tapping_force_hold_result(keycode);
}
