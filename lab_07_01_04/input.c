#include "input.h"

int cnt_elements(FILE *f_in);

void create_array(FILE *f_in, int *arr)
{
    int cnt = cnt_elements(f_in);
}

int cnt_elements(FILE *f_in)
{
    int cnt = 0, num = 0;

    // посчитать количество элементов
    while (fscanf(f_in, "%d", &num) == 1)
        cnt++;
    return cnt;
}
