#include <stdio.h>
#define MAX_SIZE 10
typedef int matrix[MAX_SIZE][MAX_SIZE];

int input_array(matrix arr, int rows, int cols);
void swap(int *link1, int *link2);
int bubble_sort_rows(matrix arr, int rows, int cols);
int row_key(matrix arr, int row, int cols);
void print_arr(matrix arr, int rows, int cols);

int main()
{
    int status = 0, rows = 0, cols = 0, check = 0;
    matrix arr;
    printf("Введите количество строк и столбцов матрицы: ");
    check = scanf("%d%d", &rows, &cols);
    if (check != 2 || rows > MAX_SIZE || rows <= 0 || cols > MAX_SIZE || cols <= 0)

    {
        printf("Input error");
        status = 1;
    }
    else
    {
        status = input_array(arr, rows, cols);
        if (!status)
        {
            status = bubble_sort_rows(arr, rows, cols);
            if (!status)
            {
                print_arr(arr, rows, cols);
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

void swap(int *link1, int *link2)
{
    int tmp = *link1;
    *link1 = *link2;
    *link2 = tmp;
}

void print_arr(matrix arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int row_key(matrix arr, int row, int cols)
{
    int result = 1;
    for (int i = 0; i < cols; i++)
        result *= arr[row][i];
    return result;
}

void swap_rows(matrix arr, int row1, int row2, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        int *link1 = arr[row1] + i;
        int *link2 = arr[row2] + i;
        swap(link1, link2);
    }
}

int bubble_sort_rows(matrix arr, int rows, int cols)
{
    int status = 0;
    for (int i = 0; i < rows; i++)
        for (int j = i + 1; j < rows; j++)
        {
            if (row_key(arr, i, cols) > row_key(arr, j, cols) && i != j)
            {
                swap_rows(arr, i, j, cols);
            }
        }

    return status;
}