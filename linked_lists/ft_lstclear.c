/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:02:16 by amtadevo          #+#    #+#             */
/*   Updated: 2022/11/22 17:02:17 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstclear(t_token **lst, void (*del)(char *))
{
	t_token	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		del((*lst)->arg);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
