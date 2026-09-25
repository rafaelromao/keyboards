#!/bin/bash
PROJECT_DIR="$(pwd)"

# Initialize default values
CONFIG=""
SHIELD=""
BOARD="nice_nano//zmk"
VERBOSE=""
PRISTINE=""
ZMK="zmkfirmware/zmk"
# Pinned rather than "main". Tracking a branch meant two boards built a week
# apart ran different ZMK, and "what changed since it worked?" had no answer.
# This is the commit today's working builds used. v0.3, the latest release, is
# still on Zephyr 3.x and will not build this tree. Moving the pin is a
# deliberate act: bump it, rebuild everything, and check the modules still
# compile, since they track main. -r overrides it for a one-off.
REVISION="9ebbeff0a8b69a42f14aec022cdf16c7a107b9e0"
EXTRA_SHIELDS=()
FLAGS=()
MODULES=""
SNIPPETS=()
DEF_MODULES=(urob/zmk-leader-key urob/zmk-auto-layer urob/zmk-adaptive-key rafaelromao/zmk-layer-morph rafaelromao/zmk-vim-mode rafaelromao/zmk-layer-hud rafaelromao/zmk-os-detection)
# The layer signal's USB carrier is a CDC-ACM interface that exists only if this
# snippet adds it, so a build without it reaches the HUD over BLE or not at all.
# zmk-layer-hud is in DEF_MODULES, which are appended to whatever -m gives, so
# the snippet is always on the search path. -n replaces this, it does not add.
DEF_SNIPPETS=(layer-hud-usb-uart)

# Function to display usage
usage() {
    echo "Usage: zmk [<config> <shield>] [-k <config>] [-s <shield>] [-b <board=$BOARD>] [-z <zmk=$ZMK>] [-r <revision=$REVISION>] [-v] [-p] [-e <extra_shield1,extra_shield2,...>] [-d <flag1,flag2,...>] [-m <module1,module2,...>] [-n <snippet1,snippet2,...>] [-h | --help]"
    echo
    echo "Parameters:"
    echo "  <config>               Specify the zmk config."
    echo "  <shield>               Specify the shield."
    echo "  -k <config>            Specify the zmk config."
    echo "  -s <shield>            Specify the shield."
    echo "  -b <board>             Specify the board (default: $BOARD)."
    echo "  -z <zmk>               Specify the zmk repo (default: $ZMK)."
    echo "  -r <revision>          Specify the zmk revision (default: $REVISION)."
    echo "  -v                     Enable verbose mode (dump the applied Kconfig)."
    echo "  -p                     Pristine build: wipe the zmk build directory first."
    echo "  -n <snippets>          Comma-separated list of snippets (replaces the default: ${DEF_SNIPPETS[*]})."
    echo "  -e <extra_shields>     Comma-separated list of additional shields (default: empty)."
    echo "  -d <flags>             Comma-separated list of extra -D flags (default: empty)."
    echo "  -m <modules>           Comma-separated list of modules, added to the defaults (${DEF_MODULES[*]})."
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

while getopts "k:s:b:z:r:n:e:d:m:pv" opt; do
    case $opt in
        k)
            CONFIG="$OPTARG"
            ;;
        s)
            SHIELD="$OPTARG"
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
            MODULES="$OPTARG"
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

