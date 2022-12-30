SRCS = $(addsuffix .c, $(addprefix srcs/builtins/, $(BUILTINS)))
 	 
OBJS = $(SRCS:.c=.o)

CC = cc

RM = rm -f

CFLAGS = -c -Wall -Wextra -Werror -lreadline
LINK = -lft -Llibft
NAME = minishell

all: lib $(NAME)

%.c:
	$(CC) $(CFLAGS) $(SRCS)

lib:
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(LINK) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS) libft/*.o

fclean: clean
	$(RM) $(NAME) libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus .c.o lib