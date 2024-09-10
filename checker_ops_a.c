#include "stack_ops.h"

void	checker_swap_a(t_stack_head *a)
{
	t_stack_node	*first_item;
	t_stack_node	*second_item;

	first_item = stack_pop(a);
	second_item = stack_pop(a);
	if (first_item == NULL
		|| second_item == NULL)
		return ;
	stack_push(a, first_item);
	stack_push(a, second_item);
}

void	checker_push_a_b(t_stack_head *a, t_stack_head *b)
{
	t_stack_node	*content1;

	content1 = stack_pop(a);
	if (content1 == NULL)
		return ;
	stack_push(b, content1);
}

void	checker_rotate_a(t_stack_head *a)
{
	t_stack_node	*head;
	t_stack_node	*holder;
	t_stack_node	*item;

	if (stack_size(a) > 1)
	{
		item = stack_pop(a);
		head = a->head;
		while (head != NULL)
		{
			holder = head;
			head = head->next;
		}
		holder->next = item;
		item->next = head;
		a->len++;
	}
}

void	checker_reverse_rotate_a(t_stack_head *a)
{
	t_stack_node	*head;
	t_stack_node	*penultimate;
	t_stack_node	*last;

	head = a->head;
	while (head != NULL)
	{
		penultimate = last;
		last = head;
		head = head->next;
	}
	stack_push(a, last);
	a->len--;
	penultimate->next = NULL;
}
