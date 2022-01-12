# rafaelromao's keyboard layout

## Home Block Modifiers

[Home Block Modifiers](https://precondition.github.io/home-row-mods#alternative-home-row-mods-layout) are an alternative to [Home Row Modifiers](https://precondition.github.io/home-row-mods), but with the pinky key replaced by the index colunm key in the bottom row.

- Home block modifiers are available on both sides of the base layers.
![img](https://i.imgur.com/Wjnyss9.png)
- Home block modifiers are not available on lower and raise layers, since they delay the symbol activation and are not that much useful anyway.

## One-Shot Modifiers

One-Shot Modifiers are modifier keys that, when tapped, remain active until the next key is pressed or a timeout expires. 

- They act as standard mofiders when held.
- These modifiers will be automatically deactivated after 2 seconds. 
- They can also be activated in sticky mode, with a double tap, and remain active until manually deactivated by tapping the Default Mod thumb key.
- One-shot modifiers are available on the left side of the navigation and mouse layers.

## Standard Modifiers

- Stantard modifiers (Shift, Ctrl, Alt, Gui) are available on the left side of the [functions layer](functions.md). These standard modifiers do not have one-shot or sticky behavior, so they can be used in situations were a tap or multi tap in a modifier key is required.

## Default Mod Key 

The Default Mod key is a custom key that works as either one-shot Cmd or one-shot Ctrl.

- This key will activate the default modifier for the current operating system, which can be selected in the maintenace layer.
    - When Mac OS is selected, this key activates Cmd, otherwise it activates Ctrl.
    - If one-shot Shift is active, the default modifier will be inverted.
- This key allows using the same key combinations for shortcuts like Cmd/Ctrl+S, Cmd/Ctrl+C and Cmd/Ctrl+V.
- It is placed as a thumb key and behaves as follows, when tapped:
    - If any modifier is active or locked in one-shot mode, all these modifiers will be deactivated.
    - If no modifier is active or locked in one-shot mode, it activates the default modifier in one-shot mode.
- The hold behavior of this thumb key is used to activate the Navigation layer.
- Its alias in the keymap diagram is _Mod_.
- The Default Mod key is implemented using a custom keycode and a layer-tap.
    - The hold behavior is kept as is, but the tap behavior is intercepted and customized.
    - Source code: [default-mod-key.c](../features/default_mod_key.c)

## Capitalize Key 

The Capitalize key is a custom key that works both as Shift and Caps Lock.

- It is placed as a thumb key and behaves as follows, when tapped:
    - If Caps Lock is active, it deactivates Caps Lock.
    - If Shift is active or locked in one-shot mode, it activates Caps Lock.
    - If Shift is not active in one-shot mode, it activates Shift for one-shot.
- The hold behavior of this thumb key is used to activate the Mouse layer.
- Its alias in the keymap diagram is _Cap_.
- The Capitalize key is implemented using a custom keycode and a layer-tap.
    - The hold behavior is kept as is, but the tap behavior is intercepted and customized.
    - Source code: [capitalize-key.c](../features/capitalize_key.c)

## Caps Lock

- Caps Lock is also available in the [functions layer](functions.md), but its behavior is not what we usually see. No matter how it was activated, Caps Lock will be automatically deactivated after 4 seconds of inactivity
    - The caps lock timer feature is implemented by starting a timer when the caps lock is activated and deactivating it in the matrix scan, in case the timer has expired.
    - The caps lock timer is restarted when a valid key is pressed.
    - Source code: [capslock_timer.c](../features/capslock_timer.c)

##
[Home](../readme.md) | 
[Base](base.md) |
Modifiers |
[Symbols and Numbers](symbols.md) |
[Functions and Media](functions.md) | 
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |
