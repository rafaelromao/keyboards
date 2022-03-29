#include QMK_KEYBOARD_H

#include "combos.h"

// Numpad

const uint16_t PROGMEM r_num_tab_combo[] = {RAI_BSP, KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM r_num_ent_combo[] = {RAI_BSP, KC_P5, KC_P6, COMBO_END};

// Lower

const uint16_t PROGMEM r_low_tab_combo[] = {RAI_BSP, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM r_low_ent_combo[] = {RAI_BSP, KC_5, KC_6, COMBO_END};

// N-Grams

const uint16_t PROGMEM r_ng_ao_combo[] = {SS_TL_A, SS_TL_O, COMBO_END};
const uint16_t PROGMEM r_ng_cao_combo[] = {SS_SQ_A, SS_TL_A, SS_TL_O, COMBO_END};
const uint16_t PROGMEM r_ng_oes_combo[] = {SS_CR_E, SS_SQ_O, COMBO_END};
const uint16_t PROGMEM r_ng_coes_combo[] = {SS_SQ_E, SS_CR_E, SS_SQ_O, COMBO_END};

// Romak 0 = Qwerty

const uint16_t PROGMEM l_ro0_esc_combo[] = {LOW_SPC, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM l_ro0_sav_combo[] = {LOW_SPC, LSFTT_S, LCTLT_D, COMBO_END};
const uint16_t PROGMEM l_ro0_und_combo[] = {LOW_SPC, KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM r_ro0_tab_combo[] = {RAI_BSP, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM r_ro0_ent_combo[] = {RAI_BSP, RCTLT_K, RSFTT_L, COMBO_END};

const uint16_t PROGMEM l_ro0_sal_combo[] = {LOW_SPC, KCA_MAC, LSFTT_S, COMBO_END};
const uint16_t PROGMEM l_ro0_pas_combo[] = {LOW_SPC, LCTLT_D, LALTT_F, COMBO_END};
const uint16_t PROGMEM l_ro0_cop_combo[] = {LOW_SPC, KC_C, LGUIT_V, COMBO_END};

const uint16_t PROGMEM r_ro0_sal_combo[] = {RAI_BSP, RSFTT_L, UND_MAC, COMBO_END};
const uint16_t PROGMEM r_ro0_pas_combo[] = {RAI_BSP, RALTT_J, RCTLT_K, COMBO_END};
const uint16_t PROGMEM r_ro0_cop_combo[] = {RAI_BSP, RGUIT_M, TD_COML, COMBO_END};
const uint16_t PROGMEM r_ro0_loc_combo[] = {RAI_BSP, TD_COML, TD_DOTD, COMBO_END};
const uint16_t PROGMEM r_ro0_und_combo[] = {RAI_BSP, TD_DOTD, KC_UNDS, COMBO_END};

// Romak 1

const uint16_t PROGMEM l_ro1_cop_combo[] = {LOW_SPC, KC_Y, LGUIT_V, COMBO_END};
const uint16_t PROGMEM r_ro1_sal_combo[] = {RAI_BSP, RSFTT_L, KCC_MAC, COMBO_END};
const uint16_t PROGMEM r_ro1_pas_combo[] = {RAI_BSP, RALTT_N, RCTLT_K, COMBO_END};

// Romak 2

const uint16_t PROGMEM l_ro2_pas_combo[] = {LOW_SPC, LCTLT_D, LA_UNDS, COMBO_END};
const uint16_t PROGMEM l_ro2_sal_combo[] = {LOW_SPC, KCF_MAC, LSFTT_S, COMBO_END};
const uint16_t PROGMEM r_ro2_ent_combo[] = {RAI_BSP, RCTLT_A, RSFTT_L, COMBO_END};
const uint16_t PROGMEM r_rom_pas_combo[] = {RAI_BSP, RALTT_N, RCTLT_A, COMBO_END};

// Romak 3

const uint16_t PROGMEM l_ro3_esc_combo[] = {LOW_SPC, KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM l_rom_sal_combo[] = {LOW_SPC, KCF_MAC, LSFTT_S, COMBO_END};
const uint16_t PROGMEM l_rom_sav_combo[] = {LOW_SPC, LSFTT_S, LCTLT_E, COMBO_END};
const uint16_t PROGMEM l_rom_pas_combo[] = {LOW_SPC, LCTLT_E, LALTT_D, COMBO_END};

// Romak 4

const uint16_t PROGMEM r_rom_tab_combo[] = {RAI_BSP, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM r_rom_ent_combo[] = {RAI_BSP, RCTLT_A, RSFTT_O, COMBO_END};
const uint16_t PROGMEM r_rom_sal_combo[] = {RAI_BSP, RSFTT_O, KCC_MAC, COMBO_END};

// Romak 5

const uint16_t PROGMEM l_rom_esc_combo[] = {LOW_SPC, KC_R, KC_Q, COMBO_END};
const uint16_t PROGMEM r_rom_und_combo[] = {LOW_SPC, TD_DOTD, KC_W, COMBO_END};

// Romak 6 = Romak

const uint16_t PROGMEM l_rom_und_combo[] = {LOW_SPC, KC_B, KC_X, COMBO_END};
const uint16_t PROGMEM l_rom_cop_combo[] = {LOW_SPC, KC_Y, LGUIT_T, COMBO_END};

// Reset

const uint16_t PROGMEM rom_reset_combo[] = {KC_UNDS, KC_B, KC_W, TD_SCLE, COMBO_END};

// Secret

const uint16_t PROGMEM secret_1_combo[] = {SEC_1, SEC_2, SEC_3, SEC_4, COMBO_END};
const uint16_t PROGMEM secret_2_combo[] = {SEC_1, SEC_2, SEC_7, SEC_4, COMBO_END};
const uint16_t PROGMEM secret_3_combo[] = {SEC_1, SEC_2, SEC_5, SEC_6, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(secret_1_combo, SS_SECRET_1),
  COMBO(secret_2_combo, SS_SECRET_2),
  COMBO(secret_3_combo, SS_SECRET_3),

  COMBO(r_num_tab_combo, KC_TAB),
  COMBO(r_num_ent_combo, KC_ENT),

  COMBO(r_low_tab_combo, KC_TAB),
  COMBO(r_low_ent_combo, KC_ENT),

  COMBO(r_ng_ao_combo, SS_AO),
  COMBO(r_ng_cao_combo, SS_CAO),
  COMBO(r_ng_oes_combo, SS_OES),
  COMBO(r_ng_coes_combo, SS_COES),

  COMBO(l_ro0_esc_combo, KC_ESC),
  COMBO(l_ro0_sav_combo, CB_SAVE),
  COMBO(l_ro0_und_combo, CB_UNDO),
  COMBO(r_ro0_tab_combo, KC_TAB),
  COMBO(r_ro0_ent_combo, KC_ENT),

  COMBO(l_ro0_sal_combo, CB_SELC),
  COMBO(l_ro0_pas_combo, CB_PAST),
  COMBO(l_ro0_cop_combo, CB_COPY),

  COMBO(r_ro0_sal_combo, CB_SELC),
  COMBO(r_ro0_pas_combo, CB_PAST),
  COMBO(r_ro0_cop_combo, CB_COPY),
  COMBO(r_ro0_loc_combo, CB_LOCK),
  COMBO(r_ro0_und_combo, CB_UNDO),

  COMBO(l_ro1_cop_combo, CB_COPY),
  COMBO(r_ro1_sal_combo, CB_SELC),
  COMBO(r_ro1_pas_combo, CB_PAST),

  COMBO(l_ro2_pas_combo, CB_PAST),
  COMBO(l_ro2_sal_combo, CB_SELC),
  COMBO(r_ro2_ent_combo, KC_ENT),
  COMBO(r_rom_pas_combo, CB_PAST),

  COMBO(l_ro3_esc_combo, KC_ESC),
  COMBO(l_rom_sal_combo, CB_SELC),
  COMBO(l_rom_sav_combo, CB_SAVE),
  COMBO(l_rom_pas_combo, CB_PAST),

  COMBO(l_rom_esc_combo, KC_ESC),
  COMBO(r_rom_und_combo, CB_UNDO),

  COMBO(l_rom_und_combo, CB_UNDO),
  COMBO(l_rom_cop_combo, CB_COPY),

  COMBO(r_rom_tab_combo, KC_TAB),
  COMBO(r_rom_ent_combo, KC_ENT),
  COMBO(r_rom_sal_combo, CB_SELC),

  COMBO(rom_reset_combo, RESET),
};

extern os_t os;

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    uint16_t key;
    uint8_t idx = 0;
    bool combo_must_tap = false;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                combo_must_tap = true;
                break;
            default:
                combo_must_tap = false;
                break;
        }
        if (!combo_must_tap) {
            return false;
        }
        idx += 1;
    }
    return combo_must_tap;
}

process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record) {

    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;
    bool isOneShotShift = get_oneshot_mods() & MOD_MASK_SHIFT || get_oneshot_locked_mods() & MOD_MASK_SHIFT;

    switch (keycode) {

        case CB_SELC:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("a"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_SAVE:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("s"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_UNDO:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("z"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_COPY:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("c"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case CB_PAST:
            if (record->event.pressed) {
                clear_locked_and_oneshot_mods();
                if (should_send_ctrl(isWindowsOrLinux, isOneShotShift)) {
                    SEND_STRING(SS_LCTL("v"));
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

    }

    return PROCESS_RECORD_CONTINUE;
}
