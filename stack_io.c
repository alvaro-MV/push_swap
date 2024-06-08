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
#include "../libft/include/ft_printf.h"
#include "../libft/include/_toa.h"
#include "../libft/include/libft.h"

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
		content = ft_atoi(*argv);
		stack_push(&a, &content);
		argv++;
		n_nodes++;
	}
	return (n_nodes);
}

//void	register_instrcutions(char *record, char *instruction)
//{
	//size_t	len_instr;
	//size_t	len_record;

	//len_instr = ft_strlen(instruction);
	//len_record = ft_strlen(record);
	//if (len_record == 0)
		//record = (char *) malloc(len_instr + 2);
	//else
	//{
		//free(record);
		//record = (char *) malloc(len_instr + len_record + 2);
	//}
	//ft_strlcat(record, instruction);
	//ft_strlcat(record, " ");
//}

void	print_state(stack *a, stack *b, char *record)
{
	//print_instructions(record);
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
		read_list_argum(argv, a);
	//controlar el caso en que a o b sigan siendo NULL.
	return (0);
}
