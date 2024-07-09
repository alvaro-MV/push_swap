#include "quicksort.h"

int	*get_array(stack *a)
{
	size_t	list_len;
	size_t	i;
	int		*array;

	list_len = stack_size(a);
	i = 0;
	array = (int *) malloc(sizeof(int) * list_len);
	while (i < list_len)
	{
		array[i] = *(int *) a->content;
		a = a->next;
		i++;
	}
	return (array);
}

static void	ft_swap(int *array, int pos1, int pos2)
{
	int	tmp;

	tmp = array[pos1];
	array[pos1] = array[pos2];
    array[pos2] = tmp;
}

int	partitioning(int *array, int cursor_i, int cursor_d)
{
	int	pivot;
	int	pivot_index;

	pivot = array[cursor_d];
	pivot_index = cursor_d;
	cursor_d--;
	while (1)
	{
		while (cursor_i != pivot && array[cursor_i] < pivot)
			cursor_i++;
		while (cursor_d && array[cursor_d] > pivot)
			cursor_d--;
		if (cursor_i >= cursor_d)
			break ;
		else
		{
			ft_swap(array, cursor_i, cursor_d);
			cursor_i++;
		}
	}
	ft_swap(array, cursor_i, pivot_index);
	return (cursor_i);
}

void    quicksort(int *array, int cursor_i, int cursor_d)
{
    int     pivot_index;

    pivot_index = partitioning(array, cursor_i, cursor_d);
    if (pivot_index == cursor_d)
        return ;
    quicksort(array, cursor_i, pivot_index - 1);
    quicksort(array, pivot_index + 1, cursor_d);
}

int	main(int argc, char **argv)
{
	stack	*a;
	//stack	*b;
	int		*array;
	int		len;

	a = NULL;
	//b = NULL;
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