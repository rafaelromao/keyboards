# 0. The QMK AVR toolchain, taken from the official QMK CLI image
#
# That image ships QMK's own toolchains (qmk/qmk_toolchains, avr-gcc 15 today)
# under /opt/qmk, for ARM and RISC-V too, 1.7 GiB in all. Only the AVR part is
# needed here, ~370 MiB, so it is gathered into one directory to copy below.
# It is the same compiler scripts/qmk.sh builds with, which keeps the firmware
# sizes of the two build paths identical; Ubuntu's gcc-avr 5.4 made the XD75
# build some 1.3 KB bigger. The binaries need glibc 2.27 at most, which this
# Ubuntu base has.
FROM ghcr.io/qmk/qmk_cli:latest AS qmk_toolchain
RUN mkdir -p /avr/bin /avr/lib/gcc /avr/libexec/gcc \
    && cp -a /opt/qmk/bin/avr-* /avr/bin/ \
    && cp -a /opt/qmk/avr /avr/ \
    && cp -a /opt/qmk/lib/gcc/avr /avr/lib/gcc/ \
    && cp -a /opt/qmk/lib/bfd-plugins /avr/lib/ \
    && cp -a /opt/qmk/libexec/gcc/avr /avr/libexec/gcc/

FROM ubuntu:22.04

