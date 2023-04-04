#include <stdio.h>
#include <math.h>
#define N 10

int input_arr(int *arr, int *n);
void selection_sort(int *arr, int n);
void swap(int *link1, int *link2);
void print_arr(int *arr, int new_n);

int main()
{
    int n = 0, status = 0, arr[N];
    status = input_arr(arr, &n);
    if (status == 0)
    {
        selection_sort(arr, n);
    }
    print_arr(arr, n);
    return status;
}

int input_arr(int *arr, int *n)
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

void swap(int *link1, int *link2)
{
    int tmp = *link1;
    *link1 = *link2;
    *link2 = tmp;
}

void selection_sort(int *arr, int n)
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
        int *link1 = arr + i_sort;
        int *link2 = arr + i_mn;
        swap(link1, link2);
        i_sort++;
    }
}

void print_arr(int *arr, int new_n)
{
    for (int i = 0; i < new_n; i++)
    {
        printf("%d ", arr[i]);
    }
}