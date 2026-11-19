# Dilemma: optional headless dongle

The normal `b dilemma` build keeps the left half as central. To move the central
role to a USB-powered nice!nano dongle without a battery or OLED, build all
three devices with:

```sh
b dilemma-dongle
```

This builds `dilemma_central_dongle`, `dilemma_peripheral_left` (OLED), and
`dilemma_peripheral_right` (Cirque). The right's input is still forwarded to the
central, where the existing pointer transforms and scaling run. `b dilemma -c`
also includes these optional artifacts. Flash all three matching roles; the
normal central-left firmware cannot be used as a dongle peripheral.

All OLED builds now use the `rafaelromao/zmk-dongle-display` fork. The original
widget screen and layout remain the default on both 128x32 and 128x64, including
on a peripheral OLED. The dongle relays host connectivity, all half batteries,
layer/name, modifiers, lock indicators and WPM; Bongo Cat animates on the OLED
half from that WPM. All original widget configuration options remain available.
Dilemma's peripheral-left shows the layer name with Bongo Cat and modifiers
disabled; these widgets can still be enabled individually, even on 128x32.
The compact text screen is opt-in only via
`CONFIG_ZMK_DONGLE_DISPLAY_STATUS_SCREEN=y`.
The Dilemma dongle uses `dongle_display_relay`, not `dongle_display`: no display
or local battery sampling is enabled on it. The Zen's separate optional dongle
setup and board-specific e-paper screens are unchanged.
The [module comparison](../../../../../../../docs/zmk-display-module-research.md) records the reviewed
alternatives and why the fork was extended.

**Pairing:** when changing central roles, reset settings on the dongle and both
halves, then pair the **left/OLED first** (power the right off until the left
has connected). Battery rows follow pairing order, not physical sides. If the OLED
is already source 1 instead, set
`CONFIG_ZMK_DONGLE_DISPLAY_STATUS_RECEIVERS=0x2` in
`dilemma_central_dongle.conf`. Resetting settings clears host bonds too, so
remove old host pairings and re-pair them. To switch back, flash central-left
plus peripheral-right, reset their settings, and pair again.
`b reset` builds the nice!nano settings-reset image; flash that before the
matching role firmware when clearing device settings.

`init.sh` automatically mounts `~/projects/zmk-dongle-display` read-only and
uses that local working tree when present, so unpublished module changes are
included. For another container setup, mount it manually and select it with:

```sh
# Mount ~/projects/zmk-dongle-display as /display-module in the build container.
ZMK_DONGLE_DISPLAY_MODULE=/display-module bash scripts/b.sh dilemma-dongle
```

`scripts/zmk.sh -m` accepts absolute local module paths without fetching or
checking them out. For an initialized toolchain/module cache, run
`ZMK_DONGLE_DISPLAY_MODULE=/display-module bash scripts/validate-displays.sh`
inside the container to build all seven affected OLED/receiver targets and
verify generated Dilemma roles. This does not flash devices or measure battery
life; OLED blanking and both peripheral sleep settings remain enabled.

After flashing, verify that both halves report batteries, powering the right
off changes `P2` to disconnected, the Cirque still moves/scrolls correctly,
and host output/profile changes appear on the left OLED. Also check that the
OLED blanks after a minute idle and wakes on a left key. Battery-life gains
and physical OLED/BLE operation still need testing on the actual hardware.
