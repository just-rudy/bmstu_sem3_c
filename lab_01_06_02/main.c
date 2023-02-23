#include <stdio.h>
#include <math.h>

int check_dot_pos(double xa, double ya, double xb, double yb, double xc, double yc, double xp, double yp);

int main()
{
    double xa, ya, xb, yb, xc, yc, xp, yp;
    int check, check1, status = 0, position;
    printf("Input xa, ya, xb, yb, xc, yc: ");
    check = scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);
    printf("Input xp, yp: ");
    check1 = scanf("%lf%lf", &xp, &yp);
    double chekABC = (xa - xc) * (yb - ya) - (xb - xa) * (ya - yc);
    if (check != 6 || check1 != 2 || fabs(chekABC) < 1e-10)
    {
        status = -1;
    }
    else
    {
        position = check_dot_pos(xa, ya, xb, yb, xc, yc, xp, yp);
    }

    if (status == 0)
    {
        printf("%d", position);
    }
    else
    {
        printf("Input error");
    }
    return status;
}

int check_dot_pos(double xa, double ya, double xb, double yb, double xc, double yc, double xp, double yp)
{
    int dot_pos = -1;
    double chekAB = (xa - xp) * (yb - ya) - (xb - xa) * (ya - yp);
    double chekBC = (xb - xp) * (yc - yb) - (xc - xb) * (yb - yp);
    double chekAC = (xc - xp) * (ya - yc) - (xa - xc) * (yc - yp);
    double eps = 1e-10;

    if ((chekAB < 0 && chekAC < 0 && chekBC < 0)||(chekAB > 0 && chekAC > 0 && chekBC > 0))
    {
        dot_pos = 0;
    }
    else if ((fabs(chekAB) < eps && chekBC * chekAC >= 0) || (fabs(chekAC) < eps && chekBC * chekAB >= 0) || (fabs(chekBC) < eps && chekAB * chekAC >= 0))
    {
        dot_pos = 1;
    }
    else
    {
        dot_pos = 2;
    }

    return dot_pos;
}