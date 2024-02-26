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
	if (argv[2][0] == '\0' && argv[3][0] == '\0')
	{
		empty_str();
		empty_str();
		exit(1);
	}
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		empty_str();
		exit(1);
	}
}

int		env_check(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (0);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	empty_str(void)
{
	ft_putstr_fd("pipex: permission denied:", 2);
}
void	empty_env(char **argv)
{
	ft_putstr_fd("pipex: no such file or directory: ", 2);
	ft_putstr_fd(argv[2], 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("pipex: no such file or directory: ", 2);
	ft_putstr_fd(argv[3], 2);
	ft_putstr_fd("\n", 2);
}
