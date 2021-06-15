#include "signal.h"
#include "unistd.h"
#include "stdio.h"

void	signal_handler(int sign_int)
{
	printf("%3d : was recieved\n", sign_int);
}

int	main()
{
	struct sigaction my_action;

	my_action.sa_handler = signal_handler;

	printf("%d\n", getpid());
	while (1)
	{
		// signal(SIGUSR1, signal_handler);
		sigaction(SIGUSR1, &my_action, NULL);
		sigaction(SIGUSR2, &my_action, NULL);
		pause();
	}
	return (0);
}
