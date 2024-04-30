/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:59:17 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/29 21:07:55y alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_basic_op.h"

/* 
	Seria interesante definir en algun header los 
	stack para ir operando con ellos de forma mas sencilla.
	Se puede leer tanto de un fichero como por parametros en 
	main.

	Las funciones basca
 */

unsigned int	stack_size(stack *item)
{
	int		counter;

	counter = 0;
	while (item != NULL)
	{
		item = item->next;
		counter++;
	}
	return (counter);
}

void	stack_swap(stack **s)
{
	stack	*first_item;
	stack	*second_item;

	first_item = stack_pop(s);
	second_item = stack_pop(s);
	if (first_item == NULL
		|| second_item == NULL)
		return ;
	stack_push(s, first_item);
	stack_push(s, second_item);
}

void	stack_push_1_2(stack *item1, stack *item2)
{
	char	content1;

	content1 = stack_read(item1);
	stack_push(&item2, content1);
}
/* Controlar el caso de que la lista tenga un solo valor y dos.
	Especialemente para stack_rotate.
 */

void	stack_rotate(stack **stack_list)
{
	stack	*temporal_stack;
	void	*item;

	temporal_stack = NULL;
	item = stack_pop(stack_list);
	while (stack_list != NULL)
		stack_push(&temporal_stack, stack_pop(stack_list));
	stack_push(stack_list, item);
	while (temporal_stack != NULL)
		stack_push(stack_list, stack_pop(&temporal_stack));
}

void	stack_reverse_rotate(stack **stack_list)
{
	stack	*temporal_stack;
	void	*item;

	temporal_stack = NULL;
	while (*stack_list != NULL)
	{
		item = stack_pop(stack_list);
		stack_push(&temporal_stack, item);
	}
	stack_pop(&temporal_stack);
	while (temporal_stack != NULL)
		stack_push(stack_list, stack_pop(&temporal_stack));
	stack_push(stack_list, item);
}