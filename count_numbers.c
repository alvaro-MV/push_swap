/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:33:51 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/09 15:17:19 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_io.h"

static void	count_in_arg(char **argv, int *counter, int i)
{
	int	j;
	int	flag;
	int	n_inside;

	j = 0;
	flag = 1;
	n_inside = *counter;
	while (argv[i][j])
	{
		if (argv[i][j] != 32 && flag)
		{
			*counter = *counter + 1;
			flag = 0;
		}
		else if (argv[i][j] == 32)
			flag = 1;
		j++;
	}
	if (n_inside == *counter)
		*counter = *counter + 1;
}

int	count_numbers(char **argv)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (argv[i])
	{
		count_in_arg(argv, &counter, i);
		i++;
	}
	return (counter);
}

int	only_spaces(char **arg_expansion)
{
	int	i;
	int	j;

	i = 0;
	while (arg_expansion[i])
	{
		j = 0;
		while (arg_expansion[i][j])
		{
			if (arg_expansion[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
