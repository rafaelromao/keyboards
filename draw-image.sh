#!/bin/bash

# Check if the output parameter is provided
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: draw-image <input_file> <image_name> [--combos-only] [--2cols] [<layer1 layer2 layerN>]"
    exit 1
fi

# Assign the input file parameter
input_file="./tmp/$1"

# Assign the output image name
image_name="$2"

# Check if --combos-only is provided
combos_only=""
if [ "$3" == "--combos-only" ]; then
    combos_only="--combos-only"
    shift 1
fi

# Check if --2cols is provided
config="./img/diagrams/keymap-drawer/keymap-drawer-config-1col.yaml"
if [ "$3" == "--2cols" ]; then
    config="./img/diagrams/keymap-drawer/keymap-drawer-config-2cols.yaml"
    shift 1
fi

# Assign the source parameter if provided
source_param=""
if [ ! -z "$3" ]; then
    shift 2
    source_param="-s $@"
fi

# Execute the command
keymap -c $config draw $source_param $combos_only -o "./tmp/$image_name.svg" "$input_file"
inkscape --export-type png --export-filename "./img/diagrams/$image_name.png" --export-dpi 300 --export-background=white "./tmp/$image_name.svg"