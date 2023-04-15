## Hummingbird
### A 30 keys handwired split keyboard.

### Build Details

Hummingbird, a handwired board built using a [Seeeduino Xiao RP2040](https://pt.aliexpress.com/item/4000131085893.html).

This board has a programmable LED, used for layer and other statuses indication.
Some build pictures can be found [here](../../../../../../docs/hummingbird.md).

### Hummingbird
![img](../../../../../../img/hummingbird.jpeg)

Parts:
- 30 choc switches (Lowprokb Sunsets).
- 26 1u choc keycaps (Lowprokb LDSA).
- 4 1u choc thumb keycaps (Lowprokb LDSA).
- Hummingbird [case](https://github.com/PJE66/hummingbird).
- [Seeeduino Xiao RP2040](https://pt.aliexpress.com/item/4000131085893.html).
- [1n4148 diodes](https://pt.aliexpress.com/item/1005003540554760.html).
- [24 AWG Wires](https://pt.aliexpress.com/item/32904950428.html).
- [Dupont cables](https://pt.aliexpress.com/item/1005004155181609.html).

### QMK

#### Compile

`qmk compile -kb handwired/rafaelromao/hummingbird -km rafaelromao`

#### Flash

`qmk flash -kb handwired/rafaelromao/hummingbird -km rafaelromao`

## Resources

- [Home](https://github.com/rafaelromao/keyboards)
- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
