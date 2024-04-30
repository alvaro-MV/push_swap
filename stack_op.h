/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:59 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/30 18:21:54 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef OP_H
# define OP_H

#include "stack_basic_op.h"
#include "stack_def.h"

unsigned int	stack_size(stack *item);
void 			stack_swap(stack **s);
void 			stack_push_1_2(stack *item1, stack *item2);
void 			stack_rotate(stack **stack_list);
void 			stack_reverse_rotate(stack **stack_list);

#endif