/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:08:04 by alvaro            #+#    #+#             */
/*   Updated: 2024/07/11 17:50:31 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

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

stack_head	*read_list_argum(int argc, char **argv, stack_head *a)
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
			free(content);
			return (NULL);
		}
		stack_push(a, content);
		list_numbers[i++] = *content;
		argv++;
	}
	a->len = (size_t) argc;
	return (a);
}

void	print_state(stack_head *a, stack_head *b)
{
	stack_node	*head_a;
	stack_node	*head_b;
	
	head_a = a->head;
	head_b = b->head;
	while (head_a != NULL || head_b != NULL)
	{
		if (head_a != NULL)
		{
			ft_printf("%i", * (int *) stack_read(head_a));
			head_a = head_a->next;
		}
		ft_printf("\t");
		if (head_b != NULL)
		{
			ft_printf("%i", * (int *) stack_read(head_b));
			head_b = head_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-\t-\n");
	ft_printf("a\tb\n-------------------\n");
}

