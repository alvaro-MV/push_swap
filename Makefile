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
      main.c

SRCS_DEF=$(filter-out main.c, $(SRCS))


SRCS_BONUS=checker_ops_a.c \
           checker_ops_b.c \
           checker.c

LIB_DIR=./lib
LIB_SRCS=$(wildcard $(LIB_DIR)/*.c)
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
	rm -rf $(OBJ)
fclean:
	rm -rf $(OBJ) $(NAME) $(NAME_BONUS)
re:
	@make fclean
	@make all
norm: 
	norminette $(SRCS)

.PHONY:all bonus clean fclean re norm
