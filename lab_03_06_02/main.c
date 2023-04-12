#include <stdio.h>
#define MAX_SIZE 10
typedef int matrix[MAX_SIZE][MAX_SIZE];

void print_arr(matrix arr, int rows, int cols);
void fill_arr(matrix arr, int rows, int cols);

int main()
{
    int check = 0, status = 0, rows = 0, cols = 0;
    matrix arr;
    printf("Input number of rows and columns: ");
    check = scanf("%d%d", &rows, &cols);
    if (check != 2 || rows > MAX_SIZE || rows <= 0 || cols > MAX_SIZE || cols <= 0)
    {
        printf("Input error");
        status = 1;
    }
    else
    {
        fill_arr(arr, rows, cols);
        print_arr(arr, rows, cols);
    }
    return status;
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

void fill_arr(matrix arr, int rows, int cols)
{
    int num = 1;
    int curr_col = cols-1;
    while (num <= rows*cols)
    {
        for (int i = rows-1; i >= 0 && curr_col >= 0; i--)
        {
            arr[i][curr_col] = num;
            num++;
        }
        curr_col--;

        for (int i = 0; i < rows && curr_col >= 0; i++)
        {
            arr[i][curr_col] = num;
            num++;
        }
        curr_col--;
    }
}