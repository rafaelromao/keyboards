# rafaelromao's keyboard layout

## Symbols and Numbers
Symbols and Numbers are primarily available in the two classic Lower and Raise layers, activated holding the space and backspace thumb keys, respectively.
- Symbols are available in the left side of the Lower layer and in the right side of the Raise layer, making them easier to reach with a single hand.
- There are combos to allow cross activation and one-shot activation of both symbol layers.
- Numbers are available in the right side of the Lower layer and in a dedicated [Numpad](symbols.md#numpad) layer.
- Function keys are available in the left side of the Raise layer and in a the left side of the dedicated [Numpad](symbols.md#numpad) layer.

### Dedicated Symbol layer
- There is a dedicate symbol layer that is activated holding both inner thumb keys or, for one shot, tapping in sequence the right than the left inner thumb key.
- In this layer, there are no mod taps, so it is possible to repeat symbols holding the key.
- There are also some combos to give access to the symbols usually available holding keys in the Lower or Raise layers.

### Symbols in the Lower layer (left side)
- String delimiters, conditional operators, parenthesis and square brackets, among others, are found in the left side of the Lower layer.
- Source code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

### Numbers in the Lower layer (right side)
- In the right side of the Lower layer, there is a set of number keys, arranged as a numpad, but using number row keycodes.
  - If shift is active, these number keys will output numpad keys instead.
- The Raise layer can be activated on top of the Lower layer, holding the backspace thumb key, which makes it easier to access math operators when working with numbers.

### Functions in the Raise layer (left side)
- On the left side of the Raise layer, the F keys are available in the mirrored positions as their respective numbers, making it easier to assimilate.

### Symbols in the Raise layer (right side)
- Symbols that are commonly used in VIM are placed in the right side of the Raise layer, making them easily accessible using only the right hand.
- Curly braces and angle brackets are also found in the right side of this layer.
- Some common programmer n-grams, like ->, =>, \<!--, -->, <>, />, !=, :=, +=, -=, can all be typed rolling through keys in the right hand.

 ### Numpad Layer
- A dedicated Numpad layer can be activated from the Raise layer, or with a combo using both right thumb keys.
- The left side of the Numpad layer contains function keys.
- The right side of the Numpad layer contains number keys.
- Home block mods are also available on both sides of the Numpad layer.

### Coding Dancing
- Coding Dancing is a set of macros available through tap dances (Double Tap and Triple Tap) in the Lower and Raise layers.
- It allows fast typing for some of the most frequent Java keywords and code blocks.

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Accents and Macros](macros.md) |
Symbols and Numbers |
[Navigation and Media](navigation.md) |
[System](system.md)
