#!/bin/bash

exec 3<"$1"
exec 4<"$2"

array1=()
array2=()
same=true
while true; do
  if [ ${#array1[*]} -eq 0 ]; then
    while read -r sfile1 <&3 || [ -n "$sfile1" ]; do
      sfile1=$(echo "$sfile1" | tr -s '\r\n' ' ')
      for word in $sfile1; do
        if [[ $word =~ ^[-+]?[0-9]+([.]{1}[0-9]+)?$ ]]; then
          array1+=("$word")
        fi
      done
      if [ ${#array1[*]} -ne 0 ]; then
        break
      fi
    done
  fi

  if [ ${#array2[*]} -eq 0 ]; then
    while read -r sfile2 <&4 || [ -n "$sfile2" ]; do
      sfile2=$(echo "$sfile2" | tr -s '\r\n' ' ')
      for word in $sfile2; do
        if [[ $word =~ ^[-+]?[0-9]+([.]{1}[0-9]+)?$ ]]; then
          array2+=("$word")
        fi
      done
      if [ ${#array2[*]} -ne 0 ]; then
        break
      fi
    done
  fi

  if ([ ${#array1[*]} -eq 0 ] && [ ${#array2[*]} -ne 0 ]) || ([ ${#array1[*]} -ne 0 ] && [ ${#array2[*]} -eq 0 ]); then
    same=false
    break
  fi
  while [ ${#array1[*]} -ne 0 ] && [ ${#array2[*]} -ne 0 ]; do
    if [ ${array1[0]} -eq ${array2[0]} ]; then
      array1=("${array1[@]:1}")
      array2=("${array2[@]:1}")
    else
      same=false
      break 2
    fi
  done
  if [ -z "$sfile1" ] && [ -z "$sfile2" ]; then
    break
  fi
done

if $same; then
  exit 0
else
  exit 1
fi