/* SPDX-License-Identifier: MIT */
#define DT_DRV_COMPAT test_keymap_marker

#include <drivers/behavior.h>
#include <zmk/behavior.h>
#include <zephyr/sys/printk.h>

static int mark(struct zmk_behavior_binding *binding, struct zmk_behavior_binding_event event) {
    printk("KEYMAP_%s\n", binding->param1 ? "CASE" : "RESET");
    return ZMK_BEHAVIOR_OPAQUE;
}

static const struct behavior_driver_api marker_api = {.binding_pressed = mark};

BEHAVIOR_DT_INST_DEFINE(0, NULL, NULL, NULL, NULL, POST_KERNEL,
                        CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, &marker_api);
