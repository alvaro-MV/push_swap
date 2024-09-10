/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:41:01 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 09:43:05 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ops.h"
#include "dictionary.h"
#include "sort_algorithms.h"
#include "quicksort.h"
#include "lib/include/libft.h"
#include "verify.h"

int	count_r(t_stack_head *stack, int idx)
{
	int				count;
	t_stack_node	*tmp;

	count = 0;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->index == idx)
			return (count);
		count++;
		tmp = tmp->next;
	}
	return (0);
}

int	count_rr(t_stack_head *stack, int idx)
{
	int				count;
	t_stack_node	*tmp;

	count = stack->len;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->index == idx)
			return (count);
		count--;
		tmp = tmp->next;
	}
	return (0);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) - number))
			return (i);
	}
	return (i - 1);
}

void	k_sort_1(t_stack_head *a, t_stack_head *b)
{
	int	pivot;
	int	i;

	pivot = ft_sqrt(a->len) * 14 / 10;
	i = 0;
	while (a->head != NULL)
	{
		if (a->head->index < i)
		{
			stack_push_a_b(a, b);
			stack_rotate_b(b);
			i++;
		}
		else if (a->head->index < i + pivot)
		{
			stack_push_a_b(a, b);
			i++;
		}
		else
			stack_rotate_a(a);
	}
	k_sort_2(a, b);
}

void	k_sort_2(t_stack_head *a, t_stack_head *b)
{
	int		idx;
	int		count_rot;
	int		count_rrot;

	idx = b->len - 1;
	while (b->head != NULL)
	{
		count_rot = count_r(b, idx);
		count_rrot = count_rr(b, idx);
		if (count_rot <= count_rrot)
		{
			while (count_rot--)
				stack_rotate_b(b);
		}
		else
		{
			while (count_rrot--)
				stack_reverse_rotate_b(b);
		}
		stack_push_b_a(b, a);
		idx--;
	}
}
