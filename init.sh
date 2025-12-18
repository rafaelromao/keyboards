#!/bin/bash

# Configuration
IMAGE_NAME="zmk-toolchain:0.16.3"
VOL_CCACHE="zmk-ccache-data"
VOL_MODULES="zmk-modules-cache"
VOL_ZEPHYR="zmk-zephyr-data"

# --- 1. Auto-Build Logic ---
if ! podman image exists "$IMAGE_NAME"; then
    echo "📦 Image $IMAGE_NAME not found. Building the image now..."
    podman build -t "$IMAGE_NAME" .
fi

# --- 2. SSH Agent Self-Heal ---
if [ -z "$SSH_AUTH_SOCK" ]; then
    echo "🔑 SSH_AUTH_SOCK not found. Starting ssh-agent..."
    eval "$(ssh-agent -s)"
    [ -f "$HOME/.ssh/id_ed25519" ] && ssh-add "$HOME/.ssh/id_ed25519"
fi

# --- 3. Persistent Volumes ---
for vol in $VOL_CCACHE $VOL_MODULES $VOL_ZEPHYR; do
    podman volume inspect $vol >/dev/null 2>&1 || podman volume create $vol
done

# --- 4. Mapping Logic ---
SSH_MOUNT=""
[ -n "$SSH_AUTH_SOCK" ] && SSH_MOUNT="-v $SSH_AUTH_SOCK:/run/ssh-agent:Z -e SSH_AUTH_SOCK=/run/ssh-agent"

GIT_MOUNT=""
HOST_GIT_CONFIG="$HOME/.config/git/config"
if [ -f "$HOST_GIT_CONFIG" ]; then
    GIT_MOUNT="-v $HOST_GIT_CONFIG:/root/.gitconfig:Z"
elif [ -f "$HOME/.gitconfig" ]; then
    GIT_MOUNT="-v $HOME/.gitconfig:/root/.gitconfig:Z"
fi

echo "🚀 Starting ZMK Interactive Session..."

# --- 5. Run Container ---
podman run --rm -it \
    --name zmk-dev-session \
    --workdir /workdir \
    -v "$(pwd):/workdir:Z" \
    -v "$VOL_CCACHE:/root/.cache/ccache:Z" \
    -v "$VOL_MODULES:/workdir/modules:Z" \
    -v "$VOL_ZEPHYR:/root/.zephyr:Z" \
    $GIT_MOUNT \
    $SSH_MOUNT \
    -e CCACHE_DIR=/root/.cache/ccache \
    "$IMAGE_NAME" \
    /bin/bash
