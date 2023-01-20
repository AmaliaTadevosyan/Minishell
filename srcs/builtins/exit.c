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

void check_digit(int c, char **v)
{
    if (c >= 3)
    {
        if (is_digit(v[2]))
        {
            printf("exit: too many arguments\n");
            exit(0);
        }
    }
}

void check_char(int c, char **v)
{
    if (c >= 3)
    {
        if (ft_isalpha(v[2][0]))
        {
            printf("exit: %s : numeric argument required", v[2]);
            exit(0);
        }
    }
}
