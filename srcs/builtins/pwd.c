#include "../../includes/minishell.h"

void    ft_pwd()
{
    char    cwd[356];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}