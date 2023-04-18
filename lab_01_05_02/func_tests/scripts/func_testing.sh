#!/bin/bash

err_cnt=0

files="../data/pos_??_in.txt"
for file_in in $files; do
	number=$(echo "$file_in" | grep -o "[0-9]*")
    
    if ! [[ $number =~ ^[0-9]{2}$ ]]; then
        break
    fi

	file_out=func_tests/data/pos_"$number"_out.txt
    
    #echo $file_in
    #echo $file_out

    command="./func_tests/scripts/pos_case.sh $file_in $file_out"
    res=$($command)
    if res;then
        echo "PASS pos test pos_${number}_in.txt"
    else
        echo "FAIL pos test pos_${number}_in.txt"
        err_cnt=$((err_cnt + 1))
    fi
done


files="../data/neg_??_in.txt"
for file_in in $files; do
    number=$(echo "$file_in" | grep -o "[0-9]*")
    
    if ! [[ $number =~ ^[0-9]{2}$ ]]; then
        break
    fi

	#file_out=func_tests/data/pos_"$number"_out.txt
    
    #echo $file_in
    #echo $file_out

    command="./func_tests/scripts/pos_case.sh $file_in $file_out"
    res=$($command)
    if res; then
        echo "PASS neg test pos_${number}_in.txt"
    else
        echo "FAIL neg test pos_${number}_in.txt"
        err_cnt=$((err_cnt + 1))
    fi
done

exit $err_cnt