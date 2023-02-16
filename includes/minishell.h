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

typedef struct s_token
{
	char			*arg;
	struct s_token	*next;
}	t_token;

typedef struct s_redirect
{
	char *f_name;
	char *flag;
	char **type;
	struct s_redirect *next;
} t_redirect;

typedef struct s_evn
{
	char *key;
	char *value;
	struct s_env *next;
} t_env;

typedef struct s_shell
{
	int	exit_status;
} t_shell;

typedef struct s_data
{
	char 	*cmd;
	t_token	*token;
	int		error_code;
	t_shell shell;
	t_redirect redirect;
	t_env	*env;
} t_data;

typedef struct s_cmd
{
	char 			*cmd;
	char			*options;
	struct s_cmd	*next;
} t_cmd;

int     	is_space(char c);
int     	is_pipe(char c);
t_token		*ft_lstnew(char *arg);
void		ft_lstadd_front(t_token **lst, t_token *new);
int			ft_lstsize(t_token *lst);
t_token		*ft_lstlast(t_token *lst);
void		ft_lstadd_back(t_token **lst, t_token *new);
void		ft_lstdelone(t_token *lst, void (*del)(char *));
void		ft_lstclear(t_token **lst, void (*del)(char *));
void		ft_lstiter(t_token *lst, void *(*f)(char *));
t_token		*ft_lstmap(t_token *lst, char *(*f)(char *), void (*del)(char *));
t_token		*ft_lstseclast(t_token *lst);
int     	is_redirect_in(char c);
int     	is_redirect_out(char c);
int     	is_word(char c);
void    	ft_echo(char *str);
void    	ft_pwd(char *cwd);
int			ft_exit(char *str);
int 		ft_cd(char *str);
t_token		*create_token(char *str);
bool		is_append(char c, char d);
int			init_env(t_data *data, char **envp);
char		*get_env_value(char *key, t_data *data);
t_token		*split_string(char *input, t_token *pipe);
void		print_redirect(t_redirect *token);
void		print_cmd(t_cmd *token);
t_redirect	*split_redirect(t_token *pipe, t_redirect *ptr, t_cmd *cmd);
char 		*get_flag(char *arg, int i, int x);
char 		*get_f_name(char *arg, int start, int i);
int			get_redirect_len(char *arg, int i);

#endif 