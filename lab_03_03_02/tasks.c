#include "tasks.h"

void swap(int *link1, int *link2);
int row_key(matrix arr, int row, int cols);
void swap_rows(matrix arr, int row1, int row2, int cols);

int bubble_sort_rows(matrix arr, int rows, int cols)
{
    int status = 0;
    for (int i = 0; i < rows; i++)
        for (int j = i + 1; j < rows; j++)
        {
            if (row_key(arr, i, cols) > row_key(arr, j, cols) && i != j)
            {
                swap_rows(arr, i, j, cols);
            }
        }

    return status;
}

void swap(int *link1, int *link2)
{
    int tmp = *link1;
    *link1 = *link2;
    *link2 = tmp;
}

int row_key(matrix arr, int row, int cols)
{
    int result = 1;
    for (int i = 0; i < cols; i++)
        result *= arr[row][i];
    return result;
}

void swap_rows(matrix arr, int row1, int row2, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        int *link1 = arr[row1] + i;
        int *link2 = arr[row2] + i;
        swap(link1, link2);
    }
}