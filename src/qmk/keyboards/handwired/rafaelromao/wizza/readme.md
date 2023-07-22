## Wizza MX
### A 30 keys handwired unibody split keyboard.

### Build Details

Wizza MX, a handwired board built using a [Seeeduino Xiao RP2040](https://pt.aliexpress.com/item/4000131085893.html).

This board has a programmable LED, used for layer and other statuses indication.
Some build pictures can be found [here](../../../../../../docs/wizza.md).

### Wizza MX
![img](../../../../../../img/wizza.jpeg)

Parts:
- 30 MX switchesl
- 30 1u MX keycaps.
- Wizza MX [case](https://github.com/AlaaSaadAbdo/battoota/tree/main/boards/30keys/wizza-mx/Case).
- [Seeeduino Xiao RP2040](https://pt.aliexpress.com/item/4000131085893.html).
- [1n4148 diodes](https://pt.aliexpress.com/item/1005003540554760.html).
- [24 AWG Wires](https://pt.aliexpress.com/item/32904950428.html).
- [DIP40 Pin Wide Socket](https://a.aliexpress.com/_msloS7e).

### QMK

#### Compile

`qmk compile -kb handwired/rafaelromao/wizza -km rafaelromao`

#### Flash

`qmk flash -kb handwired/rafaelromao/wizza -km rafaelromao`

## Resources

- [Home](https://github.com/rafaelromao/keyboards)
- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
