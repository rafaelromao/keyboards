# rafaelromao's keyboard layout

## Home Block Modifiers

[Home Block Modifiers](https://precondition.github.io/home-row-mods#alternative-home-row-mods-layout) are an alternative to [Home Row Modifiers](https://precondition.github.io/home-row-mods), but with the pinky key replaced by the index colunm key in the bottom row.

- Home block modifiers are available on both sides of the [Base](base.md) and [Numpad](symbols.md#numpad-layer) layers.
- Home block modifiers are not available on lower and raise layers, since they delay the symbol activation and are not that much useful anyway.

## One-Shot Modifiers

One-Shot Modifiers are modifier keys that, when tapped, remain active until the next key is pressed or a timeout expires. 
- They are available in the [Navigation](navigation.md#navigation) layer and act as standard modifers when held.
- These modifiers will be automatically deactivated after 2 seconds. 
- They can also be activated in sticky mode, with a double tap, and remain active until manually deactivated by tapping the Default Mod thumb key.
    - Source code: [custom_oneshot_mods.c](../src/qmk/users/rafaelromao/features/custom_oneshot_mods.c)

## Standard Modifiers

- Stantard modifiers are available in the [Media](navigation.md#media) layer.
- These modifiers do not have one-shot behavior, so they can be used in situations which a tap or multi tap in a modifier key is required.

## Capitalize Key 

The Capitalize key is a custom key that works both as Shift and Caps Lock.
- It is placed in the right outer thumb key and behaves as follows, when tapped:
    - If Caps Lock is active, it deactivates Caps Lock.
    - If Shift is active or locked in one-shot mode, it activates Caps Lock.
    - If Shift is not active in one-shot mode, it activates Shift for one-shot.
- The hold behavior of this thumb key is used to activate the Mouse layer.
- The Capitalize key is implemented using a custom keycode and a layer-tap.
    - The hold behavior is kept as is, but the tap behavior is intercepted and customized.
    - Source code: [capitalize_key.c](../src/qmk/users/rafaelromao/features/capitalize_key.c)

## N-Grams Key
- The N-Grams key is available in the left outer thumb key and will toggle the N-Grams layer in one-shot mode, acting like a special shift key.
    - Source code: [ngrams.c](../src/qmk/users/rafaelromao/features/ngrams.c)

## Default Mod and Alt Thumb Keys

The Default Mod (Cmd or Ctrl) and Alt thumb keys are placed in the outer left and right thumb keys respectively, in the Navigation and Media layers, and will give access to one-shot versions of the Cmd/Ctrl or Alt keys.
- They behaves as follows, when tapped:
    - If any modifier is active or locked in one-shot mode, all these modifiers will be deactivated.
    - If no modifier is active or locked in one-shot mode, it activates the modifier in one-shot mode.
- They are implemented using a custom keycode and a layer-tap.
    - The hold behavior is kept as is, but the tap behavior is intercepted and customized.
- For the right side, this key will always activate Alt, when tapped.
- For the left side,
    - This key allows using the same key combinations for shortcuts like Cmd/Ctrl+S, Cmd/Ctrl+C and Cmd/Ctrl+V.
    - This key will activate the modifier for the current operating system, which can be selected in the maintenace layer.
        - If Mac OS is selected, the default modifier will be Cmd, otherwise it will be Ctrl.
        - If one-shot Shift is active, the default modifier will be inverted (Cmd vs Ctrl).
- Source code: [smart_thumb_keys.c](../src/qmk/users/rafaelromao/features/smart_thumb_keys.c)

## Caps Lock

- Caps Lock is also available in the [Raise layer](symbols.md), but its behavior is not what we usually see. No matter how it was activated, Caps Lock will be automatically deactivated after 10 seconds of inactivity
    - The caps lock timer feature is implemented by starting a timer when the caps lock is activated and deactivating it in the matrix scan, in case the timer has expired.
    - The caps lock timer is restarted when a valid key is pressed.
    - The caps lock timer is stopped and caps lock deactivated when Esc is pressed.
    - Source code: [capslock_timer.c](../src/qmk/users/rafaelromao/features/capslock_timer.c)

##
[Home](../readme.md) | 
[Base](base.md) |
Modifiers |
[N-Grams and Macros](macros.md) |
[Symbols and Numbers](symbols.md) |
[Navigation and Media](navigation.md) |
[Maintenance](maintenance.md)
