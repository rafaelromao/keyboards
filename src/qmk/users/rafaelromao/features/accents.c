#include "features/accents.h"
#include "features/adaptive.h"
#include "features/smart.h"
#include "features/shortcuts.h"

// AC_AGRV .. AC_UACU: the letter and the dead key that precedes it.
static const uint8_t  accent_letter[] PROGMEM = {KC_A, KC_A, KC_A, KC_A, KC_E, KC_E, KC_I, KC_O, KC_O, KC_O, KC_U};
static const uint16_t accent_dead[] PROGMEM   = {KC_GRV, KC_QUOT, KC_TILD, KC_CIRC, KC_QUOT, KC_CIRC, KC_QUOT, KC_QUOT, KC_TILD, KC_CIRC, KC_QUOT};

// Whether the next letter wants a capital: caps word, a held shift, or a
// one-shot shift (which this consumes, like ZMK's sticky shift would be by
// the key that follows it).
static bool take_shift(void) {
    bool shifted = is_caps_word_on() || ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT);
    clear_oneshot_mods();
    return shifted;
}

// Types `dead` then `letter`, shifting only the letter when asked.
static void tap_accent(uint16_t dead, uint8_t letter, bool shifted) {
    uint8_t mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    tap_code16(dead);
    tap_code16(shifted ? S(letter) : letter);
    set_mods(mods);
    adaptive_track(shifted ? S(letter) : letter);
}

static void tap_letter(uint8_t letter, bool shifted) {
    uint8_t mods = get_mods();
    del_mods(MOD_MASK_SHIFT);
    tap_code16(shifted ? S(letter) : letter);
    set_mods(mods);
    adaptive_track(shifted ? S(letter) : letter);
}

static void accent(uint8_t idx, bool shifted) {
    tap_accent(pgm_read_word(&accent_dead[idx]), pgm_read_byte(&accent_letter[idx]), shifted);
}

static void cedilla(bool shifted) {
    if (shortcuts_is_mac()) {
        // As in ZMK: the macOS ç has no shifted form, every variant is ' c.
        tap_accent(KC_QUOT, KC_C, false);
    } else {
        uint8_t mods = get_mods();
        del_mods(MOD_MASK_SHIFT);
        tap_code16(shifted ? RALT(RSFT(KC_COMM)) : RALT(KC_COMM));
        set_mods(mods);
        adaptive_track(shifted ? S(KC_C) : KC_C);
    }
}

bool process_accents(uint16_t keycode, bool pressed) {
    if (keycode >= AC_FIRST && keycode <= AC_LAST) {
        if (pressed) {
            accent(keycode - AC_FIRST, take_shift());
            smart_altrep2_arm();
        }
        return true;
    }
    switch (keycode) {
        case MC_CED:
            if (pressed) {
                cedilla(take_shift());
                smart_osl_on(_CCEDIL);
            }
            return true;
        case MC_QU: {
            // qu: Q takes the shift; U too under caps word (RS(Q) RS(U))
            if (pressed) {
                bool caps    = is_caps_word_on();
                bool shifted = take_shift();
                tap_letter(KC_Q, shifted);
                tap_letter(KC_U, caps);
                smart_altrep2_arm();
            }
            return true;
        }
        case MC_AOTIL:  // ão
            if (pressed) {
                bool caps = is_caps_word_on();
                accent(AC_ATIL - AC_FIRST, caps);
                tap_letter(KC_O, caps);
            }
            return true;
        case MC_OTILES:  // ões
            if (pressed) {
                bool caps = is_caps_word_on();
                accent(AC_OTIL - AC_FIRST, caps);
                tap_letter(KC_E, caps);
                tap_letter(KC_S, caps);
            }
            return true;
    }
    return false;
}
