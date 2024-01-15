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

static t_data ft_init(void)
{
	t_data data;

	data.envp = NULL;
	data.cmd_options = NULL;
	data.av = NULL;
	data.fd_in = -1;
	data.fd_out = -1;
	data.pipe = NULL;
	data.pids = NULL;
	data.nb_cmds = 0;
	data.ac = NULL;
	data.child = 0;
	data.cmd_path = NULL;
	data.heredoc = 0;
	return (data);
}

void ft_check_args(int argc, char **argv)
{
	if (argc >= 5)
	{
		perror("Error: too many arguments.\n");
		exit(EXIT_FAILURE);
	}
	if (argc < 4)
	{
		perror("Error: too little arguments.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (access(argv[1], F_OK | W_OK | X_OK) == -1)
		{
			perror("Error: first file does not exist.\n");
			exit(EXIT_FAILURE);
		}
		if (access(argv[4], F_OK | W_OK | X_OK) == -1)
		{
			perror("Error: second file does not exist.\n");
			exit(EXIT_FAILURE);
		}
	}
}

void ft_parse_cmds(t_data *data, int argc, char **argv)
{
	char *cmd1;
	char *cmd2;

	cmd1 = argv[2];
	cmd2 = argv[3];
	data->cmd_options = ft_split(cmd1, ' ');
	data->cmd_options = ft_split(cmd2, ' ');
}

void ft_cleanup(t_data *data)
{
	int i;

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

void ft_parse_args(t_data *data, int argc, char **argv)
{
	ft_check_args(argc, argv);
	ft_init(data);
	ft_parse_cmds(data, argc, argv);

	// parsing here

	ft_cleanup(data);
}
