#ifndef __TASK_H__
#define __TASK_H__
#include "consts.h"

int make_arr(matrix arr, int rows, int cols, int *simple_arr, int *cnt);
void reverse_arr(int *simple_arr, int cnt);
void full_matrix(matrix arr, int rows, int cols, int *simple_arr);

#endif