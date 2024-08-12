/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 19:53:06 by alvmoral          #+#    #+#             */
/*   Updated: 2024/08/12 14:06:30 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIFY_H
# define VERIFY_H

# include "stack_def.h"

int	is_sorted(int *list_n, int len);
int	is_not_in(int *list_numbers, int content, int len);
int	is_in_range_of_int(char *next_n);
int	not_valid_input(char *argv, int *list_numbers, int content, int len);

#endif