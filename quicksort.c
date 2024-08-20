/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:16:11 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/20 16:18:28 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quicksort.h"

int	*get_array(stack_head *a)
{
	size_t			i;
	int				*array;
	unsigned int	len;
	stack_node		*tmp;

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

//int	main(int argc, char **argv)
//{
	//stack_head	*a;
	////stack	*b;
	//int		*array;
	//int		len;

	//a = (stack_head*) malloc(sizeof(stack_head));
	//a->head = NULL;
	////b = NULL;
    //len = 0;
	//if (argc > 1)
	//{
		//a = read_list_argum(argc-1, argv, a);
		//if (a  == NULL)
		//{
			//ft_printf("repeated integers.");
			//return (0);
		//}
		//array = get_array(a);
		//ft_printf("\n");
        //quicksort(array, 0, a->len - 1);
        //while (len < a->len)
		//{
			//ft_printf("%d\n", array[len]);
			//len++;
		//}
		//stack_clean(a);
	//}
	//return (0);
//}