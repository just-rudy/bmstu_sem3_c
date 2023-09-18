#include "consts.h"
#include "input.h"
#include "pick_prod.h"

int main(int arg_cnt, char *args[])
{
    int status = SUCCSESS;
    int n = 0;
    array prod_arr;

    if (arg_cnt != ARG_CNT)
        status = ARG_CNT_ERR;
    else
    {
        FILE *in = fopen(args[1], "r");
        if (in == NULL)
            status = FILE_ERR;
        else
        {
            double max_price = 0;
            status = get_float(args[2], &max_price);
            if (!status)
            {
                status = read_arr(in, prod_arr, &n);
                if (!status)
                    proccess(prod_arr, n, max_price);
            }
            fclose(in);
        }
    }
    return status;
}
