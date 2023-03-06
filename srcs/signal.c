#include "../includes/minishell.h"

void    sig_handler(int signum)
{
    if (signum)
    {
        printf("\n");
        rl_on_new_line();
        rl_replace_line("", 0);
        rl_redisplay();
        printf("CTRL-C chatched!");
        exit(0);
    }
}

void	ctrl_slash_handler(int i)
{
	(void)i;
	rl_on_new_line();
	write(1, "Quit: 3\n", 8);
	rl_replace_line("", 0);
}

