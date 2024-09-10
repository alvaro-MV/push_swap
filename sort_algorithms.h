/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:10:36 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 12:10:37 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_ALGORITHMS_H
# define SORT_ALGORITHMS_H

# include "stack_ops.h"
# include "stack_io.h"
# include "lib/include/libft.h"

int		count_r(t_stack_head *stack, int idx);
int		count_rr(t_stack_head *stack, int idx);

void	sort_two(t_stack_head *stack, char s);
void	sort_three(t_stack_head *stack, char st);
void	sort_under_7(t_stack_head *a, t_stack_head *b);
void	push_n_to_b(t_stack_head *a, t_stack_head *b, int n_to_b, int init_len);
void	compare_and_push(t_stack_head *a, t_stack_head *b, int r_c, int rr_c);
void	__sort__(t_stack_head *a, t_stack_head *b);

int		ft_sqrt(int number);
void	k_sort_1(t_stack_head *a, t_stack_head *b);
void	k_sort_2(t_stack_head *a, t_stack_head *b);

#endif