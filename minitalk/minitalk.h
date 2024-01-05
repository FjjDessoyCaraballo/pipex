/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:28:59 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/05 10:29:01 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	exit_err(char *str);
void 	acknowledge(int signum);
void	bit_one(int pid);
void	bit_zero(int pid);
void	send_signal(pid_t server_pid, char *str);
void	handle_signal(int signum, siginfo_t *info, void *ucontext);


#endif