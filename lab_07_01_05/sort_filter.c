#include "sort_filter.h"
#include "output.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
int cnt_filtered_el(int *pb, int *pe);
int cnt_sum(const int *pb, const int *pe);

int make_sorted_array(int *arr_b, int *arr_e, int if_filter)
{
    int status = SUCCESS;

    if (if_filter)
    {
        int cnt = cnt_filtered_el(arr_b, arr_e);
        if (cnt == 0)
            status = IN_FILTER_ERR;
        else
        {
            int *narr_b = malloc(cnt * sizeof(int));
            int *narr_e = NULL;
            status = key(arr_b, arr_e, &narr_b, &narr_e);
            printf("\n");
            print_array(narr_b, narr_e);
        }
    }
    return status;
}

int cnt_filtered_el(int *pb, int *pe)
{
    int *cur = pb;
    int cnt = 0, sum = 0;
    sum = cnt_sum(pb, pe);

    while (cur + 1 < pe)
    {
        sum -= (*cur);
        if (*cur > sum)
            cnt++;
    }
    return cnt;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int status = SUCCESS;
    if (pb_src == NULL || pe_src == NULL || pb_dst == NULL || (*pb_dst) == NULL || pb_src <= pe_src)
        status = IN_FILTER_ERR;
    else
    {
        int sum = cnt_sum(pb_src, pe_src);
        int *cur = (int*) pb_src;
        pe_dst = pb_dst;
        while (cur + 1 < pe_src)
        {
            sum -= *cur;
            if (*cur < sum)
            {
                **pe_dst = *cur;
                (*pe_dst)++;
            }
        }
    }
    return status;
}

int cnt_sum(const int *pb, const int *pe)
{
    int sum = 0;
    int *cur = (int*) pb;
    while (cur < pe)
        sum += *cur;
    return sum;
}