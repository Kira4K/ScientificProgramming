#!/bin/bash

cd "$(dirname "$0")" || exit 1

echo "Building project..."

g++ -std=c++17 -Wall -Wextra \
    Matrix.cpp Solver.cpp main.cpp \
    -o program

if [ $? -eq 0 ]; then
    echo "Compilation successful!"
    echo "Starting program..."
    ./program
else
    echo "Compilation failed!"
    exit 1
fi
