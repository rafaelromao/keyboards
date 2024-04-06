## Dactyl Cygnus
### A 36 keys handwired split keyboard.

### Build Details

Dactyl Cygnus is a handwired board originally designed by @juhakaup and available at [https://github.com/juhakaup/keyboards](https://github.com/juhakaup/keyboards).

### Dactyl Cygnus
![img](../../../../../../../img/cygnus.jpeg)

Parts:
- 36 MX switches (Gateron Oil Kings).
- 34 1u MX keycaps (MT3 Blanks).
- 2 1.5u MX thumb keycaps (MT3 Blanks).
- Cygnus [case](https://github.com/juhakaup/keyboards/tree/main/Cygnus%20v1.0/stl/cygnus).
- [2 Supermini NRF52840](https://www.aliexpress.com/item/1005006035267231.html).
- [2 500mAh 3.7v battery - 752035](https://www.aliexpress.com/item/1005005984848543.html)
- [36 Single Switch PCBs](https://keycapsss.com/keyboard-parts/pcbs/173/mxledbit-single-switch-pcb-mx-choc-hot-swap-socket).
- [Dupont cables](https://aliexpress.com/item/1005004155181609.html).
- [1n4148 diodes + diode legs](https://pt.aliexpress.com/item/1005003540554760.html).

### ZMK

#### Compile

- Run the script `build_cygnus`.

#### Flash

- Connect the keyboard, put it in bootloader mode and copy the file `build/artifacts/cygnus-zmk.uf2` to the drive NICENANO. Wait for the drive to be disconnected.

## Keymap

- The list of supported features in this keymap can be found [here](../../../../../readme.md).

## Resources

- [Home](https://github.com/rafaelromao/keyboards)
- [ZMK Docs](https://zmk.dev/docs)
- [Keyboard Tester](https://config.qmk.fm/#/test)
