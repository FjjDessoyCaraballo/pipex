/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:32:00 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/05 16:39:04 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* libft */
# include "libft/includes/libft.h"

/* permitted libraries */
/* for close, read, write, unlink, dup, dup2, execve, fork, pipe */
# include <unistd.h>

/* for open, */
# include <fcntl.h>

/* for strerror */
# include <string.h>

/* for malloc, free, exit */
# include <stdlib.h>

/* for perror, access */
# include <stdio.h>

/* for waitpid, wait, */
# include <sys/wait.h>

/* pipex.c */
int		pipex(char **argv, char **envp);
void	child_1(int *fd, char **parsed_cmd, char **argv, char **envp);
void	child_2(int *fd, char **parsed_cmd, char **argv, char **envp);

/* parsing.c */ 
char	*fetch_env_str(char **envp);
char	*parse_env(char **parsed_cmd, char **envp);
char	**parse_cmds(char *cmd);
char	*access_path(char **path, char **parsed_cmd);

/* utils.c */

void	ft_forking(char **argv, int *fd, int *pid, int *status, char **envp);
void	pid_handling(int *pid, int *fd, int *status);
void	ft_exec(char **parsed_cmd, char **envp);
void	free_array(char **array);
void	ft_closefd(int *fd);


/* error.c */
void	print_me(char *str, int num);

#endif
