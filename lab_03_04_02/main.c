#include "consts.h"
#include "input.h"
#include "tasks.h"

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