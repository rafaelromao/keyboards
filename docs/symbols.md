# rafaelromao's keyboard layout

## Symbols and Numbers
Symbols and Numbers are primarily available in the two classic Lower and Raise layers, activated holding the space and backspace thumb keys, respectively.
- Symbols are available in the left side of the Lower layer and in the right side of the Raise layers, making them easier to reach with a single hand.
- Numbers are available in the right side of the Lower layer and in a dedicated [Numpad](symbols.md#numpad) layer, which can be toggled on with a dedicated key in the Lower and Raise layers, or using a combo.
- Function keys are available in the left side of the Raise layer and in a the left side of the dedicated [Numpad](symbols.md#numpad) layer.

### Symbols in the Lower layer (left side)
- String delimiters, conditional operators, parenthesis and square brackets, among others, are found in the left side of the Lower layer.
- Source code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

### Numbers in the Lower layer (right side)
- In the right side of the Lower layer, there is a set of number keys, arranged as a numpad, but using number row keycodes.
- The Raise layer can be activated on top of the Lower layer, holding the backspace thumb key, which makes it easier to access math operators when working with numbers.

### Functions in the Raise layer (left side)
- On the left side of the Raise layer, the F keys are available in the mirrored positions as their respective numbers, making it easier to assimilate. F10 and F12 are available in the inner index column, while F14 to F15 goes bottom up in the pinky column and can be mapped to custom actions or macros in the operating system level, or used to control brightness in MacOS.

### Symbols in the Raise layer (right side)
- Symbols that are commonly used in VIM are placed in the right side of the Raise layer, making them easily accessible using only the right hand.
- Curly braces and angle brackets are also found in the right side of this layer.
- Some common programmer n-grams, like ->, =>, \<!--, -->, <>, />, !=, :=, +=, -=, ${, can all be typed rolling through keys in the right hand.

### Dancing Brackets
- Although closing brackets are available in dedicated keys, it is also possible to type them by double tapping the open bracket keys. It works for parenthesis, curly braces, square brackets and angle brackets.
- Holding the open curly braces key will insert it in the end of the line, after a space. It is usefull when coding, particularly when using VIM plugins. A similar behavior is also implemented for the semicolon key, but without the extra space.

 ### Numpad Layer
- A dedicated Numpad layer can be activated from the Lower or Raise layers, or holding the inner thumb keys in the [N-Grams](macros.md) layer.
- Unlike numbers in the Lower layer, numbers in the Numpad layer use numpad keycodes, instead of numrow keycodes.
- Numpad navigation, using shift, which usually does not work on MacOS, is implemented using [Custom Shift](../src/qmk/users/rafaelromao/features/custom_shift.c).
- The left side of the Numpad layer also contains function keys.

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[N-Grams and Macros](macros.md) |
Symbols and Numbers |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)
