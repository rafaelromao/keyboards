# Create temporary directory
mkdir -p ./tmp

# Separate target files
cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer.yaml
cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer-noseparatecombos.yaml
cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer-onlyseparatecombos.yaml
cp ./docs/keymap-drawer/keymap-drawer.yaml ./tmp/keymap-drawer-onlyvimcombos.yaml
cp ./docs/keymap-drawer/keymap-drawer-extras.yaml ./tmp/keymap-drawer-mehs.yaml
cp ./docs/keymap-drawer/keymap-drawer-extras.yaml ./tmp/keymap-drawer-window.yaml

yq -i 'del(.combos[] | select(.draw_separate == true))' ./tmp/keymap-drawer-noseparatecombos.yaml
yq -i 'del(.combos[] | select(.draw_separate != true))' ./tmp/keymap-drawer-onlyseparatecombos.yaml

# Generate SVG files using keymap

# "Usage: draw-image <input_file> <image_name> [--combos-only] [<source_param>]"

./draw-image.sh keymap-drawer.yaml all --2cols
./draw-image.sh keymap-drawer.yaml overview --2cols alpha1 alpha2 numbers symbols shortcuts nav media text smart func 

./draw-image.sh keymap-drawer-onlyseparatecombos.yaml separatecombos --combos-only --2cols alpha1 

./draw-image.sh keymap-drawer-noseparatecombos.yaml overview-nocombos --2cols alpha1 alpha2 numbers symbols shortcuts nav media text smart func 
./draw-image.sh keymap-drawer-noseparatecombos.yaml alphas alpha1 alpha2
./draw-image.sh keymap-drawer-noseparatecombos.yaml cedil ç-extension
./draw-image.sh keymap-drawer-noseparatecombos.yaml boot --2cols func smart
./draw-image.sh keymap-drawer-noseparatecombos.yaml plain --2cols plain1 plain2
./draw-image.sh keymap-drawer-noseparatecombos.yaml shifted --2cols shifted1 shifted2
./draw-image.sh keymap-drawer-noseparatecombos.yaml vim vim-remaps

./draw-image.sh keymap-drawer-noseparatecombos.yaml alpha1 alpha1
./draw-image.sh keymap-drawer-noseparatecombos.yaml numbers numbers
./draw-image.sh keymap-drawer-noseparatecombos.yaml symbols symbols 
./draw-image.sh keymap-drawer-noseparatecombos.yaml functions func
./draw-image.sh keymap-drawer-noseparatecombos.yaml shortcuts shortcuts
./draw-image.sh keymap-drawer-noseparatecombos.yaml mehs mehs 
./draw-image.sh keymap-drawer-noseparatecombos.yaml nav nav 
./draw-image.sh keymap-drawer-noseparatecombos.yaml text text 
./draw-image.sh keymap-drawer-noseparatecombos.yaml media media 
./draw-image.sh keymap-drawer-noseparatecombos.yaml smart smart 

./draw-image.sh keymap-drawer-mehs.yaml coding-mehs coding-meh coding-hyper
./draw-image.sh keymap-drawer-mehs.yaml meh-morphs --2cols left-meh-morphs right-meh-morphs
./draw-image.sh keymap-drawer-window.yaml window desktop-management window-management