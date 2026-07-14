# Use ubuntu image inside the container as its base
FROM ubuntu:24.04

# Avoids interactive prompts during package install
ENV DEBIAN_FRONTEND=noninteractive

# Install packages
# * build-essential has GCC, G++, Make
# * ninja-build for faster builds
# * gbd for debugging
# * valgrind for detection of memory/thread issues
# * clang-tidy for static analysis
RUN apt update && apt install -y \
    build-essential \
    gcc \
    g++ \
    gdb \
    cmake \
    ninja-build \
    git \
    valgrind \
    clang \
    clang-format \
    clang-tidy \
    curl \
    wget \
    vim \
    && rm -rf /var/lib/apt/lists/*

# All commands start here
WORKDIR /workspace

# Default command to starts a shell when the container runs
CMD ["/bin/bash"]