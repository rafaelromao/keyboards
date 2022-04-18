#include QMK_KEYBOARD_H

#include "smart_case.h"

static smart_case_t smart_case = {
    .timer = 0
};

bool smart_case_timer_expired(void) {
    return smart_case.timer > 0 && (timer_elapsed(smart_case.timer) > 5 * CUSTOM_ONESHOT_TIMEOUT);
}

void start_smart_case_timer(void) {
    smart_case.timer = timer_read();
}

void clear_smart_case_timer(void) {
    smart_case.timer = 0;
}

void disable_smart_case(bool isCapsLocked) {
    if (isCapsLocked) {
        tap_code(KC_CAPS);
    }
}

void disable_smart_case_when_timeout(bool isCapsLocked) {
    // Disable capslock if timer expired
    if (smart_case_timer_expired()) {
        clear_smart_case_timer();
        disable_smart_case(isCapsLocked);
    }
}

void check_start_smart_case_timer(bool isCapsLocked) {
    // Start timer to automatically disable capslock
    if (isCapsLocked) {
        start_smart_case_timer();
    } else {
        clear_smart_case_timer();
    }
}

void check_disable_smart_case(void) {
    // Disable smart_case if autodisable timer expired
    disable_smart_case_when_timeout(host_keyboard_led_state().caps_lock);
}

process_record_result_t process_smart_case_timer_extension(uint16_t keycode, keyrecord_t *record) {
    if (keycode == SS_CAPS) {
        if (record->event.pressed) {
            clear_smart_case_timer();
            tap_code(KC_CAPS);
        }
        return PROCESS_RECORD_RETURN_FALSE;
    }

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
            keycode = extract_base_tapping_keycode(keycode);
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
                start_smart_case_timer();
        }
        // Deactivate capslock
        switch (keycode) {
            case KC_ESC:
                clear_smart_case_timer();
                disable_smart_case(host_keyboard_led_state().caps_lock);
                break;
        }
    }

    return PROCESS_RECORD_CONTINUE;
}

