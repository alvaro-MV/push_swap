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