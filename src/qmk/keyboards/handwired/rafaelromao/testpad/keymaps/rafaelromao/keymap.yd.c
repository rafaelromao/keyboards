#include QMK_KEYBOARD_H

#define LAYOUT_wrapper(...) LAYOUT_split_3x5(__VA_ARGS__)

// clang-format off

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [0] = LAYOUT_wrapper(
        KC_0 , KC_A , KC_B , KC_C , KC_D , 
        KC_E , KC_F , KC_G , KC_H , KC_I , 
        KC_J , KC_K , KC_L , KC_M , KC_N , 
        KC_R , KC_O , KC_P , KC_Q , KC_0 , 
        KC_S , KC_T , KC_U , KC_V , KC_W ,
        KC_X , KC_Y , KC_Z , KC_1 , KC_2 )
};

// clang-format on