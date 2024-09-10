/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:39 by alvaro            #+#    #+#             */
/*   Updated: 2024/09/10 09:45:31 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Para aclararnos: initializa, --> lo mismo que el de abajo
push (que pongas uno encima), --> lstnew + addback.
pop (elimina y devuelve) y --> delone y devolver el contenido
read (lee el ultimo) --> accede al contenido. 
*/

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