# Prevent interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# 1. Install essential system dependencies
RUN apt-get update && apt-get install -y \
    git cmake ninja-build gperf ccache dfu-util \
    device-tree-compiler wget python3-dev python3-pip \
    python3-setuptools python3-wheel xz-utils file make gcc \
    libsdl2-dev libmagic1 inkscape \
    && rm -rf /var/lib/apt/lists/*

# 2. Install yq, for the host architecture: the image is arm64 on Apple
# Silicon, where an x86_64 yq cannot run and draw.sh fails before it starts.
ARG YQ_VERSION=v4.53.6
RUN case "$(uname -m)" in \
      x86_64)  YQ_ARCH=amd64 ;; \
      aarch64|arm64) YQ_ARCH=arm64 ;; \
      *) echo "No yq build for $(uname -m)" >&2; exit 1 ;; \
    esac \
    && wget -q "https://github.com/mikefarah/yq/releases/download/${YQ_VERSION}/yq_linux_${YQ_ARCH}" -O /usr/bin/yq \
    && chmod +x /usr/bin/yq

# 3. Upgrade core Python tools
RUN pip3 install --upgrade pip setuptools wheel

# 4. Install West and Keymap-drawer, pinned like everything else in the image
RUN pip3 install west==1.5.0 keymap-drawer==0.23.0

# 5. Install ZMK/Zephyr Python requirements
#
# requirements-base.txt, not requirements.txt: the latter also pulls in
# requirements-compliance.txt, whose `reuse` package is fetched straight from
# codeberg.org and fails behind a TLS-inspecting proxy with
# "certificate verify failed: unable to get local issuer certificate".
# Those are licence-compliance tools that a firmware build never uses, and
# requirements-base.txt is what ZMK's own build documentation installs.
# The Zephyr revision is the one ZMK's app/west.yml pins for the ZMK commit in
# scripts/zmk.sh, so the Python requirements match the tree that gets built
# rather than whatever upstream main asks for this week.
RUN git clone --depth 1 --branch v4.1.0+zmk-fixes https://github.com/zmkfirmware/zephyr.git /tmp/zephyr \
    && pip3 install -r /tmp/zephyr/scripts/requirements-base.txt \
    && rm -rf /tmp/zephyr

# 6. Install Zephyr SDK 0.17.0: minimal bundle plus only the ARM toolchain.
#
# The full linux-x86_64 bundle is ~1.6 GiB compressed and carries every
# architecture Zephyr supports. Unpacked it is large enough that committing the
# layer can fail outright, which is what podman's
# "writing blob: ... Digest did not match" means here.
# ZMK targets Cortex-M only (nRF52840, RP2040), and both resolve to
# arm-zephyr-eabi in the SDK's cmake/zephyr/target.cmake.
#
#   minimal bundle  ~43 MiB  +  arm-zephyr-eabi  ~110 MiB  =  ~150 MiB
#
# The toolchain archive unpacks to a top-level arm-zephyr-eabi/ and must land
# inside the SDK directory, which is where the build looks for it:
# ${ZEPHYR_SDK_INSTALL_DIR}/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc.
# Extracting it here rather than letting `setup.sh -t arm-zephyr-eabi` fetch it
# keeps the download out of setup.sh, which skips any toolchain whose directory
# already exists, so `setup.sh -c` is then only registering the CMake package.
#
# setup.sh requires both cmake and wget on PATH (installed in step 1). Note its
# -h flag installs host tools rather than printing help; help is -?.
# The SDK host architecture must match the image, which is not always x86_64:
# on Apple Silicon the container is arm64, and an x86_64 arm-zephyr-eabi-gcc
# there gets handed to qemu, which then fails with
# "qemu-x86_64-static: Could not open '/lib64/ld-linux-x86-64.so.2'" because an
# arm64 image has no x86_64 loader. The release ships the same 28 toolchains
# for linux-aarch64 as for linux-x86_64, so pick by uname rather than hardcode.
ARG SDK_VERSION=0.17.0
RUN set -eu; \
    case "$(uname -m)" in \
      x86_64)  SDK_HOST=linux-x86_64 ;; \
      aarch64|arm64) SDK_HOST=linux-aarch64 ;; \
      *) echo "No Zephyr SDK build for $(uname -m)" >&2; exit 1 ;; \
    esac; \
    base="https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v${SDK_VERSION}"; \
    echo "Installing Zephyr SDK ${SDK_VERSION} for ${SDK_HOST}"; \
    wget -q "${base}/zephyr-sdk-${SDK_VERSION}_${SDK_HOST}_minimal.tar.xz" \
    && tar xf "zephyr-sdk-${SDK_VERSION}_${SDK_HOST}_minimal.tar.xz" -C /opt \
    && rm "zephyr-sdk-${SDK_VERSION}_${SDK_HOST}_minimal.tar.xz" \
    && wget -q "${base}/toolchain_${SDK_HOST}_arm-zephyr-eabi.tar.xz" \
    && tar xf "toolchain_${SDK_HOST}_arm-zephyr-eabi.tar.xz" -C "/opt/zephyr-sdk-${SDK_VERSION}" \
    && rm "toolchain_${SDK_HOST}_arm-zephyr-eabi.tar.xz"

WORKDIR /opt/zephyr-sdk-${SDK_VERSION}
# Actually run the compiler, rather than just testing the executable bit: a
# wrong-architecture binary is executable and still cannot run, which is how
# the x86_64/arm64 mismatch above slipped past image build and only surfaced
# during cmake configuration.
RUN ./setup.sh -c \
    && /opt/zephyr-sdk-${SDK_VERSION}/arm-zephyr-eabi/bin/arm-zephyr-eabi-gcc --version

# 7. Install the QMK toolchain, for the boards that cannot run ZMK
#
# The BM40 and the XD75 are ATmega32U4 boards, so this is the AVR toolchain
# from step 0 plus the qmk CLI. QMK itself is the modules/qmk/qmk_firmware
# submodule, which scripts/qmk-build.sh clones into the modules volume and
# pins. This comes after the Zephyr SDK so that changing it does not download
# the SDK again.
COPY --from=qmk_toolchain /avr /opt/qmk
RUN pip3 install qmk \
    && /opt/qmk/bin/avr-gcc --version \
    && qmk --version

# 8. Add Aliases to .bashrc
RUN echo "alias zmk='/workdir/scripts/zmk.sh'" >> /root/.bashrc && \
    echo "alias b='/workdir/scripts/b.sh'" >> /root/.bashrc && \
    echo "alias draw='/workdir/scripts/draw.sh'" >> /root/.bashrc

# 9. Environment Variables
ENV ZEPHYR_SDK_INSTALL_DIR=/opt/zephyr-sdk-${SDK_VERSION}
ENV PATH="${PATH}:/root/.local/bin:/opt/qmk/bin"

WORKDIR /workdir
CMD ["/bin/bash"]
