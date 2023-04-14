#include <stdio.h>
#include "consts.h"
#include "input.h"
#include "tasks.h"
#include "output.h"

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
        status = input_matrix(arr, rows, cols);
        if (status == 0)
        {
            status = add_rows(arr, &rows, cols);
            if (status == 0)
                print_arr(arr, rows, cols);
        }
    }
    return status;
}