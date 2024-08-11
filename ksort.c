#include "stack_ops.h"
#include "dictionary.h"
#include "sort_algorithms.h"
#include "quicksort.h"
#include "lib/include/libft.h"
#include "verify.h"

int count_r(stack_head *stack, int idx)
{
    int         count;
    stack_node  *tmp;

    count = 0;
    tmp = stack->head;
    while (tmp)
    {
        if (tmp->index == idx)
            return (count);
        count++;
		//ft_printf("\ncount: %d", count);
        tmp = tmp->next;
    }
    return (0);
}

int count_rr(stack_head *stack, int idx)
{
    int         count;
    stack_node  *tmp;

    count = stack->len;
	//ft_printf("count principio en count_rr: %d\n", count);
    tmp = stack->head;
	//ft_printf("tmp->index: %d\n", tmp->index);
    while (tmp)
    {
        if (tmp->index == idx)
            return (count);
        count--;
		//ft_printf("\ncount: %d", count);
        tmp = tmp->next;
    }
    return (0);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) - number))
			return (i);
	}
	return (i - 1);
}

void	k_sort_1(stack_head *a, stack_head *b)
{
	int	pivot;
	int	i;

	pivot = ft_sqrt(a->len) * 14 / 10;
	i = 0;
	while (a->head != NULL)
	{
		//ft_printf("index_head: %d\n", a->head->index);
		if (a->head->index < i)
		{
			stack_push_a_b(a, b);
			stack_rotate_b(b);
			i++;
		}
		else if (a->head->index < i + pivot)
		{
			stack_push_a_b(a, b);
			i++;
		}
		else
			stack_rotate_a(a);
		//ft_printf("i: %d\n", i); //testeo
	}
	k_sort_2(a, b);
}

void	k_sort_2(stack_head *a, stack_head *b)
{
	int		idx;
	int		count_rot;
	int		count_rrot;

	idx = b->len - 1;
	while (b->head != NULL)
	{
		count_rot = count_r(b, idx);
		count_rrot = count_rr(b, idx);
		//ft_printf("count_rot :%d   ccount_rr: %d\n", count_rot, count_rrot);
		if (count_rot <= count_rrot)
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
		idx--;
		//ft_printf("i: %d\n", idx); //testeo
    }
}
