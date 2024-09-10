/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:10:27 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 12:10:28 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"

void	sort_two(t_stack_head *stack, char s)
{
	if (stack->head->content > stack->head->next->content)
		return (swap_dual(stack, s));
}

void	sort_three(t_stack_head *stack, char st)
{
	int				f;
	int				s;
	int				t;
	t_stack_node	*node;

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

void	compare_and_push(t_stack_head *a, t_stack_head *b, \
int r_c, int rr_c)
{
	if (r_c < rr_c)
	{
		while (r_c--)
			stack_rotate_a(a);
	}
	else
	{
		while (rr_c--)
			stack_reverse_rotate_a(a);
	}
	stack_push_a_b(a, b);
}

void	push_n_to_b(t_stack_head *a, t_stack_head *b, int n_to_b, int init_len)
{
	int				r_count;
	int				rr_count;
	t_stack_node	*node;

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

void	sort_under_7(t_stack_head *a, t_stack_head *b)
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
