#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)

{
	int	hash[255];
	int	j;

	j = 0;
	while (hash[j])
		hash[j++] = 0;
	j = 0;
	if (ac == 3)
	{
			while (av[1][j])
			{
				if (hash[(unsigned int)av[1][j]] == 0)
				{
					hash[(unsigned int)av[1][j]] = 1;
					write(1, &av[1][j], 1);
				}
				j++;
			}
	}
	write (1, "\n", 1);
	return (0);
}