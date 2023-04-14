#include <stdio.h>
#include "consts.h"

int look_for_5(matrix arr, int rows, int cols, int *max_num)
{
    int status = 0, max = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = cols - i; j < cols; j++)
        {
            int element = (arr[i][j] < 0) ? arr[i][j] * (-1) : arr[i][j];
            if (element % 10 == 5 && (arr[i][j] > max || max == 0))
                max = arr[i][j];
        }
    }
    status = max ? 0 : 1;
    (*max_num) = max;
    return status;
}