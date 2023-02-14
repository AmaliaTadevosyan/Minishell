// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/02/02 16:01:52 by tumolabs          #+#    #+#             */
// /*   Updated: 2023/02/14 17:10:40 by tumolabs         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/minishell.h"

// // void	print_redirect(t_redirect *token)
// // {
// // 	while (token)
// // 	{
// // 		printf("token->flag: %s\n", token->flag);
// // 		printf("token->value: %s\n", token->f_name);
// // 		token = token->next;
// // 	}
// // }

// // void	print_cmd(t_cmd *token)
// // {
// // 	while (token)
// // 	{
// // 		printf("cmd->cmd: %s\n", token->cmd);
// // 		token = token->next;
// // 	}
// // }

// // int count_quote(char *s, char c)
// // {
// //     int i;
// //     int count;

// //     i = 0;
// //     count = 0;
// //     while (s[i])
// //     {
// //         if (s[i] == c)
// //             count++;
// //         i++;
// //     }
// //     return (count);
// // }

// // char    *clean_quotes(char *str)
// // {
// //     int     i;
// //     int     j;
// //     char    *clean;

// //     i = 0;
// //     j = 0;
// //     clean = ft_strdup("");
// //     while (str[i])
// //     {
// //         if (str[i] != '\'' && count_quote(str, '\'') % 2 == 0)
// //             clean[j++] = str[i];
// //         i++;
// //     }
// //     return (clean);
// // }

// // // int main(int c, char **v)
// // // {
// // // 	while (token)
// // // 	{
// // // 		printf("pipe->arg: %s\n", token->arg);
// // // 		token = token->next;
// // // 	}
// // // }

// // t_token	*split_string(char *input, const char *delimiter, t_token *pipe)
// // {
// // 	int		i;
// // 	int		token_index;
// // 	int		in_quote;
// // 	t_token	*head;
// // 	t_token	*node;

// // 	i = 0;
// // 	token_index = 0;
// // 	in_quote = 0;
// // 	head = ft_lstnew(&input[0]);
// // 	while (i++ < ft_strlen(input))
// // 	{
// // 		if (input[i] == '"' || input[i] == '\'')
// // 		{
// // 			in_quote = !in_quote;
// // 		}
// // 		if (input[i] == *delimiter && !in_quote)
// // 		{
// // 			input[i] = '\0';
// // 			token_index++;
// // 			node = ft_lstnew(&input[i + 1]);
// // 			ft_lstadd_back(&head, node);
// // 		}
// // 	}
// // 	return (head);
// // }

// // t_redirect	*split_redirect(t_token *pipe, t_redirect *ptr)
// // {
// // 	int			i;
// // 	int			x;
// // 	int			start;
// // 	t_redirect	*head;

// // 	i = 0;
// // 	head = ptr;
// //     ccmd = cmd;
// // 	char *line =  ft_strdup("ec''''ho  >> 'amalia | ls' <t >u -la \"he'l'lo >>  m\" |  'hello  \"   world'   ");
// // 	x = 1;
// // 	while (line[i] != '\0')
// // 	{
// // 		while (pipe->arg[i] != '\0')
// // 		{
// // 			while (ft_isspace(pipe->arg[i]))
// // 				i++;
// // 			if (is_redirect_in(pipe->arg[i]) || is_redirect_out(pipe->arg[i]))
// // 			{
// // 				if (pipe->arg[i + 1] && is_append(pipe->arg[i], pipe->arg[i + 1]))
// // 					x++;
// // 				ptr->flag = ft_substr(pipe->arg, i, x);
// // 				i += x;
// // 				while (is_space(pipe->arg[i]))
// // 					i++;
// // 				start = i;
// // 				while (!ft_strchr(METACHARACTER, pipe->arg[i]))
// // 					i++;
// // 				ptr->f_name = ft_substr(pipe->arg, start, i - start);
// // 				printf("token->f_name: %s\n", ptr->f_name);
// // 				i--;
// // 				ptr->next = malloc(sizeof(t_redirect));
// // 				ptr = ptr->next;
// // 				x = 1;
// // 			}
// // 			i++;
// // 		}
// //         // else if (line[i] == '"') 
// //         // {
// //         //     i++;
// //         //     start = i;
// //         //     while (line[i] != '"')
// //         //         i++;
// //         //     cmd->cmd = ft_substr(line, start, i - start);
// //         //     cmd->next = malloc(sizeof(t_cmd));
// //         //     cmd = cmd->next;
// //         // }
// //         // else if (line[i] == '\'')
// //         // {
// //         //     i++;
// //         //     start = i;
// //         //     while (line[i] != '\'')
// //         //         i++;
// //         //     cmd->cmd = ft_substr(line, start, i - start);
// //         //     cmd->next = malloc(sizeof(t_cmd));
// //         //     cmd = cmd->next;
// //         // }
// //         else
// //         {
// //             if (i < ft_strlen(line))
// //             {
// //                 while (ft_isspace(line[i]))
// //                     i++;
// //                 k = i;
// //                 while (line[i] && (ft_isalpha(line[i]) || line[i] == '-'))
// //                     i++;
// //                 cmd->cmd = ft_substr(line, k, i - k);
// //                 cmd->next = malloc(sizeof(t_cmd));
// //                 cmd = cmd->next;
// //             }
// //         }
// // 		i++;
// // 	}
// //     print_redirect(head);
// //     print_cmd(ccmd);
// //     // char *l = "h'h'hyhyhyh\"\"\"\"\"\"Hel'''lo\"\"\"\"\"\" bhyyb  jhuhb";
// //     // printf("' count: %d\n", count_quote(line, '\''));
// //     // printf("\" count: %d\n", count_quote(line, '"'));
// //     // printf("cleaned string: %s\n", clean_quotes(line));
// // 	return (0);
// // }

