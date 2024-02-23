/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:02:07 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/05 16:55:05 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*parse_env(t_ppx pipex, char **parsed_cmd)
{
	char	**path;
	char	*allpath;
	char	*curr_path;

	if (!access(parsed_cmd[0], F_OK | X_OK))
		return (ft_strdup(parsed_cmd[0]));
	allpath = fetch_env_str(pipex);
	if (!allpath)
		return (NULL);
	path = ft_split(allpath, ':');
	if (!path)
		return (NULL);
	curr_path = access_path(path, parsed_cmd);
	if (curr_path == NULL)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(parsed_cmd[0], 2);
		return (NULL);
	}
	else
		return (curr_path);
}

char	*access_path(char **path, char **parsed_cmd)
{
	int		i;
	char	*curr_path;

	i = 0;
	while (path[i])
	{
		curr_path = ft_strsjoin(path[i], parsed_cmd[0], '/');
		if (!access(curr_path, F_OK))
		{
			if (!access(curr_path, X_OK))
			{
				free_array(path);
				return (curr_path);
			}
			ft_putstr_fd("pipex: command not found: ", 2);
			ft_putendl_fd(parsed_cmd[0], 2);
		}
		free(curr_path);
		i++;
	}
	return (NULL);
}

char	*fetch_env_str(t_ppx pipex)
{
	int	i;

	i = 0;
	if (!pipex.env)
		return (NULL);
	while (pipex.env[i])
	{
		if (ft_strncmp(pipex.env[i], "PATH=", 5) == 0)
			return (pipex.env[i] + 5);
		i++;
	}
	return (NULL);
}

char	**parse_cmds(char *cmd)
{
	int		i;
	char	**a_cmd;

	i = 0;
	if (ft_strncmp(cmd, "./", 2) == 0)
		i += 2;
	a_cmd = ft_split(cmd + i, ' ');
	if (a_cmd == NULL)
		return (NULL);
	return (a_cmd);
}

