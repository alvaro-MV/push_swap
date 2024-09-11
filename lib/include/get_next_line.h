#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define FILE_PATH "textos/ejemplo.txt"

typedef struct s_list_g
{
	void			*content;
	struct s_list_g	*next;
}					t_list_g;

char	*get_next_line(int fd);
char	*ft_strchr_g(char *s, int c);
void	ft_lstadd_front_g(t_list_g **lst, char *content);
void	ft_lstadd_back_g(t_list_g **lst, char *content);
void	ft_lstclear_g(t_list_g **lst);
int		ft_lstsize_g(t_list_g *lst);

#endif