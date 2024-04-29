/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:59:17 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/29 20:11:33 by alvaro           ###   ########.fr       */
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

	if ((*s)->next != NULL)
	{
		first_item = stack_pop(&s);
		second_item = stack_pop(&s);
		stack_push(&s, first_item);
		stack_push(&s, second_item);
	}
}

void	stack_push_1_2(stack *item1, stack *item2)
{
	char	content1;

	content1 = stack_read(item1);
	stack_push(&item2, content1);
}

void	stack_rotate(stack **stack_list)
{
	stack	*list;
	stack	*init;
	stack	*last;
	stack	*penultimate;
	
	
	list = *stack_list;
	init = list;
	if (list != NULL)	
	{
		while (list != NULL)
		{
			penultimate = last;
			last = list;
			list = list ->next;
		}
		last->next = init;
		penultimate->next = NULL;
	}
}