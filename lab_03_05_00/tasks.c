#include <stdio.h>
#include "consts.h"

int check_if_simple(int element);
void swap(int *link1, int *link2);

int check_if_simple(int element)
{
    int if_simple = (element < 2) ? 0 : 1;
    if (element > 2)
        for (int i = 2; i <= element / 2 && if_simple; i++)
            if (element % i == 0)
                if_simple = 0;
    return if_simple;
}

int make_arr(matrix arr, int rows, int cols, int *simple_arr, int *cnt)
{
    int status = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (check_if_simple(arr[i][j]))
            {
                simple_arr[(*cnt)] = arr[i][j];
                (*cnt)++;
            }
        }
    }
    status = (*cnt) ? 0 : 1;
    return status;
}

void swap(int *link1, int *link2)
{
    int tmp = *link1;
    *link1 = *link2;
    *link2 = tmp;
}

void reverse_arr(int *simple_arr, int cnt)
{
    for (int i = 0; i < cnt / 2; i++)
    {
        int *link1 = simple_arr + i;
        int *link2 = simple_arr + cnt - i - 1;
        swap(link1, link2);
    }
}

void full_matrix(matrix arr, int rows, int cols, int *simple_arr)
{
    int *curr_simple_el = simple_arr;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if (check_if_simple(arr[i][j]))
            {
                arr[i][j] = *curr_simple_el;
                curr_simple_el++;
            }
    }
}
