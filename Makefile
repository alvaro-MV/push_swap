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
LIB_SRCS=$(wildcard $(LIB_DIR)/*.c)
LIBFT=./lib/libft.a

NAME=push_swap
CC=cc -Wall -Werror -Wextra

ifeq ($(DEBUG), 1)
    DEBUGFLAGS =-g
endif

OBJ=$(patsubst %.c, %.o, $(SRCS))

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIB_SRCS)
	@make -C $(LIB_DIR)

%.o: %.c
	$(CC) $(DEBUGFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $@

clean:
	rm -rf $(OBJ)
fclean:
	rm -rf $(OBJ) $(NAME)
re:
	@make fclean
	@make all
norm: 
	norminette $(SRCS)

.PHONY:all clean fclean re norm
