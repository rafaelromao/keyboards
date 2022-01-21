# rafaelromao's keyboard layout

## Romak

![img](https://i.imgur.com/xxTSX8y.png)

- Romak is the layout used in the default base layer. It is a Colemak-DHm variant, improved to remove load from pinkies and for prose in Portuguese.
- Romak has a higher SFB rate than Colemak-DHm, close to Workman, but most of this load goes to the stronger fingers.
- Compared to Colemak-DHm, Romak cycle A, W and S, inverts Y with O and reverts back H and M, since M is much more commom than H in Portuguese.
- Compared with Qwerty, it also changes the position of the symbols _ and ; the same way the Colemak-DHm layer does.
- There is a commented out transition path from Qwerty to Romak in the [keymap_blocks.h](../qmk/users/rafaelromao/definitions/keymap_blocks.h), similar to Tarmak, but moving _ instead of J.

### From Qwerty to Romak in 5 steps

![img](https://i.imgur.com/eDtSnKh.png)

## Romak vs Colemak-DH
[Stevep99's Layout Analyzer Tool](https://stevep99.github.io/keyboard-layout-analyzer) was used to compare Colemak-DH and Romak, with [Portuguese](corpus.pt.txt) and [English](corpus.en.txt) text corpus.
### Heatmaps
#### Portuguese
<p float="left">
  <img src="https://i.imgur.com/5A9PgPA.png" width="450" />
  <img src="https://i.imgur.com/xwk3u82.png" width="450" /> 
</p>

#### English
<p float="left">
  <img src="https://i.imgur.com/99K1wAh.png" width="450" />
  <img src="https://i.imgur.com/nj8fayg.png" width="450" /> 
</p>

#### Qwerty heatmaps, for reference. Portuguese vs English
<p float="left">
  <img src="https://i.imgur.com/VdLPAD8.png" width="450" />
  <img src="https://i.imgur.com/cC0OvUS.png" width="450" /> 
</p>

### Finger Usage
Pinkies will get less load in Romak, by design. This load will go to the ring and middle fingers.
#### Portuguese
In Portuguese, Romak shows a much better finger distribution than Colemak-DH.
![img](https://i.imgur.com/U9GH4Lo.png)
#### English
In English, the finger distribution is quite similar between Romak and Colemak-DH, considering the lesser load in the pinkies.
![img](https://i.imgur.com/OYoF1rj.png)

### Detailed Finger Analysis
The [Colemak mod-DH analysis tool](https://colemakmods.github.io/mod-dh/analyze.html) was also used to compare the Romak against Colemak-DH.
<p float="left">
  <img src="https://i.imgur.com/Gm0WWTU.png" width="450" />
  <img src="https://i.imgur.com/rF0jHEE.png" width="450" /> 
</p>

##
[Home](../readme.md) | 
Base |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
[Functions and Media](functions.md) | 
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |
