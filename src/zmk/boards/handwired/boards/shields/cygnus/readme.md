## Dactyl Cygnus
### A 36 keys handwired split keyboard.

### Build Details

Dactyl Cygnus is a handwired board originally designed by @juhakaup and available at [https://github.com/juhakaup/keyboards](https://github.com/juhakaup/keyboards).

### Dactyl Cygnus
![img](../../../../../../../img/cygnus/cygnus.jpeg)

Parts:
- 36 MX switches (Gateron Oil Kings).
- 34 1u MX keycaps (MT3 Blanks).
- 2 1.5u MX thumb keycaps (MT3 Blanks).
- Cygnus [case](https://github.com/juhakaup/keyboards/tree/main/Cygnus%20v1.0/stl).
- [2 Supermini NRF52840](https://www.aliexpress.com/item/1005006035267231.html).
- [2 500mAh 3.7v battery - 752035](https://www.aliexpress.com/item/1005005984848543.html)
- [36 Single Switch PCBs](https://keycapsss.com/keyboard-parts/pcbs/173/mxledbit-single-switch-pcb-mx-choc-hot-swap-socket).
- [Dupont cables](https://aliexpress.com/item/1005004155181609.html).
- [1n4148 diodes + diode legs](https://pt.aliexpress.com/item/1005003540554760.html).

Parts for the dongle:
- Dongle [case](../../../../../../../stls/Dongle/).
- [1 0.96 I2C OLED Screen](https://www.aliexpress.com/item/1005006262908701.html).
- [1 6x6x6 switch](https://www.aliexpress.com/item/4001166999847.html).
- [1 SS12F15 switch](https://www.aliexpress.com/item/4000699324084.html).
- [1 Supermini NRF52840](https://www.aliexpress.com/item/1005006035267231.html).
- [1 500mAh 3.7v battery - 752035](https://www.aliexpress.com/item/1005005984848543.html)

[Here](../../../../../../../docs/builds/cygnus.md) you can see some build images.

### ZMK

#### Compile

- Run the script `build_cygnus` to build the firmware for the central left side (use it without a dongle) and the dongle only.
- Run the script `build_cygnus_all` to build the firmware for both sides and the dongle.

#### Flash

- Connect the central dongle, put it in bootloader mode and copy the file `build/artifacts/cygnus_dongle-zmk.uf2` to the drive NICENANO. Wait for the drive to be disconnected.
- Connect the left half, put it in bootloader mode and copy the file `build/artifacts/cygnus_left-zmk.uf2` to the drive NICENANO. Wait for the drive to be disconnected.
- Connect the right half, put it in bootloader mode and copy the file `build/artifacts/cygnus_right-zmk.uf2` to the drive NICENANO. Wait for the drive to be disconnected.

## Keymap

- The list of supported features in this keymap can be found [here](../../../../../readme.md).

## Resources

- [Home](https://github.com/rafaelromao/keyboards)
- [ZMK Docs](https://zmk.dev/docs)
- [Keyboard Tester](https://config.qmk.fm/#/test)
