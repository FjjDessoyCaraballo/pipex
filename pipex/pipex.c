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

void	child_2(t_ppx pipex, char **parsed_cmd, char **argv)
{
	int		fd_out;

	fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
	{
		perror("Pipex");
		close(fd_out);
		exit(127);
	}
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[0]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(pipex.fd[1]);
	if (parsed_cmd == NULL)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putendl_fd(parsed_cmd[0], 2);
		free_array(parsed_cmd);
		exit(127);
	}
	ft_exec(pipex, parsed_cmd);
}

void	child_1(t_ppx pipex, char **parsed_cmd, char **argv)
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
	dup2(pipex.fd[1], STDOUT_FILENO);
	ft_closefd(pipex);
	if (parsed_cmd == NULL)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putendl_fd(parsed_cmd[0], 2);
		free_array(parsed_cmd);
		exit(127);
	}
	ft_exec(pipex, parsed_cmd);
}

int	pipex(t_ppx pipex, char **argv)
{
	int		status[2];

	if (pipe(pipex.fd) == -1)
	{
		perror("pipex");
		ft_closefd(pipex);
		exit(0);
	}
	ft_forking(pipex, argv, status);
	ft_closefd(pipex);
	waitpid(pipex.pid[0], &status[0], 0);
	waitpid(pipex.pid[1], &status[1], 0);
	return (WEXITSTATUS(status[1]));
}
