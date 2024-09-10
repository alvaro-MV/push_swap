/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:11:07 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 12:11:08 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_def.h"
#include "lib/include/libft.h"
#include "dictionary.h"
#include <stdio.h>

void	stack_push(t_stack_head *stack, t_stack_node *new_n)
{
	if (new_n == NULL)
		return ;
	new_n->next = stack->head;
	stack->head = new_n;
	stack->len++;
}

int	stack_read(t_stack_node *node)
{
	return (node->content);
}

t_stack_node	*stack_pop(t_stack_head *stack_list)
{
	t_stack_node	*head;
	t_stack_node	*holder;

	if (stack_list == NULL)
		return (NULL);
	head = stack_list->head;
	if (head == NULL)
		return (NULL);
	holder = head->next;
	stack_list->head = holder;
	stack_list->len--;
	return (head);
}

void	stack_clean(t_stack_head *stack_list)
{
	t_stack_node	*holder;
	t_stack_node	*tmp;

	tmp = stack_list->head;
	while (tmp != NULL)
	{
		holder = tmp;
		tmp = tmp->next;
		free(holder);
	}
	free(stack_list);
}

unsigned int	stack_size(t_stack_head *stack_list)
{
	t_stack_node		*temporal;
	unsigned int		counter;

	counter = 0;
	temporal = stack_list->head;
	while (temporal != NULL)
	{
		temporal = temporal->next;
		counter++;
	}
	return (counter);
}
