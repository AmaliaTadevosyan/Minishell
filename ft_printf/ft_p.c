/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:40:20 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:40:21 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned long int nbr, const char *base, int fd)
{
	int	counter;

	counter = 0;
	if (nbr >= ft_strlen_ft(base))
		counter = counter + ft_nbr_count(nbr / ft_strlen_ft(base), base, fd);
	counter = counter + write(fd, &base[nbr % ft_strlen_ft(base)], 1);
	return (counter);
}

int	ft_p(unsigned long int c, int fd)
{
	int	counter;

	counter = 0;
	counter += write(fd, "0x", 2);
	counter += count(c, "0123456789abcdef", fd);
	return (counter);
}
