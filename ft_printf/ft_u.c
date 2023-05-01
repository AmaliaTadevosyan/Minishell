/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:34 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:41:35 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 0 && n < 10)
	{
		n += 48;
		count += ft_c(n, fd);
	}
	else
	{
		count += ft_u(n / 10, fd);
		n = n % 10 + 48;
		count += ft_c(n, fd);
	}
	return (count);
}
