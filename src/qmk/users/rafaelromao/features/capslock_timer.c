#include QMK_KEYBOARD_H

#include "capslock_timer.h"

static capslock_timer_t capslock_timer = {
    .timer = 0
};

bool capslock_timer_expired(void) {
    return capslock_timer.timer > 0 && (timer_elapsed(capslock_timer.timer) > 5 * ONESHOT_TIMEOUT);
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
        // Deactivate capslock
        switch (keycode) {
            case KC_ESC:
                clear_capslock_timer();
                disable_capslock(host_keyboard_led_state().caps_lock);
                break;
        }
    }

    return PROCESS_RECORD_CONTINUE;
}

