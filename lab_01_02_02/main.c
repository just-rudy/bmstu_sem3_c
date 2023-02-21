#include <stdio.h>
#include <stdlib.h>

int main() //задача 2 вариант 2
{
    float xa, ya, xb, yb, xc, yc;
    printf("Input a(x, y): ");
    scanf("%f%f", &xa, &ya);

    printf("Input b(x, y): ");
    scanf("%f%f", &xb, &yb);

    printf("Input c(x, y): ");
    scanf("%f%f", &xc, &yc);

    float ab = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    float ac = sqrt((xa-xc)*(xa-xc) + (ya-yc)*(ya-yc));
    float cb = sqrt((xc-xb)*(xc-xb) + (yc-yb)*(yc-yb));
    float perimetr = ((ab+ac+cb)*1000000)/1000000;
    printf("Perimeter: %f ", ab+ac+cb);

    return 0;
}
