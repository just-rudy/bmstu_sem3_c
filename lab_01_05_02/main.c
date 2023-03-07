#include <stdio.h>
#define MAX_INT 46

int fib(int n);

int main()
{
    int check = 0, n = 0, status = 0, ans = -1;

    printf("Input integer: ");
    check = scanf("%d", &n);
    if (check != 1)
    {
        status = -1;
    }
    else
    {
        ans = fib(n);
    }

    if (ans == -1)
    {
        printf("Input error");
        status = -1;
    }
    else
    {
        printf("%d", ans);
    }
    return status;
}

int fib(int n)
{
    int num = -1;
    if (n == 0)
    {
        num = 0;
    }
    else if (n == 1)
    {
        num = 1;
    }
    else if (n > 1 && n <= MAX_INT)
    {
        int n0 = 0, n1 = 1;
        for (int i = 2; i <= n; i++)
        {
            int tmp = n0 + n1;
            n0 = n1;
            n1 = tmp;
        }
        num = n1;
    }
    return num;
}