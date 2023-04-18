#!/bin/bash

file1=$1
file2=$2

regular="^[-+]?[0-9]+([.]{1}[0-9]+)?"

from_f1=grep -e "$regular" "$file1"
from_f2=grep -e "$regular" "$file2"

if [ "$from_f1" -eq "$from_f2" ]; then
    exit 0
else
    exit 1
fi