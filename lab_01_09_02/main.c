#include <stdio.h>
#include <math.h>

int main()
{
    double g_x = 0, x;
    int n = 0, check, status = 0;
    printf("Input x: ");
    check = scanf("%lf", &x);
    while (check == 1 && x >= 0)
    {
        n += 1;
        g_x += sqrt(n + x);
        printf("input next x: ");
        fflush(stdin);
        check = scanf("%lf", &x);
    }
    if (check != 1 || n == 0)
    {
        status = -1;
        printf("Incorrect input!!!");
    }
    else
    {
        g_x /= n;
        printf("%lf", g_x);
    }
    return status;
}