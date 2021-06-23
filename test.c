#include "utils.h"
#include <stdlib.h>

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
		while (i < len + 1)
		{
			if (i < len)
				(*s)[i] = tmp[i];
			else
				(*s)[i] = c;
			i++;
		}
		(*s)[i] = 0;
	}
	return (1);
}

void	pass(int a[2])
{
	;
}

int 	bintodec(int arr[8])
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

int	main(void)
{
	// char *s1 = NULL;
	// char *s2 = "";
	// char *s3 = "strin";

	// concatenate(&s1, 'g');
	// concatenate(&s2, 'g');
	// concatenate(&s3, 'g');
	// printf("%s\n", s1);
	// printf("%s\n", s2);
	// printf("%s\n", s3);
	// free(s1);free(s2);free(s3);
	// scanf("%s", s1);

	// int a[2] = {0,0};
	// int i = 0;
	// int j = 0;
	// char	*s = "string";
	// char	*m = malloc(7);
	// while (s[i])
	// {
	// 	// write(1, &s[i++], 1);
	// 	m[i] = s[j++];
	// }
	// pass(a);
	// m[i] =0;
	// printf("%s", m);
	// printf("\n");

	int a[8] = {0, 0, 1, 1, 1, 1, 1, 1};
	printf("%d\n", bintodec(a));
	return (0);
}
