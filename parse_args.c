/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:22:59 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/26 18:42:39 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/include/libft.h"

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

int	count_numbers(char **argv)
{
	int	i;
	int	j;
	int	counter;
	int	flag;

	i = 0;
	counter = 0;
	while (argv[i])
	{
		j = 0;
		flag = 1;
		while (argv[i][j])
		{
			if (argv[i][j] != 32 && flag)
			{
				counter++;
				flag = 0;
			}
			else if (argv[i][j] == 32)
				flag = 1;
			j++;
		}
		i++;
	}
	return (counter);
}

void	fill_args(char **arg_expansion, char **arguments, int *j)
{
	unsigned int	idx_arg_exp;

	idx_arg_exp = 0;
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
		fill_args(arg_expansion, arguments, &j);
		free(arg_expansion);
		i++;
	}
	arguments[j] = NULL;
	return (arguments);
}

//int	main(int argc, char **argv)
//{
	//char	**args_parsed;
	//char	*freed_arg;

	//argv++;
	//args_parsed = parse_args(argc - 1, argv);
	//if (args_parsed == NULL)
		//return (-1);
	//while(*args_parsed)
	//{
		//freed_arg = *args_parsed;
		//ft_printf("%s\n", *args_parsed);
		//free(freed_arg);
		//args_parsed++;
	//}
	//return (0);
//}