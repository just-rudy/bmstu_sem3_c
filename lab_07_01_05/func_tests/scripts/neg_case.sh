#!/bin/bash

inn=$1
file_args=$2
out="func_tests/data/TMP_output.txt"

#valgrind -q --track-origins=yes --show-leak-kinds=definite,possible --leak-check=full --show-leak-kinds=all ../../app.exe < "$inn" > $out 2> "valgrind.txt"
#cat "valgrind.txt"
app=../../app.exe

if [  $# -eq 2 ]; then
    arg=$(cat $file_args)
    app="$app $arg"
fi

if $app > "$out"; then
    #echo Ошибка
    exit 1
else
    #echo Not Ошибка
    exit 0
fi