#ifndef QUICKSORT_H
# define QUICKSORT_H

#include "io.h"
#include "stack_ops.h"
#include "lib/include/libft.h"

int	    partitioning(int *array, int cursor_i, int cursor_d, int len);
int	    *get_array(stack_head *a);
int     *quicksort(int *array, int cursor_i, int cursor_d, int len);

#endif