#include <stdio.h>

int main()
{
    float r1, r2, r3;
    printf("Input R1, R2, R3: ");
    scanf("%f%f%f", &r1, &r2, &r3);

    float r = 1 / r1 + 1 / r2 + 1 / r3;
    float R = 1 / r;
    printf("R: %f ", R);

    return 0;
}
