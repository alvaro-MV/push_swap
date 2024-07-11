#include "quicksort.h"

int	*get_array(stack_head *a)
{
	size_t			i;
	int				*array;
	unsigned int	len;

	i = 0;
	len = stack_size(a);
	array = (int *) malloc(sizeof(int) * a->len);
	while (i < len)
	{
		array[i] = *(int *) a->head->content;
		a->head = a->head->next;
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

int	partitioning(int *array, int cursor_i, int cursor_d, int len)
{
	int	pivot;
	int	pivot_index;
	int	i = 0; //testeo

	pivot = array[cursor_d];
	pivot_index = cursor_d;
	cursor_d--;
	while (1)
	{
		while (cursor_i < pivot_index && array[cursor_i] < pivot)
			cursor_i++;
		while (cursor_d > 0 && array[cursor_d] > pivot)
			cursor_d--;
		//testeo
		i = 0;
		ft_printf("cursor_i: %d, cursor_d: %d,  pivot: %d, pivot_index: %d\n\n", cursor_i, cursor_d, pivot, pivot_index);
		while (i < len)
		{
			ft_printf("array[%d]: %d\n", i, array[i]);
			i++;
		}
		//testeo
		if (cursor_i >= cursor_d)
			break ;
		else
		{
			ft_swap(array, cursor_i, cursor_d);
			cursor_i++;
		}
	}
	ft_swap(array, cursor_i, pivot_index);
	//testeo
	i = 0;
	ft_printf("cursor_i: %d, cursor_d: %d,  pivot: %d, pivot_index: %d\n\n", cursor_i, cursor_d, pivot, pivot_index);
	while (i < len)
	{
		ft_printf("array[%d]: %d\n", i, array[i]);
		i++;
	}
	ft_printf("\n-----------------\n");
	//testeo
	return (cursor_i);
}

int    *quicksort(int *array, int cursor_i, int cursor_d, int len)
{
    int     pivot_index;

    pivot_index = partitioning(array, cursor_i, cursor_d, len);
    if (pivot_index == cursor_d)
        return (array);
	ft_printf("EN QUICKSORT: cursor_i: %d,   cursor_d: %d\n\n\n", cursor_i, cursor_d);
    array = quicksort(array, cursor_i, pivot_index - 1, len);
	ft_printf("EN QUICKSORT PA EL GRANDE: cursor_i: %d,   cursor_d: %d\n\n\n", pivot_index+1, cursor_d);
    array = quicksort(array, pivot_index + 1, cursor_d, len);
	return (array);
}

int	main(int argc, char **argv)
{
	stack_head	*a;
	//stack	*b;
	int		*array;
	int		len;

	a = (stack_head*) malloc(sizeof(stack_head));
	a->head = NULL;
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
		ft_printf("\n");
        quicksort(array, 0, a->len - 1, a->len);
        while (len < a->len)
		{
            ft_printf("%d\n", array[len]);
			len++;
		}
		stack_clean(a);
	}
	return (0);
}