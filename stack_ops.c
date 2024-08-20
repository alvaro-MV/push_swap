/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:26:06 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/20 16:23:58 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ops.h"

void	swap_dual(stack_head *stack, char s)
{
	if (s == 'a')
		stack_swap_a(stack);
	else if (s == 'b')
		stack_swap_b(stack);
	else
		return ;
}

void	rotate_dual(stack_head *stack, char s)
{
	if (s == 'a')
		stack_rotate_a(stack);
	if (s == 'b')
		stack_rotate_b(stack);
}

void	reverse_rotate_dual(stack_head *stack, char s)
{
	if (s == 'a')
		stack_reverse_rotate_a(stack);
	if (s == 'b')
		stack_reverse_rotate_b(stack);
}
