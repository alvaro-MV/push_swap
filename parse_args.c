/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:03:36 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 09:43:45 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/libft.h"
#include "stack_io.h"

int	check_digit_spaces(int argc, char **argv)
{
	int	i;
	int	j;
	int	not_number;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == 32)
			j++;
		if (argv[i][j] == 43 || argv[i][j] == 45)
			j++;
		if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j])
			return (0);
		while (argv[i][j])
		{
			not_number = argv[i][j] < 48 || argv[i][j] > 57;
			if (not_number && argv[i][j] != 32)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	fill_args(char **arg_expansion, char **arguments, int *j)
{
	unsigned int	idx_arg_exp;

	idx_arg_exp = 0;
	if (only_spaces(arg_expansion) == 1)
	{
		arguments[*j] = ft_strdup(" ");
		*j = *j + 1;
		ft_free_array(arg_expansion);
		ft_printf("Error\n");
		return (0);
	}
	while (arg_expansion[idx_arg_exp])
	{
		if (arg_expansion[idx_arg_exp][0] != ' ')
		{
			arguments[*j] = arg_expansion[idx_arg_exp];
			*j = *j + 1;
		}
		else
			free(arg_expansion[idx_arg_exp]);
		idx_arg_exp++;
	}
	return (1);
}

char	**intialize_parse_var(int *i, int *j, char **argv)
{
	char	**arguments;

	arguments = ft_calloc(count_numbers(argv) + 1, sizeof(char *));
	if (arguments == NULL)
		return (NULL);
	*i = 0;
	*j = 0;
	return (arguments);
}

char	**parse_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	**arguments;
	char	**arg_expansion;

	if (!check_digit_spaces(argc, argv))
	{
		write(2, "Error\n", 7);
		return (NULL);
	}
	arguments = intialize_parse_var(&i, &j, argv);
	if (!arguments)
		return (NULL);
	while (argv[i])
	{
		arg_expansion = ft_split(argv[i], ' ');
		if (arg_expansion == NULL)
			return (ft_free_array(arguments), NULL);
		if (!fill_args(arg_expansion, arguments, &j))
			return (ft_free_array(arguments), NULL);
		free(arg_expansion);
		i++;
	}
	arguments[j] = NULL;
	return (arguments);
}
