/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:37:20 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:37:21 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	k = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[j])
		j++;
	if (dstsize)
	{
		while ((i + k + 1) < dstsize && src[k])
		{
			dst[i + k] = src[k];
			k++;
		}
	}
	if (i != dstsize)
	{
		dst[i + k] = 0;
	}
	return (i + j);
}
