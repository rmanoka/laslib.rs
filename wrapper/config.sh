#!/bin/zsh

rm -rf build && mkdir build && cd build
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 "$@" .. || exit 1
cp compile_commands.json ../..
