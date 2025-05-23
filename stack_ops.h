/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:11:58 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 12:11:59 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPS_H
# define STACK_OPS_H

# include "stack_def.h"
# include "lib/include/libft.h"

void	stack_swap_a(t_stack_head *a);
void	stack_push_a_b(t_stack_head *a, t_stack_head *b);
void	stack_rotate_a(t_stack_head *a);
void	stack_reverse_rotate_a(t_stack_head *a);

void	stack_swap_b(t_stack_head *b);
void	stack_push_b_a(t_stack_head *b, t_stack_head *a);
void	stack_rotate_b(t_stack_head *b);
void	stack_reverse_rotate_b(t_stack_head *b);

void	swap_dual(t_stack_head *stack, char s);
void	rotate_dual(t_stack_head *stack, char s);
void	reverse_rotate_dual(t_stack_head *stack, char s);

void	checker_swap_a(t_stack_head *a);
void	checker_push_a_b(t_stack_head *a, t_stack_head *b);
void	checker_rotate_a(t_stack_head *a);
void	checker_reverse_rotate_a(t_stack_head *a);

void	checker_swap_b(t_stack_head *b);
void	checker_push_b_a(t_stack_head *b, t_stack_head *a);
void	checker_rotate_b(t_stack_head *b);
void	checker_reverse_rotate_b(t_stack_head *b);

#endif