NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

SRCS = main.c \
push_swap.c \
push_swap_set_values.c \
push_int_utils.c \
push_do_rot_utils.c \
push_and_main_utils.c \
parse_utils_split.c \
parse_token.c \
op_swap.c \
op_rotate.c \
op_reverse.c \
op_push.c \
list_mem_handling.c \
list_func.c \

HEADER = push_swap.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
