#include <stdio.h>
#include <stdlib.h>

int main() //задача 3 вариант 2
{
    float r1, r2, r3;
    printf("Input R1, R2, R3: ");
    scanf("%f%f%f", &r1, &r2, &r3);

    float r = 1/r1 + 1/r2 + 1/r3;
    float R = round(1/r*1000000)/1000000;
    printf("R: %f ", R);

    return 0;
}
