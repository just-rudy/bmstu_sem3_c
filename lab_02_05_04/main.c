#include <stdio.h>
#include <math.h>
#define N 10
#define EPS 1e-10

int input_arr(int *beginning, int *ending);
int calc_uniq_numbers(int *beginning, int *ending, int *arr);
void print_arr(int *beginning, int *ending);

int main()
{
    int n = 0, status = 0, arr[N];
    int check = scanf("%d", &n);
    if (check != 1 || n < 1 || n > 10)
    {
        status = 1;
        printf("Incorrect input error");
    }
    else
    {
        int *beginning = arr, *ending = arr + n;
        int cnt = 0;
        status = input_arr(beginning, ending);
        if (status == 0)
        {
            cnt = calc_uniq_numbers(beginning, ending, arr);
        }
        printf("%d", cnt);
    }
    return status;
}

int input_arr(int *beginning, int *ending)
{
    int status = 0, check = 0;
    int *current = beginning;
    while (current < ending)
    {
        check = scanf("%d", current);
        if (check != 1)
        {
            status = 1;
            printf("Incorrect input error");
        }
        current++;
    }
    return status;
}

int calc_uniq_numbers(int *beginning, int *ending, int *arr)
{
    int cnt = 0;
    int *current = beginning;
    while (current < ending)
    {
        int is_uniq = 1;
        int *current_layer2 = beginning;
        while (current_layer2 < ending && is_uniq)
        {
            if (current_layer2 != current && *current == *current_layer2)
            {
                is_uniq = 0;
                break;
            }
            current_layer2++;
        }
        if (is_uniq)
        {
            cnt++;
        }
        current++;
    }
    return cnt;
}

void print_arr(int *beginning, int *ending)
{
    int *current = beginning;
    while (current < ending)
    {
        printf("%d ", *current);
        current++;
    }
}