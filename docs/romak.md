# rafaelromao's keyboard layout

## Romak

Romak is a new keyboard layout, inspired by [Colemak](https://colemak.org) and [BEAKL](https://ieants.cc/beakl), improved to remove load from pinkies and for typing in Portuguese and English.

![img](../img/romak.png)

- The name Romak is a combination of my last name, **Rom**ão, and Dvor**ak**'s name.
- Romak assumes the right hand as dominant, puts vowels, H and R it the right hand, and has a lower SFB rate than Colemak, with most of the load on the stronger fingers.
- Romak is also designed to favor hand alternation more than rolls.

## Romak vs Colemak-DH
[Stevep99's Layout Analyzer Tool](https://stevep99.github.io/keyboard-layout-analyzer) was used to compare Romak with Colemak-DH and some other layouts, using the Magna Carta as text corpus, combining [Portuguese](analysis/corpus.pt.txt) and [English](analysis/corpus.en.txt).
### General Performance
#### Portuguese + English
![img](../img/perf.png)

### Heatmaps
#### Portuguese + English
<p float="left">
  <img src="../img/heat_romak.png" width="450" />
  <img src="../img/heat_coldh.png" width="450" /> 
  <img src="../img/heat_qwerty.png" width="450" /> 
</p>

### Finger Usage
Pinkies will get less load in Romak, by design.
#### Portuguese + English
![img](../img/fingers.png)

### Detailed Finger Analysis
The [Colemak mod-DH analysis tool](https://colemakmods.github.io/mod-dh/analyze.html) was also used to compare Romak against Colemak-DH (English text corpus only).
<p float="left">
  <img src="../img/sfbs_en_romak.png" width="450" />
  <img src="../img/sfbs_en_coldh.png" width="450" />
</p>

## Extentions

- The [N-Grams and Accents](macros.md#n-grams-and-accents) layer extend the Romak base layer to give easy access to common English and Portuguese n-grams and Portuguese accentuated characters.
- The [Lower and Raise](symbols.md) layers give access to function keys, symbols and numbers. The symbols are arranged to make them easy to use in software programming, with VIM, and math operations.

##
[Home](../readme.md) | 
Base |
[Modifiers](modifiers.md) |
[N-Grams and Macros](macros.md) |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)
