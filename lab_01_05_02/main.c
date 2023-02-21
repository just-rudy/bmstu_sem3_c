#include <stdio.h>
#include <stdlib.h>

int main() //задача 5 вариант 2
{
    int check, n;
    char tmp;

    printf("Input integer: ");

    while (((check = scanf("%d%c", &n, &tmp)) != 2 && check != EOF) || tmp != '\n')
    {
        printf("Error. Input integer again: ");
        do
        {
            check = scanf("%c", &tmp);
        }
        while (check != EOF && tmp != '\n');
    }
    if (n == 0)
    {
        printf("Fib%d = %d", n, 0);
    }
    else if (n == 1)
    {
        printf("Fib%d = %d", n, 1);
    }
    else
    {
        int Fib0 = 0, Fib1 = 1;
        for (int i = 0; i <= n; i++)
        {
            int tmp = Fib0;
            Fib0 = Fib0 + Fib1;
            Fib1 = tmp;
        }
        printf("Fib%d = %d", n, Fib1);
    }
}
