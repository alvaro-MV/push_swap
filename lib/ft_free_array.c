#include "include/libft.h"

void	ft_free_array(char **marr)
{
	char			*free_ptr;
	unsigned int	i;

	if (marr == NULL)
		return ;
	i = 0;
	while (marr[i])
	{
		free_ptr = marr[i];
		i++;
		free(free_ptr);
	}
	free(marr);
}