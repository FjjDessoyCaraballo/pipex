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

/* libft and printf */
# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"

/* permitted libraries */
/* for close, read, write, unlink, dup, dup2, execve, fork, pipe */
# include <unistd.h>

/* for open, */
# include <fcntl.h>

/* for strerror */
# include <string.h>

/* for malloc, free, exit */
# include <stdlib.h>

/* for perror, strerror, access */
# include <stdio.h>

/* for waitpid, wait, */
# include <sys/wait.h>

/* pipex functions */
int		pipex(char **argv, char **envp);
void	parent_process(int *fd, char **argv, char **envp);
void	child_process(int *fd, char **argv, char **envp);
char	*fetch_env_str(char **envp);
char	*parse_env(char **parsed_cmd, char **envp);
char	**parse_cmds(char *cmd);
void	free_array(char **array);
void	exec(char **parsed_cmd, char **envp);

#endif
