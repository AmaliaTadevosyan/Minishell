NAME = minishell
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f

SRCS = $(shell find ./srcs -name "*.c")
OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

%.c:
	$(CC) $(CFLAGS) -c $(SRCS)

lib:
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) libft/*.o

clean:
	$(RM) $(OBJS) libft/*.o

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re lib