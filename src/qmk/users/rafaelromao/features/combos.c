#include QMK_KEYBOARD_H

#include "combos.h"

// Numpad

const uint16_t PROGMEM l_num_esc_combo[] = {LOW_SPC, KC_F9, KC_F8, COMBO_END};
const uint16_t PROGMEM l_num_sav_combo[] = {LOW_SPC, SF_F6, CT_F5, COMBO_END};
const uint16_t PROGMEM r_num_ent_combo[] = {RAI_BSP, CT_5, SF_6, COMBO_END};

// Lower

const uint16_t PROGMEM l_low_par_combo[] = {TD_OPAR, TD_CPAR, COMBO_END};
const uint16_t PROGMEM r_low_tab_combo[] = {RAI_BSP, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM r_low_ent_combo[] = {RAI_BSP, KC_5, KC_6, COMBO_END};

// Raise

const uint16_t PROGMEM r_rai_cur_combo[] = {TD_LCRB, TD_RCRB, COMBO_END};

// Navigation

const uint16_t PROGMEM l_nav_esv_combo[] = {MC_ESC, MC_SAVE, COMBO_END};

// Media

const uint16_t PROGMEM r_med_del_combo[] = {TG_NUM, KC_MPLY, COMBO_END};
const uint16_t PROGMEM r_med_hom_combo[] = {KC_MPLY, KC_MPRV, COMBO_END};
const uint16_t PROGMEM r_med_end_combo[] = {KC_MPRV, KC_MNXT, COMBO_END};
const uint16_t PROGMEM r_med_ins_combo[] = {KC_MNXT, HYPR_V, COMBO_END};
const uint16_t PROGMEM r_med_ent_combo[] = {KC_ENT, KC_TAB, COMBO_END};

// Accents

const uint16_t PROGMEM r_ng_ao_combo[]   = {MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_ng_cao_combo[]  = {MC_TL_A, MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_ng_oes_combo[]  = {MC_CR_O, MC_CR_E, COMBO_END};
const uint16_t PROGMEM r_ng_coes_combo[] = {MC_CR_A, MC_CR_O, MC_CR_E, COMBO_END};

// Macros

const uint16_t PROGMEM r_mac_ref_combo[] = {MC_MODM, SF_MODP, COMBO_END};
const uint16_t PROGMEM r_mac_clo_combo[] = {MC_SWLE, MC_SWRI, COMBO_END};

// Base

const uint16_t PROGMEM l_rom_z_combo[]   = {KC_C, LALTT_P, COMBO_END};
const uint16_t PROGMEM l_rom_esc_combo[] = {LOW_SPC, KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM l_rom_ful_combo[] = {LOW_SPC, KCR_MAC, LSFTT_N, COMBO_END};
const uint16_t PROGMEM l_rom_rai_combo[] = {LOW_SPC, LSFTT_N, COMBO_END};
const uint16_t PROGMEM l_rom_low_combo[] = {LOW_SPC, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_sav_combo[] = {LOW_SPC, LSFTT_N, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_usc_combo[] = {KC_B, KC_C, COMBO_END};
const uint16_t PROGMEM l_rom_pas_combo[] = {LOW_SPC, LCTLT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM l_rom_fin_combo[] = {LOW_SPC, RALTT_Q, KC_B, COMBO_END};
const uint16_t PROGMEM l_rom_cop_combo[] = {LOW_SPC, KC_C, LALTT_P, COMBO_END};

const uint16_t PROGMEM r_rom_x_combo[]   = {LALTT_M, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_tab_combo[] = {RAI_BSP, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_pas_combo[] = {RAI_BSP, RGUIT_H, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_ent_combo[] = {RAI_BSP, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_rai_combo[] = {RAI_BSP, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_low_combo[] = {RAI_BSP, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_sal_combo[] = {RAI_BSP, RSFTT_E, KCI_MAC, COMBO_END};
const uint16_t PROGMEM r_rom_cop_combo[] = {RAI_BSP, LALTT_M, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_sco_combo[] = {TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_und_combo[] = {RAI_BSP, TD_DOT, RALTT_Y, COMBO_END};
const uint16_t PROGMEM r_rom_sce_combo[] = {LALTT_M, TD_COMM, TD_DOT, COMBO_END};

// Reset

const uint16_t PROGMEM rom_reset_combo[] = {KCR_MAC, RALTT_Q, KCI_MAC, RALTT_Y, COMBO_END};

// Secret

const uint16_t PROGMEM secret_1_combo[] = {SEC_1, SEC_2, SEC_3, SEC_4, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(l_rom_z_combo, KC_Z),      COMBO(r_rom_x_combo, KC_X),      COMBO(l_num_esc_combo, KC_ESC),
    COMBO(l_nav_esv_combo, MC_ESAV), COMBO(l_num_sav_combo, MC_SAVE), COMBO(r_num_ent_combo, KC_ENT),
    COMBO(l_low_par_combo, TD_PARN), COMBO(r_low_tab_combo, KC_TAB),  COMBO(r_low_ent_combo, KC_ENT),
    COMBO(r_ng_ao_combo, MC_AO),     COMBO(r_ng_cao_combo, MC_CAO),   COMBO(r_ng_oes_combo, MC_OES),
    COMBO(r_ng_coes_combo, MC_COES), COMBO(r_mac_ref_combo, MC_REF),  COMBO(r_mac_clo_combo, MC_CTAB),
    COMBO(r_rom_cop_combo, MC_COPY), COMBO(r_rom_sco_combo, TD_SCLE), COMBO(l_rom_usc_combo, MC_UNDS),
    COMBO(l_rom_ful_combo, MC_FULL), COMBO(r_rom_pas_combo, MC_PAST), COMBO(l_rom_rai_combo, OS_RAI),
    COMBO(l_rom_low_combo, OS_LOW),  COMBO(l_rom_sav_combo, MC_SAVE), COMBO(l_rom_pas_combo, MC_PAST),
    COMBO(l_rom_esc_combo, KC_ESC),  COMBO(r_rom_und_combo, MC_UNDO), COMBO(r_rom_sce_combo, MC_SENT),
    COMBO(l_rom_fin_combo, MC_FIND), COMBO(l_rom_cop_combo, MC_COPY), COMBO(r_rom_tab_combo, KC_TAB),
    COMBO(r_rom_low_combo, OS_LOW),  COMBO(r_rom_rai_combo, OS_RAI),  COMBO(r_rom_ent_combo, KC_ENT),
    COMBO(r_rom_sal_combo, MC_SELC), COMBO(r_med_hom_combo, KC_HOME), COMBO(r_med_end_combo, KC_END),
    COMBO(r_rai_cur_combo, MC_CUR),  COMBO(r_med_del_combo, KC_DEL),  COMBO(r_med_ins_combo, KC_INS),
    COMBO(r_med_ent_combo, TD_EENT), COMBO(rom_reset_combo, QK_BOOT), COMBO(secret_1_combo, MC_SECRET_1),
};