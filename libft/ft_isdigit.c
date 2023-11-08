/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:12:40 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/07 12:40:37 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}
/*
int main(void)
{
	char c1 = '1';
	char c2 = 'a';
	char c3 = '#';

	int dig1 = ft_isdigit(c1);
	int dig2 = ft_isdigit(c2);
	int dig3 = ft_isdigit(c3);

	printf("%d\n", dig1);
	printf("%d\n", dig2);
	printf("%d\n", dig3);
} // */
