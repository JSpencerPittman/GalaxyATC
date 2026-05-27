#!/bin/bash

clear
mkdir -p build
g++ src/main_graphics.c -o build/main_graphics
./build/main_graphics