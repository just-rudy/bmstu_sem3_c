#include "consts.h"
#include "input.h"
#include "sort_filter.h"

int arg_controller();

// int main(int arg_cnt, char *args[])
int main()
{
    int arg_cnt = 3;
    int *arr_first = NULL;
    char *args[] = {"3", "test.txt", "out.txt"};
    int status = SUCCESS;

    if (arg_cnt < MIN_ARG_CNT || arg_cnt > MAX_ARG_CNT)
        status = ARG_ERROR;
    else
    {
        FILE *f_in = fopen(args[1], "r");
        if (f_in == NULL)
            status = FILE_ERROR;
        else
        {
            FILE *f_out = fopen(args[2], "w");
            if (f_out == NULL)
                status = FILE_ERROR;
            else
            {
                create_array(f_in, &arr);
                fclose(f_out);
            }
            fclose(f_in);
        }
    }

    return status;
}

int arg_controller()
{
    int status = SUCCESS;
    return status;
}