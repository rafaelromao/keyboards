#pragma once

#include QMK_KEYBOARD_H
#include "process_record_result.h"
#include "../definitions/keycodes.h"

typedef struct {
    uint16_t timer;
} smart_case_t;

void check_start_smart_case_timer(bool isCapsLocked);
void check_disable_smart_case(void);
process_record_result_t process_smart_case_timer_extension(uint16_t keycode, keyrecord_t *record);
