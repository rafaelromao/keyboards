#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "process_record_result.h"

typedef enum {
    MACOS,
    WINDOWS,
    LINUX
} os_type_t;

typedef struct {
    os_type_t type;
} os_t;

process_record_result_t process_os_toggle(uint16_t keycode, keyrecord_t *record);
