/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:21:28 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/20 16:21:38 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ops.h"

/* 
	Seria interesante definir en algun header los 
	stack para ir operando con ellos de forma mas sencilla.
	Se puede leer tanto de un fichero como por parametros en 
	main.

	Las funciones basca
 */

void	stack_swap_b(stack_head *b)
{
	stack_node	*first_item;
	stack_node	*second_item;

	first_item = stack_pop(b);
	second_item = stack_pop(b);
	if (first_item == NULL
		|| second_item == NULL)
		return ;
	stack_push(b, first_item);
	stack_push(b, second_item);
	ft_printf("sb\n");
}

void	stack_push_b_a(stack_head *b, stack_head *a)
{
	stack_node	*content1;

	content1 = stack_pop(b);
	if (content1 == NULL)
		return ;
	stack_push(a, content1);
	ft_printf("pa\n");
}
/* Controlar el caso de que la lista tenga un solo valor y dos.
	Especialemente para stack_rotate.
	Quizá el motivo por el que antes no iba era porque aunque
	sea argumento, se le dota de un nuevo espacio en el stack para
	guardar los argumentos.
 */

void	stack_rotate_b(stack_head *b)
{
	stack_node	*head;
	stack_node	*holder;
	stack_node	*item;

	if (stack_size(b) > 1)
	{
		item = stack_pop(b);
		head = b->head;
		while (head != NULL)
		{
			holder = head;
			head = head->next;
		}
		holder->next = item;
		item->next = head;
		b->len++;
		ft_printf("rb\n");
	}
}

void	stack_reverse_rotate_b(stack_head *b)
{
	stack_node	*head;
	stack_node	*penultimate;
	stack_node	*last;

	head = b->head;
	while (head != NULL)
	{
		penultimate = last;
		last = head;
		head = head->next;
	}
	stack_push(b, last);
	b->len--;
	penultimate->next = NULL;
	ft_printf("rrb\n");
}
