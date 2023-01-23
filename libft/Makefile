NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra# -fsanitize=address
AR		= ar rcs
RM		= rm -f

SRCS	=	$(wildcard ft_*.c)

OBJS	=	$(patsubst %.c, %.o, $(SRCS))

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
