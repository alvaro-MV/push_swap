/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:20:18 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/26 19:37:45 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

void	sort_two(stack_head *stack, char s)
{
	if (stack->head->content > stack->head->next->content)
		return (swap_dual(stack, s));
}

void	sort_three(stack_head *stack, char st)
{
	int			f;
	int			s;
	int			t;
	stack_node	*node;

	node = stack->head;
	f = node->index;
	s = node->next->index;
	t = node->next->next->index;
	if (f < s && s < t)
		return ;
	else if (f < s && s > t && f < t)
		(swap_dual(stack, st), rotate_dual(stack, st));
	else if (f < s && s > t && f > t)
		reverse_rotate_dual(stack, st);
	else if (f > s && s > t)
		(swap_dual(stack, st), reverse_rotate_dual(stack, st));
	else if (f > s && s < t && f < t)
		swap_dual(stack, st);
	else if (f > s && s < t && f > t)
		rotate_dual(stack, st);
}

void	compare_and_push(stack_head *a, stack_head *b, \
int r_count, int rr_count)
{
	if (r_count < rr_count)
	{
		while (r_count--)
			stack_rotate_a(a);
	}
	else
	{
		while (rr_count--)
			stack_reverse_rotate_a(a);
	}
	stack_push_a_b(a, b);
}

void	push_n_to_b(stack_head *a, stack_head *b, int n_to_b, int init_len)
{
	int			r_count;
	int			rr_count;
	stack_node	*node;

	while (a->len > init_len - n_to_b)
	{
		r_count = 0;
		rr_count = 1;
		node = a->head;
		while (node)
		{
			if (node->index >= init_len - n_to_b)
				break ;
			r_count++;
			node = node->next;
		}
		while (node)
		{
			rr_count++;
			if (node->index >= init_len - n_to_b)
				rr_count = 1;
			node = node->next;
		}
		compare_and_push(a, b, r_count, rr_count);
	}
}

void	sort_under_7(stack_head *a, stack_head *b)
{
	int	n_to_b;
	int	init_len;

	if (a->len == 2)
		return (sort_two(a, 'a'));
	if (a->len == 3)
		return (sort_three(a, 'a'));
	n_to_b = ((a->len / 3 - 1) * 3) + a->len % 3;
	init_len = a->len;
	push_n_to_b(a, b, n_to_b, init_len);
	sort_three(a, 'a');
	if (n_to_b == 2)
		sort_two(b, 'b');
	else if (n_to_b == 3)
		sort_three(b, 'b');
	while (b->head)
	{
		stack_push_b_a(b, a);
		stack_rotate_a(a);
	}
}
