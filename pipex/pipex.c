/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:31:00 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/05 16:54:48 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, char **argv, char **envp)
{
	int		fd_in;
	char	**parsed_cmd;

	fd_in = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (fd_in == -1)
		exit(-1);
	if (dup2(fd_in, STDIN_FILENO) == -1)
	{
		perror("dup2 of child process error");
		close(fd_in);
		exit(-1);
	}
	close(fd_in);
	close(fd[0]);
	parsed_cmd = parse_cmds(argv[3]);
	if (parsed_cmd == NULL)
	{
		free_array(parsed_cmd);
		return ;
	}
	exec(parsed_cmd, envp);
}

void	parent_process(int *fd, char **argv, char **envp)
{
	int		fd_out;
	char	**parsed_cmd;

	fd_out = open(argv[1], O_RDONLY, 0644);
	if (fd_out == -1)
		exit(-1);
	if (dup2(fd_out, STDIN_FILENO) == -1)
	{
		perror("dup2 of parent process error");
		close(fd_out);
		exit(-1);
	}
	close(fd_out);
	close(fd[1]);
	parsed_cmd = parse_cmds(argv[2]);
	if (parsed_cmd == NULL)
	{
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
		exit(-1);
	pid[0] = fork();
	if (pid[0] < 0)
		exit(-1);
	if (pid[0] != 0)
		child_process(fd, argv, envp);
	pid[1] = fork();
	if (pid[1] < 0)
		exit(-1);
	if (pid[1] != 0)
		parent_process(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid[0], &status, 0);
	waitpid(pid[1], &status, 0);
	return (WEXITSTATUS(status));
}
