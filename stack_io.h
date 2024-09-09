/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:59:16 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/09 15:26:09 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_IO_H
# define STACK_IO_H

# include "stack_ops.h"
# include "lib/include/libft.h"

stack_head	*read_list_argum(int argc, char **argv, stack_head *a);
void		print_state(stack_head *a, stack_head *b);
dictionary	*get_dict_from_stack(stack_head *a, int *array);
void		ids_to_stack_from_dic(stack_head *a, dictionary *dic);
int			check_digit_spaces(int argc, char **argv);
int			count_numbers(char **argv);
int			only_spaces(char **arg_expansion);
int			fill_args(char **arg_expansion, char **arguments, int *j);
char		**parse_args(int argc, char **argv);

#endif