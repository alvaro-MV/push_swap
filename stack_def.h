/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:14:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/06/14 16:47:35 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

# include <stddef.h>
# include <stdlib.h>

typedef struct stack_item
{
	int					*content;
	struct stack_item	*next;
}						stack;

#endif