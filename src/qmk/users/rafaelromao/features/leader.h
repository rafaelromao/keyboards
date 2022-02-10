#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "secret.h"

void process_leader_dictionary(void);
void leader_start_keymap(void);
void leader_end_keymap(void);
