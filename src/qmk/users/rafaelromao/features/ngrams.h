#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "os_toggle.h"

typedef struct {
    uint16_t timer;
} ngrams_timer_t;

process_record_result_t process_ngrams(uint16_t keycode, keyrecord_t *record);
void check_ngrams_timeout(void);
