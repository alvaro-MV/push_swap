/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:45:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/04/30 21:03:59 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_op.h"

stack	*bubble_sort(stack *a, char *record, size_t len)
{
	int		swap;
	stack	*b;

	swap = 0;
	b = NULL;
	while (1)
	{
		swap = 0;
		while (len--)
		{
			stack_push_1_2(a, b);
			print_state(a, b, record);
			if (stack_read(b) > stack_read(a))
			{
				stack_swap(&a);
				swap++;
				stack_push_1_2(a, b);
				stack_push_1_2(a, b);
				print_satate(a, b, record);
			}
			while (b != NULL)
				stack_push_1_2(a, b);
			print_sate(a, b, record);
		}
		if (swap == 0)
			break ;
	}
	return (a);
}

stack	*insertion_sort(stack *a, size_t len)
{
	int		temp;
	stack	*b;

	b = NULL;
	while (len--)
	{
		temp = stack_pop(&a);
		while (b != NULL && stack_read(b) > temp)
			stack_push_1_2(a, b);
		stack_push(&a, temp);
	}
	while (b != NULL)
		stack_push_1_2(b, a);
}