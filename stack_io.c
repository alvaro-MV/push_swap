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

size_t	read_list_argum(char **argv, stack *a)
{
	int		content;
	size_t	n_nodes;

	while (*argv)
	{
		content = (int*) malloc(sizeof(int));
		content = ft_atoi(*argv);
		stack_push(&a, content);
		argv++;
		n_nodes++;
	}
	return (n_nodes);
}

//void	read_list_file(int fd, stack *a, stack *b)
//{
	//char	*next_list;
	//char	**split_list;
	//int		*content;
	//stack	*filling_stack;

	//filling_stack = a;
	//while (fd != -1)
	//{
		//next_list = get_next_line(fd);
		//split_list = ft_split(next_list, ' ');
		//free(next_list);
		////n_sep++;
		//while (*split_list)	
		//{
			//content = (int*) malloc(sizeof(int));
			//content = ft_atoi(*split_list);
			//stack_push(&filling_stack, content);
			//split_list++;
		//}
	//}
//}

void	register_instrcutions(char *record, char *instruction)
{
	size_t	len_instr;
	size_t	len_record;

	len_instr = ft_strlen(instruction);
	len_record = ft_strlen(record);
	if (len_record == 0)
		record = (char *) malloc(len_instr + 2);
	else
	{
		free(record);
		record = (char *) malloc(len_instr + len_record + 2);
	}
	ft_strlcat(record, instruction);
	ft_strlcat(record, " ");
}

void	print_state(stack *a, stack *b, char *record)
{
	print_instructions(record);
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			ft_printf("%i  ", stack_read(a));
			a = a->next;
		}
		if (b != NULL)
		{
			ft_printf("%i", stack_read(b));
			b = b->next;
		}
	}
	ft_printf("-  -");
	ft_printf("a  b");
}

int	main(int argc, char **argv)
{
	stack	*a;
	int		fd;

	a = NULL;
	if (argc > 1)
		read_lists_argum(argv, a);
	else if (fd != -1)
		read_lists_file(fd, a);
	//controlar el caso en que a o b sigan siendo NULL.
	return (0);
}