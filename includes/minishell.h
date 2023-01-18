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
# include "../libft/libft.h"

// typedef int (*t_builtin_ptr)(t_list *, t_info);

// typedef struct s_list
// {    

// } t_list;

// typedef struct s_info 
// {
// 	t_builtin_ptr	builtins[7];
// 	char 			reserved_words[7];
// 	char 			**envp;
// 	t_list 			envp_list;
// 	int				envp_flag;
// 	int				exit_t;//flag 0;
// 	int				status;
	


// } t_info;

typedef struct s_token
{
	char 	*value;
	char	*type;
	struct	s_token *next;
	struct	s_token *prev;
} t_token;

typedef struct s_data
{
	char 	*cmd;
	t_token	*token;
	int		error_code;
} t_data;


int     is_space(char c);
int     is_pipe(char c);
int     is_redirect_in(char c);
int     is_redirect_out(char c);
int     is_word(char c);
void    ft_echo(char *str);

#endif 