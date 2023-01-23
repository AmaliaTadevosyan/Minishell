#ifndef MINISHELL
# define MINISHELL

# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <term.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "errno.h"

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
# define METACHARACTER "|&;<>() \n\t"

typedef enum
{
	PIPE,        // |
	RED_IN,      // >
	RED_OUT,     // <
	APPEND,      // >>
	HERE_DOC,    // <<
	SEP,       // " "
	SEMI_COLON,   // ;
	WORD,         // "blah"
} consts;

typedef struct s_redirect
{
	char *f_name;
	char *flag;
	char *type;
	struct s_redirect *next;
} t_redirect;

typedef struct s_shell
{
	int	exit_status;
} t_shell;

// typedef struct s_token
// {
// 	int		value;
// 	char	*type;
// 	struct	s_token *next;
// 	struct	s_token *prev;
// } t_token;

typedef struct s_data
{
	char 	*cmd;
	t_token	*token;
	int		error_code;
	t_shell shell;
} t_data;

typedef struct s_cmd
{
	char 			*cmd;
	char			*options;
	struct s_cmd	*next;
} t_cmd;



int     is_space(char c);
int     is_pipe(char c);
int     is_redirect_in(char c);
int     is_redirect_out(char c);
int     is_word(char c);
void    ft_echo(char *str);
void    ft_pwd(char *cwd);
int		ft_exit(char *str);
int 	ft_cd(char *str);
t_token	*create_token(char *str);
bool	is_append(char c, char d);


#endif 