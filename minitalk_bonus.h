/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:41 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 21:27:37 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/libft.h"

# define MAX_LEN	1000000
# define MAX_PID	100

typedef struct s_string
{
	pid_t	pid_me;
	char	me[MAX_PID];
	char	len_me;
	pid_t	pid_you;
	char	you[MAX_PID];
	char	len_you;
	char	str[MAX_LEN];
	int		len;
	int		shift;
}	t_string;

extern t_string	g_msg;
extern t_string	g_msg2;

int		send(pid_t pid, const char *s, int n);
void	handler(int signum);

#endif
