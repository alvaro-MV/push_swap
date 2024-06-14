#include "sort_algorithms.h"
#include "stack_def.h"
#include "stack_ops.h"
#include "../libft/include/ft_printf.h"

int	is_in(int *list_numbers, int content, int len);
stack	*read_list_argum(int argc, char **argv, stack *a);
void	print_state(stack *a, stack *b);
//void	*bubble_sort(stack **a, stack **b);
stack	*insertion_sort(stack **a, stack **b);

int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;
	int		fd;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		a = read_list_argum(argc-1, argv, a);
		if (a  == NULL)
		{
			ft_printf("repeated integers.");
			return (0);
		}
		print_state(a, b);
		insertion_sort(&a, &b);
		print_state(a, b);
		stack_clean(a);
	}
	//controlar el caso en que a o b sigan siendo NULL.
	return (0);
}