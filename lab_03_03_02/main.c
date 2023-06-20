#include "consts.h"
#include "input.h"
#include "tasks.h"
#include "output.h"

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