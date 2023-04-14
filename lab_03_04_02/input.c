#include <stdio.h>
#include "consts.h"

int input_array(matrix arr, int rows, int cols)
{
    int status = 0, check = 0;

    for (int i = 0; i < rows && !status; i++)
    {
        printf("Введите строку матрицы [%d]: ", i);
        for (int j = 0; j < cols && !status; j++)
        {
            int tmp = 0;
            check = scanf("%d", &tmp);
            if (check == 1)
                arr[i][j] = tmp;
            else
                status = 1;
        }
    }
    return status;
}
