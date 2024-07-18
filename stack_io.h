#ifndef STACK_IO_H
# define STACK_IO_H

#include "stack_ops.h"
#include "lib/include/libft.h"

stack_head	*read_list_argum(int argc, char **argv, stack_head *a);
void	    print_state(stack_head *a, stack_head *b);
dictionary  *get_dict_from_stack(stack_head *a);
void        put_indexes_stack(stack_head *a, dictionary *dic);

#endif