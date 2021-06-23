#include "utils.h"

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

static int	concatenate(char **s, char c)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	if (*s == NULL)
	{
		*s = malloc(2);
		if (*s == NULL)
			return (0);
		(*s)[0] = c;
		(*s)[1] = 0;
	}
	else
	{
		len = ft_strlen(*s);
		tmp = *s;
		*s = malloc(len + 2);
		if (*s == NULL)
		{
			free(tmp);
			return (0);
		}
		while (i < len + 1)
		{
			if (i < len)
				(*s)[i] = tmp[i];
			else
				(*s)[i] = c;
			i++;
		}
		(*s)[i] = 0;
		free(tmp);
	}
	return (1);
}

static int 	bintodec(int arr[8])
{
	int	i;
	int	j;
	int	dec;

	i = 0;
	j = 7;
	dec = 0;
	while (i < 8)
	{
		dec = dec + arr[i] * power(2, j);
		i++;
		j--;
	}
	return (dec);
}

void	signal_handler(int sign_int)
{
	int			c;
	static char	*msg;
	static int	i = 0;
	static int	got[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	c = 0;
	if (sign_int == SIGUSR1)
		got[i++] = 0;
	else if (sign_int == SIGUSR2)
		got[i++] = 1;
	if (i == 8)
	{
		i = 0;
		c = bintodec(got);
		if (!concatenate(&msg, c))
		{
			ft_putstr("Error occured at malloc");
			exit(EXIT_FAILURE);
		}
		if (c == 0)
		{
			ft_putstr(msg);
			free(msg);
			msg = NULL;
		}
	}
}

int	main(void)
{
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
