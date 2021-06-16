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
	}
	return (result);
}

void	signal_handler(int sign_int)
{
	//printf("\nhere");
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
	ft_putchar('\n');
	ft_putnbr(i);

	//printf("\ngot signal %d hex now is : %d%d%d%d%d%d%d%d",
	//		sign_int, got[0], got[1], got[2], got[3], got[4], got[5], got[6], got[7]);
	if (i == 8)
	{
		//printf("\n%d%d%d%d%d%d%d%d",
		//	got[0], got[1], got[2], got[3], got[4], got[5], got[6], got[7]);
		ft_putchar('\n');
		ft_putnbr(got[0]);
		ft_putnbr(got[1]);
		ft_putnbr(got[2]);
		ft_putnbr(got[3]);
		ft_putnbr(got[4]);
		ft_putnbr(got[5]);
		ft_putnbr(got[6]);
		ft_putnbr(got[7]);

		j = 7;
		i = 0;

		while (i < 8)
		{
			printf("\n%d += %d * 2 * %d", c, got[i], j);
			ft_putnbr(c);ft_putchar(' ');ft_putnbr(got[i]);ft_putchar(' ');ft_putnbr(j);
			c = c + got[i] * power(2, j);
			i++;
			j--;
		}
		ft_putchar('\n');
		ft_putchar(c);
		ft_putchar('\n');
		ft_putnbr(c);
		i = 0;
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
	// ft_putchar('\n');
	while (1)
	{
		sigaction(SIGUSR1, &my_action, NULL);
		sigaction(SIGUSR2, &my_action, NULL);
		pause();
	}
	return (0);
}
