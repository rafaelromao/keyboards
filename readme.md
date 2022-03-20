# rafaelromao's keyboard layout
 
## Overview

A 34 keys split keyboard layout, optimized for Portuguese, English, working with numbers and software programming with VIM plugins.

![img](https://i.imgur.com/BXXanTF.png)

## How this layout works?

The following pages explain how this layout works and which features are implemented.

### Layers

- [Base](docs/base.md) and [Modifiers](docs/modifiers.md)
- [Symbols and Numbers](docs/symbols.md)
- [Navigation and Mouse](docs/navigation.md)
- [Functions and Maintenance](docs/functions.md)

### Features

- [Home Block Mods](docs/modifiers.md#home-block-modifiers)
- [One Shot Mods](docs/modifiers.md#one-shot-modifiers)
- [Combos](docs/base.md#base-layer-combos)
- [Numpad layer](docs/symbols.md#numpad)
- [Macros](docs/symbols.md#symbols-in-the-lower-layer-left-side)
- [Dynamic Macros](docs/navigation.md#dynamic-macros)
- [Double Dot for New Sentence](docs/base.md#double-dot-for-new-sentences)
- [Leader Key](docs/navigation.md#leader-key)
- [Default Modifier (Cmd vs Ctrl)](docs/modifiers.md#default-mod-key)
- [Capitalize Key](docs/modifiers.md#capitalize-key)
- [Caps Lock Timer](docs/modifiers.md#caps-lock)
- [Dancing Brackets](docs/symbols.md#dancing-brackets)
- [Accentuation Keys](docs/symbols.md#accents-in-the-raise-layer-left-side)
- [Window Swapper](docs/navigation.md#window-swapper)
- [Select Word](docs/navigation.md#select-word)
- [IDE Dancing](docs/functions.md#ide-dancing)
- [Custom Shortcuts](src/qmk/users/rafaelromao/features/custom_shortcuts.c)
- [Custom Tap Hold](src/qmk/users/rafaelromao/features/taphold.c)
- [Custom Shift](src/qmk/users/rafaelromao/features/custom_shift.c)

## About this repo

- This repository contains the files that are used to customize my keyboards.
- The script [init.sh](init.sh) will clone [the QMK firmware](https://github.com/qmk/qmk_firmware) and symlink these files on it.
- After [installing QMK](https://docs.qmk.fm/#/newbs_getting_started) and running the init script with `source init.sh`, [qmk cli](https://docs.qmk.fm/#/cli) should work just fine to compile and flash.

## Compatibility

This layout was tested with the keyboards listed below, but can be easily adapted to any ortholinear or column staggered QMK keyboard with at least 34 keys, with 2 of them on each thumb.

- [kprepublic/bm40hsrgb](src/qmk/keyboards/kprepublic/bm40hsrgb/keymaps/rafaelromao/readme.md)
- [xiudi/xd75](src/qmk/keyboards/xiudi/xd75/keymaps/rafaelromao/readme.md)

Some features are not available on all keyboards though. For instance, the BM40 does not support Dynamic Macros, while the XD75 doesn't have per key RGB.

## References

Most features implemented here were based on the work referenced below.

- [Miryoku](https://github.com/manna-harbour/miryoku)
- [Seniply](https://stevep99.github.io/seniply)
- [Colemak](https://colemak.org)
- [BEAKL](https://ieants.cc/beakl)
- [Hands Down](https://sites.google.com/alanreiser.com/handsdown/home)
- [Precondition](https://github.com/precondition/dactyl-manuform-keymap)
- [Pascal Getreuer](https://github.com/getreuer/qmk-keymap)
- [Drashna](https://github.com/qmk/qmk_firmware/tree/master/users/drashna)
- [Callum Oakley](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum)
- [Weilbith](https://github.com/weilbith/keyboard_firmware)
- [DreymaR](https://dreymar.colemak.org)
- [Thomas Baart](https://thomasbaart.nl/category/mechanical-keyboards/firmware/qmk)
- [Ben Vallack](https://youtube.com/c/BenVallack)

## Resouces

- [KLE](http://www.keyboard-layout-editor.com/#/gists/1a36101d96c804188d2d104ab5296739)
- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
