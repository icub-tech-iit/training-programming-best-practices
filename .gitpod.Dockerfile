FROM gitpod/workspace-full-vnc

USER gitpod

# Install custom tools, runtime, etc. using apt-get
# For example, the command below would install "bastet" - a command line tetris clone:
#
RUN sudo apt-get -q update && \
    sudo apt-get install -yq xvfb x11vnc xterm && \
    sudo apt-get install -yq sqlite3 libsqlite3-dev \
    sudo apt-get install libudev-dev
#     sudo rm -rf /var/lib/apt/lists/*
#
# More information: https://www.gitpod.io/docs/config-docker/
