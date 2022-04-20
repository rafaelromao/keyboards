#include QMK_KEYBOARD_H

#include "smart_case.h"

static smart_case_t smart_case = {
    .timer = 0,
    .type = NO_CASE
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

void disable_smart_case(void) {
    smart_case.type = NO_CASE;
    clear_smart_case_timer();
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void check_disable_smart_case(void) {
    if (smart_case_timer_expired()) {
        disable_smart_case();
    }
}

void enable_capslock(void) {
    smart_case.type = CAPS_LOCK;
    start_smart_case_timer();
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void enable_smartcase(smart_case_type_t smart_case_types) {
    smart_case.type = smart_case.type | smart_case_types;
    start_smart_case_timer();
}

void set_smart_case(smart_case_type_t smart_case_types) {
    if (smart_case_types & NO_CASE)  {
        disable_smart_case();
        return;
    }
    if (smart_case_types & CAPS_LOCK) {
        enable_capslock();
        return;
    }
    enable_smartcase(smart_case_types);
}

bool has_smart_case(smart_case_type_t smart_case_types) {
    return smart_case.type & smart_case_types;
}

bool has_any_smart_case(void) {
    return smart_case.type > 1;
}

void toggle_capslock_smart_case(bool capslock) {
    if (capslock) {
        set_smart_case(CAPS_LOCK);
    } else {
        set_smart_case(NO_CASE);
    }
}

void toggle_smart_case(smart_case_type_t smart_case_types) {
    if (has_smart_case(smart_case_types)) {
        set_smart_case(NO_CASE);
    } else {
        set_smart_case(smart_case_types);
    }
}

process_record_result_t process_smart_case_options(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case SS_WORD:
                toggle_smart_case(CAPS_WORD);
            case SS_CAPS:
                toggle_capslock_smart_case(!host_keyboard_led_state().caps_lock);
                return PROCESS_RECORD_RETURN_FALSE;
        }
    }
    return PROCESS_RECORD_CONTINUE;
}

void set_smart_case_for_mods(void, keyrecord_t *record) {
    set_smart_case(NO_CASE);
    int8_t mods = get_mods();
    if (mods == 0) {
        process_smart_case_options(SS_CAPS, record);
    }
    if (mods & MOD_MASK_CTRL) {
        process_smart_case_options(SS_WORD, record);
    }
    if (mods & MOD_MASK_SHIFT) {
        process_smart_case_options(SS_SNAK, record);
        return;
    }
    if (mods & MOD_MASK_ALT) {
        process_smart_case_options(SS_KBAB, record);
        return;
    }
    if (mods & MOD_MASK_GUI) {
        process_smart_case_options(SS_CAML, record);
        return;
    }
}

process_record_result_t process_smart_case_chars(uint16_t keycode, keyrecord_t *record) {
    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_smart_case_extention(uint16_t keycode, keyrecord_t *record) {
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
                disable_smart_case();
                break;
        }
    }
    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_smart_case(uint16_t keycode, keyrecord_t *record) {

    switch (process_smart_case_extention(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    switch (process_smart_case_chars(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    switch (process_smart_case_options(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    return PROCESS_RECORD_CONTINUE;
}