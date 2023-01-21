#include "../../includes/minishell.h"

void    ft_pwd(char *cwd)
{
    getcwd(cwd, 356);
    printf("%s\n", cwd);
}
