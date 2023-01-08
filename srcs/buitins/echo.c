#include <unistd.h>
#include <stdio.h>

int echo(t_data *cmd)
{
	(void) argc;
	while (*++argv)
	{
		printf("%s", *argv);
		if (argv[1])
			printf(" ");
	}
	printf("\n");
	return (0);
}