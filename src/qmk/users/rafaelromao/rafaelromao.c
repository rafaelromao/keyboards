#include "rafaelromao.h"

extern os_t os;

// Led update

bool led_update_user(led_t led_state) {
    if (led_state.caps_lock != has_smart_case(CAPS_LOCK)) {
        toggle_capslock(led_state.caps_lock);
    }
    return true;
}

// Matrix scan

__attribute__((weak)) void matrix_scan_keymap(void) {}

void matrix_scan_user(void) {
    check_disable_smart_case();
    check_ngrams_timeout();
    check_oneshot_mods_timeout();
    process_leader_dictionary();
    matrix_scan_keymap();
}

// Process record

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process window swapper
    switch (process_window_swapper(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process smart case
    switch (process_smart_case(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process smart thumb keys
    switch (process_smart_thumb_keys(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process ngrams
    switch (process_ngrams(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process taphold
    switch (process_taphold(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process accentuation
    switch (process_accentuated_characters(keycode, record)) {
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

    // Process custom_shift
    switch (process_custom_shift(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process custom_shotcuts
    switch (process_custom_shortcuts(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process secrets
    switch (process_secrets(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process select word
    switch (process_select_word(keycode, record)) {
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

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    return get_tapping_force_hold_result(keycode);
}

// Dynamic macros

void dynamic_macro_record_start_user(void) {}

void dynamic_macro_play_user(int8_t direction) {}

void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {}

void dynamic_macro_record_end_user(int8_t direction) {}
