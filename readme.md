# rafaelromao's keyboards

- This repository contains the files that are used to customize my keyboards.
- The script [init.sh](init.sh) will clone [my fork](https://github.com/rafaelromao/qmk_firmware) of the qmk_firmware and symlink these files on it.
  - The script references my fork, which is qmk version 0.14.9, to ensure new versions will not make the firmware size too large.
- After running the init script, [qmk cli](https://docs.qmk.fm/#/cli) should work just fine to compile and flash my keyboards.

## Userspace
- In [my userspace](qmk/users/rafaelromao), you can see the code shared between my keyboards and a complete documentation about how they work.

## References
- [Weilbith](https://github.com/weilbith/keyboard_firmware)
