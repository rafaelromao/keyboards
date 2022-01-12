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

#include "capslock_timer.h"

static capslock_timer_t capslock_timer = {
    .timer = 0
};

bool capslock_timer_expired(void) {
    return capslock_timer.timer > 0 && (timer_elapsed(capslock_timer.timer) > 2 * ONESHOT_TIMEOUT);
}

void start_capslock_timer(void) {
    capslock_timer.timer = timer_read();
}

void clear_capslock_timer(void) {
    capslock_timer.timer = 0;
}

void disable_capslock(bool isCapsLocked) {
    if (isCapsLocked) {
        tap_code(KC_CAPS);
    }
}

void disable_capslock_when_timeout(bool isCapsLocked) {
    // Disable capslock if timer expired
    if (capslock_timer_expired()) {
        clear_capslock_timer();
        disable_capslock(isCapsLocked);
    }
}

void check_start_capslock_timer(bool isCapsLocked) {
    // Start timer to automatically disable capslock
    if (isCapsLocked) {
        start_capslock_timer();
    } else {
        clear_capslock_timer();
    }
}

void check_disable_capslock(void) {
    // Disable capslock if autodisable timer expired
    bool isCapsLocked = host_keyboard_led_state().caps_lock;
    disable_capslock_when_timeout(isCapsLocked);
}

process_record_result_t process_capslock_timer_extension(uint16_t keycode, keyrecord_t *record) {
    // Extend autodisable capslock timer
    bool isCapsLocked = host_keyboard_led_state().caps_lock;
    if (isCapsLocked) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            // Earlier return if this has not been considered tapped yet.
            if (record->tap.count == 0) {
                return PROCESS_RECORD_CONTINUE;
            }
            // Get the base tapping keycode of a mod- or layer-tap key.
            keycode &= 0xff;
        }
        // Extend capslock timer
        switch (keycode) {
            case KC_A ... KC_Z:
            case KC_1 ... KC_0:
            case KC_BSPC:
            case KC_MINS:
            case KC_UNDS:
            case KC_SPC:
            case KC_LEFT:
            case KC_RIGHT:
            case KC_HOME:
            case KC_END:
                start_capslock_timer();
        }
    }

    return PROCESS_RECORD_CONTINUE;
}

