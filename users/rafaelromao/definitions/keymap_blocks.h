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

#include QMK_KEYBOARD_H
#include "keycodes.h"

#define ___________________QWERTY_L1___________________ KC_Q    , KC_W    , KC_E    , KC_R    , KC_T
#define ___________________QWERTY_L2___________________ KCA_FUN , LSFTT_S , LCTLT_D , LALTT_F , KC_G
#define ___________________QWERTY_L3___________________ KC_Z    , KC_X    , KC_C    , LGUIT_V , KC_B
#define ____QWERTY_L4____                                                             NAV_MOD , LOW_SPC

#define ___________________QWERTY_R1___________________ KC_Y    , KC_U    , KC_I    , KC_O    , KC_P
#define ___________________QWERTY_R2___________________ KC_H    , RALTT_J , RCTLT_K , RSFTT_L , UND_MED
#define ___________________QWERTY_R3___________________ KC_N    , RGUIT_M , KC_COMM , TD_DOTD , TD_SCLE
#define ____QWERTY_R4____                               RAI_BSP , MOU_CAP

#define ___________________COLEMAK_L1__________________ KC_Q    , KC_W    , KC_F    , KC_P    , KC_B
#define ___________________COLEMAK_L2__________________ KCA_FUN , LSFTT_R , LCTLT_S , LALTT_T , KC_G
#define ___________________COLEMAK_L3__________________ KC_Z    , KC_X    , KC_C    , LGUIT_D , KC_V
#define ____COLEMAK_L4___                                                             NAV_MOD , LOW_SPC

#define ___________________COLEMAK_R1__________________ KC_J    , KC_L    , KC_U    , KC_Y    , KC_UNDS
#define ___________________COLEMAK_R2__________________ KC_M    , RALTT_N , RCTLT_E , RSFTT_I , KCO_MED
#define ___________________COLEMAK_R3__________________ KC_K    , RGUIT_H , KC_COMM , TD_DOTD , TD_SCLE
#define ____COLEMAK_R4___                               RAI_BSP , MOU_CAP

#define ___________________LOWER_L1____________________ KC_ESC  , TD_PARB , KC_RPRN , KC_BSLS , SS_TILD
#define ___________________LOWER_L2____________________ SS_BTIC , SS_DQUO , SS_SQUO , KC_AMPR , KC_PIPE
#define ___________________LOWER_L3____________________ KC_AT   , TD_SQRB , KC_RBRC , KC_QUES , KC_HASH
#define ____LOWER_L4_____                                                             _______ , XXXXXXX

#define ___________________LOWER_R1____________________ XXXXXXX , KC_7    , KC_8    , KC_9    , KC_ENT
#define ___________________LOWER_R2____________________ XXXXXXX , KC_4    , KC_5    , KC_6    , TD_DOTC
#define ___________________LOWER_R3____________________ XXXXXXX , KC_1    , KC_2    , KC_3    , XXXXXXX
#define ____LOWER_R4_____                               _______ , MOU_0

#define ___________________RAISE_L1____________________ KC_ESC  , XXXXXXX , _______ , KC_DQUO , XXXXXXX
#define ___________________RAISE_L2____________________ _______ , KC_CIRC , KC_TILD , KC_QUOT , XXXXXXX
#define ___________________RAISE_L3____________________ XXXXXXX , XXXXXXX , _______ , KC_GRV  , XXXXXXX
#define ____RAISE_L4_____                                                             _______ , _______

#define ___________________RAISE_R1____________________ SS_CIRC , KC_DLR  , TD_CURB , KC_RCBR , KC_ENT
#define ___________________RAISE_R2____________________ KC_PLUS , KC_MINS , KC_EQL  , KC_EXLM , KC_PERC
#define ___________________RAISE_R3____________________ KC_ASTR , KC_SLSH , TD_ANGB , KC_GT   , KC_COLN
#define ____RAISE_R4_____                               XXXXXXX , _______

#define ___________________NAVIGATION_L1_______________ KC_ESC  , XXXXXXX , KC_TAB  , XXXXXXX , XXXXXXX
#define ___________________NAVIGATION_L2_______________ XXXXXXX , OS_LSFT , OS_LCTL , OS_LALT , XXXXXXX
#define ___________________NAVIGATION_L3_______________ XXXXXXX , XXXXXXX , XXXXXXX , OS_LGUI , XXXXXXX
#define __NAVIGATION_L4__                                                             MO_MAI  , _______

