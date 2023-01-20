#include "../../includes/minishell.h"

int is_digit(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
           return (1);
        i++;
    }
    return (0);
}

int is_char(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isalpha(str[i]))
        {   
            printf("exit: %s : numeric argument required", str[i]);
            return (1);
        }
        i++;
    }
    return (0);
}

int exit(t_shell *shell, char *str)
{
    long double max;
    char  **line;

    max = 9223372036854775807;
    
    line = ft_split(str, ' ');
    if (line[0] && !line[1])
    {
      shell->exit_status = 0;
      exit(shell->exit_status);
    }
    else if (line[0] && !is_digit(line[1]))
    {
       shell->exit_status = ft_atoi(str[1] % 256);
       exit(shell->exit_status);
    }
    else if (!is_char(line[1]))
    {
        printf("exit: %s : numeric argument required", line[1]);
        shell->exit_status = 255;
        exit(shell->exit_status);
    }
    else if (line[0] && is_digit(line[1]) && line[2])
    {
        printf("exit: too many arguments\n");
        shell->exit_status = 1;
        exit(1);
    }
    else if (ft_atoi(line[1]) > max)
    {
         printf("exit: %s : numeric argument required", line[1]);
         shell->exit_status = 255;
         exit(shell->exit_status);
    }
}
