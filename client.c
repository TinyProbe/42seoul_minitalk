#include "minitalk.h"

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	return (send(ft_atoi(argv[1]), argv[2]));
}
