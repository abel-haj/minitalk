#include "utils.h"

int	main(int argc, char *argv[])
{
	size_t		i;
	size_t		j;
	int			n;
	int			a[8];
	sigset_t	set;

	i = 0;
	j = 0;

	if (argc > 2)
	{
		n = argv[2];
		while (j < 8)
		{
			a[j] = n % 2;
			n = n / 2;
			j++;
		}

		sigemptyset(&set);

		while (j >= 0)
		{
			if (a[j])
				sigaddset(set, SIGUSR1);
			else
				sigaddset(set, SIGUSR2);
			j--;
		}
	}

	else
		ft_putstr("Please provide a process ID 
					and a message to send!\n");

	return (0);
}
