#include <assert.h>
#include <stdio.h>

#include "rafaelromao.h"

static const uint16_t alpha1_l2[] = {ALPHA1_L2};
static const uint16_t alpha1_r2[] = {ALPHA1_R2};
static const uint16_t alpha1_l3[] = {ALPHA1_L3};
static const uint16_t base_l2[] = {BASE_L2};
static const uint16_t base_r2[] = {BASE_R2};
static const uint16_t base_l3[] = {BASE_L3};

int main(void) {
    assert(alpha1_l2[1] == LCTL_T(KC_N));
    assert(alpha1_r2[3] == LCTL_T(KC_E));
    assert(alpha1_l3[1] == LSG_T(KC_F));
    assert(alpha1_l3[2] == LSG_T(KC_C));
    assert(base_l2[1] == alpha1_l2[1]);  // N stays Ctrl
    assert(base_r2[3] == alpha1_r2[3]);  // E stays Ctrl
    assert(base_l3[1] == alpha1_l3[1]);  // F stays Shift+GUI
    assert(base_l3[2] == alpha1_l3[2]);  // C stays Shift+GUI

    puts("PASS: BASE reuses the base layout's N/E/F/C mod-taps");
}
