# rafaelromao's keyboard layout

### Symbols and Numbers
Symbols and Numbers are available in the two classic Lower and Raise layers, activated holding the space and backspace thumb keys, respectively.
- Symbols are available in the left side of the Lower layer and in the right side of the Raise layers, making them easier to reach with a single hand.
- Accents are available in the left side of the Raise layer, so they require two hands.
- Number are available in the right side of the Lower layer, also requiring two hands, but that can be mitigated using a combo to toggle the layer on, using only the right hand.
- The Lower and Raise layers can be activated also by tapping or holding a combo with the right or left hands, respectively.
- Another combo can be used to toggle these layers off.
- Source code: [combos.c](../src/qmk/users/rafaelromao/features/combos.c)

### Symbols in the Lower layer (left side)
- String delimiters, conditional operators, parenthesis and square brackets, among others, are found in the left side of the Lower layer.
- Source code: [macros.c](../src/qmk/users/rafaelromao/features/macros.c)

### Symbols in the Raise layer (right side)
- Symbols that are commonly used in VIM are placed in the right side of the Raise layer, making them easily accessible using only the right hand.
- Curly braces and angle brackets are also found in the right side of this layer.
- Some common programmer n-grams, like ->, =>, \<!--, -->, <>, />, !=, :=, +=, -=, ${, can all be typed rolling through keys in the right hand.

### Numbers in the Lower layer (right side)
- In the right side of the Lower layer, there is a set of number keys, arranged as a numpad, but using number row keycodes.
- The Raise layer can be activated on top of the Lower layer, holding the backspace thumb key, which makes it easier to access math operators when working with numbers.

 ## Numpad
- A dedicated Numpad layer can be activated holding the backspace or space keys, in the [Functions or Media](functions.md) layers.
- This Numpad layer can also be activated using a combo in the base layers.

### Accents in the Raise layer (left side)
- Accents are available in the left side of the Raise layer, while non-accent versions of these symbols are available in the left side of the Lower layer and in the right side of the Raise layer.
- For example, activating the Lower layer (holding space) + tapping ' (left middle finger) + releasing space + tapping c, gives me 'c, while activating the Raise layer (holding backspace) + tapping ' (left index finger) + tapping c, gives me ç.
- There are also dedicated keys for accentuated characters, but those keys cover only the most common accents in Portuguese.
- Source code: [accentuation.c](../src/qmk/users/rafaelromao/features/accentuation.c)

### Dancing Brackets
- Although closing brackets are available in dedicated keys, it is also possible to type them by double tapping the open bracket keys. It works for parenthesis, curly braces, square brackets and angle brackets.
- Holding the open curly braces key will insert it in the end of the line, after a space. It is usefull when coding, particularly when using VIM plugins. A similar behavior is also implemented for the semicolon key, but without the extra space.

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
Symbols and Numbers |
[Functions and Media](functions.md) | 
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |
