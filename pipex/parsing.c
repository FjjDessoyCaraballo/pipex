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

void	exec(char **parsed_cmd, char **envp)
{
	char	*path;

	path = parse_env(parsed_cmd, envp);
	if (path == NULL)
		return ;
	if (execve(path, parsed_cmd, envp) == -1)
	{
		perror("Execve error");
		free(path);
		exit(2);
	}
	free(path);
	free_array(parsed_cmd);
	exit(0);
}

char	*parse_env(char **parsed_cmd, char **envp)
{
	char	**path;
	char	*allpath;
	char	*c_path;
	int		i;

	allpath = fetch_env_str(envp);
	if (!allpath)
		return (NULL);
	path = ft_split(allpath, ':');
	i = 0;
	while (path[i])
	{
		c_path = ft_strsjoin(path[i], parsed_cmd[0], '/');
		if (!access(c_path, F_OK | X_OK))
		{
			free_array(path);
			return (c_path);
		}
		i++;
		free(c_path);
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
		if (strncmp(envp[i], "PATH=", 5) == 0)
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

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
