/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:15:35 by alvmoral          #+#    #+#             */
/*   Updated: 2024/04/11 20:11:23 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/_toa.h"

int	ft_chtoa_w(unsigned int c)
{
	int	counter;

	counter = write(1, &c, 1);
	return (counter);
}
