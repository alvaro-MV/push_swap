/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 21:17:44 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/11 21:49:28 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/libft.h"

int	check_digit_spaces(int argc, char *argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		while (*argv[i])
		{
			if ((*argv[i] < 48 || *argv[i] > 57) && *argv[i] != 32)
				return (0);
		}
		i++;
	}
	return (1);
}

int	count_numbers(char **argv)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] != 32)
				counter++;
			j++;
		}
	}
	return (counter);
}

char	**parse_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	**arguments;
	char	**arg_expansion;

	if (!check_digit_spaces(argc, argv))
	{
		ft_printf("Error\n");
		return (NULL);
	}
	arguments = ft_calloc(count_numbers(argv), sizeof(char *));
	if (arguments == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (argv[i])
	{
		arg_expansion = ft_split(argv[i], ' ');
		if (arg_expansion == NULL)
			return (free_array(arguments), NULL);
		while (*arg_expansion)
		{
			if (*arg_expansion[0] != ' ')
			{
				arguments[j] = *arg_expansion;
				j++;
			}
			else
				free(*arg_expansion);
			arg_expansion++;
		}
		i++;
	}
	return (arguments);
}
//Comprobar si hay alguna caracter que no sea digito o espacio. Expandir los argumentos en todos sus numeros. Contabilizar el número de elementos.