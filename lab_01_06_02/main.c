#include <stdio.h>
#include <math.h>
#define EPS 1e-10

int check_dot_pos(double xa, double ya, double xb, double yb, double xc, double yc, double xp, double yp);
double if_triangle(double xa, double ya, double xb, double yb, double xc, double yc);

int main()
{
    double xa, ya, xb, yb, xc, yc, xp, yp;
    int check, check1, status = 0, position;
    printf("Input xa, ya, xb, yb, xc, yc: ");
    check = scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);
    printf("Input xp, yp: ");
    check1 = scanf("%lf%lf", &xp, &yp);
    double chek_abc = if_triangle(xa, ya, xb, yb, xc, yc);
    if (check != 6 || check1 != 2 || fabs(chek_abc) < EPS)
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
    double chek_ab = (xa - xp) * (yb - ya) - (xb - xa) * (ya - yp);
    double chek_bc = (xb - xp) * (yc - yb) - (xc - xb) * (yb - yp);
    double chek_ac = (xc - xp) * (ya - yc) - (xa - xc) * (yc - yp);

    if ((chek_ab < 0 && chek_ac < 0 && chek_bc < 0) || (chek_ab > 0 && chek_ac > 0 && chek_bc > 0))
    {
        dot_pos = 0;
    }
    else if ((fabs(chek_ab) < EPS && chek_bc * chek_ac >= 0) || (fabs(chek_ac) < EPS && chek_bc * chek_ab >= 0) || (fabs(chek_bc) < EPS && chek_ab * chek_ac >= 0))
    {
        dot_pos = 1;
    }
    else
    {
        dot_pos = 2;
    }

    return dot_pos;
}


double if_triangle(double xa, double ya, double xb, double yb, double xc, double yc)
{
    double coeff = (xa - xc) * (yb - ya) - (xb - xa) * (ya - yc);
    return coeff;
}