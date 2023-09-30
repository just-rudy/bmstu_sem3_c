#include "output.h"

void print_array(int *arr_b, int *arr_e, FILE *f_out)
{
    int *arr_cur = arr_b;
    while (arr_cur < arr_e)
    {
        fprintf(f_out, "%d ", *arr_cur);
        // printf("%d ", *arr_cur);
        arr_cur++;
    }
}