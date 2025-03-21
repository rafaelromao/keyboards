## Dactyl Cygnus
### A 36 keys handwired split keyboard.

### Build Details

Dactyl Cygnus is a handwired board originally designed by @juhakaup and available at [https://github.com/juhakaup/keyboards](https://github.com/juhakaup/keyboards).

### Dactyl Cygnus
![img](../../../../../../../img/cygnus/cygnus.jpeg)

Parts:
- 36 MX switches.
- 34 1u MX keycaps.
- 2 1.5u MX thumb keycaps.
- Cygnus [case](https://github.com/juhakaup/keyboards/tree/main/Cygnus%20v1.0/stl).
- [2 Supermini NRF52840](https://www.aliexpress.com/item/1005006035267231.html).
- [2 500mAh 3.7v battery - 752035](https://www.aliexpress.com/item/1005005984848543.html)
- [36 Single Switch PCBs](https://keycapsss.com/keyboard-parts/pcbs/173/mxledbit-single-switch-pcb-mx-choc-hot-swap-socket).
- [Dupont cables](https://aliexpress.com/item/1005004155181609.html).
- [1n4148 diodes + diode legs](https://aliexpress.com/item/1005003540554760.html).
- [2 3.7x3.7x8.7x5mm On/Off Switches](https://www.aliexpress.com/item/1005003938856402.html).
- [2 6x6x4.3 Reset Switches](https://www.aliexpress.com/item/1005004159746274.html).

[Here](../../../../../../../docs/builds/cygnus.md) you can see some build images.

### ZMK

#### Compile

- Run the script `build_cygnus` to build the firmware for the left side only.
- Run the script `build_cygnus_all` to build the firmware for both sides.

#### Flash

- Connect the left half, put it in bootloader mode and copy the file `build/artifacts/cygnus_left-zmk.uf2` to the drive NICENANO. Wait for the drive to be disconnected.
- Connect the right half, put it in bootloader mode and copy the file `build/artifacts/cygnus_right-zmk.uf2` to the drive NICENANO. Wait for the drive to be disconnected.