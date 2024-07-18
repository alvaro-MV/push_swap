/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:39 by alvaro            #+#    #+#             */
/*   Updated: 2024/07/18 22:01:27 by alvaro           ###   ########.fr       */
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

void    stack_push(stack_head *stack, stack_node *new_n)
{
	char		*item;
	
	if (new_n == NULL)
		return ;
	new_n->next = stack->head;
	stack->head = new_n;	
}

int	stack_read(stack_node *node)
{
	return (node->content);
}

stack_node	*stack_pop(stack_head *stack_list)
{
	stack_node	*head;
	stack_node	*holder;

	if (stack_list == NULL)
		return (NULL);
	head = stack_list->head;
	if (head == NULL)
		return (NULL);
	holder = head->next;
	stack_list->head = holder;
	stack_list->len--;
	return(head);
}

void	stack_clean(stack_head * stack_list)
{
	stack_node  *holder;
	stack_node	*tmp;

	tmp = stack_list->head;
	while (tmp != NULL)
	{
			holder = tmp;
			tmp = tmp->next;
			free(holder);
	}
	free(stack_list);
}

unsigned int	stack_size(stack_head *stack_list)
{
	stack_node		*temporal;
	unsigned int	counter;

	counter = 0;
	temporal = stack_list->head;
	while (temporal != NULL)
	{
		temporal = temporal->next;
		counter++;
	}
	return (counter);
}

