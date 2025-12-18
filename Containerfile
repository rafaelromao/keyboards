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

# 2. Install yq
RUN wget https://github.com/mikefarah/yq/releases/latest/download/yq_linux_amd64 -O /usr/bin/yq \
    && chmod +x /usr/bin/yq

# 3. Upgrade core Python tools
RUN pip3 install --upgrade pip setuptools wheel

# 4. Install West and Keymap-drawer
RUN pip3 install west keymap-drawer

# 5. Install ZMK/Zephyr Python requirements
RUN git clone --depth 1 https://github.com/zephyrproject-rtos/zephyr.git /tmp/zephyr \
    && pip3 install -r /tmp/zephyr/scripts/requirements.txt \
    && rm -rf /tmp/zephyr

# 6. Install Zephyr SDK 0.16.3
ARG SDK_VERSION=0.16.3
RUN wget -q https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v${SDK_VERSION}/zephyr-sdk-${SDK_VERSION}_linux-x86_64.tar.xz \
    && tar xf zephyr-sdk-${SDK_VERSION}_linux-x86_64.tar.xz -C /opt \
    && rm zephyr-sdk-${SDK_VERSION}_linux-x86_64.tar.xz

WORKDIR /opt/zephyr-sdk-${SDK_VERSION}
RUN ./setup.sh -t arm-zephyr-eabi -c

# 7. Add Aliases to .bashrc
RUN echo "alias build='/workdir/scripts/build.sh'" >> /root/.bashrc && \
    echo "alias b='/workdir/scripts/b.sh'" >> /root/.bashrc && \
    echo "alias draw='/workdir/scripts/draw.sh'" >> /root/.bashrc

# 8. Environment Variables
ENV ZEPHYR_SDK_INSTALL_DIR=/opt/zephyr-sdk-${SDK_VERSION}
ENV PATH="${PATH}:/root/.local/bin"

WORKDIR /workdir
CMD ["/bin/bash"]
