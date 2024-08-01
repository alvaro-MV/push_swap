#include "verify.h"

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
	int			i;
	int			previous;
	
	i = 0;
	while (i < len - 1)
	{
		if (list_n[i] > list_n[i + 1])
			return (0);
		i++;
	}
	ft_printf("Error\n");
	return (1);
}

int	is_numeric(char	*next_n)
{
	int	i;

	i = 0;
	if (next_n == NULL)
		return (0);
	while (next_n[i])
	{
		if (next_n[i] < 48 && next_n[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int	is_in_range_of_int(int content)
{
	if (content >= -2147483648 || content <= 2147483647)
		return (1);
	else
		return (0);
}

int	not_valid_input(char *argv, int *list_numbers, int content, int len)
{
	if (len < 2)
	{
		ft_printf("Error\n"); 
		return (1);
	}
	else if (!is_not_in(list_numbers, content, len))
	{
		ft_printf("Error\n"); 
		return (1);
	}
	else if (!is_numeric(argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	else if (!is_in_range_of_int(content))
	{
		ft_printf("Error\n");
		return (1);
	}
	else
		return (0);
}
