#include <stdio.h>
#include <stdlib.h>

int main() //задача 6 вариант 2
{
    float xa, ya, xb, yb, xc, yc, xp, yp; // объявление координат
    int check; // для проверки количества успешно введенных переменных
    // ввод координат вершин треугольника
    do
    {
        printf("input xa, ya, xb, yb, xc, yc: ");
        check = scanf("%f%f%f%f%f%f", &xa, &ya, &xb, &yb, &xc, &yc);
        fflush(stdin);
        if (check != 6)
        {
            printf("input error, try again\n");
        }
    } while (check != 6);
    // ввод координат точки P
    do
    {
        printf("input xp, yp: ");
        check = scanf("%f%f", &xp, &yp);
        fflush(stdin);
        if (check != 2)
        {
            printf("input error, try again\n");
        }
    } while (check != 2);

    float chekAB = (xa-xp)*(yb-ya) - (xb-xa)*(ya-yp);
    float chekBC = (xb-xp)*(yc-yb) - (xc-xb)*(yb-yp);
    float chekAC = (xc-xp)*(ya-yc) - (xa-xc)*(yc-yp);

    if ((chekAB < 0 && chekAC < 0 && chekBC < 0)||(chekAB > 0 && chekAC > 0 && chekBC > 0))
    {
        printf("%d", 0);
    }
    else if (chekAB == 0 || chekAC == 0 || chekBC == 0)
    {
        printf("%d", 1);
    }
    else
    {
        printf("%d", 2);
    }
}
