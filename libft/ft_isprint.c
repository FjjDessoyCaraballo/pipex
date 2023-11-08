/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:13:36 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/07 12:27:49 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
/*
int main(void)
{
	char c1 = 'h';
	char c2 = '\n';
	char c3 = ' ';
	char c4 = '~';
	char c5 = 'h';

	int dig1 = ft_isprint(c1);
	int dig2 = ft_isprint(c2);
	int dig3 = ft_isprint(c3);
	int dig4 = ft_isprint(c4);
	int dig5 = ft_isprint(c5);

	printf("%d\n", dig1);
	printf("%d\n", dig2);
	printf("%d\n", dig3);
	printf("%d\n", dig4);
	printf("%d\n", dig5);
} // */
