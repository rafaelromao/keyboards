#include QMK_KEYBOARD_H

// clang-format off

// Keymap

#define LAYOUT_wrapper(...) LAYOUT_ortho_4x3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [0] = LAYOUT_wrapper(
        KC_A , KC_B , KC_C , KC_D , 
        KC_I , KC_J , KC_K , KC_L ,
        KC_S , KC_T , KC_U , KC_0)
};

// clang-format on