#!/bin/bash
set -e
cmake -S . -B build  -DCMAKE_BUILD_TYPE=Debug
cmake --build build --target picix
cd build && make
set_color green
echo searching for pico 
while [ ! -e /Volumes/RPI-RP2 ]; do; sleep 1; done
cp picix.uf2 /Volumes/RPI-RP2/
cd ..
