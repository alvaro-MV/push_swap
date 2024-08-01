/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:18:59 by alvaro            #+#    #+#             */
/*   Updated: 2024/08/01 16:49:37 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPS_H
# define STACK_OPS_H

#include "stack_def.h"
#include "lib/include/libft.h"

void    stack_swap_a(stack_head *a);
void	stack_push_a_b(stack_head *a, stack_head *b);
void	stack_rotate_a(stack_head *a);
void	stack_reverse_rotate_a(stack_head *a);

void	stack_swap_b(stack_head *b);
void	stack_push_b_a(stack_head *b, stack_head *a);
void	stack_rotate_b(stack_head *b);
void	stack_reverse_rotate_b(stack_head *b);

void	swap_dual(stack_head *stack, char s);
void	rotate_dual(stack_head *stack, char s);
void	reverse_rotate_dual(stack_head *stack, char s);

#endif