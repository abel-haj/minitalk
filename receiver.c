#include "utils.h"

int	i;
int	got[8];

int	power(int base, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result = result * base;
		power--;
	}
	return (result);
}

void	signal_handler(int sign_int)
{
	int	j;
	int	c;

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

	if (i == 8)
	{
		// ft_putchar('\n');
		// ft_putnbr(got[0]);
		// ft_putnbr(got[1]);
		// ft_putnbr(got[2]);
		// ft_putnbr(got[3]);
		// ft_putnbr(got[4]);
		// ft_putnbr(got[5]);
		// ft_putnbr(got[6]);
		// ft_putnbr(got[7]);

		j = 7;
		i = 0;

		while (i < 8)
		{
			c = c + got[i] * power(2, j);
			ft_putnbr(c);
			ft_putchar(' ');
			i++;
			j--;
		}
		i = 0;
			ft_putchar('\n');
		ft_putchar(c);
			ft_putchar('\n');
	}
}

int	main(void)
{
	i = 0;
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

	// printf("%d %d %d %d %d %d %d %d\n",
	// 		got[0], got[1], got[2], got[3], got[4], got[5], got[6], got[7]);

	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
