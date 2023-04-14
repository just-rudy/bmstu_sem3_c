#include <stdio.h>
#include "consts.h"

int input_matrix(matrix mat, int rows, int cols)
{
    int status = 0, check = 0, tmp = 0;
    for (int i = 0; i < rows && !status; i++)
    {
        printf("Input matrix [%d] row's elements: ", i);
        for (int j = 0; j < cols && !status; j++)
        {
            check = scanf("%d", &tmp);
            if (check == 1)
            {
                mat[i][j] = tmp;
                fflush(stdin);
            }
            else
            {
                status = 1;
            }
        }
    }
    return status;
}