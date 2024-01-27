#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "smart_thumbs.h"

typedef enum { SENTENCE_CASE_NONE, SENTENCE_CASE_STARTED, SENTENCE_CASE_FINISHING } sentence_case_state_t;

typedef struct {
    sentence_case_state_t state;
    uint16_t              start_time;
} sentence_case_t;

void                    start_sentence_case(void);
process_record_result_t process_sentence_case(uint16_t keycode, keyrecord_t *record);
