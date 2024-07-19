#include "stack_ops.h"
#include "dictionary.h"
#include "sort_algorithms.h"

int count_r(stack_head *b, unsigned int idx)
{
    int         count;
    stack_node  *tmp;

    count = 0;
    tmp = b->head;
    while (tmp)
    {
        count++;
        if (tmp->index == idx)
            return (count);
        tmp = tmp->next;
    }
    return (0);
}

int count_rr(stack_head *b, unsigned int idx)
{
    int         count;
    stack_node  *tmp;

    count = 0;
    tmp = b->head;
    while (tmp)
    {
        count++;
        if (tmp->index == idx)
            count = 0;
        tmp = tmp->next;
    }
    return (count);
}

void    k_sort1(stack_head *a, stack_head *b)
{
    int pivot;
    int i;

    pivot = a->len/2;
    i = 0;
    while (a->head != NULL)
    {
        if (a->head->index < i)
        {
            stack_push_a_b(a, b);
            stack_rotate_b(b);
        }
        if (a->head->index < i + pivot)
            stack_push_a_b(a, b);
        else
            stack_rotate_a(a);
        i++;
    }
}

void    k_sort_2(stack_head *a, stack_head *b)
{
    unsigned int    idx;
    int             count_rot;
    int             count_rrot;

    idx = 0;
    while (b->head != NULL)
    {
        count_rot = count_r(b, idx);
        count_rrot = count_rr(b, idx);
        if (count_rot < count_rrot)
        {
            while (count_rot--)
                stack_rotate_b(b);
        }
        else
        {
            while (count_rrot--)
                stack_reverse_rotate_b(b);
        }
        stack_push_b_a(b, a);
        idx++;
    }
}
