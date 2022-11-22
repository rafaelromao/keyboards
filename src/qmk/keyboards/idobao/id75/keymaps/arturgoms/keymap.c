#include QMK_KEYBOARD_H
#include "arturgoms.h"

#define LAYOUT_wrapper(...) LAYOUT_ortho_5x15(__VA_ARGS__)

// clang-format off

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_COLEMAK] = LAYOUT_wrapper(
 // |______________________________________________________________________________________________________________________________________________________|
      KC_GRV , _________________LAYOUT_L0________________, ________LAYOUT_M0________,  ________________LAYOUT_R0________________, KC_BSPC, 
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_TAB  ,_________________LAYOUT_L1________________ ,________LAYOUT_M1________ , ________________LAYOUT_R1________________ , KC_DEL,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_ESC  ,_________________LAYOUT_L2________________ ,________LAYOUT_M2________, ________________LAYOUT_R2________________ , KC_ENT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT ,_________________LAYOUT_L3________________ ,________LAYOUT_M3________, ________________LAYOUT_R3________________ , KC_RSFT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL, XXXXXXX , KC_LALT, KC_LGUI , ____LAYOUT_L4_____ , XXXXXXX   , ______LAYOUT_R4______ , KC_RGUI, KC_RALT , XXXXXXX , KC_RCTL),
 // |______________________________________________________________________________________________________________________________________________________|

     [_LOWER] = LAYOUT_wrapper(
 // |______________________________________________________________________________________________________________________________________________________|
      KC_GRV, __________________LOWER_L0________________, ________LOWER_M0_________,  _________________LOWER_R0________________, KC_BSPC, 
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_TAB  ,__________________LOWER_L1________________ ,XXXXXXX,XXXXXXX,XXXXXXX , _________________LOWER_R1________________ , KC_DEL,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_ESC  ,__________________LOWER_L2________________ ,XXXXXXX,XXXXXXX,XXXXXXX, _________________LOWER_R2________________ , KC_ENT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT ,__________________LOWER_L3________________ ,XXXXXXX,XXXXXXX,XXXXXXX, _________________LOWER_R3________________ , KC_RSFT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL, XXXXXXX ,  KC_LALT  , _____LOWER_L4_____   ,XXXXXXX,XXXXXXX,XXXXXXX, _______LOWER_R4______ , KC_RALT , XXXXXXX , KC_RCTL),
 // |______________________________________________________________________________________________________________________________________________________|

     [_RAISE] = LAYOUT_wrapper(
 // |______________________________________________________________________________________________________________________________________________________|
      KC_GRV   , _________________RAISE_L0___________________, XXXXXXX,XXXXXXX,XXXXXXX,  _________________RAISE_R0_________________ , KC_BSPC, 
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_TAB    ,_________________RAISE_L1___________________ ,XXXXXXX,XXXXXXX,XXXXXXX , _________________RAISE_R1_________________ , KC_DEL,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_ESC    ,_________________RAISE_L2___________________ ,XXXXXXX,XXXXXXX,XXXXXXX, _________________RAISE_R2_________________ , KC_ENT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT   ,_________________RAISE_L3___________________ ,XXXXXXX,XXXXXXX,XXXXXXX, _________________RAISE_R3_________________ , KC_RSFT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL , XXXXXXX ,  KC_LALT   , _____RAISE_L4_______   ,XXXXXXX,XXXXXXX,XXXXXXX, _______RAISE_R4_______ , KC_RALT , XXXXXXX , KC_RCTL),
 // |______________________________________________________________________________________________________________________________________________________|

     [_MAINTENANCE] = LAYOUT_wrapper(
 // |______________________________________________________________________________________________________________________________________________________|
      KC_GRV    , ______________MAINTENANCE_L0_____________, XXXXXXX,XXXXXXX,XXXXXXX,  ______________MAINTENANCE_R0____________, KC_BSPC, 
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_TAB     ,______________MAINTENANCE_L1_____________ ,XXXXXXX,XXXXXXX,XXXXXXX , ______________MAINTENANCE_R1____________ , KC_DEL,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_ESC     ,______________MAINTENANCE_L2_____________ ,XXXXXXX,XXXXXXX,XXXXXXX, ______________MAINTENANCE_R2____________ , KC_ENT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT    ,______________MAINTENANCE_L3_____________ ,XXXXXXX,XXXXXXX,XXXXXXX, ______________MAINTENANCE_R3____________ , KC_RSFT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL , XXXXXXX ,   KC_LALT   , __MAINTENANCE_L4_   ,XXXXXXX,XXXXXXX,XXXXXXX, ___MAINTENANCE_R4___ , KC_RALT , XXXXXXX , KC_RCTL),
 // |______________________________________________________________________________________________________________________________________________________|

     [_TMUX] = LAYOUT_wrapper(
 // |______________________________________________________________________________________________________________________________________________________|
      KC_GRV    , ______________TMUX_L0_____________, XXXXXXX,XXXXXXX,XXXXXXX,  ______________TMUX_R0____________, KC_BSPC, 
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_TAB     ,______________TMUX_L1_____________ ,XXXXXXX,XXXXXXX,XXXXXXX , ______________TMUX_R1____________ , KC_DEL,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_ESC     ,______________TMUX_L2_____________ ,XXXXXXX,XXXXXXX,XXXXXXX, ______________TMUX_R2____________ , KC_ENT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LSFT    ,______________TMUX_L3_____________ ,XXXXXXX,XXXXXXX,XXXXXXX, ______________TMUX_R3____________ , KC_RSFT,
 // |----------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_LCTL , XXXXXXX ,   KC_LALT   , __TMUX_L4_   ,XXXXXXX,XXXXXXX,XXXXXXX, ___TMUX_R4___ , KC_RALT , XXXXXXX , KC_RCTL),
 // |______________________________________________________________________________________________________________________________________________________|
};

