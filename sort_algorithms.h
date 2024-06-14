/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:40:35 by alvaro            #+#    #+#             */
/*   Updated: 2024/06/14 23:35:51 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGORITHMS_H
# include "stack_ops.h"

void 			stack_swap_a(stack **s);
void 			stack_push_a_b(stack **item1, stack **item2);
void 			stack_rotate_a(stack **stack_list);
void 			stack_reverse_rotate_a(stack **stack_list);

void 			stack_swap_b(stack **s);
void 			stack_push_b_a(stack **item1, stack **item2);
void 			stack_rotate_b(stack **stack_list);
void 			stack_reverse_rotate_b(stack **stack_list);

#endif