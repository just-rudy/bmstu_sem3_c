#include "consts.h"
#include "input.h"
#include "tasks.h"
#include "output.h"

int main()
{
    matrix arr;
    int status = 0, rows = 0, cols = 0, check = 0;
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
            int simple_arr[MAX_SIZE * MAX_SIZE];
            int cnt = 0;
            status = make_arr(arr, rows, cols, simple_arr, &cnt);
            if (status == 0)
            {
                printf("No simple numbers");
                status = 1;
            }
        }
    }
    return status;
}