// // int	main(int c, char **v, char **envp)
// // {
// // 	t_redirect	*ptr;
// // 	t_redirect	*head;

// // 	// char		**cmd_arr;
// // 	t_cmd       *cmd = malloc(sizeof(t_cmd));
// // 	// t_cmd       *ccmd;
// // 	t_token     *pipe = malloc(sizeof(t_token));
// // 	// int i = 0;
// // 	// int	x;
// // 	// int start;
// // 	// char *name;
// // 	// int k;
// // 	// int count;
// // 	// ccmd = cmd;
// // 	char *line =  ft_strdup("echo  >> amalia \"|\" ls <t >u -la | \"he'l'lo >> | m\" 'hello  \"  | world'   ");
// // 	// x = 1;
// // 	// while (line[i] != '\0')
// // 	// {
// // 	// 	while (ft_isspace(line[i]))
// // 	// 		i++;
// // 	// 	if (is_redirect_in(line[i]) || is_redirect_out(line[i]))
// // 	// 	{
// // 	// 		if (line[i + 1] && is_append(line[i], line[i + 1]))
// // 	// 			x++;
// // 	// 		ptr->flag = ft_substr(line, i, x);
// // 	// 		i += x;
// // 	// 		while (is_space(line[i]))
// // 	// 			i++;
// // 	// 		start = i;
// // 	// 		while (!ft_strchr(METACHARACTER, line[i]))
// // 	// 			i++;
// // 	// 		ptr->f_name = ft_substr(line, start, i - start);
// // 	// 		i--;
// // 	// 		ptr->next = malloc(sizeof(t_redirect));
// // 	// 		ptr = ptr->next;
// // 	// 		x = 1;
// // 	// 	}
// // 	// 	else if (line[i] == '"') 
// // 	// 	{
// // 	// 		i++;
// // 	// 		start = i;
// // 	// 		while (line[i] != '"')
// // 	// 			i++;
// // 	// 		cmd->cmd = ft_substr(line, start, i - start);
// // 	// 		cmd->next = malloc(sizeof(t_cmd));
// // 	// 		cmd = cmd->next;
// // 	// 	}
// // 	// 	else if (line[i] == '\'')
// // 	// 	{
// // 	// 		i++;
// // 	// 		start = i;
// // 	// 		while (line[i] != '\'')
// // 	// 			i++;
// // 	// 		cmd->cmd = ft_substr(line, start, i - start);
// // 	// 		cmd->next = malloc(sizeof(t_cmd));
// // 	// 		cmd = cmd->next;
// // 	// 	}
// // 	// 	else
// // 	// 	{
// // 	// 		if (i < ft_strlen(line))
// // 	// 		{
// // 	// 			while (ft_isspace(line[i]))
// // 	// 				i++;
// // 	// 			k = i;
// // 	// 			while (line[i] && (ft_isalpha(line[i]) || line[i] == '-'))
// // 	// 				i++;
// // 	// 			cmd->cmd = ft_substr(line, k, i - k);
// // 	// 			cmd->next = malloc(sizeof(t_cmd));
// // 	// 			cmd = cmd->next;
// // 	// 		}
// // 	// 	}
// // 	// 	i++;
// // 	// }
// // 	// print_cmd(ccmd);
// // 	pipe = split_string(line, "|", pipe);
// // 	ptr = malloc(sizeof(t_redirect));
// // 	ptr = split_redirect(pipe, ptr);
// // 	print_pipe(pipe);
// // 	// print_redirect(head);
// // 	return (0);
// // } 

// // /*
// // int main()
// // {
// // 	// char *cmd;
// // 	// char **line;

// // 	// while(1)
// // 	// {
// // 		// cmd = readline("minishell$ ");
// // 		//printf("%s\n", cmd);  
// // 		// line = ft_split(cmd, ' ');
// // 		// ft_echo(&cmd[5]);
// // 		// int i = 0;
// // 		// while (cmd[i])
// // 		// {
// // 		//     printf("cmd[%d]= %c\n", i, cmd[i]);
// // 		//     i++;
// // 		// }
// // 		// i = 0;
// // 		// while (line[i])
// // 		// {
// // 		//     printf("line[%d]= %s\n", i, line[i]);
// // 			// i++;
// // 		// }
// // 		// printf("cmd[5]: %c\n", cmd[5]);
// // 		// ft_cd(line[1]);
// // 		// ft_exit(cmd);
// // 		// printf("hello\n");
// // 		// char *line =  "    >>amalia >>b>>c<t<o>p<<t<<u ls <t >u -la";
// // 		// // char *line =  "'echo'  \"cd\"";
// // 		// // t_redirect *token = malloc(sizeof(t_redirect));
// // 		t_redirect *tmp;

// // 		// tmp = create_token(line);
// // 		// print_redirect(tmp);
// // 		// ft_pwd(&cmd[3]);1
// // 	// }
// // 	return (0);
// //} 
// */
