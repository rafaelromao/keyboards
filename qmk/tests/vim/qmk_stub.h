#pragma once

// Host-side QMK API seam for exercising the real Vim state machine.
#include <stdbool.h>
#include <stdint.h>

#define SAFE_RANGE 0x7E40
#define MOD_MASK_CTRL 0x11
#define MOD_MASK_SHIFT 0x22
#define S(kc) (0x0200 | (kc))
#define C(kc) (0x0100 | (kc))
#define LT(layer, kc) (0x4000 | (((layer) & 0xF) << 8) | (kc))
#define LGUI_T(kc) (0x2800 | (kc))
#define LSG_T(kc) (0x2A00 | (kc))
#define IS_QK_MOD_TAP(kc) (((kc) & 0xE000) == 0x2000)
#define IS_QK_LAYER_TAP(kc) (((kc) & 0xF000) == 0x4000)
#define IS_QK_MOMENTARY(kc) (((kc) & 0xFFE0) == 0x5220)
#define IS_MODIFIER_KEYCODE(kc) ((kc) >= 0xE0 && (kc) <= 0xE7)
#define QK_MOD_TAP_GET_TAP_KEYCODE(kc) ((kc) & 0xFF)
#define QK_LAYER_TAP_GET_TAP_KEYCODE(kc) ((kc) & 0xFF)

enum {
    KC_NO = 0, KC_A = 4, KC_C = 6, KC_D = 7, KC_E = 8,
    KC_I = 12, KC_J = 13, KC_O = 18, KC_P = 19, KC_Q = 20,
    KC_R = 21, KC_S = 22, KC_U = 24, KC_V = 25, KC_X = 27,
    KC_Y = 28, KC_ENT = 40, KC_ESC = 41, KC_SLSH = 56,
    KC_F23 = 114,
    KC_COLN = S(51), KC_QUES = S(KC_SLSH), KC_EXLM = S(30),
    KC_EQL = 46, KC_TILD = S(53), KC_AT = S(31)
};

typedef struct {
    struct { bool pressed; } event;
    struct { uint8_t count; } tap;
} keyrecord_t;

void layer_on(uint8_t layer);
void layer_off(uint8_t layer);
uint8_t get_mods(void);
uint8_t get_oneshot_mods(void);
uint16_t timer_read(void);
uint16_t timer_elapsed(uint16_t start);
void tap_code(uint8_t keycode);
