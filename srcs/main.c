#include "../includes/minishell.h"

void    print_redirect(t_redirect *token)
{
    while (token)
    {
        printf("token->flag: %s\n", token->flag);
        printf("token->value: %s\n", token->f_name);
        token = token->next;
    }
}

void    print_cmd(t_cmd *token)
{
    while (token)
    {
        printf("cmd->cmd: %s\n", token->cmd);
        // printf("token->value: %s\n", token->f_name);
        token = token->next;
    }
}

int main(int c, char **v)
{
	t_redirect	*ptr;
	t_redirect	*head;

	// char		**cmd_arr;
    t_cmd       *cmd = malloc(sizeof(t_cmd));
    t_cmd       *ccmd;
	int i = 0;
	int	x;
	int start;
    int j;
	char *name;
    int k;
	ptr = malloc(sizeof(t_redirect));
	head = ptr;
    ccmd = cmd;
	char *line =  "    >> amalia ls <t >u -la";
    // char *line =  ">> a lokoos";
	x = 1;
	while (line[i] != '\0')
	{
        while (ft_isspace(line[i]))
            i++;
		if (is_redirect_in(line[i]) || is_redirect_out(line[i]))
		{
			if (is_append(line[i], line[i + 1]))
				x++;
			ptr->flag = ft_substr(line, i, x);
			i += x;
			while (is_space(line[i]))
				i++;
			start = i;
			while (!ft_strchr(METACHARACTER, line[i]))
                i++;
			ptr->f_name = ft_substr(line, start, i - start);
            i--;
			ptr->next = malloc(sizeof(t_redirect));
			ptr = ptr->next;
			x = 1;
		}
        else
        {
            while (ft_isspace(line[i]))
                i++;
            k = i;
            while (line[i] && (ft_isalpha(line[i]) || line[i] == '-'))
                i++;
            cmd->cmd = ft_substr(line, k, i - k);
            // printf("cmd: %s\n", cmd->cmd);
            cmd->next = malloc(sizeof(t_cmd));
            cmd = cmd->next;
        }
		i++;
	}
    print_redirect(head);
    print_cmd(ccmd);
    // get_cmd(line);
	return (0);
}

/*
int main()
{
    // char *cmd;
    // char **line;

    // while(1)
    // {
        // cmd = readline("minishell$ ");
        //printf("%s\n", cmd);  
        // line = ft_split(cmd, ' ');
        // ft_echo(&cmd[5]);
        // int i = 0;
        // while (cmd[i])
        // {
        //     printf("cmd[%d]= %c\n", i, cmd[i]);
        //     i++;
        // }
        // i = 0;
        // while (line[i])
        // {
        //     printf("line[%d]= %s\n", i, line[i]);
            // i++;
        // }
        // printf("cmd[5]: %c\n", cmd[5]);
        // ft_cd(line[1]);
        // ft_exit(cmd);
        // printf("hello\n");
        // char *line =  "    >>amalia >>b>>c<t<o>p<<t<<u ls <t >u -la";
        // // char *line =  "'echo'  \"cd\"";
        // // t_redirect *token = malloc(sizeof(t_redirect));
        t_redirect *tmp;

        // tmp = create_token(line);
        // print_redirect(tmp);
        // ft_pwd(&cmd[3]);1
    // }
    return (0);
} 
*/