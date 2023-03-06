#include <stdio.h>
#include <math.h>

double perimeter(double xa, double ya, double xb, double yb, double xc, double yc);

int main()
{
    double xa, ya, xb, yb, xc, yc;
    printf("Input a(x, y): ");
    scanf("%lf%lf", &xa, &ya);

    printf("Input b(x, y): ");
    scanf("%lf%lf", &xb, &yb);

    printf("Input c(x, y): ");
    scanf("%lf%lf", &xc, &yc);

    double p = perimeter(xa, ya, xb, yb, xc, yc);
    printf("Perimeter: %lf ", p);

    return 0;
}

double perimeter(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double ab = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    double ac = sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    double cb = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb));
    double p = ab + ac + cb;
    return p;
}
