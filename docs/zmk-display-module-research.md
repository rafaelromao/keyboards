# ZMK peripheral status display selection

Checked 2026-10-26 against first-party documentation and source. No reviewed
module satisfied the complete requirement: a 128x32/128x64 OLED on either a
central or a peripheral, showing central host connectivity and the battery and
connection state of **every** peripheral, with a battery-less/display-less dongle.
This is a finding about the implementations reviewed, not proof that no other
project exists.

## Existing hardware and firmware

- Dilemma: 128x32 SSD1306 OLED on the left, Cirque on the right; existing split
  input forwarding and a mock-matrix dongle shield. The old peripheral-left
  configuration disabled the display.
- Diamond, Choc Diamond and Rommana dongles: 128x64 SSD1306 OLEDs.
- ZMK is pinned to `9ebbeff0a8b69a42f14aec022cdf16c7a107b9e0` in
  `scripts/zmk.sh`, using Zephyr 4.1 and LVGL 9. This is not a ZMK v0.3 setup.

## Candidates

| Module | Relevant capability | Missing requirement |
| --- | --- | --- |
| [englmaxi/zmk-dongle-display](https://github.com/englmaxi/zmk-dongle-display) | Existing 128x64/128x32 OLED widgets and peripheral batteries on a central. | Its [CMake condition](https://github.com/englmaxi/zmk-dongle-display/blob/main/boards/shields/dongle_display/CMakeLists.txt) explicitly excludes split peripherals. Removing that condition alone would not relay host or sibling state. |
| [mctechnology17/zmk-nice-oled](https://github.com/mctechnology17/zmk-nice-oled) | OLED peripheral screens, configurable layouts, central multi-battery widgets. | The [peripheral implementation](https://github.com/mctechnology17/zmk-nice-oled/blob/main/boards/shields/nice_oled/widgets/screen_peripheral.c) reads local `zmk_battery_state_of_charge()` and local `zmk_split_bt_peripheral_is_connected()`. It does not supply every sibling's battery/connection on that screen. The [README](https://github.com/mctechnology17/zmk-nice-oled/blob/main/README.md) labels all-peripheral battery options as **central** options and documents v0.3 testing. |
| [janpfischer/zmk-dongle-screen (YADS)](https://github.com/janpfischer/zmk-dongle-screen) | Host output and central/peripheral battery widgets on a dongle. | The [documented target](https://github.com/janpfischer/zmk-dongle-screen/blob/main/README.md) is an ST7789V color display on the central dongle, not a drop-in peripheral SSD1306 screen for both existing resolutions. Its main branch also documents a separate Zephyr 4.1 upgrade branch. |
| [carrefinho/prospector-zmk-module](https://github.com/carrefinho/prospector-zmk-module) | Dongle status with peripheral batteries. | [Prospector's first-party hardware description](https://github.com/carrefinho/prospector/blob/main/README.md) targets a 1.69-inch IPS color LCD desktop dongle, not these peripheral OLEDs. |
| [ArtemYurov/nice-view-central-relay](https://github.com/ArtemYurov/nice-view-central-relay) with [zmk-central-states-relay](https://github.com/ArtemYurov/zmk-central-states-relay) | Actual reverse relay of central host/battery state over the existing BLE link; a peripheral screen with local and central state. | The [documented 16-byte payload](https://github.com/ArtemYurov/zmk-central-states-relay/blob/main/README.md) has one `central_battery` field and no sibling battery/connection array. The [display fork](https://github.com/ArtemYurov/nice-view-central-relay/blob/main/README.md) is for nice!view, not these two OLED resolutions. This is a useful partial alternative, not a complete replacement. |

## Why reverse relay is necessary

ZMK's [split configuration](https://zmk.dev/docs/config/split) defines battery
fetching from peripherals **to the central**. Its [battery proxy documentation](https://zmk.dev/docs/config/battery)
describes exposing those values to connected hosts, not broadcasting them back
to sibling peripherals. A peripheral OLED cannot infer central host profiles or
the other half's battery merely by enabling the built-in widgets.

## Selected fallback

Extend `~/projects/zmk-dongle-display` and migrate the existing OLED build entry
points to that fork. Keep the original animated central screen selectable, but
default to a compact battery/connectivity screen that fits both resolutions.

- `dongle_display`: OLED screen on central or peripheral.
- `dongle_display_relay`: headless central, no display/LVGL or battery sampling.
- Relay host status and a record for each configured peripheral using ZMK's
  [existing split behavior invocation](https://github.com/zmkfirmware/zmk/blob/9ebbeff0a8b69a42f14aec022cdf16c7a107b9e0/app/src/split/central.c).
  The [BLE behavior payload](https://github.com/zmkfirmware/zmk/blob/9ebbeff0a8b69a42f14aec022cdf16c7a107b9e0/app/include/zmk/split/bluetooth/service.h)
  fits 20 bytes with a short behavior name. No additional BLE connection or
  upstream ZMK patch is needed.
- Separate connected, unknown battery, valid 0%, and battery-less central states;
  keep the local battery authoritative while receiving relayed records.
- Coalesce changes, pace records, resend infrequent heartbeats, expire stale
  remote values, and preserve normal display blanking and peripheral sleep.
- Pair the OLED half first, or change the receiver source-ID mask. Source IDs
  are pairing order, not fixed handedness.

Physical BLE/OLED behavior and battery-life improvement require hardware
testing; successful compilation and protocol tests do not establish those.

## Additional source checks and caveats

- **Pin and dimensions:** the read-only inspection found the pin in
  [`scripts/zmk.sh`](../scripts/zmk.sh). Its upstream
  [manifest](https://github.com/zmkfirmware/zmk/blob/9ebbeff0a8b69a42f14aec022cdf16c7a107b9e0/app/west.yml)
  selects `v4.1.0+zmk-fixes` and LVGL commit `f1db87ee`; that commit's
  [version header](https://github.com/zmkfirmware/lvgl/blob/f1db87ee98f1810328a8419572fa42a3b5f352ae/lv_version.h)
  identifies LVGL **9.3.0-dev**. The OLED dimensions are explicit in
  [Dilemma's DTS](../zmk/keyboards/bastardkb/dilemma/boards/shields/dilemma/dilemma.dtsi),
  [Diamond's dongle overlay](../zmk/keyboards/rafaelromao/diamond/boards/shields/diamond/diamond_central_dongle.overlay),
  [Choc Diamond's dongle overlay](../zmk/keyboards/rafaelromao/choc_diamond/boards/shields/choc_diamond/choc_diamond_central_dongle.overlay)
  and [Rommana's dongle overlay](../zmk/keyboards/mabroum/rommana/boards/shields/rommana/rommana_central_dongle.overlay).
- **Built-in ZMK widgets are not a hidden solution.** At the pinned commit,
  [output/layer widgets are central-only](https://github.com/zmkfirmware/zmk/blob/9ebbeff0a8b69a42f14aec022cdf16c7a107b9e0/app/src/display/widgets/Kconfig).
  The peripheral [connection widget](https://github.com/zmkfirmware/zmk/blob/9ebbeff0a8b69a42f14aec022cdf16c7a107b9e0/app/src/display/widgets/peripheral_status.c)
  reads only its link to the central, and the [battery widget](https://github.com/zmkfirmware/zmk/blob/9ebbeff0a8b69a42f14aec022cdf16c7a107b9e0/app/src/display/widgets/battery_status.c)
  reads only its own battery. Neither provides sibling or central-host state.
- **Other dongle-display forks remain central-only:**
  [hitsmaxft's Zephyr 4 branch](https://github.com/hitsmaxft/zmk-dongle-display/blob/zephyr4/boards/shields/dongle_display/CMakeLists.txt)
  and [mctechnology17's nice!view variant](https://github.com/mctechnology17/zmk-dongle-display-view/blob/main/boards/shields/dongle_display_view/CMakeLists.txt)
  retain the same peripheral-excluding CMake condition. A Zephyr/LVGL port or
  different screen layout is not remote-state synchronization.
- **Prospector Scanner is the closest broadcast alternative, not a drop-in.**
  [t-ogura's documentation](https://github.com/t-ogura/zmk-config-prospector#protocol-specification)
  describes a separate ST7789V display receiving BLE advertisements. Its
  [actual payload](https://github.com/t-ogura/prospector-zmk-module/blob/72a71aeea816eb0f86ffc5b108b267076ce5f0af/include/zmk/status_advertisement.h)
  carries USB-powered/HID-ready and BLE-host flags plus three peripheral battery
  bytes, but **no per-peripheral connected/valid bitmap** (`0` means N/A).
  The [scanner Kconfig](https://github.com/t-ogura/prospector-zmk-module/blob/72a71aeea816eb0f86ffc5b108b267076ce5f0af/Kconfig)
  explicitly describes a standalone display. Integrating its receiver into an
  actively connected keyboard peripheral, adding both OLED layouts, and making
  connection/unknown/0% unambiguous would still require development and radio/power
  testing. Its keyboard-side Zephyr 4 support does not establish that integration.
- **ArtemYurov's relay really does move remote state**, unlike local-only status
  screens. However, its [sender](https://github.com/ArtemYurov/zmk-central-states-relay/blob/39e3d8ab15fded008c543618acce7a1724ca0459/src/central_states_sender.c)
  sets `CSR_FLAG_USB` from `zmk_usb_is_powered()`, **not** HID readiness or selected
  output, and its [wire structure](https://github.com/ArtemYurov/zmk-central-states-relay/blob/39e3d8ab15fded008c543618acce7a1724ca0459/include/zmk/split/central-states/event.h)
  has no sibling records or battery-valid/absent flags. Reusing/extending this
  transport is viable, but the unmodified module fails the full requirement.
- **Alternative extension seam:** if avoiding behavior-payload multiplexing is
  preferred, reuse ArtemYurov's module-owned GATT service design: discover a
  display-status characteristic on the existing split connection and write a
  versioned aggregate snapshot. Its [receiver](https://github.com/ArtemYurov/zmk-central-states-relay/blob/39e3d8ab15fded008c543618acce7a1724ca0459/src/central_states_receiver.c)
  already demonstrates encrypted writes and deferred event delivery. Keep this
  headless sender independent of `CONFIG_ZMK_DISPLAY` and local battery sensing.
  This is a design recommendation, not a tested replacement.

**Acceptance gate:** on the peripheral OLED, distinguish central host HID-ready
from merely USB-powered, show every configured peripheral independently, preserve
a valid 0% reading, and mark remote data unknown/stale after disconnects. Exercise
128x32 and 128x64, both central/peripheral display roles, and a headless central
with no battery sensor. No reviewed upstream module passes all of these unchanged.
