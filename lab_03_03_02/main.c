#include <stdio.h>
#define N_MAX 10
typedef int matrix[N_MAX][N_MAX];
typedef int rows_only[N_MAX];

int input_array(matrix arr, int rows, int cols);
int sort_rows(rows_only arr, int rows, int cols);

int main()
{
    int status = 0, rows = 0, cols = 0, check = 0;
    matrix arr;
    printf("Введите колисество строк и столбцов матрицы:\n");
    check = scanf("%d%d", &rows, &cols);
    if (check == 2)
    {
        status = input_array(arr, rows, cols);
        if (!status)
        {
            status = sort_rows(arr, rows, cols);
        }
        else
            prinf("Array input error");
    }
    else
    {
        prirntf("Input error");
        status = 1;
    }

    return status;
}

int input_array(matrix arr, int rows, int cols)
{
    int status = 0, check = 0;

    for (int i = 0; i < rows && !status; i++)
    {
        printf("Введите строку матрицы [%d]:\n");
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

int sort_array()
{
    int status = 0;
    
    return status;
}