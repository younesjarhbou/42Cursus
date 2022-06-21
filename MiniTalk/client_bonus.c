/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjarhbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:40:25 by yjarhbou          #+#    #+#             */
/*   Updated: 2022/05/25 17:40:26 by yjarhbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	send_byte(char byte, int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (byte >> j & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				error("bad pid\n");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				error("bad pid\n");
		}
		usleep(800);
		j--;
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_byte(str[i], pid);
	send_byte(0, pid);
}

void	handler2(int sig)
{
	(void)sig;
	ft_putstr("The message has arrived\n");
}

int	main(int ac, char *av[])
{
	int		srv_pid;
	char	*msg;

	signal(SIGUSR2, handler2);
	if (ac != 3)
		error("./client_bonus [Server-pid] [Message] Or [More..]\n");
	srv_pid = ft_atoi(av[1]);
	if (srv_pid <= 0)
		error("bad pid\n");
	msg = av[2];
	send_message(msg, srv_pid);
	return (0);
}
