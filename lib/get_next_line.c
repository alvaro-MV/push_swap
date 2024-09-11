/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro <alvaro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:50:45 by alvmoral          #+#    #+#             */
/*   Updated: 2024/09/11 10:02:00 by alvaro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
	{
		while (n--)
		{
			*(char *) s = 0;
			s++;
		}
	}
}

static char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		len;
	int		i;

	if (s1 == NULL)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[len])
		len++;
	ptr = (char *) malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	get_lst_from_reads(int fd, t_list_g **lst)
{
	char		*read_buffer;
	t_list_g	*last_node;
	int			bytes_read;
	int			eol_present;

	bytes_read = 1;
	last_node = *lst;
	read_buffer = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
	while (bytes_read)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read < 0)
			return (free(read_buffer), 0);
		read_buffer[bytes_read] = '\0';
		ft_lstadd_back_g(&last_node, ft_strdup(read_buffer));
		if (*lst == NULL)
			return (0);
		eol_present = (ft_strchr_g(read_buffer, '\n') != NULL);
		if (eol_present)
			break ;
		last_node = last_node->next;
	}
	free(read_buffer);
	return (bytes_read);
}

static void	fill_buffers(t_list_g *lst, char *return_buffer, char *after_eol)
{
	t_list_g	*first_node;
	char		*lst_content;
	int			i;

	if (lst == NULL)
		return ;
	i = 0;
	first_node = lst;
	while (lst)
	{
		lst_content = lst->content;
		while (*lst_content && *lst_content != '\n')
			return_buffer[i++] = *lst_content++;
		if (*lst_content == '\n')
		{
			return_buffer[i++] = *lst_content++;
			break ;
		}
		lst = lst->next;
	}
	return_buffer[i] = '\0';
	while (*lst_content)
		*after_eol++ = *lst_content++;
	*after_eol = '\0';
	ft_lstclear_g(&first_node);
}

char	*get_next_line(int fd)
{
	static char	after_eol[BUFFER_SIZE];
	char		*return_buffer;
	t_list_g	*lst;
	int			bytes_read;

	if (fd < 0)
		return (NULL);
	lst = NULL;
	bytes_read = 1;
	ft_lstadd_front_g(&lst, ft_strdup(after_eol));
	if (lst == NULL)
		return (NULL);
	if (ft_strchr_g(after_eol, '\n') == NULL)
		bytes_read = get_lst_from_reads(fd, &lst);
	return_buffer = (char *) malloc(BUFFER_SIZE * ft_lstsize_g(lst) + 1);
	ft_bzero(return_buffer, BUFFER_SIZE * (ft_lstsize_g(lst) - 1) + 1);
	fill_buffers(lst, return_buffer, after_eol);
	if (bytes_read == 0)
		after_eol[0] = '\0';
	if (return_buffer[0] == '\0' && bytes_read <= 0)
	{
		free(return_buffer);
		return (NULL);
	}
	return (return_buffer);
}
