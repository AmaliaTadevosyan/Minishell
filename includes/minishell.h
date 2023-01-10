#ifndef MINISHELL
# define MINISHELL

# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <term.h>
# include <stdbool.h>
# include "./libft/libft.h"


typedef struct s_token
{
	char 	*value;
	int		type;
	struct	s_token *next;
	struct	s_token *prev;
	
} t_token;

typedef struct s_data
{
	char 	*cmd;
	t_token	*token;
	int		error_code;
} t_data;

#endif