#include "key.h"

int cnt_sum(const int *pb, const int *pe);

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int status = SUCCESS;
    if (pb_src == NULL || pe_src == NULL || pb_src >= pe_src)
        status = IN_FILTER_ERR;
    else
    {
        int sum = cnt_sum(pb_src, pe_src);
        int cnt = cnt_filtered_el(pb_src, pe_src);
        if (cnt < 0)
            status = IN_FILTER_ERR;
        else
        {
            (*pb_dst) = malloc(cnt * sizeof(int));
            if ((*pb_dst) == NULL)
                status = MALLOC_ERR;
            else
            {
                int *cur = (int *)pb_src;
                *pe_dst = *pb_dst;
                while (cur + 1 < pe_src)
                {
                    sum -= *cur;
                    if (*cur > sum)
                    {
                        **pe_dst = *cur;
                        (*pe_dst)++;
                    }
                    cur++;
                }
            }
        }
    }
    return status;
}

int cnt_sum(const int *pb, const int *pe)
{
    int sum = 0;
    int *cur = (int *)pb;
    while (cur < pe)
    {
        sum += *cur;
        cur++;
    }
    return sum;
}

int cnt_filtered_el(const int *pb, const int *pe)
{
    int *cur = (int *)pb;
    int cnt = 0, sum = 0;
    sum = cnt_sum(pb, pe);

    while (cur + 1 < pe)
    {
        sum -= (*cur);
        if (*cur > sum)
            cnt++;
        cur++;
    }
    return cnt;
}