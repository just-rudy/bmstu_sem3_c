#!/bin/bash

inn=$1
out="TMP_output.txt"

program="../../app.exe"

launch=$program < "$inn" > $out

comparator="./comparator.sh"

if $launch; then
    exit 1
    echo Ошибка
else
    exit 0
    echo Not Ошибка
fi