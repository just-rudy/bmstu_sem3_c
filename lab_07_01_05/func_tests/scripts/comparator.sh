#!/bin/bash

file1=$1
file2=$2

#from_f1=$(< $file1 grep -oz 'Result: .*' | sed 's/\x00//g')
#from_f2=$(< $file2 grep -oz 'Result: .*' | sed 's/\x00//g')

from_f1=$(< $file1)
from_f2=$(< $file2)

# cat file1
# echo 1

if [ "$from_f1" == "$from_f2" ]; then
    exit 0
else
    exit 1
fi