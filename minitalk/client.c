/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:30:52 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/05 13:30:55 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ack;

void	acknowledge(int signum)
{
	(void)signum;
	g_ack = 1;
}

void	bit_one(int pid)
{
	if (kill(pid, SIGUSR1) < 0)
		exit_err("Invalid PID.\n");
}

void	bit_zero(int pid)
{
	if (kill(pid, SIGUSR2) < 0)
		exit_err("Invalid PID.\n");
}

void send_signal(pid_t server_pid, char *str)
{
	int	i;
	size_t	len;

	i = 0;
	len = ft_strlen(str) + 1;
	while (len--)
	{
		if (*str & 1 << i)
			bit_one(server_pid);
		else
			bit_zero(server_pid);
		while (!g_ack)
			pause();
		g_ack = 0;
	}
	str++;
}

int main(int argc, char **argv)
{
	if (argc < 3)
		exit_err("Usage: ./client [SRV_PID] [STRING]\n");
	signal(SIGUSR1, acknowledge);
	send_signal(ft_atoi(argv[1]), (argv[2]));
	return (0);
}

