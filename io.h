#ifndef IO_H
# define IO_H

#include "stack_ops.h"
#include "lib/include/libft.h"

int	    is_in(int *list_numbers, int content, int len);
stack	*read_list_argum(int argc, char **argv, stack *a);
void	print_state(stack *a, stack *b);

#endif