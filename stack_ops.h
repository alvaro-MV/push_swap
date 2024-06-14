/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:59 by alvaro            #+#    #+#             */
/*   Updated: 2024/06/14 16:47:52 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPS_H
# define STACK_OPS_H

#include "stack_def.h"

void	stack_push(stack **stack_list, void *content);
int     *stack_pop(stack **stack_list);
int     *stack_read(stack *item);
void	stack_clean(stack *s);

#endif