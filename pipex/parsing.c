/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:02:07 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/29 16:02:08 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/includes/ft_printf.h"
#include "libft/includes/libft.h"

char    *parse_env(char **argv, char *cmd, char **envp)
{
    char        **path;
    char        *allpath;
    char        *c_path;
    int         i;

    allpath = fetch_env_str(envp); 
    if (!allpath)
        return (NULL);
    path = ft_split(allpath, ':');
    i = 0;
    while (path[i])
    {//cmd needs to be parsed and joined to the path
        c_path = ft_strjoin(path, cmd);//maybe parse in pipex // if I just strjoin the path[i] and cmd
        if (!access(c_path, F_OK | X_OK)) // it should work... lets see
            return (c_path);
        else
            i++;
    }
    return (NULL);
}

char    *fetch_env_str(char **envp)
{
    int     i;

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

char    *parse_cmds(char *cmd);
{
    char **a_cmd;
    char *result;

    a_cmd = ft_split(cmd, ' '); //use position zero of a_cmd
    if (a_cmd == NULL || a_cmd[0] == NULL)
        return (NULL);
    result = ft_strdup(a_cmd[0]);
    if (result == NULL)
    {
        free_array(a_cmd);
        return (NULL);
    }
    free_array(a_cmd);    // true_path = ft_strjoin(path, a_cmd[0]);
    return (result);
} //parsing should go to parent and child so you don't need to specify the position of the arg

void    free_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}