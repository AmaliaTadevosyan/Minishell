#include "../includes/minishell.h"

// int main(int c, char **v)
// {
// 	t_redirect	*ptr;
// 	t_redirect	*head;
// 	char		**argv;
	
// 	int i = 0;
// 	int	x;
// 	int start;
// 	char *name;
// 	ptr = malloc(sizeof(t_redirect));
// 	head = ptr;
// 	char *line =  "    >> amalia  >>b>>c<t<o>p<<t<<u ls <t >u -la";
// 	x = 1;
// 	while (line[i] != '\0')
// 	{
// 		if (is_redirect_in(line[i]) || is_redirect_out(line[i]))
// 		{
// 			if (is_append(line[i], line[i + 1]))
// 				x++;
// 			ptr->flag = ft_substr(line, i, x);
// 			i += x;
// 			while (is_space(line[i]))
// 				i++;
// 			start = i;
// 			while (!ft_strchr(METACHARACTER, line[i]))
//                 i++;
// 			ptr->f_name = ft_substr(line, start, i - start);
// 			ptr->next = malloc(sizeof(t_redirect));
// 			ptr = ptr->next;
// 			x = 1;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int check_symbol(char *str)
{
    int i;
    i = 0;
    if(str[i] == '-')
    {
        i++;
    while (str[i] && str[i] == 'n') 
    {
        i++;
    }
        if(str[i] == '\0')
         return (1);
    
        else 
            return (0);
    }
    
    return (0);
}


void    ft_echo(char *str)
{
    int     i;
    int     flag;
    char    **ptr;

    i = 0;
    flag = 0;
    ptr = ft_split(str, ' ');

    while(ptr[i])
    {
        if(check_symbol(ptr[i]) == 0)
        {

            write(1, ptr[i], ft_strlen(ptr[i]));
            i++;
            if(ptr[i + 1] == '\0')
            {
                write(1, " ", 1);
            }
        }
        else
        {

            flag = 1;
            i++;
        }
    }
    if (flag == 0)
    {
        write(1, "\n", 1);
    }
    
}




int main(void)
{
    char *cmd;
    char **line;
  
  

    while(1)
    {
        cmd = readline("minishell$ ");
        //printf("%s\n", cmd);
        line = ft_split(cmd, ' ');
        ft_echo(&cmd[5]);
    }
    return (0);
} 