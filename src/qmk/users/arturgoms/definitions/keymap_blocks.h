#pragma once

#include QMK_KEYBOARD_H
#include "keycodes.h"

// clang-format off
// Layout 9 = Colemak DH 

#define _________________LAYOUT_L0________________ KC_1 , KC_2 , KC_3 , KC_4 , KC_5
#define _________________LAYOUT_L1________________ KC_Q , KC_W , KC_F , KC_P , KC_B
#define _________________LAYOUT_L2________________ KC_A , KC_R , KC_S , KC_T , KC_G
#define _________________LAYOUT_L3________________ KC_Z , KC_X , KC_C , KC_D , KC_V
#define ____LAYOUT_L4_____                         LCTL(KC_B),LT(_RAISE, KC_BSPC), KC_LGUI

#define ________LAYOUT_M0________                 KC_MUTE, KC_VOLD, KC_VOLU
#define ________LAYOUT_M1________                 RGB_VAD, RGB_VAI, RGB_TOG
#define ________LAYOUT_M2________                 KC_MRWD, KC_MPLY, KC_MFFD
#define ________LAYOUT_M3________                 KC_LBRC, KC_UP, KC_RBRC
#define ________LAYOUT_M4________                 KC_LEFT, KC_DOWN, KC_RGHT

#define ________________LAYOUT_R0________________ KC_6  , KC_7 , KC_8    , KC_9   , KC_0
#define ________________LAYOUT_R1________________ KC_J  , KC_L , KC_U    , KC_Y   , KC_QUOT
#define ________________LAYOUT_R2________________ KC_M  , KC_N , KC_E    , KC_I   , KC_O
#define ________________LAYOUT_R3________________ KC_K  , KC_H , KC_COMM , KC_DOT , KC_SLSH
#define ______LAYOUT_R4______                     KC_LSFT, LT(_LOWER, KC_SPC) , LT(_MAINTENANCE, KC_ENT)
 // |_______________________________________________________________________________________________________________________________|

#define __________________LOWER_L0________________ KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define __________________LOWER_L1________________ XXXXXXX, XXXXXXX, KC_RBRC, KC_RPRN, LSFT(KC_RBRC)
#define __________________LOWER_L2________________ XXXXXXX, KC_PIPE, KC_LBRC, KC_LPRN, LSFT(KC_LBRC)
#define __________________LOWER_L3________________ XXXXXXX, KC_SLSH, LSFT(KC_EQL), KC_SCLN, KC_MINS
#define _____LOWER_L4_____                         KC_LGUI,  _______ , MED_0

#define ________LOWER_M0_________                 KC_F6, KC_F7, KC_F8

#define _________________LOWER_R0________________ KC_F9, KC_F10, KC_F11, KC_F12, RGB_TOG
#define _________________LOWER_R1________________ KC_DQUO, LCTL(KC_LEFT), LCTL(KC_RGHT), KC_QUOT, XXXXXXX
#define _________________LOWER_R2________________ KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       XXXXXXX
#define _________________LOWER_R3________________ LSFT(KC_MINS), KC_COLN,       KC_EQL,        KC_BSLS,       XXXXXXX
#define _______LOWER_R4______                     _______ , _______ , KC_RGUI
 // |_______________________________________________________________________________________________________________________________|

#define _________________RAISE_L0___________________ MC_HARPOON_1 , MC_HARPOON_2 ,MC_HARPOON_3,MC_HARPOON_4,MC_HARPOON_5 
#define _________________RAISE_L1___________________ MC_QUIT, XXXXXXX, LCTL(KC_H), LCTL(KC_L), MC_BUFFERS
#define _________________RAISE_L2___________________ XXXXXXX, XXXXXXX,    LSFT(KC_L), LSFT(KC_U), LCTL(KC_BSLS)
#define _________________RAISE_L3___________________ XXXXXXX, XXXXXXX,    MC_CPR,     MC_DELETE_WORD, MC_MAXIMIZER
#define _____RAISE_L4_______                                           KC_LGUI, _______ , _______

#define _________________RAISE_R0_________________ MC_HARPOON_6 , MC_HARPOON_7 , MC_HARPOON_8 , MC_HARPOON_9 ,MC_HARPOON_0 
#define _________________RAISE_R1_________________ LCTL(KC_U) , KC_HOME , KC_END , XXXXXXX , XXXXXXX
#define _________________RAISE_R2_________________ LCTL(KC_D) , LCTL(KC_K) , LCTL(KC_J) , XXXXXXX , XXXXXXX
#define _________________RAISE_R3_________________ MC_SAVE , MC_VISTA,  MC_PREV_TAB , MC_NEXT_TAB, XXXXXXX
#define _______RAISE_R4_______                     _______ , _______, KC_RGUI
 // |_______________________________________________________________________________________________________________________________|

#define ______________MAINTENANCE_L0_____________ XXXXXXX , RGB_VAD , RGB_VAI , RGB_RMOD , EEP_RST
#define ______________MAINTENANCE_L1_____________ RESET ,   RGB_VAD , RGB_VAI , RGB_MOD  , EEP_RST
#define ______________MAINTENANCE_L2_____________ RGB_TOG , RGB_HUD , RGB_HUI , XXXXXXX  , XXXXXXX
#define ______________MAINTENANCE_L3_____________ XXXXXXX , RGB_SAD , RGB_SAI , XXXXXXX  , XXXXXXX
#define __MAINTENANCE_L4_                                             KC_LGUI,  _______ , _______

#define ______________MAINTENANCE_R0____________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ______________MAINTENANCE_R1____________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ______________MAINTENANCE_R2____________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ______________MAINTENANCE_R3____________ XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX
#define ___MAINTENANCE_R4___                     _______ , _______, KC_RGUI




// clang-format on
