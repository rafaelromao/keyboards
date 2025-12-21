# Create temporary directory
mkdir -p ./tmp

# Separate target files
cp docs/img/diagrams/keymap-drawer/keymap-drawer.yaml tmp/keymap-drawer.yaml
cp docs/img/diagrams/keymap-drawer/keymap-drawer.yaml tmp/keymap-drawer-noseparatecombos.yaml
cp docs/img/diagrams/keymap-drawer/keymap-drawer.yaml tmp/keymap-drawer-onlyseparatecombos.yaml

yq -i 'del(.combos[] | select(.draw_separate == true))' tmp/keymap-drawer-noseparatecombos.yaml
yq -i 'del(.combos[] | select(.draw_separate != true))' tmp/keymap-drawer-onlyseparatecombos.yaml

cp tmp/keymap-drawer-onlyseparatecombos.yaml tmp/keymap-drawer-onlyshortcutcombos.yaml
cp tmp/keymap-drawer-onlyseparatecombos.yaml tmp/keymap-drawer-onlynavcombos.yaml
cp tmp/keymap-drawer-onlyseparatecombos.yaml tmp/keymap-drawer-onlymediacombos.yaml

yq -i 'del(.combos[] | select(.layers | contains(["shortcuts"]) | not))' tmp/keymap-drawer-onlyshortcutcombos.yaml
yq -i 'del(.combos[] | select(.layers | contains(["nav"]) | not))' tmp/keymap-drawer-onlynavcombos.yaml
yq -i 'del(.combos[] | select(.layers | contains(["media"]) | not))' tmp/keymap-drawer-onlymediacombos.yaml

# Generate SVG files using keymap

# "Usage: draw-image <input_file> <image_name> [--combos-only] [--2cols] [<layer1 layer2 layerN>]"

./scripts/draw-image.sh keymap-drawer.yaml all --2cols --footernote

./scripts/draw-image.sh keymap-drawer-onlyshortcutcombos.yaml shortcutcombos --combos-only --2cols shortcuts
./scripts/draw-image.sh keymap-drawer-onlynavcombos.yaml navcombos --combos-only --2cols nav
./scripts/draw-image.sh keymap-drawer-onlymediacombos.yaml mediacombos --combos-only --2cols media

./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml overview --2cols --footernote alpha1 alpha2 ç-extension vim numbers symbols shortcuts mehs nav media text macros func toggles 
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml alphas alpha1 alpha2
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml cedil ç-extension
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml boot --2cols func macros
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml plain plain1 plain2
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml shifted shifted1 shifted2
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml vim alpha1 shortcuts vim-layer

./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml alpha1 alpha1
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml numbers numbers
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml symbols symbols 
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml functions func
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml shortcuts shortcuts
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml mehs mehs 
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml nav nav 
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml text text 
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml media media 
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml macros macros 

./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml toggles toggles 
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml coding-mehs coding-meh coding-hyper
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml meh-morphs --2cols left-meh-morphs right-meh-morphs
./scripts/draw-image.sh keymap-drawer-noseparatecombos.yaml window desktop-management window-management
