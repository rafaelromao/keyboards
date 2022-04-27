#pragma once

#include QMK_KEYBOARD_H
#include "process_record_result.h"
#include "../definitions/keycodes.h"

typedef enum {
    NO_CASE = 1 << 0,
    CAPS_LOCK = 1 << 1,
    WORD_CASE = 1 << 2,
    SNAKE_CASE = 1 << 3,
    KEBAB_CASE = 1 << 4,
    CAMEL_CASE = 1 << 5, 
} smart_case_type_t;

typedef struct {
    smart_case_type_t type;
    uint16_t timer;
} smart_case_t;

void toggle_capslock_smart_case(bool capslock);
void check_disable_smart_case(void);
process_record_result_t process_smart_case(uint16_t keycode, keyrecord_t *record);

void disable_smart_case(void);
void set_smart_case(smart_case_type_t smart_case_types);
void set_smart_case_for_mods(keyrecord_t *record);
bool has_smart_case(smart_case_type_t smart_case_types);
bool has_any_smart_case(void);