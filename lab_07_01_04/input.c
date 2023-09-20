#include "input.h"

int cnt_elements(FILE *f_in);
void read_array(int * arr_b, int ** arr_e, int cnt);

void create_array(FILE *f_in, int **arr_b, int **arr_e)
{
    int cnt = cnt_elements(f_in);
    (*arr_b) = malloc(cnt * sizeof(int));
    read_array(*arr_b, arr_e, cnt);
}

int cnt_elements(FILE *f_in)
{
    int cnt = 0, num = 0;

    // посчитать количество элементов
    while (fscanf(f_in, "%d", &num) == 1)
        cnt++;
    return cnt;
}

void read_array(int * arr_b, int ** arr_e, int cnt)
{
    ;
}