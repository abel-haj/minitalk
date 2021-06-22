/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:50:33 by abel-haj          #+#    #+#             */
/*   Updated: 2021/06/20 16:49:00 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	send_sig(int pid, int sig)
{
		ft_putnbr(sig);
		ft_putchar('\n');
	if (kill(pid, sig))
	{
		ft_putstr("Failed to send a signal!\n");
		ft_putnbr(pid);
		return (0);
	}
	else
	{
		return (1);
	}
}

static void	send_message(int pid, char *str)
{
	size_t	i;
	int		bits;

	i = 0;
	while (str[i])
	{
		bits = 7;
		while (bits >= 0)
		{
			// ft_putnbr((str[i] >> bits) & 1);
			if ((str[i] >> bits) & 1)
			{
				if (!send_sig(pid, SIGUSR2))
					break;
			}
			else
				if (!send_sig(pid, SIGUSR1))
					break;
			usleep(100);
			bits--;
		}
		ft_putchar('\n');
		i++;
	}
}

int	main(int argc, char *argv[])
{
	// ft_putnbr(SIGUSR1);
	// ft_putchar('\n');
	// ft_putnbr(SIGUSR2);
	// ft_putchar('\n');
	if (argc == 3 && ft_atoi(argv[1]) > 0)
	{
		send_message(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_putstr("Please provide a valid PID and a one message to send!\n");
	}
	return (0);
}
