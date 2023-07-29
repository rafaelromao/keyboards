#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/led.h>
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/bluetooth/services/bas.h>

#include <zmk/ble.h>
#include <zmk/endpoints.h>
#include <zmk/events/ble_active_profile_changed.h>
#include <zmk/split/bluetooth/peripheral.h>
#include <zmk/events/split_peripheral_status_changed.h>
#include <zmk/events/battery_state_changed.h>

#include <zephyr/logging/log.h>

LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#define LED_GPIO_NODE_ID DT_COMPAT_GET_ANY_STATUS_OKAY(gpio_leds)

// GPIO-based LED device and indices of red/green/blue LEDs inside its DT node
static const struct device *led_dev = DEVICE_DT_GET(LED_GPIO_NODE_ID);
static const uint8_t rgb_idx[] = {DT_NODE_CHILD_IDX(DT_ALIAS(led_red)),
                                  DT_NODE_CHILD_IDX(DT_ALIAS(led_green)),
                                  DT_NODE_CHILD_IDX(DT_ALIAS(led_blue))};

// color values as specified by an RGB bitfield
enum color_t {
    LED_BLACK,   // 0b000
    LED_RED,     // 0b001
    LED_GREEN,   // 0b010
    LED_YELLOW,  // 0b011
    LED_BLUE,    // 0b100
    LED_MAGENTA, // 0b101
    LED_CYAN,    // 0b110
    LED_WHITE    // 0b111
};

// a blink work item as specified by the color and duration
struct blink_item {
    enum color_t color;
    uint16_t duration_ms;
};

// define message queue of blink work items, that will be processed by a separate thread
K_MSGQ_DEFINE(led_msgq, sizeof(struct blink_item), 16, 4);

#if IS_ENABLED(CONFIG_ZMK_BLE)
#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
static int led_profile_listener_cb(const zmk_event_t *eh) {
    if (zmk_endpoints_selected() != ZMK_ENDPOINT_BLE) {
        return 0;
    }

    uint8_t profile_index = zmk_ble_active_profile_index();
    struct blink_item blink = {.duration_ms = CONFIG_RGBLED_WIDGET_OUTPUT_BLINK_MS};
    if (zmk_ble_active_profile_is_connected()) {
        LOG_INF("Profile %d connected, blinking blue", profile_index);
        blink.color = LED_BLUE;
    } else if (zmk_ble_active_profile_is_open()) {
        LOG_INF("Profile %d open, blinking yellow", profile_index);
        blink.color = LED_YELLOW;
    } else {
        LOG_INF("Profile %d not connected, blinking red", profile_index);
        blink.color = LED_RED;
    }
    k_msgq_put(&led_msgq, &blink, K_NO_WAIT);
    return 0;
}

// run led_profile_listener_cb on BLE profile change (on central)
ZMK_LISTENER(led_profile_listener, led_profile_listener_cb);
ZMK_SUBSCRIPTION(led_profile_listener, zmk_ble_active_profile_changed);
#else
static int led_peripheral_listener_cb(const zmk_event_t *eh) {
    struct blink_item blink = {.duration_ms = CONFIG_RGBLED_WIDGET_OUTPUT_BLINK_MS};
    if (zmk_split_bt_peripheral_is_connected()) {
        LOG_INF("Peripheral connected, blinking blue");
        blink.color = LED_BLUE;
    } else {
        LOG_INF("Peripheral not connected, blinking red");
        blink.color = LED_RED;
    }
    k_msgq_put(&led_msgq, &blink, K_NO_WAIT);
    return 0;
}

// run led_peripheral_listener_cb on peripheral status change event
ZMK_LISTENER(led_peripheral_listener, led_peripheral_listener_cb);
ZMK_SUBSCRIPTION(led_peripheral_listener, zmk_split_peripheral_status_changed);
#endif
#endif // IS_ENABLED(CONFIG_ZMK_BLE)

#if IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING)
static int led_battery_listener_cb(const zmk_event_t *eh) {
    // check if we are in critical battery levels at state change, blink if we are
    uint8_t battery_level = bt_bas_get_battery_level();

    if (battery_level <= CONFIG_RGBLED_WIDGET_BATTERY_LEVEL_CRITICAL) {
        LOG_INF("Battery level %d, blinking red for critical", battery_level);

        struct blink_item blink = {.duration_ms = CONFIG_RGBLED_WIDGET_BATTERY_BLINK_MS,
                                   .color = LED_RED};
        k_msgq_put(&led_msgq, &blink, K_NO_WAIT);
    }
    return 0;
}

// run led_battery_listener_cb on battery state change event
ZMK_LISTENER(led_battery_listener, led_battery_listener_cb);
ZMK_SUBSCRIPTION(led_battery_listener, zmk_battery_state_changed);
#endif // IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING)

extern void led_thread(void *d0, void *d1, void *d2) {
    ARG_UNUSED(d0);
    ARG_UNUSED(d1);
    ARG_UNUSED(d2);

#if IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING)
    // check and indicate battery level on thread start
    struct blink_item blink = {.duration_ms = CONFIG_RGBLED_WIDGET_BATTERY_BLINK_MS};
    uint8_t battery_level = bt_bas_get_battery_level();

    if (battery_level >= CONFIG_RGBLED_WIDGET_BATTERY_LEVEL_HIGH) {
        LOG_INF("Battery level %d, blinking green", battery_level);
        blink.color = LED_GREEN;
    } else if (battery_level >= CONFIG_RGBLED_WIDGET_BATTERY_LEVEL_LOW) {
        LOG_INF("Battery level %d, blinking yellow", battery_level);
        blink.color = LED_YELLOW;
    } else {
        LOG_INF("Battery level %d, blinking red", battery_level);
        blink.color = LED_RED;
    }

    k_msgq_put(&led_msgq, &blink, K_NO_WAIT);
#endif // IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING)

    while (true) {
        // process blinks until message queue is empty
        while (k_msgq_num_used_get(&led_msgq)) {
            struct blink_item blink;
            k_msgq_get(&led_msgq, &blink, K_NO_WAIT);

            // turn appropriate LEDs on
            for (uint8_t pos = 0; pos < 3; pos++) {
                if (BIT(pos) & blink.color) {
                    led_on(led_dev, rgb_idx[pos]);
                }
            }

            // wait for blink duration
            k_sleep(K_MSEC(blink.duration_ms));

            // turn appropriate LEDs off
            for (uint8_t pos = 0; pos < 3; pos++) {
                if (BIT(pos) & blink.color) {
                    led_off(led_dev, rgb_idx[pos]);
                }
            }

            // wait interval before processing another blink
            k_sleep(K_MSEC(CONFIG_RGBLED_WIDGET_INTERVAL_MS));
        }
        k_sleep(K_MSEC(200)); // limit how frequently the queue is checked
        k_yield(); // yield to main thread
    }
}

// define led_thread with stack size 512, start running it 500 ms after boot
K_THREAD_DEFINE(led_tid, 512, led_thread, NULL, NULL, NULL, K_LOWEST_APPLICATION_THREAD_PRIO, 0,
                500);

static int leds_init(const struct device *device) {
    if (!device_is_ready(led_dev)) {
        LOG_ERR("Device %s is not ready", led_dev->name);
        return -ENODEV;
    }

    return 0;
}

// run leds_init on boot
SYS_INIT(leds_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
