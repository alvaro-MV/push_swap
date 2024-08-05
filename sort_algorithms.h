/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:40:35 by alvaro            #+#    #+#             */
/*   Updated: 2024/08/05 18:19:30 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGORITHMS_H
# define SORT_ALGORITHMS_H

# include "stack_ops.h"
#include "stack_io.h"
#include "lib/include/libft.h"

int     count_r(stack_head *stack, unsigned int idx);
int     count_rr(stack_head *stack, unsigned int idx);

void    sort_two(stack_head *stack, char s);
void	sort_three(stack_head *stack, char s);
void    push_n_to_b(stack_head *a, stack_head *b, int n_to_b, int init_len);
void    compare_and_push(stack_head *a, stack_head *b, int r_count, int rr_count);
void    __sort__(stack_head *a, stack_head *b);

int	    ft_sqrt(int number);
void    k_sort_1(stack_head *a, stack_head *b);
void    k_sort_2(stack_head *a, stack_head *b);

#endif