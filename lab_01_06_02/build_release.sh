#!/bin/bash

gcc main.c -c -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -fprofile-arcs -ftest-coverage

gcc main.o -o app.exe -ftest-coverage -fprofile-arcs -lm