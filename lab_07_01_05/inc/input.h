#ifndef __IN_H__
#define __IN_H__

#include "consts.h"

int cnt_elements(FILE *f_in);
int create_array(FILE *f_in, int **arr_b, int **arr_e, int *cnt);

#endif