/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_exit_status_in_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:28:06 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:28:09 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_exit_status_in_env(t_data *data, int status)
{
	char	*tmp;

	tmp = ft_itoa(status);
	ft_t_env_add_back(&data->head_env, new_t_env("?", tmp));
	free(tmp);
	return (1);
}
