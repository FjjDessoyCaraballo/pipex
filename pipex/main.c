/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:19:49 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/20 15:19:50 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_ppx	ppx;

	if (!env_check(envp))
	{
		empty_env();
		exit(1);
	}
	if (argc != 5)
	{
		ft_putstr_fd("pipex: invalid number of commands", 2);
		exit(1);
	}
	ppx.env = envp;
	return (pipex(ppx, argv));
	
}
