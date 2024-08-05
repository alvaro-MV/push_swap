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
      main.c

LIB_DIR=./lib
LIBFT=./lib/libft.a
NAME=push_swap
CC=cc -Wall -Werror -Wextra
OBJ=$(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $@

clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(OBJ) $(EXEC)
re:
	@make fclean
	@make all
norm: norminette $(SRCS)

.PHONY:all clean fclean re norm