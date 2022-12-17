## lowprokb.ca/corneish-zen
### A 30 keys split keyboard layout, optimized for programmers.

The keyboard in the picture below is a Corneish-Zen, used to design and test this layout.
![img](../../../../../img/zen.png)

### ZMK

The zmk version used for this board is the one available at https://github.com/caksoylar/zmk/tree/caksoylar/zen-v2.

#### Compile

- Run the script `build_zen`.

#### Flash

- Connect the left half, put it in bootloader mode and copy the file `build/artifacts/corneish_zen_v2_left-zmk.uf2` to the drive CORNEISHZEN. Wait for the drive to be disconnected.
- Connect the right half, put it in bootloader mode and copy the file `build/artifacts/corneish_zen_v2_right-zmk.uf2` to the drive CORNEISHZEN. Wait for the drive to be disconnected.

## Keymap

- The list of supported features in this keymap can be found [here](../../../config/rafaelromao/readme.md).

## Resources

- [Home](https://github.com/rafaelromao/keyboards)
- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
