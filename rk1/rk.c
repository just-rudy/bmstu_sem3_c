#include <stdio.h>
#define MAX_SIZE 10

void input_arr(int arr[MAX_SIZE][MAX_SIZE], int n);
int check_mistakes(int arr[MAX_SIZE][MAX_SIZE], int n);
void output_arr(int arr[MAX_SIZE][MAX_SIZE], int n);

int main()
{
    int check = 0, n = 0, status = 0, cnt_mistakes = 0;
    int arr[MAX_SIZE][MAX_SIZE];
    printf("input n: ");
    check = scanf("%d", &n);
    if (check == 1 && n < MAX_SIZE && n > 0)
    {
        input_arr(arr, n);
        cnt_mistakes = check_mistakes(arr, n);
        if (cnt_mistakes)
            printf("\nFAIL\nmistakes: %d\n\n", cnt_mistakes);
        else
            printf("\nSUCCESS\n\n");
        output_arr(arr, n);
    }
    else
    {
        status = 1;
        printf("input error");
    }
    return status;
}

void input_arr(int arr[MAX_SIZE][MAX_SIZE], int n)
{
    int status = 0;
    for (int i = 0; i < n && status == 0; i++)
    {
        printf("input arr row: ");
        for (int j = 0; j < n && status == 0; j++)
        {
            int tmp = 0;
            scanf("%d", &tmp);
            arr[i][j] = tmp;
        }
    }
}

int check_mistakes(int arr[MAX_SIZE][MAX_SIZE], int n)
{
    int mistakes = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                if (i+1 < n && j + i < n && arr[i+1][j+1] != 0)
                {
                    mistakes += 1;
                    //printf("[i, j] = [%d, %d] diag down \n", i, j);
                }
                if (i - 1 >= 0 && j + 1 < n && arr[i-1][j+1] != 0)
                {
                    mistakes += 1;
                    //printf("[i, j] = [%d, %d] diag up   \n", i, j);
                }
                if (arr[i][j] != 0 && j + 1 < n && arr[i][j + 1] != 0 && arr[i][j] != arr[i][j + 1])
                {
                    if ((i == 0 || (i - 1 >= 0 && arr[i - 1][j] != arr[i][j] && arr[i - 1][j + 1] != arr[i][j + 1])))
                    {
                        if ((i == n - 1 || (i + 1 < n && arr[i + 1][j] != arr[i][j] && arr[i + 1][j + 1] != arr[i][j + 1])))
                        {
                            mistakes += 1;
                            //printf("[i, j] = [%d, %d] side hor \n", i, j);
                        }
                    }
                }
                
                if (arr[i][j] != 0 && i + 1 < n && arr[i + 1][j] != 0 && arr[i][j] != arr[i + 1][j])
                {
                    if ((j == 0 || (j - 1 >= 0 && arr[i][j - 1] != arr[i][j] && arr[i + 1][j - 1] != arr[i + 1][j])))
                    {    
                        if ((j == n - 1 || (j + 1 < n && arr[i][j + 1] != arr[i][j] && arr[i + 1][j + 1] != arr[i + 1][j])))
                        {
                            mistakes += 1;
                            //printf("[i, j] = [%d, %d] side vert \n", i, j);
                        }
                    }
                }
            }
        }
    }
    return mistakes;
}

void output_arr(int arr[MAX_SIZE][MAX_SIZE], int n)
{
    printf("Array: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
