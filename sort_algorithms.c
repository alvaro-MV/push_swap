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

/*  
Optimizacion del algoritmo: count_r y count_rr,
*/
void    sort_under_7(stack_head *a, stack_head *b)
{
    int         n_to_b;
    int         init_len;
    stack_node  *node;

    if (a->len == 2)
        return (sort_two(a, 'a'));
    if (a->len == 3)
        return (sort_three(a, 'a'));
    n_to_b = a->len % 3;
    node = a->head;
    init_len = a->len;
    while (a->len > init_len - n_to_b)
    {
        if (node->index <= n_to_b -1)
            stack_push_a_b(a, b);
        stack_rotate_a(a);
    }
    sort_three(a, 'a');
    if (n_to_b == 2)
        sort_two(b, 'b');
    if (n_to_b == 3)
        sort_two(b, 'b');
    while (b->head)
        stack_push_b_a(b, a);
}

void    __sort__(stack_head *a, stack_head *b)
{
    if (a->len <= 7)
        sort_under_7(a, b);
    else
    {
        k_sort_1(a, b);
        k_sort_2(a, b);
    }
}