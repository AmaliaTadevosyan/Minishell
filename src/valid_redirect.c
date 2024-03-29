/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:33:27 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:33:29 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	valid_redirect_helper(char *ptr, int *i)
{
	int	j;

	while (ptr[(*i)] && ft_strchr(SPACES, ptr[(*i)]))
		(*i)++;
	j = (*i);
	while (ptr[(*i)] && !ft_strchr(METACHARACTER, ptr[(*i)]))
		++(*i);
	if ((*i) == j)
	{
		ft_printf(2, "minishell: syntax error near unexpected\
 token `newline'\n");
		return (1);
	}
	return (0);
}

int	valid_redirect(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		i = for_space(ptr, '\'', i);
		i = for_space(ptr, '"', i);
		while (ptr[i] && ft_strchr(SPACES, ptr[i]))
			i++;
		if (is_redirect_in(ptr[i]) || is_redirect_out(ptr[i]))
		{
			i++;
			if (is_append_in(ptr[i - 1], ptr[i])
				|| is_append_out(ptr[i - 1], ptr[i]))
				i++;
			if (valid_redirect_helper(ptr, &i) != 0)
				return (1);
		}
		if (ptr[i] && ptr[i] != '"' && ptr[i] != '\'')
			++i;
	}
	return (0);
}
