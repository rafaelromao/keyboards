#pragma once

#include QMK_KEYBOARD_H
#include "process_record_result.h"
#include "../definitions/keycodes.h"

typedef enum {
    NO_CASE = 0,
    CAPS_LOCK = 1 << 0,
    CAPS_WORD = 1 << 1,
    SNAKE_CASE = 1 << 2,
    KEBAB_CASE = 1 << 3,
    CAMEL_CASE = 1 << 4 
} smart_case_type_t;

typedef struct {
    uint16_t timer;
    smart_case_type_t type;
} smart_case_t;

void check_start_smart_case_timer(void);
void check_disable_smart_case(void);
process_record_result_t process_smart_case_timer_extension(uint16_t keycode, keyrecord_t *record);

void set_smart_case(smart_case_type_t smart_case_types);
bool has_smart_case(smart_case_type_t smart_case_types);