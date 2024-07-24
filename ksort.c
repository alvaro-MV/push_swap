#include "stack_ops.h"
#include "dictionary.h"
#include "sort_algorithms.h"
#include "quicksort.h"
#include "lib/include/libft.h"
#include "verify.h"

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

void    k_sort1(stack_head *a, stack_head *b)
{
    int pivot;
    int i;
    int j;

    pivot = a->len/2;
    i = 0;
    while (a->head != NULL)
    {
        j = a->len;
        while (j--)
        {
            if (a->head->index < i)
            {
                stack_push_a_b(a, b);
                stack_rotate_b(b);
            }
            else if (a->head->index < i + pivot)
                stack_push_a_b(a, b);
            else
                stack_rotate_a(a);
        }
        i++;
    }
    k_sort_2(a, b);
}

int	main(int argc, char **argv)
{
	stack_head	*a;
	stack_head	*b;
	dictionary	*dic;
	int			len;
    int         *array;

	a = ft_calloc(1, sizeof(stack_head));
	if (a== NULL)
		return (-1);
	b = ft_calloc(1, sizeof(stack_head));
	if (b == NULL)
		return (-1);
    len = 0;
	if (argc > 1)
	{
		a = read_list_argum(argc-1, argv, a);
		if (a  == NULL)
			return (0);
		array = get_array(a);
		quicksort(array, 0, a->len - 1);
		dic = get_dict_from_stack(a, array);
		ids_to_stack_from_dic(a, dic);
		b->dic = dic;
        k_sort1(a, b);
		free(array);
		stack_clean(a);
		stack_clean(b);
	}
	return (0);
}
