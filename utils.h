/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:18:18 by abel-haj          #+#    #+#             */
/*   Updated: 2021/06/24 16:18:20 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H

# define UTILS_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi(const char *s);
size_t	ft_strlen(char *s);
void	ft_putstr_char(char *s, char c);
int		ternary_norm(int cond, int a, int b);
void	ft_putnbr(long int n);
void	signal_handler(int sign_int);

#endif
