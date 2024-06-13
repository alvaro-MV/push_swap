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

#include "stack_ops.h"
#include <stdio.h>

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
	int	*first_item;
	int	*second_item;

	first_item = stack_pop(s);
	second_item = stack_pop(s);
	if (first_item == NULL
		|| second_item == NULL)
		return ;
	stack_push(s, first_item);
	stack_push(s, second_item);
}

void	stack_push_1_2(stack **item1, stack **item2)
{
	int	*content1;

	content1 = stack_pop(item1);
	if (content1 == NULL)
		return ;
	stack_push(item2, content1);
}
/* Controlar el caso de que la lista tenga un solo valor y dos.
	Especialemente para stack_rotate.
	Quizá el motivo por el que antes no iba era porque aunque
	sea argumento, se le dota de un nuevo espacio en el stack para
	guardar los argumentos.
 */

void	stack_rotate(stack **stack_list)
{
	stack	*temporal_stack;
	stack	*holder;
	int		*item;

	item = stack_pop(stack_list);
	temporal_stack = *stack_list;
	while (temporal_stack != NULL)
	{
		holder = temporal_stack;
		temporal_stack = temporal_stack->next;
	}
	temporal_stack = (stack *) malloc(sizeof(stack));
	temporal_stack->content = item;
	temporal_stack->next = NULL;
	holder->next = temporal_stack;
}

void	stack_reverse_rotate(stack **stack_list)
{
	stack	*temporal_stack;
	stack	*penultimate;
	stack	*last;
	int		*item;

	temporal_stack = *stack_list;
	while (temporal_stack != NULL)
	{
		penultimate = last;
		last = temporal_stack;
		temporal_stack = temporal_stack->next;
	}
	stack_push(stack_list, stack_read(last));
	free(last);
	penultimate->next = NULL;
}