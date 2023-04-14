#include <stdio.h>
#include "consts.h"

int check_column(matrix mat, int rows, int col);

int make_arr(matrix mat, int rows, int cols, int *arr)
{
    int status = 0;
    for (int i = 0; i < cols; i++)
    {
        arr[i] = check_column(mat, rows, i);
    }
    return status;
}

int check_column(matrix mat, int rows, int col)
{
    int if_chered = 1, if_last_was_positive = 1;
    if (rows == 1)
    {
        if_chered = 0;
    }
    else
    {
        if (mat[0][col] < 0)
            if_last_was_positive = 0;
        for (int j = 1; j < rows && if_chered; j++)
        {
            if (!((mat[j][col] < 0 && if_last_was_positive) || (mat[j][col] > 0 && !if_last_was_positive)))
            {
                if_chered = 0;
            }
            if (mat[j][col] < 0)
                if_last_was_positive = 0;
            else
                if_last_was_positive = 1;
        }
    }
    return if_chered;
}