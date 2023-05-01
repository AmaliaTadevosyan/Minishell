/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:28:58 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:29:00 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote_double(char *ptr)
{
	int		i;
	char	c;

	i = 0;
	while (ptr && ptr[i])
	{
		if (ptr[i] == '"' || ptr[i] == '\'')
		{
			c = ptr[i++];
			while (ptr[i] && ptr[i] != c)
				++i;
			if (ptr[i] == '\0')
			{
				ft_printf(2, "minishell: syntax error near unexpected\
 token `newline'\n");
				return (1);
			}
		}
		i++;
	}
	return (0);
}
