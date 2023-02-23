#include <stdio.h>

void printing(unsigned int a, int n, int status);

int main()
{
    unsigned int a;
    int n, status = 0;

    printf("Input a, n: ");
    int check = scanf("%u%d", &a, &n);

    if (check != 2 || n < 0)
    {
        status = -1;
    }
    printing(a, n, status);
    return status;
}

void printing(unsigned int a, int n, int status)
{
    if (status == 0)
    {
        unsigned int ans = a << n | a >> (32 - n);
        int cnt = 32;
        printf("Result: ");
        while (cnt > 0)
        {
            unsigned int tmp = ans >> 31;
            printf("%u", tmp);
            ans <<= 1;
            cnt--;
        }
    }
    else
    {
        printf("Error: input error");
    }
}