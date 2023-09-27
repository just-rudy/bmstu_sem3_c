#include "consts.h"
#include "input.h"
#include "sort_filter.h"
#include "output.h"

int arg_controller(int arg_cnt, char* args[], int *arr_b, int *arr_e);

// int main(int arg_cnt, char *args[])
int main()
{
    int arg_cnt = 4;
    char *args[] = {"4", "test.txt", "out.txt", "f"};
    int *arr_b = NULL, *arr_e = NULL; // begin & end
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
                status = create_array(f_in, &arr_b, &arr_e);
                status = arg_controller(arg_cnt, args, arr_b, arr_e);
                fclose(f_out);
            }
            fclose(f_in);
        }
    }
    print_array(arr_b, arr_e);
    printf("stat: %d", status);
    return status;
}

int arg_controller(int arg_cnt, char* args[], int *arr_b, int *arr_e)
{
    int status = SUCCESS;
    int if_filter = FALSE;
    if (arg_cnt == MAX_ARG_CNT && *args[3] == 'f')
        if_filter = TRUE;
    else if (arg_cnt == MAX_ARG_CNT)
        status = ARG_ERROR;
    
    make_sorted_array(arr_b, arr_e, if_filter);
    return status;
}