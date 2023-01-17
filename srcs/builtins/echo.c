#include "../../includes/minishell.h"

int check_symbol(char *str)
{
    int i;
    i = 0;

    while (str[i])
    {
        if (str[i] == '-')
        {
            i++;
            if(str[i] && str[i] == 'n')
                return (1);
        }
        else 
            return (0);
    }
    return (0);
}


void    echo(char *str)
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
            write(1, &ptr[i], ft_strlen(ptr[i]));
            i++;
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