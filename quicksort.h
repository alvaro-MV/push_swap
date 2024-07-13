#ifndef QUICKSORT_H
# define QUICKSORT_H

#include "io.h"
#include "stack_ops.h"
#include "lib/include/libft.h"

int	    partitioning(int *array, int cursor_i, int cursor_d);
int	    *get_array(stack_head *a);
void    quicksort(int *array, int cursor_i, int cursor_d);

#endif