#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "custom_oneshot.h"

process_record_result_t process_sentence_case(uint16_t keycode, keyrecord_t *record);
