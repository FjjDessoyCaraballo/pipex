/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:31:00 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/09 14:47:44 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_2(int *fd, char **parsed_cmd, char **argv, char **envp)
{
	int		fd_out;

	fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		perror("Pipex");
		close(fd_out);
		exit(127);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(fd[1]);
	if (parsed_cmd == NULL)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putendl_fd(parsed_cmd[0], 2);
		free_array(parsed_cmd);
		exit(127);
	}
	ft_exec(parsed_cmd, envp);
}

void	child_1(int *fd, char **parsed_cmd, char **argv, char **envp)
{
	int		fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror("Pipex");
		close(fd_in);
		exit(EXIT_FAILURE);
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(fd[1], STDOUT_FILENO);
	ft_closefd(fd);
	if (parsed_cmd == NULL)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putendl_fd(parsed_cmd[0], 2);
		free_array(parsed_cmd);
		exit(127);
	}
	ft_exec(parsed_cmd, envp);
}

int	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];
	int		status[2];

	if (pipe(fd) == -1)
	{
		perror("Pipex");
		ft_closefd(fd);
		exit(127);
	}
	ft_forking(argv, fd, pid, status, envp);
	ft_closefd(fd);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
	return (WEXITSTATUS(status[1]));
}
