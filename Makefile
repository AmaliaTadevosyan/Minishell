NAME = minishell
CFLAGS = -lreadline -Wall -Wextra -Werror 
CC = cc
RM = rm -f

SRCS = $(shell find ./srcs -name "*.c")
OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a

all: $(LIBFT) $(NAME)

%.c:
	$(CC) $(CFLAGS) -c $(SRCS)

$(LIBFT):
	make -C libft

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIBFT)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) libft/libft.a
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re lib