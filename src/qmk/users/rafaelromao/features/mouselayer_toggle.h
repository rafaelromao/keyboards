#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "process_record_result.h"

typedef struct {
    bool enabled;
} mouselayer_t;

process_record_result_t process_mouselayer(uint16_t keycode, keyrecord_t *record);
