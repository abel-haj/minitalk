#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	int		i = 0;
	if (argc > 2)
	{
		for (int i=0; i < atoi(argv[2]); i++)
		{
			write(1, &argv[1], 1);
		}
	}
	return (0);
}
