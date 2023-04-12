#include <stdio.h>
#define MAX_SIZE 10
typedef int matrix[MAX_SIZE][MAX_SIZE];

int input_array(matrix arr, int rows, int cols);
int make_arr(matrix arr, int rows, int cols, int *simple_arr, int *cnt);
int check_if_simple(int element);
void reverse_arr(int *simple_arr, int cnt);
void swap(int *link1, int *link2);
void print_arr(matrix arr, int rows, int cols);
void full_matrix(matrix arr, int rows, int cols, int *simple_arr);

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
                reverse_arr(simple_arr, cnt);
                full_matrix(arr, rows, cols, simple_arr);
                print_arr(arr, rows, cols);
            }
            else
            {
                printf("No simple numbers");
                status = 1;
            }
        }
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

int check_if_simple(int element)
{
    int if_simple = (element < 2) ? 0 : 1;
    if (element > 2)
        for (int i = 2; i <= element / 2 && if_simple; i++)
            if (element % i == 0)
                if_simple = 0;
    return if_simple;
}

int make_arr(matrix arr, int rows, int cols, int *simple_arr, int *cnt)
{
    int status = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (check_if_simple(arr[i][j]))
            {
                simple_arr[(*cnt)] = arr[i][j];
                (*cnt)++;
            }
        }
    }
    status = (*cnt) ? 0 : 1;
    return status;
}

void swap(int *link1, int *link2)
{
    int tmp = *link1;
    *link1 = *link2;
    *link2 = tmp;
}

void reverse_arr(int *simple_arr, int cnt)
{
    for (int i = 0; i < cnt / 2; i++)
    {
        int *link1 = simple_arr + i;
        int *link2 = simple_arr + cnt - i - 1;
        swap(link1, link2);
    }
}

void full_matrix(matrix arr, int rows, int cols, int *simple_arr)
{
    int * curr_simple_el = simple_arr;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            if (check_if_simple(arr[i][j]))
            {
                arr[i][j] = *curr_simple_el;
                curr_simple_el++;
            }
    }
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