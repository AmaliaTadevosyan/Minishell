
#include "../includes/minishell.h"

/*
** Returns the flag associated with a redirection character.
*/
char	*get_flag(char *arg, int i, int x)
{
	return (ft_substr(arg, i, x));
}

/*
** Returns the file name associated with a redirection character.
*/
char	*get_f_name(char *arg, int start, int i)
{
	return (ft_substr(arg, start, i - start));
}

/*
** Returns the length of a redirection token, taking into account whether
** it is an append redirect.
*/
int	get_redirect_len(char *arg, int i)
{
	int	x;

	x = 1;
	if (arg[i + 1] && is_append(arg[i], arg[i + 1]))
		x++;
	return (x);
}
