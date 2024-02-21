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

char	*parse_env(char **parsed_cmd, char **envp)
{
	char	**path;
	char	*allpath;
	char	*curr_path;

	if (!access(parsed_cmd[0], F_OK | X_OK))
		return (ft_strdup(parsed_cmd[0]));
	allpath = fetch_env_str(envp);
	if (!allpath)
		return (NULL);
	path = ft_split(allpath, ':');
	if (!path)
		return (NULL);
	curr_path = access_path(path, parsed_cmd);
	if (curr_path == NULL)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
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
			ft_putstr_fd("Pipex: command not found: ", 2);
			ft_putendl_fd(parsed_cmd[0], 2);
		}
		free(curr_path);
		i++;
	}
	return (NULL);
}

char	*fetch_env_str(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	**parse_cmds(char *cmd)
{
	char	**a_cmd;

	a_cmd = ft_split(cmd, ' ');
	if (a_cmd == NULL)
		return (NULL);
	return (a_cmd);
}


