#include "utils.h"

int	i;
int	got[8];

void	signal_handler(int sign_int)
{
	int	c;
	// printf("%3d : was recieved\n", sign_int);
	c = 0;
	if (sign_int == 30)
	{
		got[i] = 0;
		i++;
	}
	else if (sign_int == 31)
	{
		got[i] = 1;
		i++;
	}
	if (i == 7)
	{
		while (i >= 0)
		{
			c *= got[i] * i;
			i--;
		}
		write(1, &c, 1);
		i = 0;
	}
}

int	main(void)
{
	got[0] = 0;
	got[1] = 0;
	got[2] = 0;
	got[3] = 0;
	got[4] = 0;
	got[5] = 0;
	got[6] = 0;
	got[7] = 0;
	struct sigaction my_action;

	my_action.sa_handler = signal_handler;

	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
	{
		sigaction(SIGUSR1, &my_action, NULL);
		sigaction(SIGUSR2, &my_action, NULL);
		pause();
	}
	return (0);
}
