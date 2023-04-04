#include <stdio.h>
#include <math.h>
#define N 10
#define EPS 1e-10

int input_arr(int *arr, int n);
int check_num(int num);
int change_arr(int *arr, int n, int *new_n);
void print_arr(int *arr, int new_n);

int main()
{
    int n = 0, check = 0, status = 0, arr[N];
    check = scanf("%d", &n);
    if (check != 1 || n > N || n < 1)
    {
        status = 1;
    }
    else
    {
        int new_n = n;
        status = input_arr(arr, n);
        if (status == 0)
        {
            status = change_arr(arr, n, &new_n);
            if (status == 0)
            {
                print_arr(arr, new_n);
            }
            else
            {
                printf("array is empty");
            }
        }
        else
        {
            printf("Incorrect input error");
        }
    }
    return status;
}

int input_arr(int *arr, int n)
{
    int status = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0, check = 0;
        check = scanf("%d", &tmp);
        if (check == 1)
        {
            arr[i] = tmp;
        }
        else
        {
            status = 1;
        }
    }
    return status;
}

int check_num(int num)
{
    int if_square = 0;
    if (sqrt((double)num) - (int)sqrt((double)num) <= EPS)
    {
        if_square = 1;
    }
    return if_square;
}

int change_arr(int *arr, int n, int *new_n)
{
    int status = 0, diff = 0, i = 0;
    while (i < n)
    {
        if (check_num(arr[i]))
        {
            diff++;
            (*new_n)--;
        }
        else
        {
            i++;
        }
        if (i + diff < n)
        {
            arr[i] = arr[i + diff];
        }
        else
        {
            i = n;
        }
    }
    if (*new_n == 0)
    {
        status = 1;
    }
    return status;
}

void print_arr(int *arr, int new_n)
{
    for (int i = 0; i < new_n; i++)
    {
        printf("%d ", arr[i]);
    }
}