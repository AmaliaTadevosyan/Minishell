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

int is_redirect_out(char c)
{
    return (c == '>');
}

int is_word(char c)
{
    return (c != is_space(c) && c != is_pipe(c) && c != is_redirect_in(c) &&
            c != is_redirect_out(c) && c != '"' && c != '\'');
}
