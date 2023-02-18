#include "../../includes/minishell.h"


int	ft_unset(char **args, t_env **env)
{
	int	i;

	if (args[1] == NULL)
		printf("unset not enough arguments");
	i = 0;
  //remove_env();

	return (0);
}