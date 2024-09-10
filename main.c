/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:50:51 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 09:43:30 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"
#include "stack_ops.h"
#include "lib/include/libft.h"
#include "quicksort.h"
#include "stack_io.h"

void	__sort__(t_stack_head *a, t_stack_head *b)
{
	if (a->len < 7)
		sort_under_7(a, b);
	else
	{
		k_sort_1(a, b);
		k_sort_2(a, b);
	}
}

t_dictionary	*get_dic_idx(t_stack_head *a, t_stack_head *b)
{
	int				*array;
	t_dictionary	*dic;

	array = get_array(a);
	quicksort(array, 0, a->len - 1);
	dic = get_dict_from_stack(a, array);
	ids_to_stack_from_dic(a, dic);
	b->dic = dic;
	free(array);
	return (dic);
}

int	main(int argc, char **argv)
{
	t_stack_head	*a;
	t_stack_head	*b;
	t_dictionary	*dic;

	a = ft_calloc(1, sizeof(t_stack_head));
	if (a == NULL)
		return (-1);
	b = ft_calloc(1, sizeof(t_stack_head));
	if (b == NULL)
		return (stack_clean(a), -1);
	argv++;
	if (argc > 2)
	{
		argv = parse_args(argc - 1, argv);
		a = read_list_argum(argv, a);
		if (a == NULL)
			return (ft_free_array(argv), stack_clean(b), 0);
		ft_free_array(argv);
		dic = get_dic_idx(a, b);
		__sort__(a, b);
		stack_clean(a);
		stack_clean(b);
		dict_delete(dic);
	}
	return (0);
}
