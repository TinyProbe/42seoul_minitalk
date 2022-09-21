/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:41 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 15:47:33 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
