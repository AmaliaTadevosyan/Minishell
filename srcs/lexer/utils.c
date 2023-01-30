#include "../../includes/minishell.h"

int count_qoutes(char *str, int *i)
{
    if (str[*i + 1] == '\'' || str[*i + 1] == '\"')
        i++;
    return (*i);
}