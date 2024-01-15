/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:55:57 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/10 10:55:59 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(void)
{
	ft_init_pipex(t_data *data)
	{
		data->cmd1 = NULL;
		data->cmd2 = NULL;
		data->envp = NULL;
		data->args1 = NULL;
		data->args2 = NULL;
	}
	ft_check_args();
	ft_parse_cmds();
	ft_parse_args();
	while (cmds)
	{
		ft_cleanup(&data);
	}
}
