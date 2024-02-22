/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:05:27 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/20 10:05:28 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pid_handling(t_ppx pipex, int *status)
{
	if (pipex.pid[0] < 0)
	{
		waitpid(pipex.pid[1], &status[1], 0);
		ft_closefd(pipex);
		exit(127);
	}
	if (pipex.pid[1] < 0)
	{
		waitpid(pipex.pid[0], &status[0], 0);
		ft_closefd(pipex);
		exit(127);
	}
}

void	ft_exec(t_ppx pipex, char **parsed_cmd)
{
	char	*path;

	path = parse_env(pipex, parsed_cmd);
	if (path == NULL)
		return ;
	if (execve(path, parsed_cmd, pipex.env) == -1)
	{
		perror("Pipex");
		free_array(parsed_cmd);
		free(path);
		exit(1);
	}
}

void	ft_forking(t_ppx pipex, char **argv, int *status)
{
	char	**parsed_cmd;

	pipex.pid[0] = fork();
	pid_handling(pipex, status);
	if (pipex.pid[0] == 0)
	{
		parsed_cmd = parse_cmds(argv[2]);
		child_1(pipex, parsed_cmd, argv);
	}
	pipex.pid[1] = fork();
	pid_handling(pipex, status);
	if (pipex.pid[1] == 0)
	{
		waitpid(pipex.pid[0], &status[0], 0);
		parsed_cmd = parse_cmds(argv[3]);
		child_2(pipex, parsed_cmd, argv);
	}
}

void	ft_closefd(t_ppx pipex)
{
	close(pipex.fd[0]);
	close(pipex.fd[1]);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
