#!/bin/bash

EXE_FILENAME="GalaxyATC"

if [[ ! -d build ]]; then
	mkdir build
fi

cmake -S . -B build -G Ninja
cd build
ninja

if [[ $? -eq 0 ]]; then
	echo -e "Executing\n\n"
	./$EXE_FILENAME
else
	echo "Build failed, terminating..."
fi

