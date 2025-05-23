/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:12:03 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 20:16:52 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "verify.h"

int	is_not_in(int *list_numbers, int content, int len)
{
	int		i;

	i = 0;
	while (i < len - 1)
	{
		if (list_numbers[i] == content)
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(int *list_n, int len)
{
	int			i;

	i = 0;
	while (i < len - 1)
	{
		if (list_n[i] > list_n[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_in_range_of_int(char *next_n)
{
	size_t	len;
	int		max_common;
	char	*ch_number;
	int		sign;

	len = ft_strlen(next_n) - 1;
	sign = next_n[0] == '-';
	max_common = 214748364;
	if (len + 1 > 11 || (len + 1 == 11 && !sign))
		return (0);
	else if (len + 1 < 10)
		return (1);
	if (next_n[0] == '-')
	{
		next_n++;
		len--;
	}
	ch_number = ft_substr(next_n, 0, len);
	if (ft_atoi(ch_number) > max_common)
		return (free(ch_number), 0);
	else if ((sign && next_n[len] > '8') || (!sign && next_n[len] > '7'))
		return (free(ch_number), 0);
	else
		return (free(ch_number), 1);
}

/* 
-Controlar si solo numeros, espacios y signos.
Vacia ??
-Otra para ver el desbordamiento

-Otro para contar los numeros.

Para crear la lista.	

 */

int	not_valid_input(char *argv, int *list_numbers, int content, int len)
{
	if (!is_not_in(list_numbers, content, len))
	{
		write(2, "Error\n", 7);
		return (1);
	}
	else if (!is_in_range_of_int(argv))
	{
		write(2, "Error\n", 7);
		return (1);
	}
	else
		return (0);
}
