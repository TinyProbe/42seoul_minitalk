#include "minitalk.h"

static int	getsig(int bit);

int	send(pid_t pid, const char *s)
{
	int	shift;
	int	len;
	int	i;

	len = ft_strlen(s);
	i = -1;
	while (++i <= len)
	{
		shift = 8;
		while (shift--)
		{
			if (kill(pid, getsig(s[i] & (1 << shift))))
				return (-1);
			usleep(100);
		}
	}
	return (0);
}

static int	getsig(int bit)
{
	if (bit)
		return (SIGUSR2);
	return (SIGUSR1);
}
