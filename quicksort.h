/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:10:19 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 12:10:20 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICKSORT_H
# define QUICKSORT_H

# include "stack_io.h"
# include "stack_ops.h"
# include "lib/include/libft.h"

int		partitioning(int *array, int cursor_i, int cursor_d);
int		*get_array(t_stack_head *a);
void	quicksort(int *array, int cursor_i, int cursor_d);

#endif