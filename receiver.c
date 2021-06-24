/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:14:20 by abel-haj          #+#    #+#             */
/*   Updated: 2021/06/24 16:14:22 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	puttogether(char ***s, char *t, char c, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l + 1)
	{
		if (i < l)
			(*(*s))[i] = t[i];
		else
			(*(*s))[i] = c;
		i++;
	}
	(*(*s))[i] = 0;
}

static int	concatenate(char **s, char c)
{
	size_t	len;
	char	*tmp;

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
		puttogether(&s, tmp, c, len);
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
	static char	*s_msg;
	static int	s_i = 0;
	static int	s_got[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	c = 0;
	s_got[s_i++] = ternary_norm(sign_int == SIGUSR1, 0, 1);
	if (s_i == 8)
	{
		s_i = 0;
		c = bintodec(s_got);
		if (!concatenate(&s_msg, c))
		{
			ft_putstr_char("Error occured at malloc", 0);
			exit(EXIT_FAILURE);
		}
		if (c == 0)
		{
			ft_putstr_char(s_msg, 0);
			free(s_msg);
			s_msg = NULL;
		}
	}
}
