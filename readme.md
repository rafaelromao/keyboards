# rafaelromao's keyboard layout
 
## Overview

A split keyboard layout optimized for Portuguese, English, working with numbers and software programming with VIM plugins.

![img](img/overview.png)

## How this layout works?

The following pages explain how this layout works and which features are implemented.

### Layers

- [Alphas](docs/alphas.md)
- [Symbols and Numbers](docs/symbols.md)
- [Navigation and Media](docs/navigation.md)
- [Functions and Smart Cases](docs/functions.md)
- [Shortcuts and Mehs](docs/shortcuts.md) 

### Special Features

- [Two Alpha Layers](docs/alphas.md)
- [Thumb Shift](docs/alphas.md)
- [Sentence Case](docs/alphas.md)
- [Caps Word](docs/alphas.md)
- [Magic Key](docs/alphas.md)
- [Repeat Key](docs/alphas.md)
- [VIM Remaps](docs/navigation.md)
- [Shortcut Combos](docs/alphas.md)
- [Num Word](docs/symbols.md)
- [Optimized Symbol Layers](docs/symbols.md)
- [Coding Macros](docs/symbols.md)
- [Smart Cases](docs/functions.md)
- [Select Word](docs/shortcuts.md)
- [Leader Key](docs/shortcuts.md)
- [Custom Shortcuts](docs/shortcuts.md)
- [Mouse Keys](docs/navigation.md)

## About this repo

This repository contains the keymap files that are used to customize my keyboards. The firmware files are included as submodules or external references.

## Compatibility

This layout was tested with the keyboards listed below, but can be easily adapted to most ortholinear or column staggered keyboards with at least 24 keys, with 2 of them on each thumb.

### QMK

There is an outdated QMK version of this keymap, available in the branch [last_qmk](https://github.com/rafaelromao/keyboards/tree/last_qmk).

### ZMK

The zmk version used for this keymap is the one available in [this fork](https://github.com/rafaelromao/zmk), which contains some experimental code to implement features like:
- [Auto Layer](https://github.com/zmkfirmware/zmk/pull/1451)
- [Leader Key](https://github.com/zmkfirmware/zmk/pull/1380)
- [Antecedent Morph](https://github.com/zmkfirmware/zmk/pull/2042)
- [Mouse Keys](https://github.com/zmkfirmware/zmk/pull/2027)
- [Corne-ish Zen display improvements](https://gist.github.com/caksoylar/c411313990978e1903c244f03039187a)

This fork is also updated to Zephyr 3.5.

#### Initializing the local build environment

The script [init.sh](init.sh) will clone [the ZMK firmware](https://github.com/rafaelromao/zmk) and configure the toolchain.
After [installing ZMK](https://zmk.dev/docs/development/setup) and running the init script above, [west cli](https://zmk.dev/docs/development/build-flash) should be working to compile and flash.

## Building

The script [build.sh](build.sh) can be used to build the firmware for any of my boards. Run `build --help` for more details.

## Diagram

The Diagram for my keymap was created using [Keymap Drawer](https://github.com/caksoylar/keymap-drawer). The source and config files can be found in the docs folder and the commands below can be used to generate an `svg` diagram and convert it to `png`, using Inkscape:

```
keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw ./docs/keymap-drawer/keymap-drawer.yaml > ./img/overview.svg
inkscape --export-type png --export-filename ./img/overview.png --export-dpi 300 --export-background=white ./img/overview.svg
```

The script [draw.sh](draw.sh) is used to draw all diagrams in my keymap using commands like the example above.

## References

Most features implemented here were based on the work referenced below.

### Layouts
- [Romak](https://github.com/rafaelromao/romak)
- [Colemak](https://colemak.org)
- [BEAKL](https://deskthority.net/wiki/BEAKL)
- [Hands Down](https://sites.google.com/alanreiser.com/handsdown/home)
- [Engram](https://engram.dev)
- [Miryoku](https://github.com/manna-harbour/miryoku)
- [Seniply](https://stevep99.github.io/seniply)
- [Thinqu](https://microexploitation.com/2018/06/04/thinqu/)
- [Suraj Kurapati](https://sunaku.github.io/moergo-glove80-keyboard.html)
- [bmijanovich](https://github.com/bmijanovich/zmk-config)
- [DreymaR](https://dreymar.colemak.org)
- [Ben Vallack](https://youtube.com/c/BenVallack)
- [Magic Sturdy](https://github.com/Ikcelaks/keyboard_layouts/blob/main/magic_sturdy/magic_sturdy.md)
- [Unity](https://lykt.xyz/uno)
- [Nordrassil](https://github.com/empressabyss/nordrassil)
- [Sartak](https://github.com/sartak/keyboard)

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
- [petejohanson](https://github.com/petejohanson/)
- [bravekarma](https://github.com/caksoylar)
- [nickconway](https://github.com/nickconway)
- [urob](https://github.com/urob)
- [ssbb](https://github.com/ssbb)
- [krikun98](https://github.com/krikun98)
- [voidyourwarranty2](https://github.com/voidyourwarranty2/zmk)

### 3D Printing and Handwiring
- [Jan Lunge](https://m.youtube.com/@JanLunge)
- [Sadek Baroudi](https://github.com/sadekbaroudi)
- [Joe Scotto](https://github.com/joe-scotto)
- [Alaa Saad Mansour](https://github.com/AlaaSaadAbdo)
- [Peter Elliot](https://github.com/PJE66)

## Resouces

- [Keymap Drawer](https://github.com/caksoylar/keymap-drawer)
- [Keymap DB](https://keymapdb.com/keymaps/rafaelromao/)
- [QMK Docs](https://docs.qmk.fm)
- [ZMK Docs](https://zmk.dev/docs)
- [Keyboard Tester](https://config.qmk.fm/#/test)
- [Word Finder - English](https://www.merriam-webster.com/wordfinder/classic/contains/all/-1/th/1)
- [Word Finder - Portuguese](https://www.palavras.net/search.php?m=th&d=17)
- [r/olkb](https://www.reddit.com/r/olkb)
- [r/ErgoMechKeyboards](https://www.reddit.com/r/ErgoMechKeyboards)
