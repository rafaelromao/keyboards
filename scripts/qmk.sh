#!/bin/bash
#
# QMK counterpart of init.sh. Runs the official QMK CLI container with this
# repo mounted at /workdir and the same named volume the ZMK toolchain uses
# mounted over /workdir/modules, so modules/qmk/qmk_firmware lives next to
# modules/zmkfirmware/zmk inside that volume and never touches the host tree
# (modules/ is gitignored on the host for the same reason).
#
#   scripts/qmk.sh              interactive shell in the container
#   scripts/qmk.sh bm40         build the BM40 (kprepublic/bm40hsrgb/rev1)
#   scripts/qmk.sh xd75         build the XD75 (xiudi/xd75)
#   scripts/qmk.sh all [-p]     build both; -p is a pristine (clean) build
#
# The build itself is scripts/qmk-build.sh, which runs inside the container.

set -euo pipefail

IMAGE_NAME="ghcr.io/qmk/qmk_cli:latest"
VOL_MODULES="zmk-modules-cache"
PROJECT_DIR="$(cd "$(dirname "$0")/.." && pwd)"

# --- 1. Image ---
if ! podman image exists "$IMAGE_NAME"; then
    echo "📦 Image $IMAGE_NAME not found. Pulling it now..."
    podman pull "$IMAGE_NAME"
fi

# --- 2. Persistent modules volume (shared with init.sh) ---
podman volume inspect "$VOL_MODULES" >/dev/null 2>&1 || podman volume create "$VOL_MODULES"

# --- 3. Git settings the container needs ---
# Same reasoning as init.sh: the host gitconfig is not mounted, only what a
# build needs is passed as config env vars. safe.directory because /workdir is
# a bind mount whose ownership git may distrust; user.* to avoid surprises if a
# step ever commits; the insteadOf rewrite because there is no ssh-agent in the
# container and every repo involved is public.
GIT_ENV=(
    -e GIT_CONFIG_COUNT=4
    -e GIT_CONFIG_KEY_0=safe.directory -e "GIT_CONFIG_VALUE_0=*"
    -e GIT_CONFIG_KEY_1=user.name      -e "GIT_CONFIG_VALUE_1=$(git config user.name || echo 'QMK Build')"
    -e GIT_CONFIG_KEY_2=user.email     -e "GIT_CONFIG_VALUE_2=$(git config user.email || echo 'qmk@localhost')"
    -e GIT_CONFIG_KEY_3=url.https://github.com/.insteadOf -e "GIT_CONFIG_VALUE_3=git@github.com:"
)

TTY_FLAGS=()
if [ -t 0 ]; then
    TTY_FLAGS=(-it)
fi

# --- 4. Run ---
if [[ $# -eq 0 ]]; then
    echo "🚀 Starting QMK interactive session..."
    exec podman run --rm "${TTY_FLAGS[@]}" \
        --name qmk-dev-session \
        --workdir /workdir \
        -v "$PROJECT_DIR:/workdir:Z" \
        -v "$VOL_MODULES:/workdir/modules:Z" \
        "${GIT_ENV[@]}" \
        "$IMAGE_NAME" \
        /bin/bash
fi

exec podman run --rm "${TTY_FLAGS[@]}" \
    --name qmk-build-session \
    --workdir /workdir \
    -v "$PROJECT_DIR:/workdir:Z" \
    -v "$VOL_MODULES:/workdir/modules:Z" \
    "${GIT_ENV[@]}" \
    "$IMAGE_NAME" \
    /bin/bash /workdir/scripts/qmk-build.sh "$@"
