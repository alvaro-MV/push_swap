/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:40:35 by alvaro            #+#    #+#             */
/*   Updated: 2024/07/18 16:56:00 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGORITHMS_H
# include "stack_ops.h"

void    stack_swap_a(stack_head *a);
void	stack_push_a_b(stack_head *a, stack_head *b);
void	stack_rotate_a(stack_head *a);
void	stack_reverse_rotate_a(stack_head *a);

void	stack_swap_b(stack_head *b);
void	stack_push_b_a(stack_head *b, stack_head *a);
void	stack_rotate_b(stack_head *b);
void	stack_reverse_rotate_b(stack_head *b);

#endif