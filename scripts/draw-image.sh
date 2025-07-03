#!/bin/bash

# Check if the output parameter is provided
if [ -z "$1" ] || [ -z "$2" ]; then
    echo "Usage: draw-image <input_file> <image_name> [--combos-only] [--2cols] [--footernote] [<layer1 layer2 layerN>]"
    exit 1
fi

# Assign the input file parameter
input_file="tmp/$1"

# Assign the output image name
image_name="$2"

# Check if --combos-only is provided
combos_only=""
if [ "$3" == "--combos-only" ]; then
    combos_only="--combos-only"
    shift 1
fi

config="docs/img/diagrams/keymap-drawer/keymap-drawer-config.yaml"

# Check if --2cols is provided
yq eval '.draw_config.n_columns = 1' -i $config
if [ "$3" == "--2cols" ]; then
    yq eval '.draw_config.n_columns = 2' -i $config
    shift 1
fi

# Check if footernote is requested
yq eval '.draw_config.footer_text = "" ' -i $config
if [ "$3" == "--footernote" ]; then
    yq eval '.draw_config.footer_text = "Created with keymap-drawer"' -i $config
    shift 1
fi

# Assign the source parameter if provided
source_param=""
if [ ! -z "$3" ]; then
    shift 2
    source_param="-s $@"
fi

# Execute the command
keymap -c $config draw $source_param $combos_only -o "tmp/$image_name.svg" "$input_file"
inkscape --export-type png --export-filename "docs/img/diagrams/$image_name.png" --export-dpi 300 --export-background=white "tmp/$image_name.svg"