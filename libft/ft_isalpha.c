/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:12:08 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/10/31 11:48:04 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*
int main(void)
{
	char c1 = 'h';
	char c2 = 'H';
	char c3 = '#';

	int dig1 = ft_isalpha(c1);
	int dig2 = ft_isalpha(c2);
	int dig3 = ft_isalpha(c3);

	printf("%d\n", dig1);
	printf("%d\n", dig2);
	printf("%d\n", dig3);
} // */
