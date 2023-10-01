#!/bin/bash

out_expect=$1
file_args=$2
out="TMP_output.txt"

# arg=$(cat $file_args)
app=./app.exe
if [ -f "file_args" ]; then
    app = "$app $(cat "$file_args")"

#valgrind -q --track-origins=yes --show-leak-kinds=definite,possible --leak-check=full --show-leak-kinds=all ../../app.exe "$arg" > $out 2> "valgrind.txt"
#cat "valgrind.txt"
#echo heeeere
#echo $arg

if app > "$out"; then
    if bash func_tests/scripts/comparator.sh "$out" "$out_expect"; then
        #echo Тест пройден
        exit 0
    else
        #echo Ошибка
        exit 1
    fi
else
    #echo Ошибка
    exit 1
fi