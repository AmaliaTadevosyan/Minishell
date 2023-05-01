/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:41:39 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:41:40 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xl(unsigned int n, int fd)
{
	int	count;

	count = 0;
	count += ft_nbr_count(n, "0123456789ABCDEF", fd);
	return (count);
}
