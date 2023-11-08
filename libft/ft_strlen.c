/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 11:19:41 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/10/30 15:11:38 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}
/* // TEST
#include <string.h>
#include <stdio.h>

int main(void)
{
    char str[10] = "hello";
    int length = ft_strlen(str);

    printf("%d\n", length);

    return (0);
}*/
