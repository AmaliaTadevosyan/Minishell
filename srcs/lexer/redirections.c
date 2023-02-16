#include "../includes/minishell.h"

/*
** Splits a single redirection token from the input command and saves
** the relevant information in a t_redirect structure.
*/
t_redirect *split_redirect_token(char *arg, int i, t_redirect *ptr)
{
    ptr->flag = get_flag(arg, i, get_redirect_len(arg, i));
    i += get_redirect_len(arg, i);
    while (is_space(arg[i]))
        i++;
    int start = i;
    while (!ft_strchr(METACHARACTER, arg[i]))
        i++;
    ptr->f_name = get_f_name(arg, start, i);
    printf("token->f_name: %s\n", ptr->f_name);
    ptr->next = malloc(sizeof(t_redirect));
    return (ptr->next);
}

/*
** Splits a single command from the input command and saves it in a t_cmd
** structure.
*/
t_cmd *split_redirect_cmd(char *arg, int i, t_cmd *cmd)
{
	int	start;

    while (ft_isspace(arg[i]))
        i++;
    start = i;
    while (arg[i] && (ft_isalpha(arg[i]) || arg[i] == '-'))
        i++;
    cmd->cmd = ft_substr(arg, start, i - start);
    cmd->next = malloc(sizeof(t_cmd));
    return (cmd->next);
}

/*
** Splits a single argument from the input command by its redirection
** characters and saves the relevant information in a linked list of
** t_redirect structures.
*/
t_redirect *split_redirect_arg(char *arg, t_redirect *ptr, t_cmd *cmd)
{
    int i;

	i = 0;
    while (arg[i] != '\0')
	{
        while (ft_isspace(arg[i]))
            i++;
        if (is_redirect_in(arg[i]) || is_redirect_out(arg[i]))
		{
            ptr = split_redirect_token(arg, i, ptr);
            i += get_redirect_len(arg, i);
        }
		else
		{
            if (i < ft_strlen(arg))
                cmd = split_redirect_cmd(arg, i, cmd);
        }
        i++;
    }
    return (ptr);
}

/*
** Splits the input command by its redirection characters and saves the
** relevant information in a linked list of t_redirect structures.
*/
t_redirect *split_redirect(t_token *pipe, t_redirect *ptr, t_cmd *cmd)
{
    while (pipe)
	{
        ptr = split_redirect_arg(pipe->arg, ptr, cmd);
        pipe = pipe->next;
    }
    return (ptr);
}
