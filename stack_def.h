/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:20 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/29 16:07:21 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef STACK_DEF_H
 # define STACK_DEF_H

#include <stddef.h>

typedef struct stack_item
{
	void				*content;
	struct stack_item	*next;
}						stack;

#endif