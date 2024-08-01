/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:14:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/08/01 16:02:40 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

# include <stddef.h>
# include <stdlib.h>
# include "dictionary.h"

typedef struct stack_n
{
	int					content;
	struct stack_n		*next;
	int					index;
}						stack_node;

typedef struct stack_h
{
	int			len;
	stack_node	*head;
	dictionary	*dic;
}				stack_head;

void            stack_push(stack_head *stack, stack_node *new_n);
stack_node	    *stack_pop(stack_head *stack_list);
int				*stack_read(stack_node *item);
void			stack_clean(stack_head *s);
unsigned int	stack_size(stack_head *stack_list);

#endif