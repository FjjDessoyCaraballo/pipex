/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:10:56 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/09 10:10:57 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* libft and printf */
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

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

/* struct for initializing pipes (data) */
typedef struct s_data
{
	char	**envp; //environment pointer
	char	**cmd_options;
	char	**av; //argument vector
	char	*cmd_path;
	int		heredoc;
	int		fd_out;
	int		fd_in;
	int		*pipe;
	int		*pids;
	int		nb_cmds;
	int		ac; // argc
	int		child;
}			t_data;

/* functions */
static t_data	ft_init(void)
void			ft_check_args(int argc, char **argv);
void			ft_parse_cmds(t_data *data, int argc, char **argv);
void			ft_parse_args(t_data *data, int argc, char **argv);
void			ft_cleanup(t_data* data);

#endif