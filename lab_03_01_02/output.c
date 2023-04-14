#include <stdio.h>
#include "consts.h"

void print_arr(int *arr, int arr_n)
{
    for (int i = 0; i < arr_n; i++)
    {
        printf("%d ", arr[i]);
    }
}