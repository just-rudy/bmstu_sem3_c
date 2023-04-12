#include <stdio.h>
#define MAX_SIZE 10
typedef int matrix[MAX_SIZE][MAX_SIZE];

int input_matrix(matrix mat, int rows, int cols);
int make_arr(matrix mat, int rows, int cols, int *arr);
void print_arr(int *arr, int arr_n);

int main()
{
    int status = 0, rows = 0, cols = 0, check = 0;
    matrix mat;
    printf("Input number of rows and number of columns: ");
    check = scanf("%d%d", &rows, &cols);
    if (check != 2 || rows > MAX_SIZE || rows <= 0 || cols > MAX_SIZE || cols <= 0)
    {
        status = 1;
        printf("Size input error");
    }
    else
    {
        status = input_matrix(mat, rows, cols);
        if (status == 0)
        {
            int arr[MAX_SIZE];
            status = make_arr(mat, rows, cols, arr);
            print_arr(arr, cols);
        }
        else
        {
            printf("Matrix input error");
        }
    }
    return status;
}

int input_matrix(matrix mat, int rows, int cols)
{
    int status = 0, check = 0, tmp = 0;
    for (int i = 0; i < rows && !status; i++)
    {
        printf("Input matrix [%d] row's elements: ", i);
        for (int j = 0; j < cols && !status; j++)
        {
            check = scanf("%d", &tmp);
            if (check == 1)
            {
                mat[i][j] = tmp;
                fflush(stdin);
            }
            else
            {
                status = 1;
            }
        }
    }
    return status;
}

int make_arr(matrix mat, int rows, int cols, int *arr)
{
    int status = 0;
    for (int i = 0; i < cols; i++)
    {
        int if_chered = 1, if_last_was_positive = 1;
        if (mat[0][i] < 0)
            if_last_was_positive = 0;

        for (int j = 1; j < rows && if_chered; j++)
        {
            if (!((mat[j][i] < 0 && if_last_was_positive) || (mat[j][i] > 0 && !if_last_was_positive)))
            {
                if_chered = 0;
            }
            if (mat[j][i] < 0)
                if_last_was_positive = 0;
            else
                if_last_was_positive = 1;
        }
        arr[i] = if_chered;
    }
    return status;
}

void print_arr(int *arr, int arr_n)
{
    for (int i = 0; i < arr_n; i++)
    {
        printf("%d ", arr[i]);
    }
}