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
yq -i 'del(.combos[] | select(.k.s != "vim"))' ./tmp/keymap-drawer-onlyvimcombos.yaml

# Generate SVG files using keymap
# "Usage: draw-image <input_file> <image_name> [--combos-only] [<source_param>]"

./draw-image.sh keymap-drawer.yaml all --2cols
./draw-image.sh keymap-drawer.yaml overview --2cols alpha1 alpha2 numbers symbols shortcuts nav media text smart func 
./draw-image.sh keymap-drawer-onlyseparatecombos.yaml separatecombos --combos-only --2cols alpha1 

./draw-image.sh keymap-drawer-noseparatecombos.yaml alpha-layers --2cols alpha1 alpha2 ç-extension shifted1 shifted2 
./draw-image.sh keymap-drawer-noseparatecombos.yaml symbol-layers --2cols numbers symbols 
./draw-image.sh keymap-drawer-noseparatecombos.yaml shortcuts-layers --2cols shortcuts mehs 
./draw-image.sh keymap-drawer-noseparatecombos.yaml nav-layers --2cols nav text media 
./draw-image.sh keymap-drawer-noseparatecombos.yaml vim-layers --2cols vim-remaps numbers smart 

./draw-image.sh keymap-drawer-noseparatecombos.yaml alpha1 alpha1
./draw-image.sh keymap-drawer-noseparatecombos.yaml numbers numbers
./draw-image.sh keymap-drawer-noseparatecombos.yaml symbols symbols 
./draw-image.sh keymap-drawer-noseparatecombos.yaml functions func
./draw-image.sh keymap-drawer-noseparatecombos.yaml shortcuts shortcuts
./draw-image.sh keymap-drawer-noseparatecombos.yaml mehs mehs 
./draw-image.sh keymap-drawer-noseparatecombos.yaml nav nav 
./draw-image.sh keymap-drawer-noseparatecombos.yaml text text 
./draw-image.sh keymap-drawer-noseparatecombos.yaml media media 

./draw-image.sh keymap-drawer-mehs.yaml mehs --2cols left-meh-morphs right-meh-morphs coding-meh coding-hyper fusion360-meh fusion360-hyper 
./draw-image.sh keymap-drawer-window.yaml window --2cols desktop-management window-management