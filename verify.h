/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:53:06 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/09 19:58:19 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIFY_H
# define VERIFY_H

# include "stack_def.h"

int	is_sorted(int *list_n, int len);
int	is_not_in(int *list_numbers, int content, int len);
int	is_numeric(char	*argv);
int	is_in_range_of_int(char *next_n);
int	not_valid_input(char *argv, int *list_numbers, int content, int len);

#endif