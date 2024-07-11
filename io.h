#ifndef IO_H
# define IO_H

#include "stack_ops.h"
#include "lib/include/libft.h"

int         is_in(int *list_numbers, int content, int len);
stack_head	*read_list_argum(int argc, char **argv, stack_head *a);
void	    print_state(stack_head *a, stack_head *b);

#endif