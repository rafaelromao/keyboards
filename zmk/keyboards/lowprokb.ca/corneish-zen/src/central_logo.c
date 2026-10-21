/* SPDX-License-Identifier: MIT */

#include <lvgl.h>

LV_IMG_DECLARE(zenlogo);

void __real_lv_screen_load(lv_obj_t *screen);

void __wrap_lv_screen_load(lv_obj_t *screen) {
    lv_obj_t *logo = lv_image_create(screen);
    lv_image_set_src(logo, &zenlogo);
    lv_obj_align(logo, LV_ALIGN_BOTTOM_MID, 0, -5);

    __real_lv_screen_load(screen);
}
