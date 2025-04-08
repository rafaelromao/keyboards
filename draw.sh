# Create temporary directory
mkdir -p ./tmp

# Separate target files
cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer-noseparatecombos.yaml
cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer-onlyseparatecombos.yaml
cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer-onlyvimcombos.yaml
cp ./docs/keymap-drawer/keymap-drawer-extras.yaml ./tmp/keymap-drawer-mehs.yaml
cp ./docs/keymap-drawer/keymap-drawer-extras.yaml ./tmp/keymap-drawer-window.yaml

yq -i 'del(.combos[] | select(.draw_separate == true))' ./tmp/keymap-drawer-noseparatecombos.yaml
yq -i 'del(.combos[] | select(.draw_separate != true))' ./tmp/keymap-drawer-onlyseparatecombos.yaml
yq -i 'del(.combos[] | select(.k.s != "vim"))' ./tmp/keymap-drawer-onlyvimcombos.yaml

# Generate SVG files using keymap
keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -o ./tmp/overview.svg ./docs/keymap-drawer/keymap-drawer.yaml

keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s alpha1 --combos-only -o ./tmp/separatecombos.svg ./tmp/keymap-drawer-onlyseparatecombos.yaml

keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s alpha1 alpha2 ç-extension shifted1 shifted2 -o ./tmp/alphas.svg ./tmp/keymap-drawer-noseparatecombos.yaml

keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s lower raise -o ./tmp/symbols.svg ./tmp/keymap-drawer-noseparatecombos.yaml

keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s functions smartcases -o ./tmp/functions.svg ./tmp/keymap-drawer-noseparatecombos.yaml

keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s shortcuts mehs -o ./tmp/shortcuts.svg ./tmp/keymap-drawer-noseparatecombos.yaml

keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s nav media -o ./tmp/navigation.svg ./tmp/keymap-drawer-noseparatecombos.yaml

keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s vim-remaps lower media -o ./tmp/vim.svg ./tmp/keymap-drawer-onlyvimcombos.yaml

keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s left-meh-morphs right-meh-morphs coding-meh coding-hyper fusion360-meh fusion360-hyper -o ./tmp/mehs.svg ./tmp/keymap-drawer-mehs.yaml

keymap -c ./docs/keymap-drawer/keymap-drawer-config.yaml draw -s desktop-management window-management -o ./tmp/window.svg ./tmp/keymap-drawer-window.yaml

# Convert SVG files to PNG using Inkscape
inkscape --export-type png --export-filename ./img/overview.png --export-dpi 300 --export-background=white ./tmp/overview.svg
inkscape --export-type png --export-filename ./img/separatecombos.png --export-dpi 300 --export-background=white ./tmp/separatecombos.svg
inkscape --export-type png --export-filename ./img/alphas.png --export-dpi 300 --export-background=white ./tmp/alphas.svg
inkscape --export-type png --export-filename ./img/symbols.png --export-dpi 300 --export-background=white ./tmp/symbols.svg
inkscape --export-type png --export-filename ./img/functions.png --export-dpi 300 --export-background=white ./tmp/functions.svg
inkscape --export-type png --export-filename ./img/shortcuts.png --export-dpi 300 --export-background=white ./tmp/shortcuts.svg
inkscape --export-type png --export-filename ./img/navigation.png --export-dpi 300 --export-background=white ./tmp/navigation.svg
inkscape --export-type png --export-filename ./img/vim.png --export-dpi 300 --export-background=white ./tmp/vim.svg
inkscape --export-type png --export-filename ./img/mehs.png --export-dpi 300 --export-background=white ./tmp/mehs.svg
inkscape --export-type png --export-filename ./img/window.png --export-dpi 300 --export-background=white ./tmp/window.svg
