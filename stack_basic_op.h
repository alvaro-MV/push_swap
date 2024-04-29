/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_op.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:14:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/29 18:43:26 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

#include <stddef.h>
#include <stdlib.h>

typedef struct stack_item
{
	void				*content;
	struct stack_item	*next;
}						stack;

void stack_push(stack **stack_list, void *content);
void *stack_pop(stack **stack_list);
void *stack_read(stack *item);
void stack_rotate(stack **stack_list);

#endif