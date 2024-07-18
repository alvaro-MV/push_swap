#include "sort_algorithms.h"
#include "stack_ops.h"
#include "lib/include/libft.h"
#include "quicksort.h"
#include "stack_io.h"

void	haz_mierdas(stack_head *a, stack_head *b)
{
	print_state(a, b);
	stack_rotate_a(a);
	print_state(a, b);
	stack_reverse_rotate_a(a);
	print_state(a, b);
	stack_push_a_b(a, b);
	stack_push_a_b(a, b);
	print_state(a, b);
	stack_swap_b(b);
	print_state(a, b);
}

int	main(int argc, char **argv)
{
	stack_head	*a;
	stack_head	*b;
	dictionary	*dic;
	int			len;

	a = ft_calloc(1, sizeof(stack_head));
	if (a == NULL)
		return (-1);
	b = ft_calloc(1, sizeof(stack_head));
	if (b == NULL)
		return (-1);
    len = 0;
	if (argc > 1)
	{
		a = read_list_argum(argc-1, argv, a);
		if (a  == NULL)
			return (0);
		haz_mierdas(a, b);
		dic = get_dict_from_stack(a);
		put_indexes_stack(a, dic);
		b->dic = dic;
		stack_clean(a);
		stack_clean(b);
	}
	return (0);
}
