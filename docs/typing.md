# rafaelromao's keyboard layout

## Romak
- The base layer for this layout is [Romak](romak.md), a new keyboard layout optimized for typing in Portuguese and English.
- It puts less load on pinkies, moving A, E and O to better positions for typing in Portuguese, when compared to Colemak.
- It is also designed to work with only 30 keys and fit boards like the Rommana or the Hummingbird. For that to be possible,
some letters are moved to the Accents layer. This layer not only contains these missing letters but also accented versions of
the vowels, as well as macros to type `'`, `ç`, `Qu` and to repeat the last key or shortcut.

```
Base Layer:

   F  D  W        L  O  U
R  N  S  T  G  V  H  A  E  I
   B  C  P  K  J  M  ,  . 

Accents Layer:

      ®           Õ  Ó  Ú
'  Qu X  Z     Y  Ã  Á  É  Í
   Q  Ç        À  Â  Ô  Ê
```
## Accents
- The Accents layer is a oneshot layer. It means it will be automatically deactivated after the first key on it is pressed. Also, this layer is activated tapping the home thumb key at the right side, position R0, which makes it really fast to transition between the base layer and the Accents layer.
- Tapping R0 twice will lock the Accents layer and it will be active until you tap it again or press the Layer Escape Key. It is helpful for when we need to repeat a key that is in the Accents layer or repeat a shortcut multiple times (see Repeat Key).
## Layer Escape Key
- The Layer Escape Key is a simple macro that types Esc and then returns to the base layer, deactivating any locked layer.
## Capitalization
- The best way to capitalize a letter is to use the oneshot shift key, position R1. Tap it and the next key will be capitalized. Which is also pretty fast to use.
## Combos
- In the accents layer, there are combos for some Portuguese n-grams that use keys present in the Accents layer, so that they can be typed with a single tap, like `ção`, `ão`, `ões`, among others.
- There are combos for some letters in the base layer too, like `y`, `q`, `x` and `z`, but they are not intended to be used for typing, but for things like VIM bindings instead.
- There are also combos for the Layer Escape Key (L0+LTR+LTM), Enter (R0+RHM+RHR) and Backspace (R0+RTM+RTR). The combo for Enter is probably the best way to type it most of the times.
## Repeat Key
- The Repeat Key, LTM in the Accents layer, can be used to repeat the last key or shortcut. Although it requires an additional tap with the thumb, it might be more comfortable, and faster, to use than typing the same key twice.
## Punctuation
- Dot and Comma are kept in their qwerty positions, RBM and RBR.
- Semicolon can be typed tapping Dot and Comma together, and colon can be typed tapping shift before that. But there is also a Colon/Semicolon key at RHC, in the Raise layer, which is activated holding R0.
- Question Mark is at LBI, in the Lower layer, activated holding L0. So it can be typed holding L0 and tapping LBI. It can also be typed as a regular shifted slash, RBI. For that, just tap R1, hold R0 and tap RBI. It is also fast and helpfull when the left hand is in the trackball (see the premisses in Overview doc).
- Exclamation Mark is at RBR!
### Punctuation at the end
- Any punctuation char can be inserted at the end of the line simply by holding it instead of tapping it. It is more useful for coding, but can also be helpfull for typing.
## Numbers
- Numbers, for regular typing, are available in a Numpad style in the right side of the Lower layer, with 5 at RHM. They can be accessed holding L0.
- While in the Lower layer, R0 will type Space instead of activating the Accents layer. This is handy, since L0 must be held to type numbers and it is the same key used to type Space.
- See more about [Working with Numbers](numbers.md) to see how to avoid holding L0 to work with numbers.
## Navigation
- To navigate between the text while typing, hold L1 and the right side of the keybord will become a navigation cluster, with the arrows in the 4 home positions. Delete, Home and End are available in the bottom row, and page navigation in the top row.
