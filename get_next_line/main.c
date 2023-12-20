/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:23:35 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/12/19 11:23:36 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// #include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char	*line;
	int		fd;
	// int lines;

	// lines = 1;
	fd = open("tests/test2.txt", O_RDONLY);
	printf("fd number is %d\n", fd);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
		line++;
	}
	return (0);
}