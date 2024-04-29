/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:39 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/29 20:20:03 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Para aclararnos: initializa, --> lo mismo que el de abajo
push (que pongas uno encima), --> lstnew + addback.
pop (elimina y devuelve) y --> delone y devolver el contenido
read (lee el ultimo) --> accede al contenido. 
*/

#include "stack_def.h"

void    stack_push(stack **stack_list, void *content)
{
	stack  *list;
	stack  *holder;
	stack  *new_n;

	new_n = (stack *) malloc(sizeof(stack));
	if (new_n == NULL)
		return ;
	new_n->content = content;
	if (stack_list != NULL)
	{
		list = *stack_list;
		new_n->next = list;
		*stack_list = new_n;
	}
	else
		stack_list = &new_n;
}

void    *stack_pop(stack **stack_list)
{
	void	*return_content;
	stack	*holder;

	if (*stack_list = NULL)
		return (NULL);
	return_content = (*stack_list)->content;
	holder = (*stack_list)->next;
	free(*stack_list);
	stack_list = &holder;
	return(return_content);
}

void	*stack_read(stack *item)
{
	return (item->content);
}
