#include <stdio.h>

int fib(int n)
{
    int num = -1;
    // printf("%d", n);
    if (n == 0)
    {
        num = 0;
    }
    else if (n == 1)
    {
        num = 1;
    }
    else if (n > 1 && n <= 46)
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

int main()
{
    int check, n, status = 0, ans = -1;

    printf("Input integer: ");
    check = scanf("%d", &n);
    if (check != 1)
    {
        status = -1;
    }
    else
    {
        // printf("%d", n);
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