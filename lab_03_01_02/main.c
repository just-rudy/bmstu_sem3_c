#include "consts.h"
#include "input.h"
#include "tasks.h"
#include "output.h"

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