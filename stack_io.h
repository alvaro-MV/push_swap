/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_io.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:11:33 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/10 12:11:34 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_IO_H
# define STACK_IO_H

# include "stack_ops.h"
# include "lib/include/libft.h"

t_stack_head	*read_list_argum(char **argv, t_stack_head *a);
void			print_state(t_stack_head *a, t_stack_head *b);
t_dictionary	*get_dict_from_stack(t_stack_head *a, int *array);
void			ids_to_stack_from_dic(t_stack_head *a, t_dictionary *dic);
int				check_digit_spaces(int argc, char **argv);
int				count_numbers(char **argv);
int				only_spaces(char **arg_expansion);
int				fill_args(char **arg_expansion, char **arguments, int *j);
char			**parse_args(int argc, char **argv);

#endif