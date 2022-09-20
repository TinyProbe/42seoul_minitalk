#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/libft.h"

# define MAX_LEN	1000000

typedef struct s_string
{
	char	str[MAX_LEN];
	int		len;
	int		shift;
}	t_string;

extern t_string	g_msg;

int		send(pid_t pid, const char *s);
void	handler(int sig);

#endif
