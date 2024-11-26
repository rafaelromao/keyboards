## Wired Diamond
### A 24 keys handwired split keyboard.

### Build Details

Diamond is a handwired board originally designed by me but heavily inspired by the [Rommana](https://github.com/AlaaSaadAbdo/Rommana) and using the switch holders of the [Dactyl Cygnus](https://github.com/juhakaup/keyboards).

Wired Diamond is a variant of this keyboard that uses two Xiao RP2040 connected using USB-C and using the experimental [Wired Split PR](https://github.com/zmkfirmware/zmk/pull/2080).

For more information about how this wired split PR works for this MCU, check this other repo: https://github.com/rafaelromao/wired-zmk-config.

### Wired Diamond
![img](../../../../../../../img/wired-diamond/wired-diamond.jpeg)

Parts for the keyboard:
- 24 MX switches.
- 18 1u MX keycaps.
- 6 1.5u MX keycaps.
- Diamond [case](../../../../../../../stls/Diamond) - v2 with tilted thumbs.
- [2 Xiao RP2040](https://www.aliexpress.com/item/1005006987582110.html).
- [24 Single Switch PCBs](https://keycapsss.com/keyboard-parts/pcbs/173/mxledbit-single-switch-pcb-mx-choc-hot-swap-socket).
- [2 USB-C breakout boards](https://www.aliexpress.com/item/1005006047462864.html).
- [28 AWG Wires](https://www.aliexpress.com/item/1005006249194665.html).
- [1n4148 diodes + diode legs](https://www.aliexpress.com/item/1005003540554760.html).

[Here](../../../../../../../docs/builds/wired-diamond.md) you can see some build images.

### ZMK

#### Compile

- Run the script `build_wired_diamond` to build the firmware for the central left side only.
- Run the script `build_wired_diamond_all` to build the firmware for both sides and the dongle.

#### Flash

- Connect the central dongle, put it in bootloader mode and copy the file `build/artifacts/wired_diamond_dongle-zmk.uf2` to the drive RPI-RP2. Wait for the drive to be disconnected.
- Connect the left half, put it in bootloader mode and copy the file `build/artifacts/wired_diamond_left-zmk.uf2` to the drive RPI-RP2. Wait for the drive to be disconnected.
- Connect the right half, put it in bootloader mode and copy the file `build/artifacts/wired_diamond_right-zmk.uf2` to the drive RPI-RP2. Wait for the drive to be disconnected.