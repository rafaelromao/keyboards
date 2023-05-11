# rafaelromao's keyboard layout

## Romak

Romak is a new keyboard layout, inspired by [Colemak](https://colemak.org) and [BEAKL](https://ieants.cc/beakl), improved to remove load from pinkies and for typing in Portuguese and English, using a one-shot layer to extend the base layer with accented and less frequent keys.

The number of alpha keys and the number of thumb keys can vary, from a total of 36 down to 28 keys. The variations with less keys reduce the use of pinky and index fingers.

![img](../img/romak.png)

- The name Romak is a combination of my last name, **Rom**ão, and Dvor**ak**'s name.
- Romak assumes the right hand as dominant and puts all vowels plus H on that side.
- Romak is also designed to favor hand alternation more than rolls.

## Romak vs Colemak-DH
[KLA Next](https://klanext.keyboard-design.com/) was used to compare Romak with Colemak-DH and some other layouts, using the Universal Declaration of Human Rights as text corpus, combining [Portuguese and English](analysis/corpus.txt).
### General Performance

Romak has 2 alpha layers, with an oneshot key used to quickly alternate between them. This is not supported by KLA Next, so some adjustments were necessary:
- Use AltGr instead of the oneshot key, so the tool considers the AltGr held to access the secondary alpha layer.
- Since it would consider shift, another oneshot key in Romak, to be held to access capitalized letters, it could not be in the same thumb as AltGr, so I moved space to the right hand and AltGr to the left hand, which would not change that much the effort.
- Symbols and numbers were excluded from the analysis for all considered layouts. The files with the configurations can be found [here](../docs/analysis/).
- With this configuration, Romak beats Colemak-DH and the other considered layouts.
![img](../img/perf.png)

### Heatmaps

Heatmaps show that Romak puts more load on middle and ring fingers and less load on index and pinky fingers, when compared to Colemak-DH.
<p float="left">
  <img src="../img/heat_romak.png" width="450" />
  <img src="../img/heat_coldh.png" width="450" /> 
</p>

### Finger Usage
In Romak, most fingers in the left hand will take less load than the equivalent fingers in the right hand.

![img](../img/fingers.png)

### Detailed Finger Analysis
The [Colemak mod-DH analysis tool](https://colemakmods.github.io/mod-dh/analyze.html) was also used to compare Romak against Colemak-DH.
- English text corpus only.
- Consider the 34 key version of Romak, with q, x, z and y in the base layer.

The SFB rate is highly impacted by the position of y, in the index finger, but in practice, with y below h in the accents layer, it shows good performance even for fast typing.

<p float="left">
  <img src="../img/sfbs_en_romak.png" width="450" />
  <img src="../img/sfbs_en_coldh.png" width="450" />
</p>

## Extentions

- The [Accents and Macros](macros.md) layers extend the Romak base layer to give easy access to common Portuguese accented characters, along with the letters z and x.
- The [Lower and Raise](symbols.md) layers give access to function keys, symbols and numbers. The symbols are arranged to make them easy to use in software programming, with VIM, and math operations.

##
[Home](../readme.md) | 
Base |
[Modifiers](modifiers.md) |
[Accents and Macros](macros.md) |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)
