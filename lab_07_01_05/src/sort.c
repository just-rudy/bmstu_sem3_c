#include "sort.h"

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