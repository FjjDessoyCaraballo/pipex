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

void	child_2(int *fd, char **argv, char **envp)
{
	int		fd_out;
	char	**parsed_cmd;

	fd_out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		exit(EXIT_FAILURE);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	close(fd[1]);
	parsed_cmd = parse_cmds(argv[3]);
	if (parsed_cmd == NULL)
	{
		perror("Bad argument\n");
		free_array(parsed_cmd);
		return ;
	}
	exec(parsed_cmd, envp);
}

void	child_1(int *fd, char **argv, char **envp)
{
	int		fd_in;
	char	**parsed_cmd;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		perror("Infile does not exist\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	parsed_cmd = parse_cmds(argv[2]);
	if (parsed_cmd == NULL)
	{
		perror("Bad argument\n");
		free_array(parsed_cmd);
		return ;
	}
	exec(parsed_cmd, envp);
}

int	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];
	int		status;

	if (pipe(fd) == -1)
		exit(EXIT_FAILURE);
	pid[0] = fork();
	if (pid[0] < 0)
		exit(EXIT_FAILURE);
	if (pid[0] == 0)
		child_1(fd, argv, envp);
	pid[1] = fork();
	if (pid[1] < 0)
		exit(EXIT_FAILURE);
	if (pid[1] == 0)
		child_2(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	return (WEXITSTATUS(status));
}
