#include <stdio.h>
#include <stdlib.h>

int main() //задача 7 вариант 2
// f(x) = arcsin(x) delta_a = |f(x) - s(x)|, delta_o = |f(x)-s(x)|/|f(x)|
{
    float x, eps, f_x = asin(x);
    int check, tmp = 1;
    // блок ввода и инициализации переменных
    do
    {
        printf("input x (-1 <= x <= 1), eps (0 < eps <= 1): ");
        check = scanf("%f%f", &x, &eps);
        fflush(stdin);
        if (check != 2 || eps > 1 || eps <= 0 || x > 1 || x < -1)
        {
            printf("input error, try again\n");
        }
    } while (check != 2 || eps <= 0 || eps > 1 || x > 1 || x < -1);

    float sm = x, curr_f = x; // сумма ряда и текущий член последовательности

    // блок вычислений
    while (abs(curr_f) >= eps)
    {
        curr_f = curr_f * x * x * tmp * tmp / (tmp + 1) / (tmp + 2);
        sm = sm + curr_f;
        tmp = tmp + 2;

    }
    float delta_a = abs(f_x - sm);
    float delta_o = abs(f_x - sm)/f_x;

    printf("s(x) = %f , f(x) = %f\ndelta_abs = %f , delta_otn = %f ", sm, f_x, delta_a, delta_o);

}
