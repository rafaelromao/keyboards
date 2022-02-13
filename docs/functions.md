# rafaelromao's keyboard layout

## Functions and Media
The Functions and Media layers are activated holding the left or right pinky keys in the home row, respectively.

## Functions
- On the left side of the Functions layer, there are standard modifier keys, also forming a home block, along with Caps Lock and a Menu key.
- On the right side, the F keys are available in the same positions as their respective numbers, so F5 and 5 are under the same key, making it easier to assimilate. F10 to F12 goes bottom up in the pinky column, while F13 to F15 are available in the inner index column and can be mapped to custom actions or macros in the operating system level.
- The Functions layer can be toggle on using a combo with the right hand, in the [Lower](symbols.md) layer.
- Another combo can be used to toggle the layer off.
- Source code: [combos.c](../src/qmk/users/rafaelromao/features/combos.c)

## Media
- In the left side of the Media layer, you can find the RGB control keys, while the media keys are placed in the right side.
- The Media layer can also be activated using the left hand, holding (or tapping, for one-shot) the space thumb key plus the botton row pinky key. 

## Zoom
- In the right side of the Media layer, there are keys to control Zoom, which can be either Cmd+ and Cmd- or Ctrl+ and Ctrl-, according to the operating system that is selected in the [Maintenance](maintenance.md) layer.

## Space and Backspace
- The space and backspace thumb keys are inverted in the Functions and Media layers, which allow single hand access to both of them.

## Leader Key
- The Leader Key is available in the left side of the Functions layer, but a double tap in the comma will also activate it.
- The Leader Key is used to give easy access to some useful shortcuts and macros, like typing an internet domain or recurring terminal commands.
- Source code: [leader.c](../src/qmk/users/rafaelromao/features/leader.c)

## IDE Dancing
- Also in the Functions and Media layers, which means, when holding any of the home row pinky keys, the outer thumb keys can be used to tap dance through some of the most common IDE shortcuts, using keybindings from IntelliJ IDEA.
- Left Side:
    - Tap = Build (Cmd+F9/Ctrl+F9)
    - Double Tap = Run Everything (Ctrl+Ctrl)
    - Triple Tap = Find Usages (Alt+F7)
    - Hold = Complete Statement (Shift+Cmd+Enter/Shift+Ctrl+Enter)
- Right Side:
    - Tap = Quick Actions (Alt+Enter)
    - Double Tap = Search Everywhere (Shift+Shift)
    - Triple Tap = Go To Project Window (Cmd+1/Ctrl+1)
    - Hold = Refactor This (Shift+Cmd+Alt+T/Shift+Ctrl+Alt+T)
- Source code: [tapdance.c](../src/qmk/users/rafaelromao/features/tapdance.c)
- Two other extremely helpful shortcuts are Ctrl+Space (Show Autocomplete Options) and F2 (Go To Next Error), but they are easy to type and don't need to be included in the dancing.

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
Functions and Media |
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |
