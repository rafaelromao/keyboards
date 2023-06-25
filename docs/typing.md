# rafaelromao's keyboard layout

## Romak

The base layer for this layout is [Romak](romak.md), a new keyboard layout designed for Portuguese and English, with a goal of good hand alternation, reduced finger travel and single finger bigrams, and less use of the pinkie and central columns.

There are two versions of the layout: Romak 34 and Romak 30, according to the number of keys, including four in the thumbs.

A one-shot layer is used to extend the base layer with accentuation and the missing letters, along with `Qu`, which is frequent in Portuguese, and replications of the central column letters.

`ESC`, `BSP`, `'` and some alphas like `X`, `Y`, `Q` and `K` are also available in combos. There are also some combos in the Accents layer, to complement it.

*Romak 34*:

Base Layer:

```
ESC  B  M  W  K  X  L  O  U  BSP 
  D  N  S  T  G  Z  R  A  E  I 
  Q  F  C  P  V  J  H  ,  .  Y
```

Accents Layer:

```    
     J  V  G        À  Ó  Ú
  Y  Z  X  K  '  ^  Ã  Á  É  Í
     Q  Ç  Qu `  ~  Â  Ô  Ê
```

*Romak 30*:

Base Layer:

```
ESC  B  M  W        L  O  U  BSP 
  D  N  S  T  G  Z  R  A  E  I 
     F  C  P  V  J  H  ,  .
```

Accents Layer:

```    
     J  V  G        À  Ó  Ú
  Y  Z  X  K  '  ^  Ã  Á  É  Í
     Q  Ç  Qu `  ~  Â  Ô  Ê
```

For both versions, the thumb keys are:

Tap:

```
Repeat, Space, OS Accents, OS Shift
```

Hold:

```
Navigation, Lower, Raise, Media
```

Symbols, Numbers and Function keys are available in the Lower and Raise layers, activated holding Space and OS Accents.

Modifiers, Navigation and Media keys, as well as Enter, Tab and Esc, can be found in the Navigation and Media layers.

If we consider only the alphas, we have an even smaller form, Romak 24, which is the one I'm using now. The center column is still used for other layers though.

Romak 24:

Base Layer:

```
     B  M  W        L  O  U   
  D  N  S  T        R  A  E  I 
     F  C  P        H  ,  .   
```

Accents Layer:

```
     J  V  G        À  Ó  Ú
  Y  Z  X  K        Ã  Á  É  Í
     Q  Ç  Qu       Â  Ô  Ê
```

## Accents
- The Accents layer is a oneshot layer. It means it will be automatically deactivated after the first key on it is pressed. Also, this layer is activated tapping the home thumb key at the right side, position R0, which makes it really fast to transition between the base layer and the Accents layer.
- Tapping R0 twice will lock the Accents layer and it will be active until you tap it again or press the Layer Escape Key. It is helpful for when we need to repeat a key that is in the Accents layer or repeat a shortcut multiple times (see Repeat Key).
## Layer Escape Key
- The Layer Escape Key is a simple macro that types Esc and then returns to the base layer, deactivating any locked layer.
## Capitalization
- The best way to capitalize a letter is to use the oneshot shift key, position R1. Tap it and the next key will be capitalized. Which is also pretty fast to use.
## Combos
- In the accents layer, there are combos for some Portuguese n-grams that use keys present in the Accents layer, so that they can be typed with a single tap, like `ção`, `ão`, `õe` and `ãe`.
- There are combos for some letters in the base layer too, like `y`, `q`, `x` and `z`, but they are not intended to be used for typing, but for things like VIM bindings instead.
- There are also combos for the Layer Escape Key (LTR+LTM), Enter (R0+RHM+RHR) and Backspace (RTM+RTR). The combo for Enter is probably the best way to type it most of the times.
## Punctuation
- Dot and Comma are kept in their qwerty positions, RBM and RBR.
- Semicolon can be typed tapping Dot and Comma together, and colon can be typed tapping shift before that. But there is also a Colon/Semicolon key at RHC, in the Raise layer, which is activated holding R0.
- Question Mark is at LBI, in the Lower layer, activated holding L0. So it can be typed holding L0 and tapping LBI. It can also be typed as a regular shifted slash. For that, just tap R1, hold R0 and tap RBI. It is also fast and helpfull when the left hand is in the trackball (see the premisses in Overview doc).
- Exclamation Mark is at RBR, in the Raise layer.
### Punctuation at the end
- Any punctuation char can be inserted at the end of the line simply by holding it instead of tapping it. It is more useful for coding, but can also be helpfull for typing.
### Sentence Case
- Double tap space in the base layer, within the tapping term, will send DOT SPACE ONESHOT SHIFT.
## Repeat Key
- The Repeat Key, L1 in the base layer, can be used to repeat the last key or shortcut.
## Numbers
- Numbers, for regular typing, are available in a Numpad style in the right side of the Lower layer, with 5 at RHM. They can be accessed holding L0.
- While in the Lower layer, R0 will type Space instead of activating the Accents layer. This is handy, since L0 must be held to type numbers and it is the same key used to type Space.
- See more about [Working with Numbers](numbers.md) to see how to avoid holding L0 to work with numbers.
## Navigation
- To navigate between the text while typing, hold L1 and the right side of the keybord will become a navigation cluster, with the arrows in the 4 home positions. Delete, Home and End are available in the bottom row, and page navigation in the top row.
- While in the Lower layer, holding LHP will also activate the Navigation layer, allowing easy trasition between numbers and arrow keys.