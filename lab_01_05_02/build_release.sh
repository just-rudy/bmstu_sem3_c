#!/bin/bash

gcc main.c -c -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion

gcc main.o -o app.exe -lm