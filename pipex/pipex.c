/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex->c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student->hive->fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:10:50 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/09 10:10:51 by fdessoy-         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_data *ft_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->envp = NULL;
	data->cmd_options = NULL;
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

void ft_check_args(int argc, char **argv)
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

// void ft_getenv(char **envp) //project is not parsing the path yet
// {
	
// } 

void ft_parse_cmds(t_data *data, int argc, char **argv)
{
	char	*cmd1;
	char	*cmd2;

	cmd1 = argv[2];
	cmd2 = argv[3];
	data->cmd_options = ft_split(cmd1, ' ');
	data->cmd_options = ft_split(cmd2, ' ');
}

void ft_cleanup(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmds)
	{
		free(data->cmd_options[i]);
		i++;
	}
	free(data->cmd_options);
	free(data->cmd_path);
	free(data->pipe);
	free(data->pids);
}

t_data *ft_parse_args(t_data *data, int argc, char **argv)
{
	ft_check_args(argc, argv);
	data = ft_init();
	ft_parse_cmds(data, argc, argv);
	// parsing here
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

void pipex(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	data = ft_parse_args(data, argc, argv);
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
				dup2(data->pipe[i - 1], STDIN_FILENO);
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