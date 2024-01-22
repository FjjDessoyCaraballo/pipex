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
	char	**envp;
	char	**cmd_options;
	char	**av;
	char	*cmd_path;
	int		heredoc;
	int		fd_out;
	int		fd_in;
	int		*pipe;
	int		*pids;
	int		nb_cmds;
	int		ac;
	int		child;
}			t_data;

/* functions */
static t_data	*ft_init(void);
void			ft_check_args(int argc, char **argv);
void			ft_parse_cmds(t_data *data, int argc, char **argv);
t_data			*ft_parse_args(t_data *data, int argc, char **argv);
void			ft_cleanup(t_data* data);
void			pipex(t_data *data, int argc, char **argv);

/* libft functions */
char 			**ft_split(const char *s, char c);
int 			ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*free_array(char **array);
static int		ft_countwords(char const *s, char c);
static int		ft_wordlen(char const *s, char c);
void			*ft_memset(void *s, int c, size_t len);

#endif