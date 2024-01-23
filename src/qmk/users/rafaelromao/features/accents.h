#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "os_toggle.h"
#include "smart_thumbs.h"

process_record_result_t process_accents(uint16_t keycode, keyrecord_t *record);