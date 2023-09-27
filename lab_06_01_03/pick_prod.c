#include "pick_prod.h"

void print(struct product prod);

void proccess(array arr, int n, double mprice)
{
    for (int i = 0; i < n; i++)
        if (arr[i].price < mprice)
            print(arr[i]);
}

void print(struct product prod)
{
    printf("%s\n%d\n", prod.name, prod.price);
}