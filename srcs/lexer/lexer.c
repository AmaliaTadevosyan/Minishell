#include "../includes/minishell.h"

void next()
{
	char *last_pos;
	int hash;

	while (token = *src)
	{
		++src;
		//Parse token
		if (token == '\n')
			++line;
	}
	return;
}