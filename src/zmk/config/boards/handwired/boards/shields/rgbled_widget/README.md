# LED indicators using an RGB LED

This is a shield containing a simple widget that utilizes a (typically built-in) RGB LED controlled by three separate GPIOs.

By default this is supported by Xiao BLE and Xiao RP2040 boards, see overlays in the [`boards` folder](boards/).
You can also add support for your board/shield by defining `aliases` to the RGB LED node labels, similar to the examples in that folder.

Currently the widget does the following:
- Blink green/yellow/red on boot depending on battery level (for both central/peripherals), thresholds set by `CONFIG_RGBLED_WIDGET_BATTERY_LEVEL_{HIGH,LOW}`
- Blink red on every battery level read if below critical battery level (`CONFIG_RGBLED_WIDGET_BATTERY_LEVEL_CRITICAL`)
- Blink blue for connected, yellow for open, red for disconnected profile on profile switch (on central side)
- Blink blue for connection, red for disconnection on peripheral side

Blink durations can also be adjusted, see the [Kconfig file](Kconfig.defconfig).

See [this video](https://cdn.discordapp.com/attachments/1134635625455292426/1134639930501496832/rgbled_widget.mp4) for a short demo, running through power on, profile switching and power offs.
