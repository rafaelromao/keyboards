# ZMK Vim Mode

These scripts are used to notify the keyboard when NeoVim or any other Vim-like editor is in focus.

This is achieved by using the NUM_LOCK state. My keyboards assume that when NUM_LOCK is toggled on, Vim Mode should be activated — which means enabling the VIM_NORMAL layer and sending an ESC key tap.

When Vim Mode is active, the keyboard tracks user actions to mimic Vim’s state transitions, activating the corresponding layer based on the current Vim mode.

This setup allows me to use my alternative layout for regular typing, while an optimized Vim layer is automatically used for navigation and command execution.

## Limitations

This is still a work in progress, and there are a few limitations I plan to address in the future.

# How to Use It

There are versions available for MacOS and Omarchy.

For MacOS it uses a Hammerspoon watcher to monitor the active application and setledsmac to toggle NUM_LOCK.

For Omarchy I haven’t yet found a reliable way to toggle NUM_LOCK programmatically. The current implementation works, but only takes effect after the next keypress. It uses a systemd daemon to monitor the active application and hyprctl to change the NUM_LOCK state.

Read the scripts carefully before using them, and proceed at your own risk.

