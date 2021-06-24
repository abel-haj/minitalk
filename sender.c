/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sender.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 17:23:31 by abel-haj          #+#    #+#             */
/*   Updated: 2021/06/24 17:23:34 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	send_sig(int pid, int sig)
{
	if (kill(pid, sig))
	{
		ft_putstr_char("Failed to send a signal!\n", 0);
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
	size_t	len;
	int		bits;

	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		bits = 7;
		while (bits >= 0)
		{
			if ((str[i] >> bits) & 1)
			{
				if (!send_sig(pid, SIGUSR2))
					break ;
			}
			else
				if (!send_sig(pid, SIGUSR1))
					break ;
			usleep(100);
			bits--;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3 && ft_atoi(argv[1]) > 0)
	{
		send_message(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_putstr_char("Please provide a valid PID and a one message!\n", 0);
	}
	return (0);
}
