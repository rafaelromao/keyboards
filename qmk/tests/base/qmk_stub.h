#pragma once

// Minimal QMK API surface for the OS-aware BASE mod-tap unit tests.
#include <stdbool.h>
#include <stdint.h>

#define SAFE_RANGE 0x7E40
#define QK_MOD_TAP_GET_TAP_KEYCODE(kc) ((kc) & 0xFF)
#define MT(mod, kc) (0x2000 | ((mod) << 8) | (kc))
#define RCTL_T(kc) MT(0x10, (kc))
#define MOD_BIT(kc) (1U << ((kc) - KC_LCTL))

enum {
    KC_C = 6,
    KC_E = 8,
    KC_F = 9,
    KC_N = 17,
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
