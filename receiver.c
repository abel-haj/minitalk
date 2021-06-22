#include "utils.h"

int	i;
int	got[8];

static int	power(int base, int power)
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
	

	c = 0;
	if (sign_int == SIGUSR1)
	{
		got[i] = 0;
		i++;
	}
	else if (sign_int == SIGUSR2)
	{
		got[i] = 1;
		i++;
	}

	if (i == 8)
	{
		j = 7;
		i = 0;

		while (i < 8)
		{
			c = c + got[i] * power(2, j);
			i++;
			j--;
		}
		i = 0;
		ft_putchar(c);
		c = 0;
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

	ft_putstr("PID : ");
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
