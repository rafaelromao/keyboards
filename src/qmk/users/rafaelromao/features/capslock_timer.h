#pragma once

#include QMK_KEYBOARD_H
#include "process_record_result.h"

typedef struct {
    uint16_t timer;
} capslock_timer_t;

void check_start_capslock_timer(bool isCapsLocked);
void check_disable_capslock(void);
process_record_result_t process_capslock_timer_extension(uint16_t keycode, keyrecord_t *record);
