# rafaelromao's keyboard layout

A 34 keys split keyboard layout, optimized for programmers.

### Overview

![img](https://i.imgur.com/mESmbEi.png)

### How this layout works?

The following pages explain how this layout works and which features were implemented.

- [Base](docs/base.md)
- [Modifiers](docs/modifiers.md)
- [Symbols and Numbers](docs/symbols.md)
- [Functions and Media](docs/functions.md)
- [Navigation and Mouse](docs/navigation.md)
- [Maintenance](docs/maintenance.md)

### About this repo

- This repository contains the files that are used to customize my keyboards.
- The script [init.sh](init.sh) will clone [the QMK firmware](https://github.com/qmk/qmk_firmware) and symlink these files on it.
- After [installing QMK](https://docs.qmk.fm/#/newbs_getting_started) and running the init script with `source init.sh`, [qmk cli](https://docs.qmk.fm/#/cli) should work just fine to compile and flash.

### Compatibility

This layout was tested with the keyboards listed below, but can be easily adapted to any ortholinear or column staggered QMK keyboard with at least 34 keys, with 2 of them on each thumb.

- [kprepublic/bm40hsrgb](qmk/keyboards/kprepublic/bm40hsrgb/keymaps/rafaelromao/readme.md)
- [xiudi/xd75](qmk/keyboards/xiudi/xd75/keymaps/rafaelromao/readme.md)

### References

Most features implemented here were based on the work referenced below.

- [Miryoku](https://github.com/manna-harbour/miryoku)
- [Seniply](https://stevep99.github.io/seniply)
- [Precondition](https://github.com/precondition/dactyl-manuform-keymap)
- [Callum Oakley](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum)
- [Drashna](https://github.com/qmk/qmk_firmware/tree/master/users/drashna)
- [Pascal Getreuer](https://github.com/getreuer/qmk-keymap)
- [Weilbith](https://github.com/weilbith/keyboard_firmware)
- [DreymaR](https://dreymar.colemak.org)
- [Thomas Baart](https://thomasbaart.nl/category/mechanical-keyboards/firmware/qmk)
- [Ben Vallack](https://youtube.com/c/BenVallack)

### Resouces

- [KLE](http://www.keyboard-layout-editor.com/#/gists/1a36101d96c804188d2d104ab5296739)
- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
