#include <stdio.h>
#define MAX_SIZE 10
typedef int matrix[MAX_SIZE][MAX_SIZE];

int input_matrix(matrix arr, int rows, int cols);
void shift_left(matrix arr, int rows, int cols, int curr);
int add_rows(matrix arr, int *rows, int cols);
int check_odd_sum(matrix arr, int rows, int cols);
void print_arr(matrix arr, int rows, int cols);

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

int input_matrix(matrix arr, int rows, int cols)
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
                arr[i][j] = tmp;
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

int check_sum(int element)
{
    element = (element < 0) ? element * (-1) : element;
    int sum = 0;
    while (element > 0)
    {
        sum += element % 10;
        element /= 10;
    }
    int status = (sum % 2 == 1) ? 1 : 0;
    return status;
}

int check_odd_sum(matrix arr, int row, int cols)
{
    int cnt = 0;
    for (int j = 0; j < cols; j++)
    {
        if (check_sum(arr[row][j]))
        {
            cnt++;
        }
    }
    cnt = (cnt >= 2) ? 1 : 0;
    return cnt;
}

void shift_left(matrix arr, int rows, int cols, int curr)
{
    for (int i = rows - 1; i >= curr; i--)
    {
        for (int j = 0; j < cols; j++)
            arr[i][j] = arr[i - 1][j];
    }
    for (int i = 0; i < cols; i++)
    {
        arr[curr - 1][i] = -1;
    }
}

int add_rows(matrix arr, int *rows, int cols)
{
    int status = 0, i = 0, if_was_in = 0;
    while (i < *rows && *rows < MAX_SIZE)
    {
        if (check_odd_sum(arr, i, cols) && (*rows) + 1 <= MAX_SIZE)
        {
            (*rows)++;
            if_was_in = 1;
            i++;
            shift_left(arr, *rows, cols, i);
        }
        i++;
    }
    if ((*rows) + 1 > MAX_SIZE && !if_was_in)
    {
        status = 1;
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