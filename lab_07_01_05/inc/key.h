#ifndef __KEY_H__
#define __KEY_H__

#include "consts.h"

int cnt_filtered_el(const int *pb, const int *pe);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif