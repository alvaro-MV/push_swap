#include "stack_ops.h"

/* 
	Seria interesante definir en algun header los 
	stack para ir operando con ellos de forma mas sencilla.
	Se puede leer tanto de un fichero como por parametros en 
	main.

	Las funciones basca
 */

void	checker_swap_b(t_stack_head *b)
{
	t_stack_node	*first_item;
	t_stack_node	*second_item;

	first_item = stack_pop(b);
	second_item = stack_pop(b);
	if (first_item == NULL
		|| second_item == NULL)
		return ;
	stack_push(b, first_item);
	stack_push(b, second_item);
}

void	checker_push_b_a(t_stack_head *b, t_stack_head *a)
{
	t_stack_node	*content1;

	content1 = stack_pop(b);
	if (content1 == NULL)
		return ;
	stack_push(a, content1);
}

void	checker_rotate_b(t_stack_head *b)
{
	t_stack_node	*head;
	t_stack_node	*holder;
	t_stack_node	*item;

	if (stack_size(b) > 1)
	{
		item = stack_pop(b);
		head = b->head;
		while (head != NULL)
		{
			holder = head;
			head = head->next;
		}
		holder->next = item;
		item->next = head;
		b->len++;
	}
}

void	checker_reverse_rotate_b(t_stack_head *b)
{
	t_stack_node	*head;
	t_stack_node	*penultimate;
	t_stack_node	*last;

	head = b->head;
	while (head != NULL)
	{
		penultimate = last;
		last = head;
		head = head->next;
	}
	stack_push(b, last);
	b->len--;
	penultimate->next = NULL;
}
