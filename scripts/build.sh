#!/bin/bash
PROJECT_DIR="$(pwd)"

# Initialize default values
CONFIG=""
SHIELD=""
OPERATING_SYSTEM="MACOS"
BOARD="nice_nano"
VERBOSE=""
PRISTINE=""
ZMK="zmkfirmware/zmk"
REVISION="main"
EXTRA_SHIELDS=()
FLAGS=()
MODULES=()
SNIPPETS=()
DEF_MODULES=(urob/zmk-leader-key,urob/zmk-auto-layer,urob/zmk-adaptive-key,rafaelromao/zmk-layer-morph,ssbb/zmk-listeners)

# Function to display usage
usage() {
    echo "Usage: build [<config> <shield> <operating_system=$OPERATING_SYSTEM>] [-k <config>] [-s <shield>] [-b <board=$BOARD>] [-z <zmk=$ZMK>] [-r <revision=$REVISION>] [-v <verbose>] [-p <pristine>] [-e <extra_shield1,extra_shield2,...>] [-d <flag1,flag2,...>] [-m <module1,module2,...>] [-n <snippet1,snippet2,...>] [-h | --help]"
    echo
    echo "Parameters:"
    echo "  <config>               Specify the zmk config."
    echo "  <shield>               Specify the shield."
    echo "  <operating_system>     Specify the operating system."
    echo "  -k, --config           Specify the zmk config."
    echo "  -s, --shield           Specify the shield."
    echo "  -o, --operating_system Specify the operating system (default: $OPERATING_SYSTEM)."
    echo "  -b, --board            Specify the board (default: $BOARD)."
    echo "  -z, --zmk              Specify the zmk repo (default: $ZMK)."
    echo "  -r, --revision         Specify the zmk revision (default: $REVISION)."
    echo "  -v, --verbose          Enable verbose mode."
    echo "  -p, --pristine         Enable pristine mode."
    echo "  -n, --snippets         Specify a comma-separated list of snippets (default: empty)."
    echo "  -e, --extra_shields    Specify a comma-separated list of additional shields (default: empty)."
    echo "  -d, --flags            Specify a comma-separated list of extra flags (default: empty)."
    echo "  -m, --modules          Specify a comma-separated list of modules (default: empty)."
    echo "  -h, --help             Display this help message."
    exit 1
}

# Check for help flags or insufficient parameters
if [[ "$1" == "-h" || "$1" == "--help" || "$#" -lt 1 ]]; then
    usage
fi

# Parse command line arguments
if [[ $# -gt 0 ]] && [[ ! $1 =~ ^- ]]; then
    CONFIG="$1"
    shift
fi

if [[ $# -gt 0 ]] && [[ ! $1 =~ ^- ]]; then
    SHIELD="$1"
    shift
fi

if [[ $# -gt 0 ]] && [[ ! $1 =~ ^- ]]; then
    OPERATING_SYSTEM="$1"
    shift
fi

while getopts "k:s:o:b:z:r:n:e:d:m:pv" opt; do
    case $opt in
        k)
            CONFIG="$OPTARG"
            ;;
        s)
            SHIELD="$OPTARG"
            ;;
        o)
            OPERATING_SYSTEM="$OPTARG"
            ;;
        b)
            BOARD="$OPTARG"
            ;;
        z)
            ZMK="$OPTARG"
            ;;
        r)
            REVISION="$OPTARG"
            ;;
        n)
            IFS=',' read -r -a SNIPPETS <<< "$OPTARG"
            ;;
        e)
            IFS=',' read -r -a EXTRA_SHIELDS <<< "$OPTARG"
            ;;
        d)
            IFS=',' read -r -a FLAGS <<< "$OPTARG"
            ;;
        m)
            IFS=',' read -r -a MODULES <<< "$OPTARG"
            ;;
        v)
            VERBOSE="true"
            ;;
        p)
            PRISTINE="true"
            ;;
        *)
            usage
            ;;
    esac
done

# Shift processed options away
shift $((OPTIND - 1))

