#########################################
# UBI8 C++ Dev Container
#########################################
FROM redhat/ubi8

ENV LANG=en_US.UTF-8 \
    LC_ALL=en_US.UTF-8

#############################################
# Non-root user for VS Code
#############################################
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=1000

RUN groupadd --gid ${USER_GID} ${USERNAME} && \
    useradd --uid ${USER_UID} --gid ${USER_GID} -m -s /bin/bash ${USERNAME}

#############################################
# Core build tools
#############################################
RUN yum install -y \
        gcc gcc-c++ make cmake \
        git wget curl tar xz which \
        pkgconfig \
        openssl openssl-devel \
        zlib zlib-devel \
        libcurl libcurl-devel \
        python3 \
        gdb \
    && yum clean all

#############################################
# Python tools
#############################################
RUN python3 -m pip install --no-cache-dir conan

#############################################
# Optional: Protobuf (C++)
#############################################
ARG PROTOBUF_VERSION=v24.4

RUN set -eux; \
    mkdir -p /tmp/build-protobuf && cd /tmp/build-protobuf; \
    git clone --depth 1 -b "${PROTOBUF_VERSION}" https://github.com/protocolbuffers/protobuf.git; \
    cd protobuf; \
    git submodule update --init --recursive; \
    cmake -S . -B build \
        -DCMAKE_BUILD_TYPE=Release \
        -Dprotobuf_BUILD_TESTS=OFF \
        -Dprotobuf_BUILD_SHARED_LIBS=ON; \
    cmake --build build --target install -j"$(nproc)"; \
    ldconfig; \
    rm -rf /tmp/build-protobuf

#############################################
# Workspace
#############################################
WORKDIR /workspace

RUN chown -R ${USERNAME}:${USERNAME} /workspace

USER ${USERNAME}