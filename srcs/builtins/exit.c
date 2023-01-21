#include "../../includes/minishell.h"

int is_digit(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
           return (2);
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
            return (2);
        i++;
    }
    return (0);
}

int ft_exit(char *str)
{
    long double max;
    char  **line;

    max = 9223372036854775807;
    
    line = ft_split(str, ' ');
    int i = 0;
    while (line[i])
    {
        printf("line[%d]= %s\n", i, line[i]);
        i++;
    }
    printf("ft_atoi max: %d\n", ft_atoi(line[1]));
    if (line[0] && !line[1])
    {
    //   shell.exit_status = 0;
        exit(0);
    }
    else if (line[0] && is_digit(line[1]) && line[2])
    {
        printf("exit: too many arguments\n");
        // shell.exit_status = 2;
        // exit(2);
    }
    else if (line[0] && is_digit(line[1]))
    {
    //    shell.exit_status = ft_atoi(&str[2]) % 256;
        exit(ft_atoi(&str[1]));
    }
    else if (line[0] && is_char(line[1]))
    {
        printf("exit: %s: numeric argument required\n", line[1]);
        // shell.exit_status = 255;
        // exit(255);
    }
    else if (ft_atoi(line[1]) > max)
    {
        printf("exit: %s: numeric argument required\n", line[1]);
        //  shell.exit_status = 255;
        exit(255);
    }
    return (0);
}
