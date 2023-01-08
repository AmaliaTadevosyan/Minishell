#include <unistd.h>
#include <stdio.h>

void pwd(t_data *cmd)
{
	char wd[1000];
	printf("Current directory: %s", getcwd(wd, sizeof(wd)));
}