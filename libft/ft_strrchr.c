/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:38:12 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:38:13 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		i;
	int		j;
	char	l;

	l = c;
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j++;
		i++;
	}
	while (j >= 0)
	{
		if (s[j] == l)
			return ((char *)&s[j]);
		j--;
	}
	return (NULL);
}
