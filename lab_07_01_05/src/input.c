#include "input.h"

int fill_array(FILE *f_in, int **arr_e);

int create_array(FILE *f_in, int **arr_b, int **arr_e, int *cnt)
{
    int status = SUCCESS;
    *cnt = cnt_elements(f_in);
    rewind(f_in);
    (*arr_b) = malloc((*cnt) * sizeof(int));
    if (*arr_b == NULL)
        return MALLOC_ERR;
    (*arr_e) = (*arr_b);
    status = fill_array(f_in, arr_e);
    return status;
}

int cnt_elements(FILE *f_in)
{
    int cnt = 0, num = 0;
    rewind(f_in);
    // посчитать количество элементов
    while (fscanf(f_in, "%d", &num) == 1)
        cnt++;
    return cnt;
}

int fill_array(FILE *f_in, int **arr_e)
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