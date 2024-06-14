/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:08:04 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/29 18:47:51y alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ops.h"
#include "lib/include/ft_printf.h"
#include "lib/include/_toa.h"
#include "lib/include/libft.h"

/* 
	La lectura de las listas de numeros se pueden hacer pasando 
	argumentos a main, utilizando el separador "/" para diferenciar 
	el stack a y b. Tambien se puede hacer 
 */

int	is_in(int *list_numbers, int content, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (list_numbers[i] == content)
			return (1);
		i++;
	}
	return (0);
}

stack	*read_list_argum(int argc, char **argv, stack *a)
{
	int		*content;
	int		list_numbers[argc];
	int		i;

	argv++;
	i = 0;
	while (*argv)
	{
		content = (int *) malloc(sizeof(int));
		*content = ft_atoi(*argv);
		if (is_in(list_numbers, *content, i))
		{
			stack_clean(a);
			return (NULL);
		}
		stack_push(&a, content);
		list_numbers[i++] = *content;
		argv++;
	}
	return (a);
}

void	print_state(stack *a, stack *b)
{
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			ft_printf("%i", * (int *) stack_read(a));
			a = a->next;
		}
		ft_printf("\t");
		if (b != NULL)
		{
			ft_printf("%i", * (int *) stack_read(b));
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-\t-\n");
	ft_printf("a\tb\n-------------------\n");
}

