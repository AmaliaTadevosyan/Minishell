/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:20 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:41:21 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s(char *s, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (!s)
		count += ft_s("(null)", fd);
	else
		while (s[i] != '\0')
			count += write(fd, &s[i++], 1);
	return (count);
}
