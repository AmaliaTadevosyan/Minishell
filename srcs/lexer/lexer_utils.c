#include "../../includes/minishell.h"

int is_space(char c)
{
    return (c <= 32);
}

int is_pipe(char c)
{
    return (c == '|');
}

int is_redirect_in(char c)
{
    return (c == '<');
}

int is_redirect_ouy(char c)
{
    return (c == '>');
}


