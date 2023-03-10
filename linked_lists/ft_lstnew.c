/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:03:20 by amtadevo          #+#    #+#             */
/*   Updated: 2022/11/22 17:03:21 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*ft_lstnew(char *arg)
{
	t_token	*new_node;

	new_node = (t_token *)malloc(sizeof(t_token));
	if (new_node == NULL)
		return (NULL);
	new_node -> arg = arg;
	new_node -> next = NULL;
	return (new_node);
}
