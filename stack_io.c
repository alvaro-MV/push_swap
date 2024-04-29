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

#include "stack_basic_op.h"

/* 
	La lectura de las listas de numeros se pueden hacer pasando 
	argumentos a main, utilizando el separador "/" para diferenciar 
	el stack a y b. Tambien se puede hacer 
 */

void	read_lists_argum(char **argv, stack *a, stack *b)
{
	stack	*filling_stack;
	int		content;

	filling_stack = a;
	while (*argv)
	{
//		if (ft_strncmp(*argv, "/", 1) == 0) // posiblidad de n = ft_strlen
		//{
			//n_sep++;
			//filling_stack = b;
		//}
		content = (int*) malloc(sizeof(int));
		content = ft_atoi(*argv);
		stack_push(&filling_stack, content);
		argv++;
	}
}

/* Hay que gestionar el caso en que el b no se llene. */
void	read_list_file(int fd, stack *a, stack *b)
{
	char	*next_list;
	char	**split_list;
	int		*content;
	stack	*filling_stack;

	filling_stack = a;
	while (fd != -1)
	{
		next_list = get_next_line(fd);
		split_list = ft_split(next_list, ' ');
		free(next_list);
		//n_sep++;
		while (*split_list)	
		{
			content = (int*) malloc(sizeof(int));
			content = ft_atoi(*split_list);
			stack_push(&filling_stack, content);
			split_list++;
		}
	}
}

int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;
	int		fd;

	a = NULL;
	b = NULL;
	if (argc > 1)
		read_lists_argum(argv, a, b);
	else if (fd != -1)
		read_lists_file(fd, a, b);
	//controlar el caso en que a o b sigan siendo NULL.
	return (0);
}