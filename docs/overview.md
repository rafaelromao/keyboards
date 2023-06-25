# rafaelromao's keyboard layout

## Premisses
This layout consider the following premisses, which might not be acceptable for most people, so let's start with that:
- If it is possible, use just one hand. It is the opposite of what Miryoku states.
- The pointing device I use is a Kensington Expert Mouse, used with the left hand, in the left side of the left half of the keyboard. This fact influenced a lot of decisions during the development of this layout.
- Most of the load will go to the right hand, assuming that the left hand might be in the trackball, so it might not be a good layout for left handed people.

## Layout Overview
- This is a 30 keys split layout, 3x5+2 keys on each side, minus the two top row pinkie and index keys.
- This layout works well with the OS configured for US International keyboards.
- It was designed mostly for typing in Portuguese and English, working with numbers and programming in Java.
- It reduces the usage of pinkies and indexes and considers the right hand as dominant.
- The base layer is [Romak](romak.md), a new keyboard layout optimized for what is described above.

## Smart Thumb Keys
- The Smart Thumb keys in this layout change behavior according to the context (active layer and active modifiers).
- The four thumb keys control layer transitions, when held (navigation, lower, raise and media).
- Holding both outer thumb keys will activate the maintenance layer.

## Layers




### Navigation
- The Navigation layer gives access to [One-Shot Modifiers](modifiers.md#one-shot-modifiers), Enter, Tab, Insert, Delete, Home, End, Page Up, Page Down and VIM style navigation, as well as Esc and a Save shortcut.
### Media
- The Media layer gives access to [Standard Modifiers](modifiers.md#standard-modifiers), Media controls, Esc and a Save shortcut.
- The right side of this layer gives access to media keys and shortcuts to toggle the Navigation or Numpad layers on or off.

### Navigation Layer Toggle
- A clone of the Navigation layer can be toggled on permanently using the Media layer.
- This clone works the same way as the original Navigation layer, but the outer right thumb key will activate the Media layer instead of the Maintenance layer.

## Key Position Reference
- In the rest of these docs, keys will be referred to using the layer they are and the codes below:
```
  ╭─────────────────────╮ ╭─────────────────────╮
  │ LTP LTR LTM LTI     │ │     RTI RTM RTR RTP │
  │ LHP LHR LHM LHI LHC │ │ RHC RHI RHM RHR RHP │
  │     LBR LBM LBI LBC │ │ RBC RBI RBM RBR     │
  ╰───────────╮ L1  L0  │ │ R0  R1  ╭───────────╯
              ╰─────────╯ ╰─────────╯ 
```
- The first char represents the side, L for Left and R for right.
- The second represents the row, T for top, H for home and B for bottom.
- The third represents the finger, P for pinkie, R for ring, M for middle, I for index and C for the center column.
- Thumbs are represented only with the side indicator and an index number, from inside to outside.

### Secrets
- Secret combos and leader sequencies can be included in the files [secret.h](https://gist.github.com/rafaelromao/29b444b8b0bdec5402067beb35c2bcda) and [secret.c](https://gist.github.com/rafaelromao/76be290d7d58176699b8e20859c15618). These files are not part of the repo, for obvious reasons, so these two gists are provided as templates.