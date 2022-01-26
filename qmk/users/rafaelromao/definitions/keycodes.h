/* Copyright 2021 Rafael Romão https://github.com/rafaelromao
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

#pragma once

#include "layers.h"

// Custom keycodes

enum {
    SS_BTIC = SAFE_RANGE,
    SS_DQUO,
    SS_SQUO,
    SS_CIRC,
    SS_TILD,
    TG_MAC,
    TG_WIN,
    TG_LIN,
    TG_M_ON,
    TG_M_OF,
    SP_CAP,
    SP_MOD,
    SS_MODP,
    SS_MODM
};

// Mod-taps

#define LSFTT_S LSFT_T(KC_S)
#define LSFTT_R LSFT_T(KC_R)
#define RSFTT_I RSFT_T(KC_I)
#define RSFTT_L RSFT_T(KC_L)
#define RSFTT_O RSFT_T(KC_O)

#define LCTLT_D LCTL_T(KC_D)
#define LCTLT_E LCTL_T(KC_E)
#define LCTLT_A LCTL_T(KC_A)
#define LCTLT_S LCTL_T(KC_S)
#define LC_UNDS LCTL_T(KC_UNDS)
#define RCTLT_K RCTL_T(KC_K)
#define RCTLT_A RCTL_T(KC_A)
#define RCTLT_E RCTL_T(KC_E)

#define LALTT_F LALT_T(KC_F)
#define LALTT_T LALT_T(KC_T)
#define LA_UNDS LALT_T(KC_UNDS)
#define RALTT_J RALT_T(KC_J)
#define RALTT_N RALT_T(KC_N)

#define LGUIT_V LGUI_T(KC_V)
#define LGUIT_D LGUI_T(KC_D)
#define LG_UNDS LGUI_T(KC_UNDS)
#define RGUIT_M RGUI_T(KC_M)
#define RGUIT_H RGUI_T(KC_H)

// One-shot mods

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

// Layer-taps

#define MOU_CAP LT(_MOUSE, SP_CAP)
#define MOU_0   LT(_MOUSE, KC_0)

#define NAV_MOD LT(_NAVIGATION, SP_MOD)

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_BSP LT(_RAISE, KC_BSPC)

#define KCA_FUN LT(_FUNCTIONS, KC_A)
#define KCF_FUN LT(_FUNCTIONS, KC_F)
#define KCW_FUN LT(_FUNCTIONS, KC_W)
#define UND_FUN LT(_FUNCTIONS, KC_UNDS)

#define KCO_MED LT(_MEDIA, KC_O)
#define KCC_MED LT(_MEDIA, KC_C)
#define UND_MED LT(_MEDIA, KC_UNDS)
#define DOT_MED LT(_MEDIA, KC_DOT)

// Layer transitions

#define DF_ROM DF(_ROMAK)
#define DF_QWE DF(_QWERTY)
#define DF_COL DF(_COLEMAK)
#define TO_RAI TO(_RAISE)
#define TG_RAI TG(_RAISE)
#define TT_RAI TT(_RAISE)
#define OS_LOW OSL(_LOWER)
#define TO_LOW TO(_LOWER)
#define TG_LOW TG(_LOWER)
#define TT_LOW TT(_LOWER)
#define MO_NAV MO(_NAVIGATION)
#define TO_NAV TO(_NAVIGATION_CLONE)
#define TG_NAV TG(_NAVIGATION_CLONE)
#define MO_MOU MO(_MOUSE)
#define TO_MOU TO(_MOUSE)
#define TG_MOU TG(_MOUSE)
#define MO_MAI MO(_MAINTENANCE)
#define TO_MAI TO(_MAINTENANCE)
#define TO_MED TO(_MEDIA)
#define TG_MED TG(_MEDIA)
#define OS_MED OSL(_MEDIA)
#define MO_FUN MO(_FUNCTIONS)
#define TO_FUN TO(_FUNCTIONS)
#define TG_FUN TG(_FUNCTIONS)

// Custom Shortcuts

#define HYPR_A HYPR(KC_A)
#define HYPR_V HYPR(KC_V)

#define CB_SELC LGUI(KC_A)
#define CB_SAVE LGUI(KC_S)
#define CB_UNDO LGUI(KC_Z)
#define CB_COPY LGUI(KC_C)
#define CB_PAST LGUI(KC_V)
