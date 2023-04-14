#include <stdio.h>
#include "consts.h"

void shift_left(matrix arr, int rows, int cols, int curr);
int check_odd_sum(matrix arr, int rows, int cols);

int add_rows(matrix arr, int *rows, int cols)
{
    int status = 0, i = 0, if_was_in = 0;
    while (i < *rows && *rows < MAX_SIZE)
    {
        if (check_odd_sum(arr, i, cols) && (*rows) + 1 <= MAX_SIZE)
        {
            (*rows)++;
            if_was_in = 1;
            i++;
            shift_left(arr, *rows, cols, i);
        }
        i++;
    }
    if ((*rows) + 1 > MAX_SIZE && !if_was_in)
    {
        status = 1;
    }
    return status;
}

void shift_left(matrix arr, int rows, int cols, int curr)
{
    for (int i = rows - 1; i >= curr; i--)
    {
        for (int j = 0; j < cols; j++)
            arr[i][j] = arr[i - 1][j];
    }
    for (int i = 0; i < cols; i++)
    {
        arr[curr - 1][i] = -1;
    }
}

int check_sum(int element)
{
    element = (element < 0) ? element * (-1) : element;
    int sum = 0;
    while (element > 0)
    {
        sum += element % 10;
        element /= 10;
    }
    int status = (sum % 2 == 1) ? 1 : 0;
    return status;
}

int check_odd_sum(matrix arr, int row, int cols)
{
    int cnt = 0;
    for (int j = 0; j < cols; j++)
    {
        if (check_sum(arr[row][j]))
        {
            cnt++;
        }
    }
    cnt = (cnt >= 2) ? 1 : 0;
    return cnt;
}