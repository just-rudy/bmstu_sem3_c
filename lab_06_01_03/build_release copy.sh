#!/bin/bash

gcc *.c -c -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion --coverage -Wpedantic

gcc *.o -o app.exe -lm --coverage