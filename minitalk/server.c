/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:30:44 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/05 13:30:46 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	c;
	static int 				i;

	(void)ucontext;
	if (signum == SIGUSR1)
		c = c << 1 | 1;
	else if (signum == SIGUSR2)
		c = c << 1 | 0;
	i++;
	if (i == 8)
	{
		if (!c)
			write (1, "\n", 1);
		else
			write(1, &c, 1);
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction act;
	
	ft_printf("PID: %d\n", getpid());
	act.sa_sigaction = handle_signal;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}