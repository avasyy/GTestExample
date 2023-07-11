#!/bin/bash

# Remove build folder
rm -r build/

# Create clear build folder and go inside
mkdir build && cd build

# Use cmake to create Makefile
cmake ..

# Use make to build executables
make