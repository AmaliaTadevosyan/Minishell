/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:02:35 by amtadevo          #+#    #+#             */
/*   Updated: 2022/11/22 17:02:36 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_token *lst, void *(*f)(int))
{
	t_token	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->data);
		tmp = tmp -> next;
	}
}
