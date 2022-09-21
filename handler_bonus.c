/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:45:10 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 22:05:43 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	quarter();
static void pack_anal();

void	handler(int signum)
{
	g_msg.shift--;
	if (signum == SIGUSR2)
		g_msg.str[g_msg.len] |= (1 << g_msg.shift);
	if (g_msg.shift == 0)
		quarter();
}

static void	quarter()
{
	g_msg.shift = 8;
	if (g_msg.str[g_msg.len++] == 0)
	{
		write(1, g_msg.str + (g_msg.len_you + 1),
				g_msg.len - (g_msg.len_you + 2));
		write(1, "\n", 1);
		g_msg.len = 0;
	}
	g_msg.str[g_msg.len] = 0;
}

static void pack_anal()
{
	g_msg.len_you = g_msg.str[0];
	ft_memcpy(g_msg.you, g_msg.str + 1, g_msg.len_you);
	g_msg.you[g_msg.len_you] = '\0';
	g_msg.pid_you = ft_atoi(g_msg.you);
}
