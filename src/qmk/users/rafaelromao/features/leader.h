#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "secret.h"

typedef struct {
    bool isLeading;
} leader_t;

void process_leader_dictionary(void);