#include "rafaelromao.h"

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
    check_oneshot_timeout();
    check_repeat_key_timeout();
    matrix_scan_keymap();
#ifdef MOUSE_ENABLE
    orbital_mouse_task();
#endif
}

// Process record

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef MOUSE_ENABLE
    // Process Orbital Mouse
    process_orbital_mouse(keycode, record);
#endif

    // Process custom oneshot
    switch (process_custom_oneshot(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process Sentence Case
    switch (process_sentence_case(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };
    // Process swapper
    switch (process_swapper(keycode, record)) {
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

    // Process custom_shift
    switch (process_custom_shift(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process custom taphold
    switch (process_taphold(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process accents
    switch (process_accents(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    // Process common shortcuts
    switch (process_common_shortcuts(keycode, record)) {
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

#ifdef DYNAMIC_MACRO_ENABLE
// Dynamic macros

void dynamic_macro_record_start_user(int8_t direction) {}

void dynamic_macro_play_user(int8_t direction) {}

void dynamic_macro_record_key_user(int8_t direction, keyrecord_t *record) {}

void dynamic_macro_record_end_user(int8_t direction) {}
#endif
