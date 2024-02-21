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

void	pid_handling(int *pid, int *fd, int *status)
{
	if (pid[0] < 0)
	{
		waitpid(pid[1], &status[1], 0);
		ft_closefd(fd);
		exit(127);
	}
	if (pid[1] < 0)
	{
		waitpid(pid[0], &status[0], 0);
		ft_closefd(fd);
		exit(127);
	}
}

void	ft_exec(char **parsed_cmd, char **envp)
{
	char	*path;

	path = parse_env(parsed_cmd, envp);
	if (path == NULL)
		return ;
	if (execve(path, parsed_cmd, envp) == -1)
	{
		perror("Pipex");
		free_array(parsed_cmd);
		free(path);
		exit(1);
	}
}

void	ft_forking(char **argv, int *fd, int *pid, int *status, char **envp)
{
	char 	**parsed_cmd;

	pid[0] = fork();
	pid_handling(pid, fd, status);
	if (pid[0] == 0)
	{
		parsed_cmd = parse_cmds(argv[2]);
		child_1(fd, parsed_cmd, argv, envp);
	}
	pid[1] = fork();
	pid_handling(pid, fd, status);
	if (pid[1] == 0)
	{
		waitpid(pid[0], &status[0], 0);
		parsed_cmd = parse_cmds(argv[3]);
		child_2(fd, parsed_cmd, argv, envp);
	}
}

void	ft_closefd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
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
