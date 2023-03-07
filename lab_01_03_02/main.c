#include <stdio.h>

double resistance(double r1, double r2, double r3);

int main()
{
    double r1 = 0, r2 = 0, r3 = 0;
    printf("Input R1, R2, R3: ");
    scanf("%f%f%f", &r1, &r2, &r3);

    double r = resistance(r1, r2, r3);
    printf("R: %f ", r);

    return 0;
}

double resistance(double r1, double r2, double r3)
{
    double r_result = 1 / r1 + 1 / r2 + 1 / r3;
    r_result = 1 / r_result;
    return r_result;
}