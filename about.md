# About this repo

- This repository contain only the files that are used to customize my keyboards.
- The script [init.sh](init.sh) will clone [my fork](https://github.com/rafaelromao/qmk_firmware) of the qmk_firmware and symlink these files onto it.
  - The script references my fork, which is version 0.14.9, to ensure new versions will not make the firmware size too long.
- After that, [qmk cli](https://docs.qmk.fm/#/cli) should work just fine to compile and flash my keyboards.

## References
- [My userspace](users/rafaelromao/readme.md)
- [Weilbith repo](https://github.com/weilbith/keyboard_firmware)