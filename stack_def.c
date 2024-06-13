/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:39 by alvaro            #+#    #+#             */
/*   Updated: 2024/06/13 15:16:43 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Para aclararnos: initializa, --> lo mismo que el de abajo
push (que pongas uno encima), --> lstnew + addback.
pop (elimina y devuelve) y --> delone y devolver el contenido
read (lee el ultimo) --> accede al contenido. 
*/

#include "stack_def.h"
#include <stdio.h>

void    stack_push(stack **stack_list, void *content)
{
	stack  *list;
	stack  *holder;
	stack  *new_n;

	new_n = (stack *) malloc(sizeof(stack));
	if (new_n == NULL)
		return ;
	new_n->content = content;
	if (*stack_list != NULL)
	{
		list = *stack_list;
		new_n->next = list;
	}
	*stack_list = new_n;
}

void    *stack_pop(stack **stack_list)
{
	int		*return_content;
	stack	*holder;
	stack	*s;

	s = *stack_list;
	if (s == NULL)
		return (NULL);
	return_content = s->content;
	printf(" retu: %i\n", *return_content);
	holder = s->next;
	free(s);
	*stack_list = holder;
	return(return_content);
}

void	*stack_read(stack *item)
{
	return (item->content);
}

void	stack_clean(stack * s)
{
	stack  *holder;

	while (s != NULL)
	{
			holder = s;
			s = s->next;
			free(holder->content);
			free(holder);
	}
	s = NULL;	
}