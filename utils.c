/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:18:27 by abel-haj          #+#    #+#             */
/*   Updated: 2021/06/24 16:18:28 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr_char(char *s, char c)
{
	if (c)
		write(1, &c, 1);
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr(long int n)
{
	if (n < 0)
	{
		ft_putstr_char(NULL, '-');
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putstr_char(NULL, n % 10 + 48);
}

int	ternary_norm(int cond, int a, int b)
{
	if (cond)
		return (a);
	else
		return (b);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	size_t			result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		sign = ternary_norm(str[i] == 45, -1, 1);
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	if (result > 9223372036854775807 && sign == 1)
		return (-1);
	else if (result > 9223372036854775807 && sign == -1)
		return (0);
	return ((int)result * sign);
}
