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
#include "../libft/include/libft.h"
#include <unistd.h>
#include <stdio.h>

void	print_state(stack *a, stack *b);

//void	*bubble_sort(stack **a, stack **b)
//{
	//int		swap;
	//int		len;

	//len = stack_size(*a);
	//swap = 0;
	//while (1)
	//{
		//swap = 0;
		//while (len--)
		//{
			//stack_push_1_2(a, b);
			//if (stack_read(*b) > stack_read(*a))
			//{
				//stack_push_1_2(b, a);
				//printf("energumeno");
				//stack_swap(a);
				//swap++;
				//stack_push_1_2(a, b);
				//stack_push_1_2(a, b);
				//printf("b que es: %i", *(int*)(*b)->content);
			//}
			//while (b != NULL)
				//stack_push_1_2(b, a);
		//}
		//if (swap == 0)
			//break ;
	//}
//}

void	insertion_sort(stack **a, stack **b)
{
	int		i;
	int		sort_idx;
	size_t	len;

	len = stack_size(*a);
	i = 1;
	while (i < len)
	{
		sort_idx = i;
		write(1, "volcado\n", 8);
		while (sort_idx--)
			stack_push_1_2(a, b);
		print_state(*a, *b);
		sort_idx = i;
		while (sort_idx--)
		{
			if (*stack_read(*a) < *stack_read(*b))
			{
				write(1, "elllo\n", 6);
				stack_push_1_2(b, a);
				print_state(*a, *b);
				stack_swap(a);
			}
			else
			{
				write(1, "rotado\n", 7);
				stack_rotate(b);
			}
			print_state(*a, *b);
		}
		while(*b != 0)
			stack_push_1_2(b, a);
		i++;
	}
}