#include <stdio.h>
#define N 10

int input_arr(int n, int *arr);
double cnt_aver(int n, int *arr);

int main()
{
    int n = 0, check = 0, status = 0, arr[10];
    check = scanf("%d", &n);
    if (check != 1 || n > 10 || n <= 0)
    {
        status = 1;
    }

    if (status == 0)
    {
        status = input_arr(n, arr);
        if (status == 0)
        {
            double average = cnt_aver(n, arr);
            if (average != 0)
            {
                printf("%lf", average);
            }
            else
            {
                status = 1;
            }
        }
    }
    return status;
}

int input_arr(int n, int *arr)
{
    int status = 0, check = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        check = scanf("%d", &tmp);
        if (check != 1)
        {
            status = 1;
            break;
        }
        else
        {
            arr[i] = tmp;
        }
    }

    return status;
}

double cnt_aver(int n, int *arr)
{
    int cnt = 0, sm = 0;
    double aver_res = 0;
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
        aver_res = sm*(1.0) / cnt;
    }
    return aver_res;
}