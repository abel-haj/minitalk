#include "unistd.h"
#include "sys/types.h"
#include "signal.h"
#include "stdio.h"

int	main(void)
{
	pid_t	this_pid;

	this_pid = getpid();

	printf("%d\n", this_pid);
	printf("Suspending...\n");

	kill(this_pid, SIGTSTP);

	printf("Back!\n");

	return (0);
}
