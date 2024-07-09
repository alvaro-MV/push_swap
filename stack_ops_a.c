#include "stack_ops.h"
#include "lib/include/libft.h"

/* 
	Seria interesante definir en algun header los 
	stack para ir operando con ellos de forma mas sencilla.
	Se puede leer tanto de un fichero como por parametros en 
	main.
 */

void	stack_swap_a(stack **a)
{
	int	*first_item;
	int	*second_item;

	first_item = stack_pop(a);
	second_item = stack_pop(a);
	if (first_item == NULL
		|| second_item == NULL)
		return ;
	stack_push(a, first_item);
	stack_push(a, second_item);
	ft_printf("sa\n");
}

void	stack_push_a_b(stack **a, stack **b)
{
	int	*content1;

	content1 = stack_pop(a);
	if (content1 == NULL)
		return ;
	stack_push(b, content1);
	ft_printf("pab\n");
}
/* Controlar el caso de que la lista tenga un solo valor y dos.
	Especialemente para stack_rotate.
	Quizá el motivo por el que antes no iba era porque aunque
	sea argumento, se le dota de un nuevo espacio en el stack para
	guardar los argumentos.
 */

void	stack_rotate_a(stack **a)
{
	stack	*temporal_stack;
	stack	*holder;
	int		*item;

	if (stack_size(*a) > 1)
	{
		item = stack_pop(a);
		temporal_stack = *a;
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
	ft_printf("ra\n");
}

void	stack_reverse_rotate_a(stack **a)
{
	stack	*temporal_stack;
	stack	*penultimate;
	stack	*last;

	temporal_stack = *a;
	while (temporal_stack != NULL)
	{
		penultimate = last;
		last = temporal_stack;
		temporal_stack = temporal_stack->next;
	}
	stack_push(a, stack_read(last));
	free(last);
	penultimate->next = NULL;
	ft_printf("rra\n");
}