# The operating system used to be a third positional argument. getopts stops at
# the first non-option, so a leftover "MACOS" here would swallow every flag that
# followed it -- including -b -- and the build would quietly use the default
# board and report success. Say so instead.
if [[ $# -gt 0 ]]; then
    echo "Unexpected argument: $1"
    echo
    echo "The operating system argument was removed. Every build targets Linux;"
    echo "macOS lives on the ALT_OS layer, set by os-detection or the toggles layer."
    echo
    usage
fi

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

# Add the default snippets, unless the caller named their own.
if [ ${#SNIPPETS[@]} -eq 0 ]; then
    SNIPPETS=("${DEF_SNIPPETS[@]}")
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
echo "Board: $BOARD"
echo "Verbose: $VERBOSE"
echo "Pristine: $PRISTINE"
echo "ZMK: $ZMK"
echo "Revision: $REVISION"
echo "Snippets: ${SNIPPETS[*]}"
echo "Extra Shields: ${EXTRA_SHIELDS[*]}"
echo "Flags: ${FLAGS[*]}"
echo "Modules: ${MODULES[*]}"

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
    # Download the module if it is not already a usable Zephyr module.
    #
    # The test is for zephyr/module.yml rather than for the directory, because
    # that file is exactly what cmake requires: without it the build fails much
    # later, and far less obviously, with "is not a valid zephyr module".
    # A `git submodule add` that fails part way leaves a directory behind --
    # sometimes empty, sometimes holding only a .git gitlink -- and a mere
    # existence check treats all of those as "already cloned" forever.
    if [[ ! -f "$MODULE_HOME/zephyr/module.yml" ]]
    then
        echo "Add git sub-module: $MODULE"
        # Clear partial state so `git submodule add` gets a clean path. Guarded
        # to stay inside modules/ so a malformed name cannot escape.
        if [[ -d "$MODULE_HOME" && "$MODULE_HOME" == "$PREFIX"*/* ]]; then
            echo "  (clearing incomplete clone at $MODULE_HOME)"
            rm -rf "$MODULE_HOME"
            git submodule deinit -f "modules/$MODULE" 2>/dev/null
            rm -rf "$PROJECT_DIR/.git/modules/modules/$MODULE"
        fi
        git submodule add -f "git@github.com:$MODULE" "modules/$MODULE"
        # If submodule was just added, we need to cd into it to checkout the revision
        # and then return to PROJECT_DIR before the main script proceeds.
        if [ -n "$MODULE_REVISION" ]; then
            echo "Checking out revision $MODULE_REVISION of $MODULE"
            cd "$MODULE_HOME" || exit 1
            git fetch
            git checkout -f "$MODULE_REVISION"
            cd "$PROJECT_DIR" || exit 1
        fi
    else
        # If the module already exists and a revision is specified, check it out
        if [ -n "$MODULE_REVISION" ]; then
            echo "Module $MODULE already exists. Checking out revision $MODULE_REVISION."
            cd "$MODULE_HOME" || exit 1
            git fetch
            git checkout -f "$MODULE_REVISION"
            cd "$PROJECT_DIR" || exit 1
        fi
    fi

    # Prefix the module name with the path
    TEMP+="${MODULE_HOME};"
done
TEMP="${TEMP%;}"
MODULES=$TEMP

# Define zmk module
ZMK_MODULE=modules/$ZMK
ZMK_HOME="$PROJECT_DIR/$ZMK_MODULE"

# Add the sub-module for ZMK
echo "Add git sub-module: $ZMK"
git submodule add -f "git@github.com:$ZMK" "$ZMK_MODULE"

# Clean the ZMK build directory only when asked: every artifact has its own
# build dir under it, and wiping them all on every run made -p meaningless.
if [ -n "$PRISTINE" ]; then
    echo 'Cleaning zmk...'
    rm -rf "$PROJECT_DIR/$ZMK_MODULE/build"
fi

# Check out the ZMK revision
echo 'Checking out zmk...'
cd "$ZMK_HOME" || exit 1
ZMK_WAS="$(git rev-parse HEAD 2>/dev/null || true)"
git fetch --tags --force
git checkout -f "$REVISION"
# Only a branch needs fast-forwarding. A tag or a SHA leaves a detached HEAD,
# where `git pull` fails outright, and is already at the exact revision asked for.
if git symbolic-ref -q HEAD >/dev/null; then
    git pull --ff-only
fi
ZMK_NOW="$(git rev-parse HEAD)"

cd "$PROJECT_DIR" || exit 1

# Init West
if [[ ! -d "$ZMK_HOME/.west" ]]
then
    echo "Initializing West..."
    cd "$ZMK_HOME" || exit 1
    west init -l app/
    west update
    cd "$PROJECT_DIR" || exit 1
elif [[ "$ZMK_WAS" != "$ZMK_NOW" ]]
then
    # ZMK pins its own Zephyr in west.yml, so a revision change that skips this
    # builds the new ZMK against the old Zephyr -- and it fails somewhere far
    # from the cause, if it fails at all.
    echo "ZMK moved ${ZMK_WAS:0:8} -> ${ZMK_NOW:0:8}, updating west modules..."
    cd "$ZMK_HOME" || exit 1
    west update
    cd "$PROJECT_DIR" || exit 1
fi

# Board-only builds (the Zen halves) are named after the config too, since the
# same board is built from more than one config directory.
if [ -z "$CONFIG" ]; then
    ARTIFACT="$BOARD-$SHIELD"
elif [ -z "$SHIELD" ]; then
    ARTIFACT="${CONFIG##*/}-$BOARD"
else
    ARTIFACT="$SHIELD"
fi

ARTIFACT="${ARTIFACT//\/\/zmk/}"

# Build the project
cd "$PROJECT_DIR/$ZMK_MODULE" || exit 1

# Build the west command

command="west build -s app -b \$BOARD "
if [ -n "$PRISTINE" ]; then
    command+=" -p "
fi
# One -S each: "$SNIPPETS" is ${SNIPPETS[0]} in bash, so a comma-separated list
# passed to -n used to reach west as its first element alone.
for snippet in "${SNIPPETS[@]}"; do
    command+=" -S $snippet "
done
command+="--build-dir build/\"\$ARTIFACT\" --"
for flag in "${FLAGS[@]}"; do
    command+=" -D$flag"
done
if [ -n "$SHIELD" ]; then
    command+=" -DSHIELD=\"\$SHIELD ${EXTRA_SHIELDS[*]}\""
fi
if [ -n "$CONFIG" ]; then
    command+=" -DZMK_CONFIG=\"\$PROJECT_DIR/zmk/keyboards/\$CONFIG\""
fi
if [ -n "$MODULES" ]; then
    command+=" -DZMK_EXTRA_MODULES=\"\$MODULES\""
fi

echo "Executing West:"
echo "$command"
echo ""
# A stale artifact from an earlier run looks exactly like a fresh one, so drop
# it before building rather than after.
rm -f "$PROJECT_DIR/build/artifacts/$ARTIFACT-zmk.uf2"
eval "$command"
STATUS=$?

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

# Return to the keyboards directory, and report the build's own status: b.sh
# runs under set -e and used to see a success even when west had failed.
cd "$PROJECT_DIR" || true
exit $STATUS
