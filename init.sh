#!/bin/bash

# Configuration
IMAGE_NAME="zmk-toolchain:0.17.0"
VOL_CCACHE="zmk-ccache-data"
VOL_MODULES="zmk-modules-cache"
VOL_ZEPHYR="zmk-zephyr-data"

# --- 1. Auto-Build Logic ---
# Only when the tag is missing: after a Containerfile change, rebuild by hand
# with `podman build -t zmk-toolchain:0.17.0 .` (see readme.md).
if ! podman image exists "$IMAGE_NAME"; then
    echo "📦 Image $IMAGE_NAME not found. Building the image now..."
    podman build -t "$IMAGE_NAME" .
fi

# --- 3. Persistent Volumes ---
for vol in $VOL_CCACHE $VOL_MODULES $VOL_ZEPHYR; do
    podman volume inspect $vol >/dev/null 2>&1 || podman volume create $vol
done

# --- 4. Mapping Logic ---
# Agent forwarding is skipped on macOS. podman there runs the container inside a
# Linux VM, and a host unix socket cannot be reached across the shared
# filesystem no matter how it is mounted: podman aborts before the container
# starts with "statfs /var/run/com.apple.launchd.*/Listeners: no such file or
# directory", even though the socket is perfectly valid on the host.
#
# Nothing is lost, because zmk.sh names every module as git@github.com:… and
# the url.insteadOf rewrite below turns that into HTTPS inside the container;
# they are all public repositories, so no credentials are needed. Forwarding is
# still offered on native Linux, where the socket really is reachable, and can
# be forced anywhere with ZMK_FORWARD_SSH_AGENT=1.
SSH_MOUNT=""
if [ "$(uname -s)" = "Darwin" ] && [ "${ZMK_FORWARD_SSH_AGENT:-0}" != "1" ]; then
    echo "🔑 macOS: skipping ssh-agent forwarding (podman runs in a VM); clones use HTTPS."
else
    # -S, not -z: the variable is often set but pointing at a socket that no
    # longer exists, so a value inherited from an older login looks valid but
    # is dead. Only worth healing where the socket will actually be forwarded.
    if [ ! -S "$SSH_AUTH_SOCK" ]; then
        [ -n "$SSH_AUTH_SOCK" ] && echo "🔑 SSH_AUTH_SOCK is stale ($SSH_AUTH_SOCK)."
        echo "🔑 Starting ssh-agent..."
        eval "$(ssh-agent -s)"
        [ -f "$HOME/.ssh/id_ed25519" ] && ssh-add "$HOME/.ssh/id_ed25519"
    fi
    if [ -S "$SSH_AUTH_SOCK" ]; then
        SSH_MOUNT="-v $SSH_AUTH_SOCK:/run/ssh-agent:Z -e SSH_AUTH_SOCK=/run/ssh-agent"
    else
        echo "⚠️  No usable ssh-agent socket; continuing without agent forwarding."
    fi
fi

# The host gitconfig is deliberately NOT mounted. It is written for a much
# newer git than Ubuntu 22.04's 2.34, and an invalid *value* for a known key is
# fatal rather than ignored: merge.conflictstyle=zdiff3 needs git >= 2.35 and
# help.autocorrect=prompt needs >= 2.38. The result was
# "fatal: unknown style 'zdiff3'" on every git invocation, which silently broke
# the submodule clones and left west with no workspace to build in. It also
# pulls in things the container does not have (delta, the gitalias include) and
# pull.rebase, which fights the detached HEAD that submodules normally sit on.
#
# Pass only what a build actually needs, as config env vars (git >= 2.31),
# which take precedence over any file:
#   safe.directory  - /workdir is a bind mount whose ownership git may distrust
#   user.*          - harmless, and avoids surprises if a step ever commits
#   url.insteadOf   - zmk.sh and .gitmodules name modules as git@github.com:…;
#                     without agent forwarding (macOS, see above) those clones
#                     fail with "correct access rights", so rewrite them to
#                     HTTPS inside the container. Public repos need no
#                     credentials; a private module would need a token here.
GIT_ENV=(
    -e GIT_CONFIG_COUNT=4
    -e GIT_CONFIG_KEY_0=safe.directory -e "GIT_CONFIG_VALUE_0=*"
    -e GIT_CONFIG_KEY_1=user.name      -e "GIT_CONFIG_VALUE_1=$(git config user.name || echo 'ZMK Build')"
    -e GIT_CONFIG_KEY_2=user.email     -e "GIT_CONFIG_VALUE_2=$(git config user.email || echo 'zmk@localhost')"
    -e GIT_CONFIG_KEY_3=url.https://github.com/.insteadOf -e "GIT_CONFIG_VALUE_3=git@github.com:"
)

echo "🚀 Starting ZMK Interactive Session..."

# --- 5. Run Container ---
podman run --rm -it \
    --name zmk-dev-session \
    --workdir /workdir \
    -v "$(pwd):/workdir:Z" \
    -v "$VOL_CCACHE:/root/.cache/ccache:Z" \
    -v "$VOL_MODULES:/workdir/modules:Z" \
    -v "$VOL_ZEPHYR:/root/.zephyr:Z" \
    "${GIT_ENV[@]}" \
    $SSH_MOUNT \
    -e CCACHE_DIR=/root/.cache/ccache \
    "$IMAGE_NAME" \
    /bin/bash
