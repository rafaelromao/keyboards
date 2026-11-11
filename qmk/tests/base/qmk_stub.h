#pragma once

// Minimal QMK keycode macros for the BASE/base-layer mapping unit test.
#include <stdbool.h>
#include <stdint.h>

#define SAFE_RANGE 0x7E40
#define MT(mod, kc) (0x2000 | ((mod) << 8) | (kc))
#define LCTL_T(kc) MT(0x01, (kc))
#define LSFT_T(kc) MT(0x02, (kc))
#define LALT_T(kc) MT(0x04, (kc))
#define LGUI_T(kc) MT(0x08, (kc))
#define LSG_T(kc) MT(0x0A, (kc))
#define LT(layer, kc) (0x4000 | (((layer) & 0x0F) << 8) | (kc))

enum {
    KC_A = 4,
    KC_C = 6,
    KC_D = 7,
    KC_E = 8,
    KC_F = 9,
    KC_I = 12,
    KC_N = 17,
    KC_P = 19,
    KC_R = 21,
    KC_S = 22,
    KC_T = 23,
    KC_V = 25,
    KC_W = 26,
    KC_Y = 28,
    KC_Z = 29,
    KC_LCTL = 0xE0,
    KC_LSFT = 0xE1,
    KC_LGUI = 0xE3,
};

typedef struct {
    struct {
        bool pressed;
    } event;
    struct {
        uint8_t count;
    } tap;
} keyrecord_t;

void register_mods(uint8_t mods);
void unregister_mods(uint8_t mods);
