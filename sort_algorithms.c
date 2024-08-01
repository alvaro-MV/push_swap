/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:45:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/06/14 18:39:28by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"


void    sort_two(stack_head *stack, char s)
{
    if (stack->head > stack->head->next)
        swap_dual(stack, s);
}

void	sort_three(stack_head *stack, char s)
{
    int f;
    int s;
    int t;
    stack_node *node;

    node  = stack->head;
    f = node->index;
    s = node->next->index;
    t = node->next->next->index;

    if (f < s && s < t)
        return ;
    else if (f < s && s > t && f < t)
        (swap_dual(stack, s), rotate_dual(stack, s));
    else if (f < s && s > t && f > t)
        reverse_rotate_dual(stack, s);
    else if (f > s && s > t)
        (rotate_dual(stack, s), rotate_dual(stack, s));
    else if (f > s && s < t && f < t)
        swap_dual(stack, s);
    else if (f > s && s < t && f > t)
        rotate_dual(stack, s);
}

void    sort_under_7(stack_head *a, stack_head *b)
{
    
}