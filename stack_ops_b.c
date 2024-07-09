#include "stack_ops.h"
#include "lib/include/libft.h"

/* 
	Seria interesante definir en algun header los 
	stack para ir operando con ellos de forma mas sencilla.
	Se puede leer tanto de un fichero como por parametros en 
	main.

	Las funciones basca
 */

void	stack_swap_b(stack **b)
{
	int	*first_item;
	int	*second_item;

	first_item = stack_pop(b);
	second_item = stack_pop(b);
	if (first_item == NULL
		|| second_item == NULL)
		return ;
	stack_push(b, first_item);
	stack_push(b, second_item);
	ft_printf("sbn");
}

void	stack_push_b_a(stack **b, stack **a)
{
	int	*content1;

	content1 = stack_pop(b);
	if (content1 == NULL)
		return ;
	stack_push(a, content1);
	ft_printf("pba\n");
}
/* Controlar el caso de que la lista tenga un solo valor y dos.
	Especialemente para stack_rotate.
	Quizá el motivo por el que antes no iba era porque aunque
	sea argumento, se le dota de un nuevo espacio en el stack para
	guardar los argumentos.
 */

void	stack_rotate_b(stack **b)
{
	stack	*temporal_stack;
	stack	*holder;
	int		*item;

	if (stack_size(*b) > 1)
	{
		item = stack_pop(b);
		temporal_stack = *b;
		while (temporal_stack != NULL)
		{
			holder = temporal_stack;
			temporal_stack = temporal_stack->next;
		}
		temporal_stack = (stack *) malloc(sizeof(stack));
		temporal_stack->content = item;
		temporal_stack->next = NULL;
		holder->next = temporal_stack;
	}
	ft_printf("rb\n");
}

void	stack_reverse_rotate_b(stack **b)
{
	stack	*temporal_stack;
	stack	*penultimate;
	stack	*last;

	temporal_stack = *b;
	while (temporal_stack != NULL)
	{
		penultimate = last;
		last = temporal_stack;
		temporal_stack = temporal_stack->next;
	}
	stack_push(b, stack_read(last));
	free(last);
	penultimate->next = NULL;
	ft_printf("rrb\n");
}