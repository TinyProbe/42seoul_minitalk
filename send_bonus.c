/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:45:11 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 19:05:20 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	getsig(int bit);

int	send(pid_t pid, const char *s, int n)
{
	int	shift;
	int	i;

	i = -1;
	while (++i < n)
	{
		shift = 8;
		while (shift--)
			if ((usleep(100) || 1) && kill(pid, getsig(s[i] & (1 << shift))))
				return (-1);
	}
	return (0);
}

static int	getsig(int bit)
{
	if (bit)
		return (SIGUSR2);
	return (SIGUSR1);
}
