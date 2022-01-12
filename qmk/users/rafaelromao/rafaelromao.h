/* Copyright 2021 Rafael Romão @rafaelromao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#include "definitions/layers.h"
#include "definitions/keycodes.h"
#include "definitions/keymap_blocks.h"
#include "features/taphold.h"
#include "features/persistent_layers.h"
#include "features/tapdance.h"
#include "features/capslock_timer.h"
#include "features/mouselayer_toggle.h"
#include "features/os_toggle.h"
#include "features/macros.h"
#include "features/combos.h"
#include "features/leader.h"
#include "features/default_mod_key.h"
#include "features/capitalize_key.h"

void matrix_scan_keymap(void);
