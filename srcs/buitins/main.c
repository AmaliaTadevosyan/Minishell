// #include "./includes/minishell.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>

// int	main(void)
// {
// 	char *line;
// 	while (1)
// 	{
// 		line = readline("minishell $");
// 		if (!line)
// 			return (0);
// 		add_history(line);
// 	}
// 	return (0);
// }


char **get_input(char *input)
{
	char **command = malloc(8 * sizeof(char));
	if (command == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	char *separator = " ";
	char *parsed;
	int index = 0;

	parsed = strtok(input, separator);
	while (parsed != NULL)
	{
		command[index] = parsed;
		index++;
		parsed = strtok(NULL, separator);
	}
	command[index] = NULL;
	return (command);
}

int main(void)
{
	char **command;
	char *input;
	pid_t child_pid;
	int stat_loc;
	
	while (1)
	{
		input = readline("minishell$ ");
		command = get_input(input);

		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Fork failed");
			exit(1);
		}
		if(execvp(command[0], command))
		{
			perror(command[0]);
			exit(1);
		}
		else 
			waitpid(child_pid, &stat_loc, WUNTRACED);
		free(input);
		free(command);
	}
	return (0);

}