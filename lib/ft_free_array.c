/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:18:05 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 19:57:22 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_free_array(char **marr)
{
	char			*free_ptr;
	unsigned int	i;
	if (marr == NULL)
		return ;
	i = 0;
	while (marr[i])
	{
		free_ptr = marr[i];
		i++;
		free(free_ptr);
	}
	free(marr);
}
