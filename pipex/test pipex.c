/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:38:43 by fdessoy-          #+#    #+#             */
/*   Updated: 2024/01/09 11:38:44 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t pid;
	
	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork failure\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		printf("I am the child process\n");
		sleep(10);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("I am the parent process.\n");
		wait(NULL);
		printf("Child process terminated after a 10s delay.\n");
	}
	return(EXIT_SUCCESS);
}