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

int	main(int argc, char *argv[])
{
	int		i;
	size_t	j;
	int		shift
	int		bits;
	char	*str;

	i = 0;
	j = 0;
	shift = 0;

	if (argc > 2)
	{
		i = 2;
		while (argc > i)
		{
			str = argv[i];

			while (str[j])
			{
				bits = 7;
				while (bits >= 0)
				{
					shift = 1;
					if (str[j] & (1 << bits))
					{
						kill(ft_atoi(argv[1]), 31);
					}
					else
						kill(ft_atoi(argv[1]), 30);
					usleep(100);
					bits--;
				}
				j++;
			}
			i++;
		}
	}

	else
		ft_putstr("Please provide a process ID and a message to send!\n");

	return (0);
}
