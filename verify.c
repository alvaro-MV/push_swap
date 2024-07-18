#include "stack_def.h"

int	is_not_in(int *list_numbers, int content, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (list_numbers[i] == content)
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(int *list_n, int len)
{
	stack_node	*node;
	int			previous;
	
	if (len > 1)
	{
		if (list_n[len - 2] > list_n[len - 1])
			return (0);
	}
	return (1);
}

int	is_numeric(char	*argv)
{
	int	i;

	i = 0;
	if (argv == NULL)
		return (0);
	while (argv[i])
	{
		if (argv[i] < 48 && argv[i] > 57)
			return (0);
	}
	return (1);
}

int	not_valid_input(char *argv, int *list_numbers, int content, int len)
{
	if (!is_in(list_numbers, content, len))
	{
		ft_printf("Repeated integers.\n"); 
		return (1);
	}
	else if (!is_numeric(argv))
	{
		ft_printf("Not numerical entry\n");
		return (1);
	}
	else
		return (0);
}