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

/* struct */
typedef struct s_ppx
{
	pid_t	pid[2];
	int		fd[2];
	char	**env;
}				t_ppx;

/* pipex.c */
int		pipex(t_ppx pipex, char **argv);
void	child_1(t_ppx pipex, char **parsed_cmd, char **argv);
void	child_2(t_ppx pipex, char **parsed_cmd, char **argv);

/* parsing.c */
char	*parse_env(t_ppx pipex, char **parsed_cmd);
char	*access_path(char **path, char **parsed_cmd);
char	*fetch_env_str(t_ppx pipex);
char	**parse_cmds(char *cmd);

/* utils.c */
void	pid_handling(t_ppx pipex, int *status);
void	ft_exec(t_ppx pipex, char **parsed_cmd);
void	ft_forking(t_ppx pipex, char **argv, int *status);
void	ft_closefd(t_ppx pipex);
void	free_array(char **array);

/* free.c */
void	free_everything(t_ppx pipex);

/* easter egg */
void	check_stupid(char **argv);
void	empty_str(void);
void	empty_env(char **argv);
int		env_check(char **envp);

#endif
