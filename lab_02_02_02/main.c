#include <stdio.h>
#define N 10

int input_arr(int *arr, int n);
int make_arr(int *arr, int n, int *new_arr, int *new_n);
void print_arr(int *new_arr, int new_n);

int main()
{
    int n = 0, new_n = 0, check = 0, status = 0, arr[N], new_arr[N];
    check = scanf("%d", &n);
    if (check != 1 || n > N || n <= 0)
    {
        status = 1;
    }
    else
    {
        status = input_arr(arr, n);
        if (status == 1)
        {
            printf("Incorrect input error");
        }
        else
        {
            status = make_arr(arr, n, new_arr, &new_n);
            if (status == 0)
            {
                print_arr(new_arr, new_n);
            }
            else
            {
                printf("new array is empty");
            }
        }
    }
    return status;
}

int input_arr(int *arr, int n)
{
    int status = 0, check = 0;
    for (int i = 0; i < n && !status; i++)
    {
        int tmp;
        check = scanf("%d", &tmp);
        if (check != 1)
        {
            status = 1;
        }
        else
        {
            arr[i] = tmp;
        }
    }
    return status;
}

int make_arr(int *arr, int n, int *new_arr, int *new_n)
{
    int status = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = arr[i];
        if (tmp < 0)
        {
            tmp *= -1;
        }
        int end = tmp % 10;
        while (tmp >= 10)
        {
            tmp /= 10;
        }
        int begin = tmp % 10;
        if (begin == end)
        {
            new_arr[*new_n] = arr[i];
            (*new_n)++;
        }
    }
    if (*new_n == 0)
    {
        status = 1;
    }
    return status;
}

void print_arr(int *new_arr, int new_n)
{
    for (int i = 0; i < new_n; i++)
    {
        printf("%d ", new_arr[i]);
    }
}
