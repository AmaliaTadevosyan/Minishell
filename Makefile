NAME		= minishell
SRCS		= $(shell find ./srcs -name "*.c")
OBJS		= ${SRCS:.c=.o}
CC			= cc
INCLUDES	= -I./includes
CFLAGS		=  -Wall -Werror -Wextra
RM			= rm -f

.c.o :
	${CC} ${CFLAGS} $(INCLUDES) -c $< -o ${<:.c=.o}

all : $(NAME)
	
$(NAME) : ${OBJS}
	$(CC) $(CFLAGS) $(INCLUDES) ${OBJS} -o $(NAME) 

clean :
	${RM} ${OBJS} ${B_OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re