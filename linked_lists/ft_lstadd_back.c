/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:02:04 by amtadevo          #+#    #+#             */
/*   Updated: 2022/11/22 17:02:05 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*ptr;

	if (*lst == NULL)
		*lst = new;
	else
	{	
		ptr = ft_lstlast(*lst);
		ptr->next = new;
	}
}
