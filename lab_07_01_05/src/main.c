#include "consts.h"
#include "input.h"
#include "sort.h"
#include "key.h"
#include "output.h"

int proccessor(int *arr_b, int *arr_e, int cnt, int if_filter, FILE* f_out);

int main(int arg_cnt, char *args[])
// int main()
{
    // int arg_cnt = 4;
    // char *args[] = {"4", "test.txt", "out.txt", "f"};

    int *arr_b = NULL, *arr_e = NULL; // begin & end
    int status = SUCCESS;

    if (arg_cnt < MIN_ARG_CNT || arg_cnt > MAX_ARG_CNT)
        return ARG_ERROR;

    FILE *f_in = fopen(args[1], "r");
    if (f_in == NULL)
        return FILE_ERROR;

    FILE *f_out = fopen(args[2], "w");
    if (f_out == NULL)
        return FILE_ERROR;

    int cnt = 0;
    status = create_array(f_in, &arr_b, &arr_e, &cnt);
    if (!status)
    {
        int if_filter = FALSE;
        if (arg_cnt == MAX_ARG_CNT && *args[3] == 'f')
            if_filter = TRUE;

        else if (arg_cnt == MAX_ARG_CNT)
            status = ARG_ERROR;

        if (!status)
            status = proccessor(arr_b, arr_e, cnt, if_filter, f_out);
    }
    free(arr_b);
    fclose(f_out);
    fclose(f_in);
    //    printf("stat: %d", status);
    return status;
}

int proccessor(int *arr_b, int *arr_e, int cnt, int if_filter, FILE* f_out)
{
    int status = SUCCESS;
    if (if_filter)
    {
        int *filtered_arr_b = NULL, *filtered_arr_e = NULL;
        cnt = cnt_filtered_el(arr_b, arr_e);
        if (cnt > 0)
        {
            status = key(arr_b, arr_e, &filtered_arr_b, &filtered_arr_e);
            if (!status)
            {
                mysort(filtered_arr_b, cnt, sizeof(int), comparator);
                print_array(filtered_arr_b, filtered_arr_e, f_out);
                free(filtered_arr_b);
            }
            else
                status = IN_FILTER_ERR;
        }
        else
            status = IN_FILTER_ERR;
    }
    else
    {
        mysort(arr_b, cnt, sizeof(int), comparator);
        print_array(arr_b, arr_e, f_out);
    }
    return status;
}