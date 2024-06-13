/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:40:35 by alvaro            #+#    #+#             */
/*   Updated: 2024/06/13 17:52:14 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGORITHMS_H
# include "stack_ops.h"

unsigned int	stack_size(stack *item);
void 			stack_swap(stack **s);
void 			stack_push_1_2(stack **item1, stack **item2);
void 			stack_rotate(stack **stack_list);
void 			stack_reverse_rotate(stack **stack_list);

#endif