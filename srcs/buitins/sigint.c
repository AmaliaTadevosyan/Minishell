#include <stdio.h>
#include <signal.h>


typedef void (*sighandler_t)(int);

sighandler_t signal(int signum, sighandler_t handler);

void sigint_handler(int signo)
{
	printf("Caugh SIGINT\n");
}

int main(void)
{
	signal(SIGINT, sigint_handler);
	while (1);
}