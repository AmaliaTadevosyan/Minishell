NAME = minishell
CFLAGS = -c -Wall -Wextra -Werror
CC = cc
RM = rm -f

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

%.c:
	$(CC) $(CFLAGS) $(SRCS)

lib:
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(LINK) $(OBJS) -o $(NAME) libft/*.o

clean:
	$(RM) $(OBJS) libft/*.o

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus .c.o lib