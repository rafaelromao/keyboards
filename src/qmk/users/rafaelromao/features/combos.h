#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "tapdance.h"
#include "custom_oneshot.h"
#include "secret.h"

enum combos {
    l_num_esc,
    l_num_sav,
    r_num_ent,
    l_low_par,
    r_low_tab,
    r_low_ent,
    r_rai_cur,
    r_rai_plu,
    r_rai_ast,
    l_nav_esv,
    r_med_ent,
    r_ng_ao,
    r_ng_cu,
    r_ng_ca,
    r_ng_co,
    r_ng_cao,
    r_ng_oes,
    r_ng_coes,
    r_mac_ref,
    r_mac_clo,
    l_rom_z,
    l_rom_q,
    l_rom_qu,
    l_rom_esc,
    l_rom_und,
    l_rom_rai,
    l_rom_low,
    l_rom_sav,
    l_rom_usc,
    l_rom_ful,
    l_rom_fin,
    r_rom_y,
    r_rom_p,
    r_rom_x,
    r_rom_tab,
    r_rom_oes,
    r_rom_cop,
    r_rom_pas,
    r_rom_ent,
    r_rom_rai,
    r_rom_low,
    r_rom_sal,
    r_rom_sco,
    r_rom_sce,
    secret_1
};