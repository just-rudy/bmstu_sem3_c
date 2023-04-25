#include <stdio.h>
#define MAX_SIZE 10

int input_arr(int arr[MAX_SIZE][MAX_SIZE], int n);
void output_arr(int arr[MAX_SIZE][MAX_SIZE], int n);

int main()
{
    int check = 0, n = 0, status = 0;
    int arr[MAX_SIZE][MAX_SIZE];
    check = scanf("%d", &n);
    if (check == 1 && n < MAX_SIZE && n > 0)
    {
        status = input_arr(arr, n);
        output_arr(arr, n);
    }
    else
    {
        status = 1;
        printf("input error");
    }
    return status;
}

int input_arr(int arr[MAX_SIZE][MAX_SIZE], int n)
{
    int status = 0;
    for (int i = 0; i < n && status == 0; i++)
    {
        printf("input arr row: ");
        for (int j = 0; j < n && status == 0; j++)
        {
            int tmp = 0;
            scanf("%d", &tmp);
            arr[i][j] = tmp;
        }
    }
    return status;
}

void output_arr(int arr[MAX_SIZE][MAX_SIZE], int n)
{
    printf("Array: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
