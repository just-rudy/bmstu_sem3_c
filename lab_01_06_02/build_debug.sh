#!/bin/bash

gcc main.c -g -O0 -c -std=c99 -lm -Wall -Werror -Wfloat-equal -Wfloat-conversion -ftest-coverage

gcc main.o -o app.exe -lm -ftest-coverage