# rafaelromao's keyboard layout

## Functions and Maintenance
- The Functions and Maintenance layers are activated holding the left or right pinky keys in the home row, respectively.

## Functions
- On the left side of the Functions layer, there are standard modifier keys, also forming a home block, along with Caps Lock and a Menu key.
- On the right side, the F keys are available in the same positions as their respective numbers, so F5 and 5 are under the same key, making it easier to assimilate. F10 and F12 are available in the inner index column, while F14 to F15 goes bottom up in the pinky column and can be mapped to custom actions or macros in the operating system level, or used to control brightness in MacOS.
- The Functions layer can be toggle on using a combo with the right hand, in the [Numpad](symbols.md#numpad) layer.
- Another combo can be used to toggle the layer off.
- Source code: [combos.c](../src/qmk/users/rafaelromao/features/combos.c)

## Maintenance
The left side of the Maintenance layer, we have options like:
- Put the keyboard in bootloader mode (reset). 
- Clear the eeprom.
- Toggle RGB.
- Deactivate all layers and return to the base. 
- Put the host computer in sleep mode, or power it off.
- Change the operating system used in keys that are OS aware, like the [Default Mod key](modifiers.md).
- Source code: [os_toggle.c](../src/qmk/users/rafaelromao/features/os_toggle.c)
- Disable or enable the [Mouse layer](navigation.md). 
- A combo with the four extreme corner keys puts the keyboard in bootloader mode. This combo is a base layer alternative for the Reset key, in the Maintenance layer, in case some unintended layer lock prevents access to it.

### Media Controls
- In the right side of Maintenance layer we can find media keys and zoom keys.

### Zoom Controls
- In the right side of the Maintenance layer, there are keys to control Zoom, which can be either Cmd+ and Cmd- or Ctrl+ and Ctrl-, according to the operating system that is selected.

## Space and Backspace
- The space and backspace thumb keys are inverted in the Functions and Maintenance layers, which allow single hand access to both of them.

## IDE Dancing
- Also in the Functions and Maintenance layers, which means, when holding any of the home row pinky keys, the outer thumb keys can be used to tap dance through some of the most common IDE shortcuts, using keybindings from IntelliJ IDEA.
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
- Two other extremely helpful shortcuts are Ctrl+Space (Show Autocomplete Options) and F2 (Go To Next Error), but they are easy to type and don't need to be included in the dancing.
- Source code: [tapdance.c](../src/qmk/users/rafaelromao/features/tapdance.c)

##
[Home](../readme.md) | 
[Base](base.md) |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
[Navigation and Mouse](navigation.md) |
Functions and Maintenance
