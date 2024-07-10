#include "sort_algorithms.h"
#include "stack_def.h"
#include "stack_ops.h"
#include "lib/include/libft.h"

int	is_in(int *list_numbers, int content, int len);
stack	*read_list_argum(int argc, char **argv, stack *a);
void	print_state(stack *a, stack *b);
stack	*insertion_sort(stack **a, stack **b);

int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;
	int		*array;
	int		len;

	a = NULL;
	b = NULL;
    len = 0;
	if (argc > 1)
	{
		a = read_list_argum(argc-1, argv, a);
		if (a  == NULL)
		{
			ft_printf("repeated integers.");
			return (0);
		}
		array = get_array(a);
        quicksort(array, 0, a->len - 1);
        while (len < a->len)
		{
            ft_printf("%d\n", array[len]);
			len++;
		}
		stack_clean(a);
	}
	return (0);
}
