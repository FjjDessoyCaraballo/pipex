/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:31:00 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/29 11:31:02 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"

void    child_process(int *fd, char **argv, char **envp)
{
    char    *path;
    char    *cmd;
    int     fd_in;

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
    cmd = argv[3]
    parse_cmds(cmd);
    path = parse_env(argv, cmd, envp);
    if (access(path, X_OK | F_OK))
    {
        if (execve(path, &argv[3], envp) == -1) // check first when done parsing
        {
            perror("Execve (child) error");
            exit(-1);
        }
    }
}

void    parent_process(int *fd, char **argv, char **envp)
{
    int     fd_out;
    char    *cmd;
    char    *path;

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
    cmd = argv[2];
    parse_cmds(cmd);
    path = parse_env(argv, cmd, envp);
    if (access(path, X_OK | F_OK))
    {
        if (execve(path, &argv[2], envp) == -1) //remember to change 1st param
        {
            perror("Execve (parent) error");
            exit(-1);
        }
    }
}

void    pipex(char **argv, char **envp)
{
    int fd[2];
    int pid;

    if (pipe(fd) == -1)
        exit(-1);
    pid = fork();
    if (pid < 0)
        exit(-1);
    if (pid != 0)
        child_process(fd, argv, envp);
    parent_process(fd, argv, envp);
    close(fd[0]);
    close(fd[1]);
    waitpid(pid, NULL, 0);
}