# rafaelromao's keyboard layout

## Romak

![img](https://i.imgur.com/tFns5wY.png)

- Romak is the layout used in the default base layer. It is inspired in [Colemak](https://colemak.org) and [BEAKL](https://ieants.cc/beakl), improved to remove load from pinkies and for Portuguese.
- Romak has a higher SFB rate than Colemak, close to Workman, but most of this load goes to the stronger fingers.
- There is a commented out transition path from Qwerty to Romak in the [keymap_blocks.h](../qmk/users/rafaelromao/definitions/keymap_blocks.h), similar to Tarmak, but moving _ instead of J.

### From Qwerty to Romak in 6 steps

![img](https://i.imgur.com/ZIUTKkq.png)

## Romak vs Colemak-DH
[Stevep99's Layout Analyzer Tool](https://stevep99.github.io/keyboard-layout-analyzer) was used to compare Romak with Colemak-DH and Qwerty, with [Portuguese](analysis/corpus.pt.txt) and [English](analysis/corpus.en.txt) text corpus.
### Heatmaps
#### Portuguese
<p float="left">
  <img src="https://i.imgur.com/aVjm1vG.png" width="450" />
  <img src="https://i.imgur.com/XEoZ8eK.png" width="450" /> 
  <img src="https://i.imgur.com/ipPEwem.png" width="450" /> 
</p>

#### English
<p float="left">
  <img src="https://i.imgur.com/qw0gvZV.png" width="450" />
  <img src="https://i.imgur.com/lsvsHTZ.png" width="450" />   
  <img src="https://i.imgur.com/zoc13dC.png" width="450" /> 
</p>

Romak is more ballanced to Portuguese than English, so if English is your primary language, it is recommended to swap H and M.

### Finger Usage
Pinkies will get less load in Romak, by design. This load will go to the ring and middle fingers.
#### Portuguese
In Portuguese, Romak shows a better finger distribution than Colemak-DH.
![img](https://i.imgur.com/sJyqiud.png)
#### English
In English, the finger distribution is quite similar between Romak and Colemak-DH, considering the lesser load in the pinkies.
![img](https://i.imgur.com/MqwZrZ0.png)

### Detailed Finger Analysis
The [Colemak mod-DH analysis tool](https://colemakmods.github.io/mod-dh/analyze.html) was also used to compare Romak against Colemak-DH, Colemak and Workman (English text corpus only).
<p float="left">
  <img src="https://i.imgur.com/uNXMk9L.png" width="450" />
  <img src="https://i.imgur.com/3t4tMKo.png" width="450" /> 
  <img src="https://i.imgur.com/X820AXP.png" width="450" /> 
  <img src="https://i.imgur.com/saVyUQU.png" width="450" /> 
</p>

Despite the higher bigram rate, total finger effort is lesser in Romak than in Colemak, Colemak-DH or Workman.

##
[Home](../readme.md) | 
Base |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
[Functions and Media](functions.md) | 
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |
