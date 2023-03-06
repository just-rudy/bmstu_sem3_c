#!/bin/bash

input=$1
output_exp=$2
output="output.txt"

program="./main.exe"

$program < $input > $output

comparator="./func_tests/scripts/comparator.sh"

res=$($comparator $output $output_exp)
if [ $res -eq 0 ]; then
    echo Тест пройден
else
    echo Ошибка
fi