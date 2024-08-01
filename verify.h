#ifndef VERIFY_H
# define VERIFY_H

#include "stack_def.h"

int	is_sorted(int *list_n, int len);
int	is_not_in(int *list_numbers, int content, int len);
int	is_numeric(char	*argv);
int	is_in_range_of_int(int content);
int	not_valid_input(char *argv, int *list_numbers, int content, int len);

#endif