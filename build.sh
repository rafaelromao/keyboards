#!/bin/bash
PROJECT_DIR="$(pwd)"

# Initialize default values
CONFIG=""
SHIELD=""
OPERATING_SYSTEM="MACOS"
BOARD="nice_nano_v2"
VERBOSE=""
ZMK="rafaelromao/zmk"
BRANCH="main"
EXTRA_SHIELDS=()
FLAGS=()
MODULES=()
DEF_MODULES=(urob/zmk-leader-key,urob/zmk-auto-layer,urob/zmk-adaptive-key)

# Function to display usage
usage() {
    echo "Usage: build [<config> <shield> <operating_system=$OPERATING_SYSTEM>] [-k <config>] [-s <shield>] [-b <board=$BOARD>] [-v <verbose>] [-z <zmk=$ZMK>] [-n <branch=$BRANCH>] [-e <extra_shield1,extra_shield2,...>] [-d <flag1,flag2,...>] [-m <module1,module2,...>] [-h | --help]"
    echo
    echo "Parameters:"
    echo "  <config>                Specify the zmk config."
    echo "  <shield>               Specify the shield."
    echo "  <operating_system>     Specify the operating system."
    echo "  -k, --config            Specify the zmk config."
    echo "  -s, --shield           Specify the shield."
    echo "  -o, --operating_system Specify the operating system (default: $OPERATING_SYSTEM)."
    echo "  -b, --board            Specify the board (default: $BOARD)."
    echo "  -v, --verbose          Enable verbose mode."
    echo "  -z, --zmk              Specify the zmk repo (default: $ZMK)."
    echo "  -n, --branch           Specify the branch (default: $BRANCH)."
    echo "  -e, --extra_shields    Specify a comma-separated list of additional shields (default: empty)."
    echo "  -d, --flags             Specify a comma-separated list of extra flags (default: empty)."
    echo "  -m, --modules          Specify a comma-separated list of modules (default: empty)."
    echo "  -h, --help             Display this help message."
    exit 1
}

# Check for help flags or insufficient parameters
if [[ "$1" == "-h" || "$1" == "--help" || "$#" -lt 2 ]]; then
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

while getopts "k:s:e:o:b:n:z:m:d:v" opt; do
    case $opt in
        k)
            CONFIG="$OPTARG"
            ;;
        s)
            SHIELD="$OPTARG"
            ;;
        e)
            IFS=',' read -r -a EXTRA_SHIELDS <<< "$OPTARG"
            ;;
        o)
            OPERATING_SYSTEM="$OPTARG"
            ;;
        b)
            BOARD="$OPTARG"
            ;;
        n)
            BRANCH="$OPTARG"
            ;;
        v)
            VERBOSE="true"
            ;;
        z)
            ZMK="$OPTARG"
            ;;
        m)
            IFS=',' read -r -a MODULES <<< "$OPTARG"
            ;;
        d)
            IFS=',' read -r -a FLAGS <<< "$OPTARG"
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

# Define zmk module
ZMK_MODULE=modules/$ZMK

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
echo "ZMK: $ZMK"
echo "Branch: $BRANCH"
echo "Extra Shields: ${EXTRA_SHIELDS[*]}"
echo "Flags: ${FLAGS[*]}"
echo "Modules: ${MODULES[*]}"

# Init the zmk repo 
export ZMK_HOME="$PROJECT_DIR/$ZMK_MODULE"
echo "Initializing zmk..."
source ./init.sh $ZMK

# Create a new flags.h file
OUTPUT_FILE="$PROJECT_DIR/src/definitions/flags.h"
[ -f "$OUTPUT_FILE" ] && rm "$OUTPUT_FILE"
touch "$OUTPUT_FILE"
echo "#define $OPERATING_SYSTEM" >> "$OUTPUT_FILE"

# Clean ZMK build directory
echo 'Cleaning zmk...'
rm -rf "$PROJECT_DIR/$ZMK_MODULE/build"

# Check out the main ZMK branch
echo 'Checking out zmk...'
cd "$PROJECT_DIR/$ZMK_MODULE"
git fetch
git checkout -f $BRANCH
git pull

cd "$PROJECT_DIR"

if [ -z "$CONFIG" ]; then
    ARTIFACT="$BOARD-$SHIELD-$OPERATING_SYSTEM"
else
    ARTIFACT="${SHIELD:-$BOARD}-$OPERATING_SYSTEM"
fi

# Rewrite the modules list

PREFIX="$PROJECT_DIR/modules/"
TEMP=""
IFS=',' read -ra ADDR <<< "$MODULES"
for MODULE in "${ADDR[@]}"; do

    MODULE_HOME=${PREFIX}${MODULE}
    # Download the module if necessary
    if [[ ! -d "$MODULE_HOME" ]]
    then
        echo "Add git sub-module: $MODULE"
        git submodule add -f "git@github.com:$MODULE" "modules/$MODULE"
    fi

    # Prefix the module name with the path
    TEMP+="${MODULE_HOME};"
done
TEMP="${TEMP%,}"
MODULES=$TEMP

# Build the project
cd "$PROJECT_DIR/$ZMK_MODULE"

# Build the west command

command="west build -s app -b \$BOARD --build-dir build/\"\$ARTIFACT\" --"
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