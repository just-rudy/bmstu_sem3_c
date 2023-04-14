#include <stdio.h>
#include "consts.h"

void fill_arr(matrix arr, int rows, int cols)
{
    int num = 1;
    int curr_col = cols - 1;
    while (num <= rows * cols)
    {
        for (int i = rows - 1; i >= 0 && curr_col >= 0; i--)
        {
            arr[i][curr_col] = num;
            num++;
        }
        curr_col--;

        for (int i = 0; i < rows && curr_col >= 0; i++)
        {
            arr[i][curr_col] = num;
            num++;
        }
        curr_col--;
    }
}