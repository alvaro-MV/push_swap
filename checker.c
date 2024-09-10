#include "sort_algorithms.h"
#include "stack_ops.h"
#include "lib/include/libft.h"
#include "quicksort.h"
#include "stack_io.h"
#include "verify.h"

int	map_instructions(char *instr, t_stack_head *a, t_stack_head *b)
{
	if (ft_strcmp(instr, "sa\n") == 0)
		return (checker_swap_a(a), 1);
	else if (ft_strcmp(instr, "sb\n") == 0)
		return (checker_swap_b(b), 1);
	else if (ft_strcmp(instr, "ra\n") == 0)
		return (checker_rotate_a(a), 1);
	else if (ft_strcmp(instr, "rb\n") == 0)
		return (checker_rotate_b(b), 1);
	else if (ft_strcmp(instr, "rra\n") == 0)
		return (checker_reverse_rotate_a(a), 1);
	else if (ft_strcmp(instr, "rrb\n") == 0)
		return (checker_reverse_rotate_a(b), 1);
	else if (ft_strcmp(instr, "pb\n") == 0)
		return (checker_push_a_b(a, b), 1);
	else if (ft_strcmp(instr, "pa\n") == 0)
		return (checker_push_b_a(b, a), 1);
	else
		return (0);
}

void	freee(char **argv, t_stack_head *a, t_stack_head *b)
{
	ft_free_array(argv);
	stack_clean(a);
	stack_clean(b);
}

void	is_stacks_sort(t_stack_head *a, t_stack_head *b)
{
	t_stack_node	*head;
	t_stack_node	*next_node;

	if (b->head)
	{
		ft_printf("KO\n");
		return ;
	}
	head = a->head;
	while (head->next)
	{
		next_node = head->next;
		if (head->content > next_node->content)
		{
			ft_printf("KO\n");
			return ;
		}
		head = head->next;
	}
	ft_printf("OK\n");
}

int	parse_instr(t_stack_head *a, t_stack_head *b)
{
	int		valid_instr;
	char	*instr;

	while (1)
	{
		instr = get_next_line(0);
		if (!instr)
			break ;
		valid_instr = map_instructions(instr, a, b);
		if (!valid_instr)
		{
			ft_printf("KO\n");
			return (0);
		}
		free(instr);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_head	*a;
	t_stack_head	*b;

	a = ft_calloc(1, sizeof(t_stack_head));
	if (a == NULL)
		return (-1);
	b = ft_calloc(1, sizeof(t_stack_head));
	if (b == NULL)
		return (-1);
	argv++;
	if (argc > 2)
	{
		argv = parse_args(argc - 1, argv);
		a = read_list_argum(argv, a);
		if (a == NULL)
			return (stack_clean(b), 0);
		if (!parse_instr(a, b))
			return (freee(argv, a, b), 0);
		is_stacks_sort(a, b);
		freee(argv, a, b);
	}
	return (0);
}
