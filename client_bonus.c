/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:45:07 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 21:27:09 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_string	g_msg2;

static int	extract(int argc, char **argv);

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	extract(argc, argv);
	send(g_msg2.pid_you, &(g_msg2.len_me), 1);
	send(g_msg2.pid_you, g_msg2.me, g_msg2.len_me);
	send(g_msg2.pid_you, argv[2], ft_strlen(argv[2]) + 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

static int	extract(int argc, char **argv)
{
	char	*tmp;

	g_msg2.pid_me = getpid();
	tmp = ft_itoa(g_msg2.pid_me);
	g_msg2.len_me = ft_strlen(tmp);
	ft_memcpy(g_msg2.me, tmp, g_msg2.len_me);
	g_msg2.pid_you = ft_atoi(argv[1]);
	free(tmp);
}
