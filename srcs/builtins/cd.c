#include "../../includes/minishell.h"

int ft_cd(char *str)
{
    if (str == NULL)
        // our env
        chdir(getenv("HOME"));
    chdir(str);
    return (0);
}
