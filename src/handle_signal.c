/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:30:33 by amtadevo          #+#    #+#             */
/*   Updated: 2023/04/06 15:54:30 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_int(int sig_num)
{
	(void)sig_num;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	g_signal = sig_num;
}

void	handle_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &sig_int);
	g_signal = 0;
}
