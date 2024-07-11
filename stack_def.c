/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:39 by alvaro            #+#    #+#             */
/*   Updated: 2024/07/11 18:48:08 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Para aclararnos: initializa, --> lo mismo que el de abajo
push (que pongas uno encima), --> lstnew + addback.
pop (elimina y devuelve) y --> delone y devolver el contenido
read (lee el ultimo) --> accede al contenido. 
*/

#include "stack_def.h"
#include <stdio.h>

void    stack_push(stack_head *stack_list, void *content)
{
	stack_node  *new_n;

	new_n = (stack_node *) malloc(sizeof(stack_node));
	if (new_n == NULL)
		return ;
	new_n->content = content;
	if (stack_list != NULL)
		new_n->next = stack_list->head;
	stack_list->head = new_n;
	stack_list->len++;
}

int	*stack_read(stack_node *node)
{
	return (node->content);
}

int    *stack_pop(stack_head *stack_list)
{
	int			*return_content;
	stack_node	*head;
	stack_node	*holder;

	if (stack_list == NULL)
		return (NULL);
	head = stack_list->head;
	if (head == NULL)
		return (NULL);
	return_content = stack_read(head);
	holder = head->next;
	free(head);
	stack_list->head = holder;
	stack_list->len--;
	return(return_content);
}

void	stack_clean(stack_head * stack_list)
{
	stack_node  *holder;

	while (stack_list->head != NULL)
	{
			holder = stack_list->head;
			stack_list->head = stack_list->head->next;
			free(holder->content);
			free(holder);
	}
	free(stack_list);
}

unsigned int	stack_size(stack_head *stack_list)
{
	stack_node	*temporal;
	int			counter;

	counter = 0;
	temporal = stack_list->head;
	while (temporal != NULL)
	{
		temporal = temporal->next;
		counter++;
	}
	return (counter);
}

