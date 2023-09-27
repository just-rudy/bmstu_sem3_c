#ifndef __CONSTS_H__
#define __CONSTS_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 25
#define MAX_CNT 15
#define ARG_CNT 3
#define SUCCSESS 0
#define ARG_CNT_ERR 1
#define PRICE_ERR 2 
#define FILE_ERR 3
#define NUM_ERR 4
#define STR_ERR 5
#define EPS 1e-5

typedef char string[MAX_STR_LEN + 1];

struct product
{
    string name;
    int price;
};

typedef struct product array[MAX_CNT];

#endif