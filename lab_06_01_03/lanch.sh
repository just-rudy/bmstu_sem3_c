#!/bin/bash

gcc -Wall -Werror -Wvla -Wfloat-equal -Wfloat-conversion -std=c99 -Wvla -Wextra -Wpedantic *.c -o app.exe
./app.exe func_tests/data/pos_01_in.txt 1e5