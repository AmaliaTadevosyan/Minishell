RED="\033[1;31m"
GREEN='\033[3;32m'
NONE='\033[0m'

PREFIX = $(shell find ${HOME} -name rd 2>/dev/null)

NAME = minishell

CC = cc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

SRCS = $(wildcard *.c) $(wildcard srcs/*.c) $(wildcard srcs/builtins/*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

INCLUDES = -ILibft  -I./rd/include

LINKERS	= -L./libft  -L./rd/lib -lreadline

LINKERLIB = ./libft/libft.a

LIBFT = ./libft

RM = rm -f

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: readline $(NAME) 
all: $(NAME) 
	
$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@cp $(LINKERLIB) $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(LINKERS) $(INCLUDES) $(NAME) -o $(NAME)
	@echo $(NONE) $(GREEN)"       >Compiled< $(NAME)" $(NONE)

clean:
	@$(MAKE) clean -C $(LIBFT)
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT)
	@$(RM) $(NAME)
	@stty sane
	@echo $(NONE) $(RED)"       >Removed< $(NAME)" $(NONE)

readline: 
	cd readline-master && make clean && ./configure --prefix=$(PREFIX) && make && make install

re: fclean all

norm: clean
	norminette $(SRCS)

.PHONY: all clean fclean re
