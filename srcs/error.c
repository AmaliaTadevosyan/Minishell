#include "../includes/minishell.h"

int	check_quotes(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			c = str[i++];
			if (str[i] == '\0')
			{
				printf("Unclosed quotes!\n");
				return (1);
			}
			while (str[i] && str[i] != c)
				i++;
			if (str[i] != c)
			{
				printf("Unclosed Quotes!\n");
				return (1);
			}
		}
		i++;
	}
	printf("All quotes are properly closed!\n");
	return (0);
}