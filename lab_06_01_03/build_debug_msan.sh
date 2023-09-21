#!/bin/bash

clang *.c -g -O0 -c -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion

clang *.o -o app.exe -fsanitize=memory -lm