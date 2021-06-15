#ifndef UTILS_H

# define UTILS_H

# include "signal.h"
# include "unistd.h"
# include "stdio.h"

size_t	ft_strlen(char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(size_t n);
void	signal_handler(int sign_int);

#endif
