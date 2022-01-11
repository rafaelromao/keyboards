# rafaelromao's keyboard layout

## Functions and Media
The Functions and Media layers are activated holding the left or right pinky keys in the home row, respectively.
![img](https://i.imgur.com/7viWYeT.png)

## Functions
- On the left side of the Functions layer, there are standard modifier keys, also forming a home block, along with Caps Lock and a Menu key.
- On the right side, the F keys are available in the same positions as their respective numbers, so F5 and 5 are under the same key, making it easier to assimilate. F10 to F12 goes bottom up in the pinky column, while F13 to F15 are available in the inner index column and can be mapped to custom actions or macros in the operating system level.
- The Functions layer can be toggle on using a combo with the right hand, in the [Lower](symbols.md) layer.
- Another combo can be used to toggle this the layer off.
- Source code: [combos.c](../features/combos.c)

## Media
- In the left side of the Media layer, you can find the RGB control keys, while the media keys are placed in the right side.
- Also in the right side, there are keys to control Zoom, which can be either Cmd+ and Cmd- or Ctrl+ and Ctrl-, according to the operating system that is selected in the [Maintenance](maintenance.md) layer.
- The Media layer can also be activated using the left hand, holding (or tapping, for one-shot) the space thumb key plus the botton row pinky key. 

## Space and Backspace
- The space and backspace thumb keys are inverted in the Functions and Media layers, which allow single hand access to both of them.

## Leader Key
- A Leader Key is available in the home row, in the center column, in the left side of the Functions layer and in the right side of the Media layer, allowing mirrored single hand access to it.
- The Leader Key is used to give easy access to some useful shortcuts and macros, like typing an internet domain or recurring terminal commands.
- Source code: [leader.c](../features/leader.c)

## IntelliJ Shortcuts
- Also in the Functions and Media layers, which means, when holding any of the home row pinky keys, the outer thumb keys can be used to tap dance through some of the most common IntelliJ Shortcuts:
- Left Side:
    - Tap = Focus the Project Window
    - Double Tap = Run Everything
    - Hold = Find Usages
- Right Side:
    - Tap = Quick Actions
    - Double Tap = Search Everywhere
    - Hold = Next Error/Warning
- Source code: [tapdance.c](../features/tapdance.c)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
Functions and Media |
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |
