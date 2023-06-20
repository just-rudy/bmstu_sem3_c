#include "consts.h"
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
        fill_arr(arr, rows, cols);
        print_arr(arr, rows, cols);
    }
    return status;
}