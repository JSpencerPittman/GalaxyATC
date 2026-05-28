#!/bin/bash

EXE_FILENAME="GalaxyATC"

if [[ ! -d build ]]; then
	mkdir build
fi

cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=$1
cd build
ninja
