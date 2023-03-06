#include <stdio.h>
#include <math.h>
#define EPS_FIX 1e-10

double calc_sum(double x, double eps);

int main()
{
    double x, eps;
    int check, status = -1;
    // блок ввода и инициализации переменных
    printf("input x (-1<=x<=1), eps (0<eps<=1): ");
    check = scanf("%lf%lf", &x, &eps);
    if (check != 2 || eps > 1 || eps <= 0 || x > 1 || x < -1)
    {
        printf("input error, try again\n");
    }
    else
    {
        double sm = calc_sum(x, eps), f_x = asin(x);
        double delta_a = fabs(f_x - sm);
        double delta_o = (fabs(f_x) < EPS_FIX) ? 0 : fabs(f_x - sm) / f_x;

        printf("s(x) = %lf , f(x) = %lf\ndelta_abs = %lf , delta_otn = %lf ", sm, f_x, delta_a, delta_o);
        status = 0;
    }
    return status;
}

double calc_sum(double x, double eps)
{
    double sm = 0, curr_f = x; // сумма ряда и текущий член последовательности
    int tmp = 1;
    while (fabs(curr_f) >= eps)
    {
        sm = sm + curr_f;
        curr_f = curr_f * x * x * tmp * tmp / (tmp + 1) / (tmp + 2);
        tmp = tmp + 2;
    }
    return sm;
}