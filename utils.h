#ifndef UTILS_H

# define UTILS_H

# include "signal.h"
# include "unistd.h"
# include "stdio.h"

int		ft_atoi(const char *s);
size_t	ft_strlen(char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(long int n);
void	signal_handler(int sign_int);

#endif
