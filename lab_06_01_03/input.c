#include "input.h"

int get_float(char string[], double *number)
{
    int status = SUCCSESS;
    char *ptrEND;
    double d_num = strtod(string, &ptrEND);

    if (*ptrEND != 0)
        status = PRICE_ERR;
    else
        (*number) = d_num;
        
    return status;
}

int read_name(FILE *in, array prod_arr, int i)
{
    int status = SUCCSESS;
    int j = 0;
    char tmp = ' ', curr_str[MAX_STR_LEN + 2] = { "" };

    while (fscanf(in, "%c", &tmp) && tmp != '\n' && tmp != '\0' && j <= MAX_STR_LEN)
    {
        curr_str[j] = tmp;
        j++;
    }
    curr_str[j] = '\0';

    if (j == 0 || j > MAX_STR_LEN)
        status = STR_ERR;
    else
        strcpy(prod_arr[i].name, curr_str);

    return status;
}

int read_int(FILE *in, array prod_arr, int i)
{
    int status = SUCCSESS;
    int len = 0, price = 0;
    char dig, curr_str[MAX_STR_LEN + 2];

    while (!status && fscanf(in, "%c", &dig) == 1 && dig != '\n' && dig != '\0')
    {
        if (dig <= '9' && dig >= '0')
            curr_str[len] = dig;
        else
            status = NUM_ERR;
        len++;
    }
    if (!status)
    {
        curr_str[len] = '\0';
        price = atoi(curr_str);
        if (price > 0)
            prod_arr[i].price = price;
        else
            status = NUM_ERR;
    }
    return status;
}

int read_arr(FILE *in, array prod_arr, int *n)
{
    int status = SUCCSESS;
    (*n) = 0;
    char dig;

    // количество записей
    int check = fscanf(in, "%d\n", n);
    if (check == 1 && (*n) <= MAX_CNT && (*n) >= 1)
    {
        for (int i = 0; i < (*n) && !status; i++)
        {
            status = read_name(in, prod_arr, i);
            if (!status)
                status = read_int(in, prod_arr, i);
        }
        // если записей больше, чем количество
        if (fscanf(in, "%c", &dig) == 1 && dig != '\n' && dig != '\0')
            status = NUM_ERR;
    }
    else
        status = NUM_ERR;
    return status;
}