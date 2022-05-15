#include QMK_KEYBOARD_H

#include "combos.h"

// Numpad

const uint16_t PROGMEM l_num_esc_combo[] = {LOW_SPC, KC_F9, KC_F8, COMBO_END};
const uint16_t PROGMEM l_num_sav_combo[] = {LOW_SPC, SF_F6, CT_F5, COMBO_END};
const uint16_t PROGMEM r_num_ent_combo[] = {RAI_BSP, CT_5, SF_6, COMBO_END};

// Lower

const uint16_t PROGMEM r_low_tab_combo[] = {RAI_BSP, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM r_low_ent_combo[] = {RAI_BSP, KC_5, KC_6, COMBO_END};

// N-Grams

const uint16_t PROGMEM r_ng_ao_combo[]   = {MC_TL_A, MC_TL_O, COMBO_END};
const uint16_t PROGMEM r_ng_cao_combo[]  = {MC_SQ_A, MC_TL_A, MC_TL_O, COMBO_END};
const uint16_t PROGMEM r_ng_oes_combo[]  = {MC_CR_E, MC_SQ_O, COMBO_END};
const uint16_t PROGMEM r_ng_coes_combo[] = {MC_SQ_E, MC_CR_E, MC_SQ_O, COMBO_END};

// Qwerty

// const uint16_t PROGMEM r_qwe_ful_combo[] = {RAI_BSP, RSFTT_L, SCL_MAC, COMBO_END};
// const uint16_t PROGMEM r_qwe_fin_combo[] = {RAI_BSP, TD_DOTD, KC_BSLS, COMBO_END};

// Romak 0

// const uint16_t PROGMEM l_ro0_esc_combo[] = {LOW_SPC, KC_W, KC_E, COMBO_END};
// const uint16_t PROGMEM l_ro0_sav_combo[] = {LOW_SPC, LSFTT_S, LCTLT_D, COMBO_END};
// const uint16_t PROGMEM l_ro0_und_combo[] = {LOW_SPC, KC_Z, KC_X, COMBO_END};
// const uint16_t PROGMEM r_ro0_tab_combo[] = {RAI_BSP, KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM r_ro0_ent_combo[] = {RAI_BSP, RCTLT_K, RSFTT_L, COMBO_END};

// const uint16_t PROGMEM l_ro0_sal_combo[] = {LOW_SPC, KCA_MAC, LSFTT_S, COMBO_END};
// const uint16_t PROGMEM l_ro0_pas_combo[] = {LOW_SPC, LCTLT_D, LALTT_F, COMBO_END};
// const uint16_t PROGMEM l_ro0_cop_combo[] = {LOW_SPC, KC_C, LGUIT_V, COMBO_END};
// const uint16_t PROGMEM l_ro0_usc_combo[] = {KC_X, KC_C, COMBO_END};

// const uint16_t PROGMEM r_ro0_ful_combo[] = {RAI_BSP, RSFTT_L, BSL_MAC, COMBO_END};
// const uint16_t PROGMEM r_ro0_pas_combo[] = {RAI_BSP, RALTT_J, RCTLT_K, COMBO_END};
const uint16_t PROGMEM r_rom_cop_combo[] = {RAI_BSP, RGUIT_M, TD_COMM, COMBO_END};
// const uint16_t PROGMEM r_ro0_fin_combo[] = {RAI_BSP, TD_DOTD, TD_SCLE, COMBO_END};
const uint16_t PROGMEM r_rom_sco_combo[] = {TD_COMM, TD_DOTD, COMBO_END};

// Romak 1

// const uint16_t PROGMEM l_ro1_cop_combo[] = {LOW_SPC, KC_Y, LGUIT_V, COMBO_END};
// const uint16_t PROGMEM r_ro1_ful_combo[] = {RAI_BSP, RSFTT_L, KCC_MAC, COMBO_END};
// const uint16_t PROGMEM r_ro1_pas_combo[] = {RAI_BSP, RALTT_N, RCTLT_K, COMBO_END};
const uint16_t PROGMEM l_rom_usc_combo[] = {KC_X, KC_Y, COMBO_END};

// Romak 2

// const uint16_t PROGMEM l_ro2_pas_combo[] = {LOW_SPC, LCTLT_D, LA_BSLS, COMBO_END};
const uint16_t PROGMEM l_rom_sal_combo[] = {LOW_SPC, KCF_MAC, LSFTT_S, COMBO_END};
// const uint16_t PROGMEM r_ro2_ent_combo[] = {RAI_BSP, RCTLT_A, RSFTT_L, COMBO_END};
const uint16_t PROGMEM r_rom_pas_combo[] = {RAI_BSP, RALTT_N, RCTLT_A, COMBO_END};

// Romak 3

// const uint16_t PROGMEM l_ro3_esc_combo[] = {LOW_SPC, KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM l_rom_sav_combo[] = {LOW_SPC, LSFTT_S, LCTLT_E, COMBO_END};
const uint16_t PROGMEM l_rom_pas_combo[] = {LOW_SPC, LCTLT_E, LALTT_D, COMBO_END};

// Romak 4

const uint16_t PROGMEM r_rom_tab_combo[] = {RAI_BSP, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM r_rom_ent_combo[] = {RAI_BSP, RCTLT_A, RSFTT_O, COMBO_END};
const uint16_t PROGMEM r_rom_ful_combo[] = {RAI_BSP, RSFTT_O, KCC_MAC, COMBO_END};

// Romak 5

const uint16_t PROGMEM l_rom_esc_combo[] = {LOW_SPC, KC_R, KC_Q, COMBO_END};
const uint16_t PROGMEM r_rom_fin_combo[] = {RAI_BSP, TD_DOTD, KC_W, COMBO_END};

// Romak 6 = Romak

const uint16_t PROGMEM l_rom_und_combo[] = {LOW_SPC, KC_B, KC_X, COMBO_END};
const uint16_t PROGMEM l_rom_cop_combo[] = {LOW_SPC, KC_Y, LGUIT_T, COMBO_END};

// Reset

// const uint16_t PROGMEM qwe_reset_combo[] = {KC_A, KC_Z, TD_SCLE, KC_BSLS, COMBO_END};
// const uint16_t PROGMEM ro1_reset_combo[] = {KC_A, KC_Z, KCC_MAC, TD_SCLE, COMBO_END};
// const uint16_t PROGMEM ro2_reset_combo[] = {KCF_MAC, KC_Z, KCC_MAC, TD_SCLE, COMBO_END};
// const uint16_t PROGMEM ro5_reset_combo[] = {KCF_MAC, KC_Z, KCC_MAC, KC_W, COMBO_END};
const uint16_t PROGMEM rom_reset_combo[] = {KCF_MAC, KC_B, KCC_MAC, KC_W, COMBO_END};

// Secret

const uint16_t PROGMEM secret_1_combo[] = {SEC_1, SEC_2, SEC_3, SEC_4, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(secret_1_combo, MC_SECRET_1),

    COMBO(l_num_esc_combo, KC_ESC),
    COMBO(l_num_sav_combo, MC_SAVE),

    COMBO(r_num_ent_combo, KC_ENT),

    COMBO(r_low_tab_combo, KC_TAB),
    COMBO(r_low_ent_combo, KC_ENT),

    COMBO(r_ng_ao_combo, MC_AO),
    COMBO(r_ng_cao_combo, MC_CAO),
    COMBO(r_ng_oes_combo, MC_OES),
    COMBO(r_ng_coes_combo, MC_COES),

    // COMBO(r_qwe_ful_combo, MC_FULL),
    // COMBO(r_qwe_fin_combo, MC_FIND),

    // COMBO(l_ro0_esc_combo, KC_ESC),
    // COMBO(l_ro0_sav_combo, MC_SAVE),
    // COMBO(l_ro0_und_combo, MC_UNDO),
    // COMBO(r_ro0_tab_combo, KC_TAB),
    // COMBO(r_ro0_ent_combo, KC_ENT),

    // COMBO(l_ro0_sal_combo, MC_SELC),
    // COMBO(l_ro0_pas_combo, MC_PAST),
    // COMBO(l_ro0_cop_combo, MC_COPY),
    // COMBO(l_ro0_usc_combo, KC_UNDS),

    // COMBO(r_ro0_ful_combo, MC_FULL),
    // COMBO(r_ro0_pas_combo, MC_PAST),
    COMBO(r_rom_cop_combo, MC_COPY),
    // COMBO(r_ro0_fin_combo, MC_FIND),
    COMBO(r_rom_sco_combo, TD_SCLE),

    // COMBO(l_ro1_cop_combo, MC_COPY),
    // COMBO(r_ro1_ful_combo, MC_FULL),
    // COMBO(r_ro1_pas_combo, MC_PAST),
    COMBO(l_rom_usc_combo, KC_UNDS),

    // COMBO(l_ro2_pas_combo, MC_PAST),
    COMBO(l_rom_sal_combo, MC_SELC),
    // COMBO(r_ro2_ent_combo, KC_ENT),
    COMBO(r_rom_pas_combo, MC_PAST),

    // COMBO(l_ro3_esc_combo, KC_ESC),
    COMBO(l_rom_sav_combo, MC_SAVE),
    COMBO(l_rom_pas_combo, MC_PAST),

    COMBO(l_rom_esc_combo, KC_ESC),
    COMBO(r_rom_fin_combo, MC_FIND),

    COMBO(l_rom_und_combo, MC_UNDO),
    COMBO(l_rom_cop_combo, MC_COPY),

    COMBO(r_rom_tab_combo, KC_TAB),
    COMBO(r_rom_ent_combo, KC_ENT),
    COMBO(r_rom_ful_combo, MC_FULL),

    // COMBO(qwe_reset_combo, RESET),
    // COMBO(ro1_reset_combo, RESET),
    // COMBO(ro2_reset_combo, RESET),
    // COMBO(ro5_reset_combo, RESET),
    COMBO(rom_reset_combo, RESET),
};

extern os_t os;

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    uint16_t key;
    uint8_t  idx            = 0;
    bool     combo_must_tap = false;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
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