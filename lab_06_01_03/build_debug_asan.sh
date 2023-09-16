#!/bin/bash

gcc *.c -g -O0 -c -std=c99 -lm -Wall -Werror -Wfloat-equal -Wfloat-conversion

gcc *.o -o app.exe -fsanitize=address -fno-omit-frame-pointer -lm