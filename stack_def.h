/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:14:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/07/09 13:32:36 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

# include <stddef.h>
# include <stdlib.h>

typedef struct stack_n
{
	int					*content;
	struct stack_item	*next;
}						stack_node;

typedef struct stack_h
{
	int					len;
	
}						stack_head;

#endif