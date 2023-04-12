#!/bin/bash

inn=$1
out="TMP_output.txt"

#launch=../../app.exe < "$inn" > "$out"


if ../../app.exe < "$inn" > "$out"; then
    #echo Ошибка
    exit 1
else
    #echo Not Ошибка
    exit 0
fi