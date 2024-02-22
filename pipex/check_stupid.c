/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stupid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:58:06 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/22 14:21:29 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_stupid(char **argv)
{
	if (argv[2][0] == '\0')
	{
		ft_putstr_fd("pipex: permission denied:", 2);
		ft_putstr_fd("\x1b[30m<fuckoff>\x1b[0m\n", 2);
	}
	if (argv[3][0] == '\0')
	{
		ft_putstr_fd("pipex: permission denied:", 2);
		ft_putstr_fd("\x1b[30m<fuckoff>\x1b[0m\n", 2);
	}
	exit(1);
}