#define ___________________NAVIGATION_R1_______________ XXXXXXX , XXXXXXX , KC_PGDN , KC_PGUP , KC_ENT
#define ___________________NAVIGATION_R2_______________ XXXXXXX , KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT
#define ___________________NAVIGATION_R3_______________ XXXXXXX , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define __NAVIGATION_R4__                               _______ , MO_MAI

#define ___________________MOUSE_L1____________________ KC_ESC  , XXXXXXX , KC_TAB  , XXXXXXX , XXXXXXX
#define ___________________MOUSE_L2____________________ XXXXXXX , OS_LSFT , OS_LCTL , OS_LALT , KC_BTN1
#define ___________________MOUSE_L3____________________ XXXXXXX , XXXXXXX , XXXXXXX , OS_LGUI , KC_BTN2
#define ____MOUSE_L4_____                                                             MO_MAI  , _______

#define ___________________MOUSE_R1____________________ XXXXXXX , XXXXXXX , KC_WH_D , KC_WH_U , KC_ENT
#define ___________________MOUSE_R2____________________ TD_MB13 , KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R
#define ___________________MOUSE_R3____________________ TD_MB24 , KC_INS  , KC_HOME , KC_END  , KC_DEL
#define ____MOUSE_R4_____                               _______ , MO_MAI

#define ___________________FUNCTIONS_L1________________ KC_CAPS , XXXXXXX , KC_APP  , XXXXXXX , XXXXXXX
#define ___________________FUNCTIONS_L2________________ XXXXXXX , KC_LSFT , KC_LCTL , KC_LALT , KC_LEAD
#define ___________________FUNCTIONS_L3________________ XXXXXXX , XXXXXXX , XXXXXXX , KC_LGUI , XXXXXXX
#define ____FUNCTIONS_L4_                                                             TD_IJLE , KC_BSPC

#define ___________________FUNCTIONS_R1________________ KC_F15  , KC_F7   , KC_F8   , KC_F9   , KC_F12
#define ___________________FUNCTIONS_R2________________ KC_F14  , KC_F4   , KC_F5   , KC_F6   , KC_F11
#define ___________________FUNCTIONS_R3________________ KC_F13  , KC_F1   , KC_F2   , KC_F3   , KC_F10
#define ____FUNCTIONS_R4_                               KC_SPC  , TD_IJRI

#define ___________________MEDIA_L1____________________ RGB_TOG , RGB_HUD , RGB_HUI , RGB_MOD , XXXXXXX
#define ___________________MEDIA_L2____________________ XXXXXXX , RGB_VAD , RGB_VAI , XXXXXXX , XXXXXXX
#define ___________________MEDIA_L3____________________ XXXXXXX , RGB_SAD , RGB_SAI , XXXXXXX , XXXXXXX
#define ____MEDIA_L4_____                                                             TD_IJLE , KC_BSPC

#define ___________________MEDIA_R1____________________ XXXXXXX , KC_MPLY , KC_MPRV , KC_MNXT , KC_MSTP
#define ___________________MEDIA_R2____________________ KC_LEAD , KC_MUTE , KC_VOLD , KC_VOLU , XXXXXXX
#define ___________________MEDIA_R3____________________ HYPR_V  , HYPR_A  , SS_MODM , SS_MODP , XXXXXXX
#define ____MEDIA_R4_____                               KC_SPC  , TD_IJRI

#define ___________________MAINTENANCE_L1______________ XXXXXXX , XXXXXXX , KC_PWR  , XXXXXXX , EEP_RST
#define ___________________MAINTENANCE_L2______________ XXXXXXX , XXXXXXX , TG_M_ON , TG_M_OF , XXXXXXX
#define ___________________MAINTENANCE_L3______________ TO_FUN  , XXXXXXX , DF_QWE  , TO_NAV  , TO_LOW
#define __MAINTENANCE_L4_                                                             _______ , XXXXXXX

#define ___________________MAINTENANCE_R1______________ RESET   , XXXXXXX , KC_SLEP , XXXXXXX , XXXXXXX
#define ___________________MAINTENANCE_R2______________ XXXXXXX , TG_MAC  , TG_WIN  , TG_LIN  , XXXXXXX
#define ___________________MAINTENANCE_R3______________ TO_RAI  , TO_MOU  , DF_COL  , XXXXXXX , TO_MED
#define __MAINTENANCE_R4_                               XXXXXXX , _______
