/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:50:51 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/09 22:28:23 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"
#include "stack_ops.h"
#include "lib/include/libft.h"
#include "quicksort.h"
#include "stack_io.h"

void	__sort__(stack_head *a, stack_head *b)
{
	if (a->len < 7)
		sort_under_7(a, b);
	else
	{
		k_sort_1(a, b);
		k_sort_2(a, b);
	}
}

int	main(int argc, char **argv)
{
	stack_head	*a;
	stack_head	*b;
	dictionary	*dic;
    int         *array;

	a = ft_calloc(1, sizeof(stack_head));
	if (a == NULL)
		return (-1);
	b = ft_calloc(1, sizeof(stack_head));
	if (b == NULL)
		return (-1);
	if (argc > 1)
	{
		a = read_list_argum(argc-1, argv, a);
		if (a  == NULL)
			return (0);
		array = get_array(a);
		quicksort(array, 0, a->len - 1);
		dic = get_dict_from_stack(a, array);
		ids_to_stack_from_dic(a, dic);
		b->dic = dic;
		__sort__(a, b);
		free(array);
		stack_clean(a);
		stack_clean(b);
	}
	return (0);
}