if [[ -n "$SHIELD" && -n "$CONFIG" ]]; then
    if [[ "$CONFIG" == */* ]]; then
        BASENAME="${CONFIG##*/}"
    else
        BASENAME="$CONFIG" 
    fi
    if [[ "$SHIELD" == "l" ]]; then
        SHIELD="${BASENAME}_left"
    fi 
    if [[ "$SHIELD" == "cl" ]]; then
        SHIELD="${BASENAME}_central_left"
    fi 
    if [[ "$SHIELD" == "pl" ]]; then
        SHIELD="${BASENAME}_peripheral_left"
    fi 
    if [[ "$SHIELD" == "r" ]]; then
        SHIELD="${BASENAME}_right"
    fi 
    if [[ "$SHIELD" == "cr" ]]; then
        SHIELD="${BASENAME}_central_right"
    fi 
    if [[ "$SHIELD" == "pr" ]]; then
        SHIELD="${BASENAME}_peripheral_right"
    fi 
    if [[ "$SHIELD" == "cd" ]]; then
        SHIELD="${BASENAME}_central_dongle"
    fi 
fi

# Add default modules
for DEF_MODULE in "${DEF_MODULES[@]}"; do
    if [[ -n "$MODULES" ]]; then
        MODULES+=","
    fi
    MODULES+="${DEF_MODULE}"
done

# Print the parameters for verification
echo "Config: $CONFIG"
echo "Shield: $SHIELD"
echo "Operating System: $OPERATING_SYSTEM"
echo "Board: $BOARD"
echo "Verbose: $VERBOSE"
echo "Pristine: $PRISTINE"
echo "ZMK: $ZMK"
echo "Revision: $REVISION"
echo "Snippets: ${SNIPPETS[*]}"
echo "Extra Shields: ${EXTRA_SHIELDS[*]}"
echo "Flags: ${FLAGS[*]}"
echo "Modules: ${MODULES[*]}"

# Create a new flags.h file
OUTPUT_FILE="$PROJECT_DIR/src/definitions/flags.h"
[ -f "$OUTPUT_FILE" ] && rm "$OUTPUT_FILE"
touch "$OUTPUT_FILE"
echo "#define $OPERATING_SYSTEM" >> "$OUTPUT_FILE"

# Rewrite the modules list

PREFIX="$PROJECT_DIR/modules/"
TEMP=""
IFS=',' read -ra ADDR <<< "$MODULES"
for ITEM in "${ADDR[@]}"; do
    # separate module and revision
    MODULE_REVISION=""
    if [[ "$ITEM" == *":"* ]]; then
        MODULE="$(echo "$ITEM" | cut -d':' -f1)"
        MODULE_REVISION="$(echo "$ITEM" | cut -d':' -f2)"
    else
        MODULE="$ITEM"
    fi

    MODULE_HOME=${PREFIX}${MODULE}
    # Download the module if necessary
    if [[ ! -d "$MODULE_HOME" ]]
    then
        echo "Add git sub-module: $MODULE"
        git submodule add -f "git@github.com:$MODULE" "modules/$MODULE"
        # If submodule was just added, we need to cd into it to checkout the revision
        # and then return to PROJECT_DIR before the main script proceeds.
        if [ -n "$MODULE_REVISION" ]; then
            echo "Checking out revision $MODULE_REVISION of $MODULE"
            cd "$MODULE_HOME"
            git fetch
            git checkout -f "$MODULE_REVISION"
            cd "$PROJECT_DIR"
        fi
    else
        # If the module already exists and a revision is specified, check it out
        if [ -n "$MODULE_REVISION" ]; then
            echo "Module $MODULE already exists. Checking out revision $MODULE_REVISION."
            cd "$MODULE_HOME"
            git fetch
            git checkout -f "$MODULE_REVISION"
            cd "$PROJECT_DIR"
        fi
    fi

    # Prefix the module name with the path
    TEMP+="${MODULE_HOME};"
done
TEMP="${TEMP%,}"
MODULES=$TEMP

# Define zmk module
ZMK_MODULE=modules/$ZMK
ZMK_HOME="$PROJECT_DIR/$ZMK_MODULE"

# Add the sub-module for ZMK
echo "Add git sub-module: $ZMK"
git submodule add -f "git@github.com:$ZMK" "modules/$ZMK"

# Clean ZMK build directory
echo 'Cleaning zmk...'
rm -rf "$PROJECT_DIR/$ZMK_MODULE/build"

# Check out the main ZMK revision
echo 'Checking out zmk...'
cd "$PROJECT_DIR/$ZMK_MODULE"
git fetch
git checkout -f $REVISION
git pull

cd "$PROJECT_DIR"

# Init West
if [[ ! -d "$ZMK_HOME/.west" ]]
then
    echo "Initializing West..."
    cd $ZMK_HOME
    west init -l app/
    west update
    cd $PROJECT_DIR
fi

if [ -z "$CONFIG" ]; then
    ARTIFACT="$BOARD-$SHIELD-$OPERATING_SYSTEM"
else
    ARTIFACT="${SHIELD:-$BOARD}-$OPERATING_SYSTEM"
fi

# Build the project
cd "$PROJECT_DIR/$ZMK_MODULE"

# Build the west command

command="west build -s app -b \$BOARD "
if [ -n "$PRISTINE" ]; then
    command+=" -p "
fi
if [ -n "$SNIPPETS" ]; then
    command+=" -S \"\$SNIPPETS\" "
fi
command+="--build-dir build/\"\$ARTIFACT\" --"
for flag in "${FLAGS[@]}"; do
    command+=" -D$flag"
done
if [ -n "$SHIELD" ]; then
    command+=" -DSHIELD=\"\$SHIELD \$EXTRA_SHIELDS\""
fi
if [ -n "$CONFIG" ]; then
    command+=" -DZMK_CONFIG=\"\$PROJECT_DIR/src/keyboards/\$CONFIG\""
fi
if [ -n "$MODULES" ]; then
    command+=" -DZMK_EXTRA_MODULES=\"\$MODULES\""
fi

echo "Executing West:"
echo "$command"
echo ""
eval "$command"

if [[ -n "$VERBOSE" ]]; then
    # Show applied KConfig
    DOTCONFIG=build/$ARTIFACT/zephyr/.config

    if [ -f "$DOTCONFIG" ]
    then
        echo "Kconfig:"
        grep -v -e "^#" -e "^$" "$DOTCONFIG" | sort
    else
        echo "No Kconfig output"
    fi
fi

# Move the built file to artifacts directory
mkdir -p "$PROJECT_DIR/build/artifacts"
[ -f build/$ARTIFACT/zephyr/zmk.uf2 ] && \
    mv -f build/"$ARTIFACT"/zephyr/zmk.uf2 "$PROJECT_DIR/build/artifacts/$ARTIFACT-zmk.uf2"

# Return to the keyboards directory
cd "$PROJECT_DIR"