extern leader_t      leader;
extern select_word_t select_word;

int leds[] = {
     68, 67, 66, 65, 64, /*    */ 60, 59, 58, 57, 56, 
     53, 52, 51 ,50, 49, /*    */ 45, 44, 43, 42, 41, 
     38, 37, 36, 35, 34, /*    */ 30, 29, 28, 27, 26, 
};
const int led_count = 30;

// Lower leds
int leds_lower[] = {
     68, 67, 66, 65, 64, /*    */ 60, 59, 58, 57, 56, 
     53, 52, 51 ,50, 49, /*    */ 45, 44, 43, 42, 41, 
     38, 37, 36, 35, 34, /*    */ 30, 29, 28, 27, 26, 
                                                  15 
};
const int  leds_lower_count = 31;

// Nav Leds
int leds_lower_nav[] = {52, 51 ,50, 49, 45, 44, 43, 42 };
const int  leds_lower_nav_count = 8;

// Raise leds
int leds_raise[] = {
     68, 67, 66, 65, 64, /*    */ 60, 59, 58, 57, 56, 
     53, 52, 51 ,50, 49, /*    */ 45, 44, 43, 42, 41, 
     38, 37, 36, 35, 34, /*    */ 30, 29, 28, 27, 26, 
                                  19
};
const int  leds_raise_count = 31;

// Raise Nav leds
int leds_raise_nav[] = {52, 51 ,50, 49, 45, 44, 43, 42 };
const int  leds_raise_nav_count = 8;

// maintence leds
int leds_maintence[] = {
     68, 67, 66, 65, 64, /*    */ 60, 59, 58, 57, 56, 
     53, 52, 51 ,50, 49, /*    */ 45, 44, 43, 42, 41, 
     38, 37, 36, 35, 34, /*    */ 30, 29, 28, 27, 26, 
                                                  14
};
const int  leds_maintence_count = 31;

// maintence nav leds
int leds_maintence_nav[] = {52, 51 ,50, 49, 45, 44, 43, 42 };
const int  leds_maintence_nav_count = 8;
      
void set_rgblight_by_layer(uint32_t layer) {
     switch (layer) {
          case _COLEMAK:
               break;
          case _LOWER:
               for (int i = 0; i < leds_lower_count; i++) {
                    rgb_matrix_set_color(leds_lower[i], RGB_WHITE);
               }
               for (int i = 0; i < leds_lower_nav_count; i++) {
                    rgb_matrix_set_color(leds_lower_nav[i], RGB_PURPLE);
               }
               break;
          case _RAISE:
               for (int i = 0; i < leds_raise_count; i++) {
                    rgb_matrix_set_color(leds_raise[i], RGB_WHITE);
               }
               for (int i = 0; i < leds_raise_nav_count; i++) {
                    rgb_matrix_set_color(leds_raise_nav[i], RGB_RED);
               }
               break;
          case _MAINTENANCE: 
               for (int i = 0; i < leds_maintence_count; i++) {
                    rgb_matrix_set_color(leds_maintence[i], RGB_WHITE);
               }
               for (int i = 0; i < leds_maintence_nav_count; i++) {
                    rgb_matrix_set_color(leds_maintence_nav[i], RGB_SPRINGGREEN);
               }
               break;
          default:
               for (int i = 0; i < led_count; i++) {
                    rgb_matrix_set_color(leds[i], RGB_WHITE);
               }
               break;
     }
}

void set_current_layer_rgb(void) {
    set_rgblight_by_layer(get_highest_layer(layer_state | default_layer_state));
}

layer_state_t layer_state_set_user(layer_state_t state) {
    set_rgblight_by_layer(biton32(state));
    return state;
}

void rgb_matrix_indicators_user(void) {
    uint8_t mods                = get_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();

    bool isShift = mods & MOD_MASK_SHIFT || oneshot_mods & MOD_MASK_SHIFT || oneshot_locked_mods & MOD_MASK_SHIFT;
    bool isCtrl  = mods & MOD_MASK_CTRL || oneshot_mods & MOD_MASK_CTRL || oneshot_locked_mods & MOD_MASK_CTRL;
    bool isAlt   = mods & MOD_MASK_ALT || oneshot_mods & MOD_MASK_ALT || oneshot_locked_mods & MOD_MASK_ALT;
    bool isGui   = mods & MOD_MASK_GUI || oneshot_mods & MOD_MASK_GUI || oneshot_locked_mods & MOD_MASK_GUI;

    for (int i = 0; i < led_count; i++) {
        if (leader.isLeading || select_word.state != STATE_NONE) {
            rgb_matrix_set_color(leds[i], RGB_GREEN);
        } else if (has_any_smart_case()) {
            rgb_matrix_set_color(leds[i], RGB_YELLOW);
        } else if (isShift) {
            rgb_matrix_set_color(leds[i], RGB_SPRINGGREEN);
        } else if (isCtrl) {
            rgb_matrix_set_color(leds[i], RGB_RED);
        } else if ( isAlt || isGui) {
            rgb_matrix_set_color(leds[i], RGB_WHITE);
        } else {
            set_current_layer_rgb();
        }
    }
}
