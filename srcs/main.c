/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtadevo <amtadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:01:52 by tumolabs          #+#    #+#             */
/*   Updated: 2023/03/06 16:45:05 by amtadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_redirect(t_redirect *token)
{
	while (token)
	{
		printf("token->flag: %s\n", token->flag);
		printf("token->value: %s\n", token->f_name);
		token = token->next;
	}
}

void	print_cmd(t_cmd *token)
{
	while (token)
	{
		printf("cmd->cmd: %s\n", token->cmd);
		token = token->next;
	}
}

void	print_pipe(t_token *token)
{
	while (token)
	{
		printf("pipe->arg: %s\n", token->arg);
		token = token->next;
	}
}

// int	main(int c, char **v, char **envp)
// {
// 	t_redirect	*ptr;
// 	t_redirect	*head;

// 	t_cmd       *cmd = malloc(sizeof(t_cmd));
// 	t_token     *pipe = malloc(sizeof(t_token));
// 	char *line =  ft_strdup("echo  >> amalia \"|\" ls <t >u -la | \"he'l'lo >> | m\" 'hello  \"  | world\"   ");
// 	printf("line: %s\n", line);
// 	pipe = split_string(line, pipe);
// 	ptr = malloc(sizeof(t_redirect));
// 	ptr = split_redirect(pipe, ptr, cmd);
// 	print_redirect(head);
// 	print_cmd(cmd);
// 	print_pipe(pipe);
// 	return (0);
// } 


// int main() {
//   int rl_catch_signals = 0; // disable signal catching by readline
//   signal(SIGINT, sig_handler);

//   char* line;
//   while ((line = readline("> ")) != NULL) {
//     add_history(line);

//     printf("hello!\n");

//     free(line);
//   }

//   return 0;
// }


int main(int argc, char **argv, char **envp)
{
	(void) (argc+argv);
	int i;
	t_data data;
	char *ptr;
	
	i = 0;
	signal(SIGINT, sig_handler);
	while (1)
	{
		ptr = readline("minishell-$ ");
		if (*ptr)
			add_history(ptr);
		//Error handling here
		check_quotes(ptr);
		split_string(ptr, &data);
		// t_token *tmp1 = data.token;
		// print_list(data.token);
		
	}
}