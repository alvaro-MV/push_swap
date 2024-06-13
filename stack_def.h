/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:14:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/06/13 13:43:17 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

# include <stddef.h>
# include <stdlib.h>

typedef struct stack_item
{
	void				*content;
	struct stack_item	*next;
}						stack;

#endif