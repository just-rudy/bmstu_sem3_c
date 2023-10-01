#ifndef __SORT_H__
#define __SORT_H__

#include "consts.h"

// int make_sorted_array(int *arr_b, int *arr_e, int *cnt_els, int if_filter);
int comparator(const void *, const void *);
void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));

#endif