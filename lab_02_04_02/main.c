#include <stdio.h>
#include <math.h>
#define N 10

int input_arr(int *n, int *arr);
void selection_sort(int n, int *arr);
void print_arr(int n, int *arr);

int main()
{
    int n = 0, status = 0, arr[N];
    status = input_arr(&n, arr);
    if (status == 0)
    {
        selection_sort(n, arr);
    }
    print_arr(n, arr);
    return status;
}

int input_arr(int *n, int *arr)
{
    int status = 0, tmp = 0;
    int check = scanf("%d", &tmp);
    while (check == 1 && *n != N)
    {
        arr[*n] = tmp;
        (*n)++;
        fflush(stdin);
        if (*n != N + 1)
            check = scanf("%d", &tmp);
    }
    if ((*n) == N && check == 1)
    {
        status = 100;
    }
    if ((*n) < 1)
    {
        status = 1;
    }
    return status;
}

void selection_sort(int n, int *arr)
{
    int i_sort = 0, i_mn = 0;
    while (i_sort < n)
    {
        int mn = arr[i_sort];
        i_mn = i_sort;
        for (int i = i_sort; i < n; i++)
        {
            if (arr[i] < mn)
            {
                mn = arr[i];
                i_mn = i;
            }
        }
        int tmp = arr[i_sort];
        arr[i_sort] = arr[i_mn];
        arr[i_mn] = tmp;
        i_sort++;
    }
}

void print_arr(int new_n, int *arr)
{
    for (int i = 0; i < new_n; i++)
    {
        printf("%d ", arr[i]);
    }
}