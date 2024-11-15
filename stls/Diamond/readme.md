# Diamond

## A 24 keys handwired split keyboard.

Diamond is a handwired board originally designed by me but heavily inspired by the [Rommana](https://github.com/AlaaSaadAbdo/Rommana) and using the switch holders of the [Dactyl Cygnus](https://github.com/juhakaup/keyboards).
- It is componsed of 24 keys, in the format 1333+2.
- It should be handwired, ideally using single switch PCBs.
- The MCU, reset button and on/off switch goes in the base, below a cover used to hide them.
- These components should be mounted upside down, under this cover.
- The cables for column and rows will pass through 3 holes in the cover and can be tightened in the end of the assembling to make them less visible in the final build. 

[Here](../../docs/diamond.md) you can see some build images.

## Diamond

![img](../../img/diamond.jpeg)

### Diamond v1

The first version of Diamond is the result of 3 prototypes, after the first two, some small adjustment were implemented.

This version is expected to be wireless only, using a Supermini NRF52840 MCU (Nice Nano v2 clone).

### Diamond v2

For the second version, the following improvements were implemented:
- Reduced the gap between the cover and the body side from 0.4 to 0.2.
- Expanded the opening for the on/off switch to allow an USB-C port to take its place.
- Included a bracket to support a USB-C breakout board instead of an on/off switch, to allow a wired build with an USB-C connecting both sides.
- Changed the MCU bracket to allow a Seeduino Xiao (BLE or RP2040) to be used instead of a Supermini NRF52840.
- Included a hole in the base to allow the LED of the Xiao RP2040 to shine through the bottom of the keyboard.
- Included a variation of the thumb cluster, with the keys inclined instead of flat.
- Included a variation of the switch holders, using Choc switches instead of MX switches.
- Remove the bottom hole for the magnet, to simplify printing.
- Add an unibody base, with OLED support, compatible with all body versions.

#### STL Files

The STL files are provided for the right side. To print the left side, just mirror them.

- [Base Right](../Diamond/v2/base_right.stl)
- [Cover Right](../Diamond/v2/cover_right.stl)
- [MX Body Right](../Diamond/v2/body_right.stl)
- [MX Body Right - Tilted Thumbs](../Diamond/v2/body_right_tilted.stl)
- [Choc Body Right](../Diamond/v2/choc_body_right.stl)
- [Choc Body Right - Tilted Thumbs](../Diamond/v2/choc_body_right_tilted.stl)
- [Unibody Base](../Diamond/v2/unibody_base.stl)
- [Unibody Base Cover](../Diamond/v2/unibody_base_cover.stl)
