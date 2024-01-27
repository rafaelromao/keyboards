#include QMK_KEYBOARD_H

#include "rafaelromao.h"

#define LAYOUT_wrapper(...) LAYOUT_ortho_5x15(__VA_ARGS__)

// clang-format off

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [_ALPHA1] = LAYOUT_wrapper(
 // |_____________________________________________________________________________________________________________________________________________________|
      __________________ALPHA1_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ________ALPHA1_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      __________________ALPHA1_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , __________________ALPHA1_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_D    , ________ALPHA1_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , __________________ALPHA1_R3__________ , KC_I    ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ___ALPHA1_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___ALPHA1_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_NUMPAD] = LAYOUT_wrapper(                       
 // |_____________________________________________________________________________________________________________________________________________________|
      ___________________NUMPAD_L1_________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________NUMPAD_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NUMPAD_L2___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NUMPAD_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NUMPAD_L3___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NUMPAD_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____NUMPAD_L4____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____NUMPAD_R4____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_SHORTCUTS] = LAYOUT_wrapper(                    
 // |_____________________________________________________________________________________________________________________________________________________|
      ________________SHORTCUTS_L1_________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ______SHORTCUTS_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ________________SHORTCUTS_L2___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ________________SHORTCUTS_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , ______SHORTCUTS_L3___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ________________SHORTCUTS_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _SHORTCUTS_L4____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _SHORTCUTS_R4____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_NOMOD] = LAYOUT_wrapper(                        
 // |_____________________________________________________________________________________________________________________________________________________|
      ___________________NOMOD_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________NOMOD_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NOMOD_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NOMOD_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NOMOD_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NOMOD_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____NOMOD_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____NOMOD_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_ALPHA2] = LAYOUT_wrapper(                       
 // |_____________________________________________________________________________________________________________________________________________________|
      ___________________ALPHA2_L1_________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________ALPHA2_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ALPHA2_L2___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________ALPHA2_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      KC_Y    , _________ALPHA2_L3___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________ALPHA2_R3_________ , MC_SQ_I ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____ALPHA2_L4____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____ALPHA2_R4____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_FIXED_ALPHA2] = LAYOUT_wrapper(                 
 // |_____________________________________________________________________________________________________________________________________________________|
      ___________________ALPHA2_L1_________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________ALPHA2_R1___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________ALPHA2_L2___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________ALPHA2_R2___________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________ALPHA2_L3___________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________ALPHA2_R3_________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____ALPHA2_L4____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____ALPHA2_R4____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_LOWER] = LAYOUT_wrapper(                        
 // |_____________________________________________________________________________________________________________________________________________________|
      ___________________LOWER_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________LOWER_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________LOWER_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________LOWER_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________LOWER_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________LOWER_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____LOWER_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____LOWER_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_RAISE] = LAYOUT_wrapper(                        
 // |_____________________________________________________________________________________________________________________________________________________|
      ___________________RAISE_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________RAISE_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________RAISE_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________RAISE_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________RAISE_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________RAISE_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____RAISE_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____RAISE_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_SYMBOLS] = LAYOUT_wrapper(                      
 // |_____________________________________________________________________________________________________________________________________________________|
      _________________SYMBOLS_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______SYMBOLS_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _________________SYMBOLS_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________________SYMBOLS_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _______SYMBOLS_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________________SYMBOLS_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __SYMBOLS_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , __SYMBOLS_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_NAVIGATION] = LAYOUT_wrapper(                   
 // |_____________________________________________________________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NAVIGATION_L3_______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R3_____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __NAVIGATION_L4__ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , __NAVIGATION_R4__ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_MEDIA] = LAYOUT_wrapper(                        
 // |_______________________________ ______________________________________________________________________________________________________________________|
      ___________________MEDIA_L1__________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________MEDIA_R1____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________MEDIA_L2____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MEDIA_R2____________________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________MEDIA_L3____________________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________MEDIA_R3__________ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ____MEDIA_L4_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____MEDIA_R4_____ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_FIXED_NAV] = LAYOUT_wrapper(                    
 // |_____________________________________________________________________________________________________________________________________________________|
      ___________________NAVIGATION_L1_____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _________NAVIGATION_R1_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ___________________NAVIGATION_L2_______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R2_______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _________NAVIGATION_L3_______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ___________________NAVIGATION_R3_____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , __FIXED_NAV__L4__ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , __FIXED_NAV__R4__ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_LOCK] = LAYOUT_wrapper(                         
 // |_____________________________________________________________________________________________________________________________________________________|
      _______________________LOCK____L1____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _____________LOCK____R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      _______________________LOCK____L2______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______________________LOCK____R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , _____________LOCK____L3______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______________________LOCK____R3____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , ______LOCK____L4_ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ______LOCK____R4_ , XXXXXXX , XXXXXXX , XXXXXXX),
 // |_____________________________________________________________________________________________________________________________________________________|
                                                       
     [_SYSTEM] = LAYOUT_wrapper(                       
 // |_____________________________________________________________________________________________________________________________________________________|
      ______________________SYSTEM___L1____ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ____________SYSTEM___R1______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      ______________________SYSTEM___L2______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ______________________SYSTEM___R2______________ ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , ____________SYSTEM___L3______________ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , ______________________SYSTEM___R3____ , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
 // |---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      XXXXXXX , XXXXXXX , XXXXXXX , _____SYSTEM___L4_ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _____SYSTEM___R4_ , XXXXXXX , XXXXXXX , XXXXXXX)
 // |_____________________________________________________________________________________________________________________________________________________|
};

// clang-format on