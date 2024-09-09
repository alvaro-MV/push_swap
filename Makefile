SRCS=dictionary.c \
      dictionary2.c \
      ksort.c \
      sort_algorithms.c \
      stack_ops_a.c \
      stack_ops_b.c \
      quicksort.c \
      stack_io.c \
      stack_ops.c \
      verify.c \
      stack_def.c \
      parse_args.c \
	  count_numbers.c \
      main.c

SRCS_DEF=dictionary.c \
      dictionary2.c \
      ksort.c \
      sort_algorithms.c \
      stack_ops_a.c \
      stack_ops_b.c \
      quicksort.c \
      stack_io.c \
      stack_ops.c \
      verify.c \
      stack_def.c \
	  count_numbers.c \
      parse_args.c \

SRCS_BONUS=checker_ops_a.c \
           checker_ops_b.c \
           checker.c

LIB_DIR=./lib
LIB_SRCS=lib/ft_atoi.c \
		  lib/ft_bzero.c \
		  lib/ft_calloc.c \
		  lib/ft_isalnum.c \
		  lib/ft_isalpha.c \
		  lib/ft_isascii.c \
		  lib/ft_isdigit.c \
		  lib/ft_isprint.c \
		  lib/ft_itoa.c \
		  lib/ft_itoa_w.c \
		  lib/ft_memchr.c \
		  lib/ft_memcmp.c \
		  lib/ft_memcpy.c \
		  lib/ft_memmove.c \
		  lib/ft_memset.c \
		  lib/ft_putchar_fd.c \
		  lib/ft_putendl_fd.c \
		  lib/ft_putnbr_fd.c \
		  lib/ft_putstr_fd.c \
		  lib/ft_split.c \
		  lib/ft_free_array.c \
		  lib/ft_strchr.c \
		  lib/ft_strdup.c \
		  lib/ft_striteri.c \
		  lib/ft_strjoin.c \
		  lib/ft_strlcat.c \
		  lib/ft_strlcpy.c \
		  lib/ft_strlen.c \
		  lib/ft_strmapi.c \
		  lib/ft_strncmp.c \
		  lib/ft_strcmp.c \
		  lib/ft_strnstr.c \
		  lib/ft_strrchr.c \
		  lib/ft_strtrim.c \
		  lib/ft_substr.c \
		  lib/ft_tolower.c \
		  lib/ft_toupper.c \
		  lib/ft_printf.c \
		  lib/ft_chtoa.c \
		  lib/ft_ptoa.c \
		  lib/ft_utoa.c \
		  lib/ft_itoa.c \
		  lib/ft_strtoa.c \
		  lib/ft_xtoa.c \
		  lib/MT_random_generator.c \
		  lib/get_next_line.c

LIBFT=./lib/libft.a

NAME=push_swap
NAME_BONUS=checker
CC=cc -Wall -Werror -Wextra

ifeq ($(DEBUG), 1)
    DEBUGFLAGS =-g
endif

OBJ=$(patsubst %.c, %.o, $(SRCS))
OBJ_DEF=$(patsubst %.c, %.o, $(SRCS_DEF))
OBJ_BONUS=$(patsubst %.c, %.o, $(SRCS_BONUS))

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIB_SRCS)
	@make -C $(LIB_DIR)

%.o: %.c
	$(CC) $(DEBUGFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $@

bonus: $(NAME) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(OBJ_DEF) $(OBJ_BONUS) $(LIBFT) -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)
fclean:
	rm -rf $(OBJ) $(OBJ_BONUS) $(NAME) $(NAME_BONUS)
re:
	@make fclean
	@make all
norm: 
	norminette $(SRCS)

.PHONY:all bonus clean fclean re norm
