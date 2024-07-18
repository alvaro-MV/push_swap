/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:59 by alvaro            #+#    #+#             */
/*   Updated: 2024/07/18 16:50:57 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPS_H
# define STACK_OPS_H

#include "stack_def.h"

void            stack_push(stack_head *stack, stack_node *new_n);
stack_node	    *stack_pop(stack_head *stack_list);
int				*stack_read(stack_node *item);
void			stack_clean(stack_head *s);
unsigned int	stack_size(stack_head *stack_list);

#endif