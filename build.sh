#!/bin/bash
PROJECT_DIR="$(pwd)"

# Initialize default values
CONFIG=""
SHIELD=""
OPERATING_SYSTEM="MACOS"
BOARD="nice_nano_v2"
BRANCH="main"
MODULES=()
EXTRA_SHIELDS=()
EXTRA_FLAGS=()

# Function to display usage
usage() {
    echo "Usage: build [<config> <shield> <operating_system=MACOS>] [-k <config>] [-s <shield>] [-e <extra_shield1,extra_shield2,...>] [-b <board=nice_nano_v2>] [-z <branch [wired|main]=main>] [-m <module1,module2,...>] [-h | --help]"
    echo
    echo "Parameters:"
    echo "  <config>               Specify the zmk config."
    echo "  <shield>               Specify a single shield."
    echo "  <operating_system>     Specify the operating system."
    echo "  -k, --config           Specify the zmk config."
    echo "  -s, --shield           Specify a single shield."
    echo "  -o, --operating_system Specify the operating system (default: MACOS)."
    echo "  -e, --extra_shields    Specify additional shields as a comma-separated list (default: empty)."
    echo "  -b, --board            Specify the board (default: nice_nano_v2)."
    echo "  -z, --branch           Specify the branch (default: main, options: wired|main)."
    echo "  -d, --extra_flags      Specify extra flags (can be specified multiple times)."
    echo "  -m, --modules          Specify a comma-separated list of modules (default: empty)."
    echo "  -h, --help             Display this help message."
    exit 1
}

# Check for help flags or insufficient parameters
if [[ "$1" == "-h" || "$1" == "--help" || "$#" == 0 ]]; then
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

while getopts "k:s:e:o:b:z:m:d:" opt; do
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
        z)
            BRANCH="$OPTARG"
            ;;
        m)
            IFS=',' read -r -a MODULES <<< "$OPTARG"
            ;;
        d)
            EXTRA_FLAGS+=("$OPTARG")
            while [[ "$OPTIND" -le "$#" && "${!OPTIND}" != -* ]]; do
                EXTRA_FLAGS+=("${!OPTIND}")
                OPTIND=$((OPTIND + 1))
            done
            ;;
        *)
            usage
            ;;
    esac
done

# Shift processed options away
shift $((OPTIND - 1))

# Set the ZMK branch

if [[ "$BRANCH" == "wired" ]]; then
    BRANCH="20240328/rafaelromao/wired-split"
elif [[ "$BRANCH" == "main" ]]; then
    BRANCH="20240328/rafaelromao/main"
fi

# Print the parameters for verification
echo "Config: $CONFIG"
echo "Shield: $SHIELD"
echo "Operating System: $OPERATING_SYSTEM"
echo "Extra Shields: ${EXTRA_SHIELDS[*]}"
echo "Board: $BOARD"
echo "Branch: $BRANCH"
echo "Extra Flags: ${EXTRA_FLAGS[*]}"
echo "Modules: ${MODULES[*]}"

# Create a new flags.h file
OUTPUT_FILE="$PROJECT_DIR/src/zmk/definitions/flags.h"
[ -f "$OUTPUT_FILE" ] && rm "$OUTPUT_FILE"
touch "$OUTPUT_FILE"
echo "#define $OPERATING_SYSTEM" >> "$OUTPUT_FILE"

# Clean ZMK build directory
echo 'Cleaning zmk...'
rm -rf "$PROJECT_DIR/modules/rafaelromao/zmk/build"

# Check out the main ZMK branch
echo 'Checking out zmk...'
cd "$PROJECT_DIR/modules/rafaelromao/zmk"
git fetch
git checkout -f $BRANCH
git pull

# Build the project
cd "$PROJECT_DIR"
cd "$PROJECT_DIR/modules/rafaelromao/zmk"

if [ -z "$CONFIG" ]; then
    ARTIFACT="$BOARD-$SHIELD"
else
    ARTIFACT="${SHIELD:-$BOARD}"
fi

command="west build -s app -b \$BOARD --build-dir build/\"\$ARTIFACT\" --"
for flag in "${EXTRA_FLAGS[@]}"; do
    command+=" -D$flag"
done
if [ -n "$SHIELD" ]; then
    command+=" -DSHIELD=\"\$SHIELD \$EXTRA_SHIELDS\""
fi
if [ -n "$CONFIG" ]; then
    command+=" -DZMK_CONFIG=\"\$PROJECT_DIR/src/zmk/keyboards/\$CONFIG\""
fi
if [ -n "$MODULES" ]; then
    command+=" -DZMK_EXTRA_MODULES=\"\$MODULES\""
fi

eval "$command"

# Move the built file to artifacts directory
mkdir -p "$PROJECT_DIR/build/artifacts"
[ -f build/$ARTIFACT/zephyr/zmk.uf2 ] && \
    mv -f build/"$ARTIFACT"/zephyr/zmk.uf2 "$PROJECT_DIR/build/artifacts/$ARTIFACT-zmk.uf2"

# Return to the keyboards directory
cd "$PROJECT_DIR"