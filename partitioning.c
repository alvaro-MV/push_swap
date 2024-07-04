#include "stack_ops.h"

int	get_array(stack *a)
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
		a->next;
		i++;
	}
	return (array);
}

void	ft_swap(int *array, int pos1, int pos2)
{
    array[pos1], array[pos2] = array[pos2], array[pos1];
    return (array);
}

void	partitioning(int *array, size_t len)
{
	int	cursor_i;
	int	cursor_d;
	int	pivot;
	int	flag;

	cursor_i = 0;
	cursor_d = len - 2;
	pivot = get_random_pivot();
	flag = 1;
	while (1)
	{
		if (flag)
		{
			if (array[cursor_i] >= array[pivot])
			{
				flag = 0;
				continue ;
			}
			cursor_i++;
		}
		else
		{
			if (array[cursor_d] <= array[pivot])
				break ;
			cursor_d--;
		}
	}
	if (cursor_i >= cursor_d)
	{
		swapPositions(array, cursor_i, pivot);
        return array, cursor_i;
	}
   else
   {
        ft_swap(array, cursor_i, cursor_d);
        return partioning(array, cursor_i, cursor_d);
   }
}
