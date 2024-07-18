/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:14:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/07/18 16:37:40 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

# include <stddef.h>
# include <stdlib.h>
# include "dictionary.h"

typedef struct stack_n
{
	int					content;
	struct stack_n		*next;
	int					index;
}						stack_node;

typedef struct stack_h
{
	int			len;
	stack_node	*head;
	dictionary	*dic;
}				stack_head;

#endif