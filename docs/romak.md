# rafaelromao's keyboard layout

## Romak

![img](https://i.imgur.com/LoRnoUM.png)

- Romak is the layout used in the default base layer. It is inspired by [Colemak](https://colemak.org) and [BEAKL](https://ieants.cc/beakl), improved to remove load from pinkies and for Portuguese.
- Romak has a higher SFB rate than Colemak, but lower than Workman, and most of this load goes to the stronger fingers.
- There is a commented out transition path from Qwerty to Romak in the [keymap_blocks.h](../qmk/users/rafaelromao/definitions/keymap_blocks.h), similar to Tarmak, but moving _ instead of J.

### From Qwerty to Romak in 6 steps

![img](https://i.imgur.com/Ix1x3XO.png)

## Romak vs Colemak-DH
[Stevep99's Layout Analyzer Tool](https://stevep99.github.io/keyboard-layout-analyzer) was used to compare Romak with Colemak-DH and Qwerty, with [Portuguese](analysis/corpus.pt.txt) and [English](analysis/corpus.en.txt) text corpus.
### Heatmaps
#### Portuguese
<p float="left">
  <img src="https://i.imgur.com/SRi5f0z.png" width="450" />
  <img src="https://i.imgur.com/XEoZ8eK.png" width="450" /> 
  <img src="https://i.imgur.com/ipPEwem.png" width="450" /> 
</p>

#### English
<p float="left">
  <img src="https://i.imgur.com/PpZRwta.png" width="450" />
  <img src="https://i.imgur.com/lsvsHTZ.png" width="450" />   
  <img src="https://i.imgur.com/zoc13dC.png" width="450" /> 
</p>

Romak is more balanced to Portuguese than English, so if English is your primary language, it is recommended to swap H and M.

### Finger Usage
Pinkies will get less load in Romak, by design. This load will go to the ring and middle fingers.
#### Portuguese
![img](https://i.imgur.com/2O6q4WJ.png)
#### English
![img](https://i.imgur.com/Tn3zcK8.png)

### Detailed Finger Analysis
The [Colemak mod-DH analysis tool](https://colemakmods.github.io/mod-dh/analyze.html) was also used to compare Romak against Colemak-DH and Workman (English text corpus only).
<p float="left">
  <img src="https://i.imgur.com/H7z27AZ.png" width="450" />
  <img src="https://i.imgur.com/3t4tMKo.png" width="450" /> 
  <img src="https://i.imgur.com/saVyUQU.png" width="450" /> 
</p>

Despite the higher SFB rate, total finger effort is lesser in Romak than in Colemak, Colemak-DH or Workman.

##
[Home](../readme.md) | 
Base |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
[Functions and Media](functions.md) | 
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |
