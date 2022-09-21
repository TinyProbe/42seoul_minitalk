/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:45:11 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 15:46:12 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
