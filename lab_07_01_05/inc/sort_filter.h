#include "consts.h"

// int make_sorted_array(int *arr_b, int *arr_e, int *cnt_els, int if_filter);
int comparator(const void *, const void *);
int cnt_filtered_el(const int *pb, const int *pe);
void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
