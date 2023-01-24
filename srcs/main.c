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

bool    booool(char *line, int i)
{
    while (line[i])
    {
        // printf("%d i\n", i);
        while(is_space(line[i]))
        {
               printf("line[i] == %c\n", line[i]);
                i--;
        }
           
        // printf("%d i = \n", i);
        printf("line[i] == %c\n", line[i]);
        if (!is_redirect_in(line[i]) && !is_redirect_out(line[i]) && !is_append(line[i], line[i - 1]))
        {
            return (1);
        }
            
        i--;
    }
    return (0);
}

void    get_cmd(char *line)
{
    t_cmd   *head;
    t_cmd   *cmd;
    // char    *line =  "a1111    >> amalia  >>b1>>c<t<o>p<<t<<u lfrt456      ls j <t >u -la";
    // char    *lin =  "< a1111    >>";
    int flag;
    flag = 0;
    int start;
    char *str;
    int i = 0;

    while (line[i] != '\0')
    {
        if (is_redirect_in(line[i]) || is_redirect_out(line[i]))
        {
            i++;
            if (is_append(line[i - 1], line[i]))
                i++;
            flag = 1;
        }
        while (is_space(line[i]))
            i++;
          start = i;
        // printf("start %d\n", start);
        // printf("flag: %d\n", flag);
        if (ft_isalpha(line[i]))
        {
            i++;
        }     
      
        i++;
        if (flag == 1)
        {
            str = ft_substr(line, start, i - start);
            printf("str: %s\n", str);
        }
    }
}

int main(int c, char **v)
{
	t_redirect	*ptr;
	t_redirect	*head;
	char		**argv;
	int i = 0;
	int	x;
	int start;
	char *name;
	ptr = malloc(sizeof(t_redirect));
	head = ptr;
	char *line =  "    >> amalia  >>b>>c<t<o>p<<t<<u     ls <t >u -la";
    // char *line =  ">> a ls";
	x = 1;
	while (line[i] != '\0')
	{
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
			ptr->next = malloc(sizeof(t_redirect));
			ptr = ptr->next;
			x = 1;
		}
		i++;
	}
    //print_redirect(head);
    get_cmd(line);
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