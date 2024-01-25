/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 09:40:41 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/25 09:40:47 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.a"

static t_data	*ft_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->envp = NULL;
	data->cmd_options = NULL;
	data->cmd_options2 = NULL;
	data->av = NULL;
	data->fd_in = -1;
	data->fd_out = -1;
	data->pipe = NULL;
	data->pids = NULL;
	data->nb_cmds = 0;
	data->ac = 0;
	data->child = 0;
	data->cmd_path = NULL;
	data->heredoc = 0;
	return (data);
}

void	ft_check_args(int argc, char **argv)
{
	if (argc != 5)
	{
		perror("Wrong number of arguments");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (access(argv[1], F_OK | R_OK) == -1)
		{
			perror("First file not accessible");
			exit(EXIT_FAILURE);
		}
		if (access(argv[4], F_OK | W_OK) == -1)
		{
			perror("Second file not accessible");
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_getenv(t_data *data, char **envp)
{
	data->cmd_path = ft_getenv_value(envp, "PATH");
	if (!data->cmd_path)
	{
		perror("PATH variable not found in environment");
		exit(EXIT_FAILURE);
	}
}

char	*ft_getenv_values(char **envp, const char *path_env)
{
	int		i;
	size_t	len;

	if (!envp || !path_env)
		return (NULL);
	len = ft_strlen(path_env);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], path_env, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

void	ft_parse_cmds(t_data *data, int argc, char **argv)
{
	char	*cmd1;
	char	*cmd2;

	cmd1 = argv[2];
	cmd2 = argv[3];
	data->cmd_options = ft_split(cmd1, ' ');
	data->cmd_options2 = ft_split(cmd2, ' ');
}

void	ft_cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmds)
	{
		free(data->cmd_options[i]);
		free(data->cmd_options2[i]);
		i++;
	}
	free(data->cmd_options);
	free(data->cmd_options2);
	free(data->cmd_path);
	free(data->pipe);
	free(data->pids);
}

t_data	*ft_parse_args(int argc, char **argv)
{
	t_data *data;

	ft_check_args(argc, argv);
	data = ft_init();
	ft_parse_cmds(data, argc, argv);
	if (argc == 5 && ft_strncmp(argv[4], "<", sizeof(size_t)) && ft_strncmp(argv[4], ">", sizeof(size_t)))
	{
		data->heredoc = 1;
		data->fd_in = open(argv[4], O_RDONLY);
	}
	else
		data->fd_in = open(argv[4], O_RDONLY);
	ft_cleanup(data);
	return (data);
}

void	pipex(t_data *data, int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	data = ft_parse_args(argc, argv);
	ft_getenv(data, envp);
	data->pipe = malloc(sizeof(int) * (data->nb_cmds * 2));
	if (!data->pipe)
	{
		perror("Pipe malloc failure");
		exit(EXIT_FAILURE);
	}
	
	data->pids = malloc(sizeof(int) * data->nb_cmds);
	if (!data->pids)
	{
		perror("Pids malloc failure");
		exit(EXIT_FAILURE);
	}
	while (i < data->nb_cmds - 1)
	{
		pipe(data->pipe + i);
		i++;
	}
	i = 0;
	while (i < data->nb_cmds)
	{
		data->child = fork();
		if (data->child == 0)
		{
			if (i == 0)
			{
				dup2(data->fd_in, STDIN_FILENO);
				dup2(data->pipe[i], STDOUT_FILENO);
			}
			else if (i == data->nb_cmds - 1)
			{
				dup2(data->pipe[i - 1], STDIN_FILENO); // child process
				dup2(data->fd_out, STDOUT_FILENO);
			}
			else
			{
				dup2(data->pipe[i - 1], STDIN_FILENO);
				dup2(data->pipe[i], STDOUT_FILENO);
			}
			execve(data->cmd_path, data->cmd_options, data->envp);
			perror("Execve failure: execution path invalid");
			exit(EXIT_FAILURE);
		}
		else if (data->child < 0)
		{
			perror("Fork failure");
			exit(EXIT_FAILURE);
		}
		else
		{
			data->pids[i] = data->child;
			i++;
		}
	}
	i = 0;
	while (i < data->nb_cmds - 1)
	{
		close(data->pipe[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_cmds)
	{
		waitpid(data->pids[i], NULL, 0);
		i++;
	}
}