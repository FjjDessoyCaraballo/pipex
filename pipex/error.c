/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:43:21 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/02/20 12:43:22 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void print_me(char *str, int num)
{
	if (num == 1)
	{
		ft_putstr_fd("Pipex: file not found: ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (num == 2)
	{
		ft_putstr_fd("Pipex: file not found: ", 2);
		ft_putendl_fd(str, 2);
	}
	if (num == 99)
	{
		ft_putstr_fd("Pipex: command not found: ", 2);
		ft_putendl_fd(str, 2);
	}
	else if (num == 100)
		ft_putstr_fd("Pipex: Invalid number of arguments", 2);
}