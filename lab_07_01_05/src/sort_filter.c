#include "sort_filter.h"
#include "output.h"
#include "input.h"

int cnt_sum(const int *pb, const int *pe);

void swap(void *a, void *b, size_t size)
{
    char tmp[size];
    memcpy(tmp, a, size);
    memcpy(a, b, size);
    memcpy(b, tmp, size);
}

int comparator(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *))
{
    char *arr_b = (char *)first;
    char *arr_end = arr_b + number * size;

    for (size_t i = 0; i < number; i++)
    {
        char *mx = arr_b;
        for (char *cur = arr_b; cur != arr_end; cur += size)
            if (comparator(cur, mx) > 0)
                mx = cur;
        swap(mx, arr_end-size, size);
        arr_end -= size;
    }
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

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int status = SUCCESS;
    if (pb_src == NULL || pe_src == NULL || pb_src >= pe_src)
        status = IN_FILTER_ERR;
    else
    {
        int sum = cnt_sum(pb_src, pe_src);
        int cnt = cnt_filtered_el(pb_src, pe_src);
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