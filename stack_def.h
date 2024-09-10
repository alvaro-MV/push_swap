/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:14:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/09/10 09:36:41 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_DEF_H
# define STACK_DEF_H

# include <stddef.h>
# include <stdlib.h>
# include "dictionary.h"

typedef struct stack_n
{
	int					content;
	struct stack_n		*next;
	int					index;
}						t_stack_node;

typedef struct stack_h
{
	int				len;
	t_stack_node	*head;
	t_dictionary	*dic;
}				t_stack_head;

void			stack_push(t_stack_head *stack, t_stack_node *new_n);
t_stack_node	*stack_pop(t_stack_head *stack_list);
int				stack_read(t_stack_node *node);
void			stack_clean(t_stack_head *s);
unsigned int	stack_size(t_stack_head *stack_list);

#endif