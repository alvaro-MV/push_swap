/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:11:40 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 12:11:41 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ops.h"

/* 
	Seria interesante definir en algun header los 
	stack para ir operando con ellos de forma mas sencilla.
	Se puede leer tanto de un fichero como por parametros en 
	main.
 */

void	stack_swap_a(t_stack_head *a)
{
	t_stack_node	*first_item;
	t_stack_node	*second_item;

	first_item = stack_pop(a);
	second_item = stack_pop(a);
	if (first_item == NULL
		|| second_item == NULL)
		return ;
	stack_push(a, first_item);
	stack_push(a, second_item);
	ft_printf("sa\n");
}

void	stack_push_a_b(t_stack_head *a, t_stack_head *b)
{
	t_stack_node	*content1;

	content1 = stack_pop(a);
	if (content1 == NULL)
		return ;
	stack_push(b, content1);
	ft_printf("pb\n");
}

void	stack_rotate_a(t_stack_head *a)
{
	t_stack_node	*head;
	t_stack_node	*holder;
	t_stack_node	*item;

	if (stack_size(a) > 1)
	{
		item = stack_pop(a);
		head = a->head;
		while (head != NULL)
		{
			holder = head;
			head = head->next;
		}
		holder->next = item;
		item->next = head;
		a->len++;
		ft_printf("ra\n");
	}
}

void	stack_reverse_rotate_a(t_stack_head *a)
{
	t_stack_node	*head;
	t_stack_node	*penultimate;
	t_stack_node	*last;

	head = a->head;
	while (head != NULL)
	{
		penultimate = last;
		last = head;
		head = head->next;
	}
	stack_push(a, last);
	a->len--;
	penultimate->next = NULL;
	ft_printf("rra\n");
}
