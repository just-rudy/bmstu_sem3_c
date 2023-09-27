#include "output.h"

void print_array(int *arr_b, int *arr_e)
{
    int *arr_cur = arr_b;
    while (arr_cur < arr_e)
    {
        printf("%d ", *arr_cur);
        arr_cur++;
    }
}