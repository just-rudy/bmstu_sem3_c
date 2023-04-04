#include <stdio.h>
#define N 10

int input_arr(int *arr, int n);
int cnt_aver(int *arr, int n, double *average);

int main()
{
    int n = 0, check = 0, status = 0, arr[N];
    check = scanf("%d", &n);
    if (check != 1 || n > N || n <= 0)
    {
        status = 1;
    }

    if (status == 0)
    {
        status = input_arr(arr, n);
        if (status == 0)
        {
            double average = 0;
            status = cnt_aver(arr, n, &average);
            if (status != 1)
            {
                printf("%lf", average);
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
        int tmp = 0;
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

int cnt_aver(int *arr, int n, double *average)
{
    int cnt = 0, sm = 0, status = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            cnt++;
            sm += arr[i];
        }
    }
    if (cnt > 0)
    {
        *average = (double)sm / cnt;
        status = 0;
    }
    return status;
}