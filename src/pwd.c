/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:32:18 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:32:20 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(int fd)
{
	char	cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	else
		ft_printf(fd, "%s\n", cwd);
	return (0);
}
