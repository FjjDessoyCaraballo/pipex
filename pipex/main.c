/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:19:39 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/13 10:16:55 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_printf("Error with arguments: \n");
		ft_printf("Wrong number of arguments, or ");
		ft_printf("commands provided don't exist/path not specified;\n");
		return (0);
	}
	return (pipex(argv, envp));
}
