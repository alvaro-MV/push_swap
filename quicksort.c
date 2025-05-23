/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:10:12 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 12:10:13 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

int	*get_array(t_stack_head *a)
{
	size_t				i;
	int					*array;
	unsigned int		len;
	t_stack_node		*tmp;

	i = 0;
	len = stack_size(a);
	array = (int *) malloc(sizeof(int) * a->len);
	tmp = a->head;
	while (i < len)
	{
		array[i] = tmp->content;
		tmp = tmp->next;
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
		while (array[cursor_i] < pivot)
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

void	quicksort(int *array, int cursor_i, int cursor_d)
{
	int	pivot_index;

	if (cursor_d <= cursor_i)
		return ;
	pivot_index = partitioning(array, cursor_i, cursor_d);
	quicksort(array, cursor_i, pivot_index - 1);
	quicksort(array, pivot_index + 1, cursor_d);
}
