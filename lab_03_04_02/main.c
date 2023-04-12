#include <stdio.h>
#define MAX_SIZE 10
typedef int matrix[MAX_SIZE][MAX_SIZE];

int input_array(matrix arr, int rows, int cols);
int look_for_5(matrix arr, int rows, int cols, int *max_num);

int main()
{
    matrix arr;
    int status = 0, rows = 0, cols = 0, check = 0;
    printf("Введите количество строк и столбцов матрицы: ");
    check = scanf("%d%d", &rows, &cols);
    if (check != 2 || rows > MAX_SIZE || rows <= 0 || cols > MAX_SIZE || cols <= 0 || rows != cols)
    {
        printf("Input error");
        status = 1;
    }
    else
    {
        status = input_array(arr, rows, cols);
        if (!status)
        {
            int max_num = 0;
            status = look_for_5(arr, rows, cols, &max_num);
            if (!status)
            {
                printf("Число: %d", max_num);
            }
        }
        else
            printf("Array input error");
    }
    return status;
}

int input_array(matrix arr, int rows, int cols)
{
    int status = 0, check = 0;

    for (int i = 0; i < rows && !status; i++)
    {
        printf("Введите строку матрицы [%d]: ", i);
        for (int j = 0; j < cols && !status; j++)
        {
            int tmp = 0;
            check = scanf("%d", &tmp);
            if (check == 1)
                arr[i][j] = tmp;
            else
                status = 1;
        }
    }

    return status;
}

int look_for_5(matrix arr, int rows, int cols, int *max_num)
{
    int status = 0, max = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = cols - i; j < cols; j++)
        {
            int element = (arr[i][j] < 0) ? arr[i][j] * (-1) : arr[i][j];
            if (element % 10 == 5 && element > max)
                max = arr[i][j];
        }
    }
    status = max ? 0 : 1;
    (*max_num) = max;
    return status;
}