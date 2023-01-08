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

typedef struct s_data
{
	int	status;
} t_data;


typedef struct s_token
{
	int		len;
	char	*begin;
	int		type;
} t_token;

typedef struct s_cmd
{
	char *cmd;
} t_cmd;

#endif