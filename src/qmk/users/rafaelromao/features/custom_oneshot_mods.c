#include QMK_KEYBOARD_H

#include "custom_oneshot_mods.h"

extern os_t os;

static oneshot_mods_timer_t oneshot_mods_timer = {.timer = 0};

void clear_expired_oneshot_mods(void) {
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    if (!(oneshot_locked_mods & MOD_LSFT) && (oneshot_mods & MOD_LSFT)) {
        del_oneshot_mods(MOD_LSFT);
        unregister_mods(MOD_LSFT);
    }
    if (!(oneshot_locked_mods & MOD_LCTL) && (oneshot_mods & MOD_LCTL)) {
        del_oneshot_mods(MOD_LCTL);
        unregister_mods(MOD_LCTL);
    }
    if (!(oneshot_locked_mods & MOD_LGUI) && (oneshot_mods & MOD_LGUI)) {
        del_oneshot_mods(MOD_LGUI);
        unregister_mods(MOD_LGUI);
    }
    if (!(oneshot_locked_mods & MOD_LALT) && (oneshot_mods & MOD_LALT)) {
        del_oneshot_mods(MOD_LALT);
        unregister_mods(MOD_LALT);
    }
    if (!(oneshot_locked_mods & MOD_RALT) && (oneshot_mods & MOD_RALT)) {
        del_oneshot_mods(MOD_RALT);
        unregister_mods(MOD_RALT);
    }
}

void disable_expired_oneshot_mods(void) {
    clear_expired_oneshot_mods();
    oneshot_mods_timer.timer = 0;
}

bool oneshot_mods_timer_expired(void) {
    return oneshot_mods_timer.timer > 0 && (timer_elapsed(oneshot_mods_timer.timer) > CUSTOM_ONESHOT_TIMEOUT);
}

void check_oneshot_mods_timeout(void) {
    if (oneshot_mods_timer_expired()) {
        disable_expired_oneshot_mods();
    }
}

void oneshot_mods_changed_user(uint8_t mods) {
    if (mods) {
        oneshot_mods_timer.timer = timer_read();
    } else {
        oneshot_mods_timer.timer = 0;
    }
}

void clear_locked_and_oneshot_mods(void) {
    uint8_t oneshot_locked_mods = get_oneshot_locked_mods();
    uint8_t oneshot_mods        = get_oneshot_mods();
    if (oneshot_locked_mods || oneshot_mods) {
        clear_oneshot_mods();
        clear_oneshot_locked_mods();
        unregister_mods(MOD_LSFT);
        unregister_mods(MOD_LCTL);
        unregister_mods(MOD_LALT);
        unregister_mods(MOD_RALT);
        unregister_mods(MOD_LGUI);
    }
    dyn_macro_reset();
}

void clear_shift(void) {
    del_oneshot_mods(MOD_LSFT);
    unregister_mods(MOD_LSFT);
}