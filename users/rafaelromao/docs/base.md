# rafaelromao's keyboard layout

## Layout Overview
![img](https://i.imgur.com/AcOChyf.png)
- This is a 34 keys split layout, 3x5+2, optimized for programmers.
- This layout works well with the OS configured for the US International keyboard.
- This layout was designed mostly for coding and typing in English and Portuguese (but will probably work well for other latin languages).
- This layout considers the right hand as the dominant hand.
- The base layer can be either qwerty or colemak dhm.

## Thumb Keys
- The four thumb keys control layer transitions, when held (navigation, lower, raise and mouse).
- The two outer thumb keys act as [modifiers](modifiers.md) or [shortcuts](functions.md), when tapped.
- The two inner thumb keys act as space or backspace, when tapped.
- Holding both outer thumb keys will activate the maintenance layer.

## Persistent Base Layers
- The base layer can be either qwerty or colemak dhm.
- It is possible to change the base layer in the maintenance layer and this change is persistent.
- Source Code: [persistent_layers.c](../features/persistent_layers.c)

## Double Dot for New Sentences
- A double tap in the dot key outputs dot followed by space, and activates oneshot shift. This will make it easier to enter a new sentence.
- Holding the dot key will insert it in the end of the current line.

## Base Layer Combos
- Combos are available in the base layers to send ENTER, ESC, TAB, common shortcuts and to toggle the [Lower, Raise](symbols.md) or [Media](functions.md) layers.
- Most combos include the home thumb key, the one in the same side, to avoid misfires. The exception is the combo that activates the Navigation layer.
- One-shot shift can be used to invert the [default modifier](modifiers.md) used in the combos.
- If shift, or any other modifier, is held, it will be included in the combo. So hold Shift and tap Z+X+Space will send Redo instead of Undo.

##
[Home](../readme.md) | 
Base |
[Modifiers](modifiers.md) |
[Symbols and Numbers](symbols.md) |
[Functions and Media](functions.md) | 
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |
