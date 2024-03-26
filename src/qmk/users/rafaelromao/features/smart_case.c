#include QMK_KEYBOARD_H

#include "smart_case.h"

smart_case_t smart_case = {.timer = 0, .type = NO_CASE};

void clear_shift(void) {
    del_oneshot_mods(MOD_MASK_SHIFT);
    unregister_mods(MOD_MASK_SHIFT);
}

bool smart_case_timer_expired(void) {
    return smart_case.timer > 0 && (timer_elapsed(smart_case.timer) > 5 * ONESHOT_TIMEOUT);
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
    clear_shift();
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
    layer_move(_ALPHA1);
}

void check_disable_smart_case(void) {
    if (smart_case_timer_expired()) {
        disable_smart_case();
    }
}

void enable_smartcase(smart_case_type_t smart_case_types) {
    if (smart_case.type == NO_CASE) {
        smart_case.type = smart_case_types;
    } else {
        smart_case.type = smart_case.type | smart_case_types;
    }
    start_smart_case_timer();
}

void enable_capslock(void) {
    enable_smartcase(CAPS_LOCK);
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void set_smart_case(smart_case_type_t smart_case_types) {
    if (smart_case_types & NUMPAD_LOCK) {
        disable_smart_case();
        layer_on(_NUMPAD);
    }
    if (smart_case_types & NUM_CASE) {
        disable_smart_case();
        layer_on(_NUMPAD);
    }
    if (smart_case_types & CAPS_LOCK) {
        enable_capslock();
        return;
    }
    if (smart_case_types & CAMEL_CASE) {
        // Setting CapsWord with CamelCase already set, makes Pascal Case
        if (has_smart_case(WORD_CASE)) {
            disable_smart_case();
            add_oneshot_mods(MOD_LSFT);
        }
    }
    enable_smartcase(smart_case_types);
}

bool has_smart_case(smart_case_type_t smart_case_types) {
    return smart_case.type & smart_case_types;
}

bool has_any_smart_case(void) {
    return smart_case.type != NO_CASE;
}

void toggle_capslock(bool capslock) {
    if (capslock) {
        set_smart_case(CAPS_LOCK);
    } else {
        disable_smart_case();
    }
}

void toggle_smart_case(smart_case_type_t smart_case_types) {
    if (has_smart_case(smart_case_types)) {
        disable_smart_case();
    } else {
        set_smart_case(smart_case_types);
    }
}

void set_smart_case_for_mods(void) {
    int8_t mods = get_mods();
    disable_smart_case();
    if (mods == 0 || mods & MOD_BIT(KC_LCTL)) {
        toggle_smart_case(WORD_CASE);
        toggle_capslock(!host_keyboard_led_state().caps_lock);
    }
    if (mods & MOD_BIT(KC_RCTL)) {
        toggle_capslock(!host_keyboard_led_state().caps_lock);
    }
    if (mods & MOD_BIT(KC_LALT)) {
        toggle_smart_case(NUMPAD_LOCK);
    } else if (mods & MOD_BIT(KC_RALT)) {
        toggle_smart_case(NUM_CASE);
    }
    if (mods & MOD_BIT(KC_LSFT)) {
        toggle_smart_case(CAMEL_CASE);
    }
    if (mods & MOD_BIT(KC_RSFT)) {
        toggle_smart_case(SLASH_CASE);
    }
    if (mods & MOD_BIT(KC_LGUI)) {
        toggle_smart_case(SNAKE_CASE);
    }
    if (mods & MOD_BIT(KC_RGUI)) {
        toggle_smart_case(KEBAB_CASE);
    }
}

static bool spacing = false;

process_record_result_t process_smart_case(uint16_t keycode, keyrecord_t *record) {
    if (has_smart_case(NUMPAD_LOCK)) {
        start_smart_case_timer();
        return PROCESS_RECORD_CONTINUE;
    }
    if (has_any_smart_case() && record->event.pressed) {
        // Earlier return if this has not been considered tapped yet.
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                if (record->tap.count == 0) {
                    return PROCESS_RECORD_CONTINUE;
                }
        }
        // Get the base tapping keycode of a mod- or layer-tap key.
        uint16_t key = extract_tapping_keycode(keycode);
        // Check if not typing space
        if (key != KC_SPC) {
            spacing = false;
        }
        // Extend, process or break case
        switch (keycode) {
            case RAI_A2:
            case NAV_REP:
            case FNA_REP:
            case NAV_MAG:
            case MED_CAS:
                start_smart_case_timer();
                return PROCESS_RECORD_CONTINUE;
        }
        switch (key) {
            case KC_SPC:
                if (spacing) {
                    if (has_smart_case(CAMEL_CASE)) {
                        disable_smart_case();
                    } else if (has_smart_case(SNAKE_CASE) || has_smart_case(KEBAB_CASE) || has_smart_case(SLASH_CASE)) {
                        tap_code(KC_BSPC);
                        disable_smart_case();
                    }
                    tap_code(KC_SPC);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else {
                    if (has_smart_case(NUM_CASE)) {
                        tap_code(KC_SPC);
                        disable_smart_case();
                        return PROCESS_RECORD_RETURN_FALSE;
                    }
                    spacing = true;
                }
                if (has_smart_case(WORD_CASE) && !(has_smart_case(SNAKE_CASE)) && !(has_smart_case(CAMEL_CASE))) {
                    disable_smart_case();
                    return PROCESS_RECORD_CONTINUE;
                }
                if (has_smart_case(SNAKE_CASE)) {
                    tap_code16(KC_UNDS);
                    start_smart_case_timer();
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                if (has_smart_case(KEBAB_CASE)) {
                    tap_code16(KC_MINS);
                    start_smart_case_timer();
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                if (has_smart_case(SLASH_CASE)) {
                    tap_code(KC_SLSH);
                    start_smart_case_timer();
                    return PROCESS_RECORD_RETURN_FALSE;
                }
                if (has_smart_case(CAMEL_CASE)) {
                    add_oneshot_mods(MOD_LSFT);
                    start_smart_case_timer();
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            case KC_A ... KC_Z:
            case KC_1 ... KC_0:
            case KC_BSPC:
            case KC_MINS:
            case KC_UNDS:
            case KC_LEFT:
            case KC_RIGHT:
            case KC_UP:
            case KC_DOWN:
            case KC_HOME:
            case KC_END:
                start_smart_case_timer();
                break;
            case KC_DOT:
            case KC_SLSH:
                if (has_smart_case(SLASH_CASE) || has_smart_case(NUM_CASE)) {
                    start_smart_case_timer();
                    break;
                }
            case KC_PERC:
            case KC_COMM:
            case KC_PLUS:
            case KC_EQL:
            case KC_COLN:
            case KC_LPRN:
            case KC_RPRN:
            case OM_BTN2:
            case OM_L:
            case OM_U:
            case OM_R:
            case OM_W_D:
            case OM_D:
            case OM_W_U:
            case OM_RELS:
            case OM_HLDS:
                if (has_smart_case(NUM_CASE)) {
                    start_smart_case_timer();
                    break;
                }
            default:
                disable_smart_case();
                if (is_shift_macro_keycode(key)) {
                    process_macros(key, NULL);
                } else if (is_accent_macro_keycode(key)) {
                    process_accents(key, NULL);
                } else {
                    tap_code16(key);
                }
                return PROCESS_RECORD_RETURN_FALSE;
        }
    }
    return PROCESS_RECORD_CONTINUE;
}