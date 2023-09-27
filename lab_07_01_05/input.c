#include "input.h"

int cnt_elements(FILE *f_in);
int fill_array(FILE *f_in, int ** arr_e);

int create_array(FILE *f_in, int **arr_b, int **arr_e)
{
    int status = SUCCESS;
    int cnt = cnt_elements(f_in);
    rewind(f_in);
    (*arr_b) = malloc(cnt * sizeof(int));
    (*arr_e) = (*arr_b);
    status = fill_array(f_in, arr_e);
    return status;
}

int cnt_elements(FILE *f_in)
{
    int cnt = 0, num = 0;

    // посчитать количество элементов
    while (fscanf(f_in, "%d", &num) == 1)
        cnt++;
    return cnt;
}

int fill_array(FILE *f_in, int ** arr_e)
{
    int tmp = 0;
    int status = SUCCESS;
    if (fscanf(f_in, "%d", &tmp) == 1)
    {
        (**arr_e) = tmp;
        (*arr_e)++;
        while (fscanf(f_in, "%d", &tmp) == 1)
        {
            (**arr_e) = tmp;
            (*arr_e)++;
        }
    }
    else
        status = EMPTY_FILE;
    return status;
}