/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:45:26 by alvaro            #+#    #+#             */
/*   Updated: 2024/06/14 18:39:28by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort_algorithms.h"
#include "lib/include/libft.h"
#include <unistd.h>
#include <stdio.h>

void	print_state(stack *a, stack *b);

void	insertion_sort(stack **a, stack **b)
{
	int		i;
	int		contador;
	int		sort_idx;
	size_t	len;

	len = stack_size(*a);
	i = 1;
	contador = 0;
	while (i < len)
	{
		sort_idx = i;
		//write(1, "volcado\n", 8);
		while (sort_idx--)
		{
			stack_push_1_2(a, b);
			contador++;
		}
		//print_state(*a, *b);
		sort_idx = i;
		while (sort_idx--)
		{
			if (*stack_read(*a) < *stack_read(*b))
			{
				//write(1, "elllo\n", 6);
				stack_push_1_2(b, a);
				//print_state(*a, *b);
				stack_swap(a);
				contador += 2;
			}
			else
			{
				//write(1, "rotado\n", 7);
				stack_rotate(b);
				contador++;
			}
			//print_state(*a, *b);
		}
		while(*b != 0)
		{
			stack_push_1_2(b, a);
			contador++;
		}
		//write(1, "vaciado_b\n", 10);
		//print_state(*a, *b);
		i++;
	}
	printf("contador:%i", contador);
}
