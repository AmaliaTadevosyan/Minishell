#include "../includes/minishell.h"

t_token	*split_string(char *input, t_token *pipe)
{
	int		i;
	int		in_quote;
	int		len;
	t_token	*head;
	t_token	*node;

	i = 0;
	in_quote = 0;
	head = ft_lstnew(&input[0]);
	len = ft_strlen(input);
	while (i < len)
	{
		if (input[i] == '"' || input[i] == '\'')
			in_quote = !in_quote;
		if (input[i] == '|' && !in_quote)
		{
			input[i] = '\0';
			node = ft_lstnew(&input[i + 1]);
			ft_lstadd_back(&head, node);
		}
		i++;
	}
	return (head);
}	