# Prisma firmware

Build all nine images with `b prisma -c -p` in the project container.

| Central | Artifact (append `-zmk.uf2`) |
| --- | --- |
| Left half | prisma_central_left |
| XIAO headless dongle | prisma_central_dongle |
| XIAO OLED dongle | prisma_central_dongle_oled |
| XIAO trackball | prisma_central_trackball_xiao |
| nice!nano trackball | prisma_central_trackball_nano |
| XIAO trackpad | prisma_central_trackpad_xiao |
| nice!nano trackpad | prisma_central_trackpad_nano |

Use one central. For any module central, flash `prisma_peripheral_left` and
`prisma_peripheral_right` to the halves. For a left-half central, flash only
the right peripheral. Clear stale split and host bonds using settings-reset
when switching roles. Standalone mouse builds in the hardware repository
are separate and are not split centrals.

Pointing centrals append local positions 36/37 to the shared 36-position map.
Forward button clicks left, rear button taps right or holds scroll, both
click middle. Layer 30 converts pointer motion to scrolling; existing
keyboard layers and combos retain their numbers. Cirque tap remains enabled.
GPIO assignments are copied from the hardware shields at 8ff795c171cc35836cdc8c733cf70cd11ce255c9.
The PMW3610 driver pin matches the hardware manifest.

All centrals use USB/BLE host transport; module centrals expect two split
peers. No builds or hardware tests were performed. Inspect generated maps,
layer counts, key positions, and controller pins; verify both halves pair,
reconnect, and forward all keys; test simultaneous keyboard/mouse HID,
clicks, scroll, tap, all layers while scrolling, reset and power.
