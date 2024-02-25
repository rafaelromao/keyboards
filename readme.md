# rafaelromao's keyboard layout
 
## Overview

A split keyboard layout optimized for Portuguese, English, working with numbers and software programming with VIM plugins.

![img](img/overview.png)

## How this layout works?

The following pages explain how this layout works and which features are implemented.

### Layers

- [Alphas](docs/base.md)
- [Symbols and Numbers](docs/symbols.md)
- [Shortcuts and Macros](docs/shortcuts.md) 
- [Navigation and Media](docs/navigation.md)
- [System](docs/system.md)

### Main Features

- [Smart Modifiers](docs/modifiers.md)
- [Smart Thumb Keys](docs/base.md#smart-thumb-keys)
- [Smart Shift / Repeat Key](docs/base.md#smart-thumb-keys)
- [Smart Shift / Magic Key](docs/base.md#smart-thumb-keys)
- [Smart Cases](docs/modifiers.md#smart-cases)
- [Sentence Case](docs/base.md#sentence-case)
- [Shortcut Combos](docs/base.md#base-layer-combos)
- [Numpad Layer](docs/symbols.md#numpad)
- [NumWord](docs/symbols.md#numword)
- [Leader Key](docs/shortcuts.md#leader-key)
- [Swapper](docs/shortcuts.md#swapper)
- [Select Word](docs/shortcuts.md#select-word-and-select-line)
- [Dynamic Macros](docs/shortcuts.md#dynamic-macros)
- [Coding Dancing](docs/symbols.md#coding-dancing)
- [Coding Shortcuts](docs/shortcuts.md#coding-shortcuts)
- [Orbital Mouse](docs/navigation.md#orbital-mouse)

## About this repo

This repository contains the keymap files that are used to customize my keyboards. The firmware files are included as submodules or external references and symlinks are used to make them see the keymap files.

## Compatibility

This layout was tested with the keyboards listed below, but can be easily adapted to most ortholinear or column staggered keyboards with at least 24 keys, with 2 of them on each thumb.

### QMK

The reference implementation is done in QMK, so it has all features supported.

The QMK version recommended for this keymap is 0.22.10.

The tested boards are listed below:

- [handwired/rafaelromao/fauxberry](src/qmk/keyboards/handwired/rafaelromao/fauxberry/readme.md)
- [handwired/rafaelromao/rommana](src/qmk/keyboards/handwired/rafaelromao/rommana/readme.md)
- [kprepublic/bm40hsrgb](src/qmk/keyboards/kprepublic/bm40hsrgb/keymaps/rafaelromao/readme.md)
- [xiudi/xd75](src/qmk/keyboards/xiudi/xd75/keymaps/rafaelromao/readme.md)

Some features are not available on all keyboards though. For instance, the BM40 does not support Dynamic Macros.

### ZMK

The zmk version used for this keymap is the one available in [this fork](https://github.com/rafaelromao/zmk/tree/rafaelromao/main), which contains some experimental code from [Nick Conway](https://github.com/nickconway/zmk-config), [Cem Aksoylar](https://github.com/caksoylar/zmk-config ), [Robert U](https://github.com/urob/zmk-config) and [Alexander Krikun](https://github.com/krikun98), to implement features like:
- [Swapper](https://github.com/zmkfirmware/zmk/pull/1366)
- [Smart Word](https://github.com/zmkfirmware/zmk/pull/1451)
- [Leader Key](https://github.com/zmkfirmware/zmk/pull/1380)
- [Dynamic Macros](https://github.com/zmkfirmware/zmk/pull/1351)
- [Mouse Keys](https://github.com/zmkfirmware/zmk/pull/778)
- [Some improvements for the Corne-ish Zen display](https://gist.github.com/caksoylar/c411313990978e1903c244f03039187a)

This fork is also updated to Zephyr 3.5.

The tested boards are listed below:

- [lowprokb.ca/corneish-zen](src/zmk/config/boards/lowprokb.ca/corneish-zen/readme.md)

Some features might not be available in ZMK. [This readme file](src/zmk/config/rafaelromao/readme.md) will indicate what features are missing.

## Building

### QMK

The script [init_qmk.sh](init_qmk.sh) will clone [the QMK firmware](https://github.com/qmk/qmk_firmware) and symlink these keyboard files on it.
After [installing QMK](https://docs.qmk.fm/#/newbs_getting_started) and running the init script above, [qmk cli](https://docs.qmk.fm/#/cli) should be working to compile and flash.

### ZMK

The script [init_zmk.sh](init_zmk.sh) will clone [the ZMK firmware](https://github.com/rafaelromao/zmk) and configure the toolchain.
After [installing ZMK](https://zmk.dev/docs/development/setup) and running the init script above, [west cli](https://zmk.dev/docs/development/build-flash) should be working to compile and flash.

## References

Most features implemented here were based on the work referenced below.

### Layouts
- [Colemak](https://colemak.org)
- [BEAKL](https://ieants.cc/beakl)
- [Hands Down](https://sites.google.com/alanreiser.com/handsdown/home)
- [Engram](https://engram.dev)
- [Miryoku](https://github.com/manna-harbour/miryoku)
- [Seniply](https://stevep99.github.io/seniply)
- [Suraj Kurapati](https://sunaku.github.io/moergo-glove80-keyboard.html)
- [bmijanovich](https://github.com/bmijanovich/zmk-config)
- [DreymaR](https://dreymar.colemak.org)
- [Ben Vallack](https://youtube.com/c/BenVallack)

### QMK
- [Pascal Getreuer](https://github.com/getreuer/qmk-keymap)
- [Precondition](https://github.com/precondition/dactyl-manuform-keymap)
- [Drashna](https://github.com/drashna/qmk_userspace)
- [Callum Oakley](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum)
- [Andrew Rae](https://github.com/andrewjrae/kyria-keymap)
- [Weilbith](https://github.com/weilbith/keyboard_firmware)
- [Treeman](https://github.com/treeman/qmk_firmware/tree/master/keyboards/ferris/keymaps/treeman)
- [Thomas Baart](https://thomasbaart.nl/category/mechanical-keyboards/firmware/qmk)

### ZMK
- [Nick Conway](https://github.com/nickconway/zmk-config)
- [Cem Aksoylar](https://github.com/caksoylar/zmk-config )
- [Robert U](https://github.com/urob/zmk-config)
- [Alexander Krikun](https://github.com/krikun98)

### 3D Printing and Handwiring
- [Jan Lunge](https://m.youtube.com/@JanLunge)
- [Sadek Baroudi](https://github.com/sadekbaroudi)
- [Joe Scotto](https://github.com/joe-scotto)
- [Alaa Saad Mansour](https://github.com/AlaaSaadAbdo)
- [Peter Elliot](https://github.com/PJE66)

## Resouces

- [KLE](http://www.keyboard-layout-editor.com/#/gists/38f4435ff9a10256d9a7e1a0645c2fec)
- [Keymap DB](https://keymapdb.com/rafaelromao/)
- [QMK Docs](https://docs.qmk.fm)
- [ZMK Docs](https://zmk.dev/docs)
- [Keyboard Tester](https://config.qmk.fm/#/test)
- [r/olkb](https://www.reddit.com/r/olkb)
- [r/ErgoMechKeyboards](https://www.reddit.com/r/ErgoMechKeyboards)
