/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvmoral <alvmoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:08:04 by alvaro            #+#    #+#             */
/*   Updated: 2024/08/20 16:23:35 by alvmoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_io.h"
#include "stack_ops.h"
#include "verify.h"
#include "dictionary.h"
#include "quicksort.h"

/* 
	Gestionar:

	-Valor no numérico. --> Liberar todo lo anterior.

	-Números ordenados?

	-Son iguales?
	
	-Contar numero de argumentos.

	Coger toda la lista. Ver cáracter a carácter.
 */

stack_head	*push_numbers_a(stack_head *a, int *list_numbers, int i)
{
	stack_node	*number;

	while (i--)
	{
		number = (stack_node *) malloc(sizeof(stack_node));
		if (number == NULL)
			return (NULL);
		number->content = list_numbers[i];
		stack_push(a, number);
	}
	return (a);
}

stack_head	*read_list_argum(int argc, char **argv, stack_head *a)
{
	int			*list_numbers;
	int			i;

	i = 0;
	if (argv == NULL)
		return (stack_clean(a), ft_free_array(argv), NULL);
	list_numbers = malloc(count_numbers(argv) * sizeof(int));
	if (list_numbers == NULL)
		return (stack_clean(a), ft_free_array(argv), free(list_numbers), NULL);
	while (argv[i])
	{
		list_numbers[i] = ft_atoi(argv[i]);
		if (not_valid_input(argv[i], list_numbers, list_numbers[i], i + 1))
			return (stack_clean(a), ft_free_array(argv), NULL);
		i++;
	}
	if (is_sorted(list_numbers, argc) || !push_numbers_a(a, list_numbers, i))
		return (stack_clean(a), ft_free_array(argv), free(list_numbers), NULL);
	a->len = (size_t) count_numbers(argv);
	return (a);
}

void	print_state(stack_head *a, stack_head *b)
{
	stack_node	*head_a;
	stack_node	*head_b;

	head_a = a->head;
	head_b = b->head;
	ft_printf("\n");
	while (head_a != NULL || head_b != NULL)
	{
		if (head_a != NULL)
		{
			ft_printf("%i-->%i", stack_read(head_a), head_a->index);
			head_a = head_a->next;
		}
		ft_printf("\t");
		if (head_b != NULL)
		{
			ft_printf("%i-->%i", stack_read(head_b), head_b->index);
			head_b = head_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-\t-\n");
	ft_printf("a\tb\n-------------------\n");
}

dictionary	*get_dict_from_stack(stack_head *a, int *array)
{
	int				i;
	dic_entry		*entry;
	dictionary		*dic;

	i = 0;
	dic = dict_init(2 * (a->len));
	if (dic == NULL)
		return (NULL);
	while (i < a->len)
	{
		entry = (dic_entry *) malloc(sizeof(dic_entry));
		if (entry == NULL)
			return (dict_delete(dic), NULL);
		entry->key = ft_itoa(array[i]);
		entry->value = ft_itoa(i);
		dict_insert(&dic, entry);
		i++;
	}
	return (dic);
}

void	ids_to_stack_from_dic(stack_head *a, dictionary *dic)
{
	stack_node	*tmp;
	char		*content;

	tmp = a->head;
	while (tmp)
	{
		content = ft_itoa(tmp->content);
		tmp->index = ft_atoi(dict_get(dic, content));
		free(content);
		tmp = tmp->next;
	}
	a->dic = dic;
}
