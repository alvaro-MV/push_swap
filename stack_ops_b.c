/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:21:28 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 09:26:05 by alvaro           ###   ########.fr       */
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

void	stack_swap_b(t_stack_head *b)
{
	t_stack_node	*first_item;
	t_stack_node	*second_item;

	first_item = stack_pop(b);
	second_item = stack_pop(b);
	if (first_item == NULL
		|| second_item == NULL)
		return ;
	stack_push(b, first_item);
	stack_push(b, second_item);
	ft_printf("sb\n");
}

void	stack_push_b_a(t_stack_head *b, t_stack_head *a)
{
	t_stack_node	*content1;

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

void	stack_rotate_b(t_stack_head *b)
{
	t_stack_node	*head;
	t_stack_node	*holder;
	t_stack_node	*item;

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

void	stack_reverse_rotate_b(t_stack_head *b)
{
	t_stack_node	*head;
	t_stack_node	*penultimate;
	t_stack_node	*last;

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
