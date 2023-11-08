/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:11:12 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/07 12:30:44 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c < 48 || c > 57) && (c < 65 || c > 90) && (c < 97 || c > 122))
	{
		return (0);
	}
	else
		return (1);
}
/*
int main(void)
{
	int c1 = 'H';
	int c2 = 'h';
	int c3 = '3';
	int c4 = '#';

	int dig1 = ft_isalnum(c1);
	int dig2 = ft_isalnum(c2);
	int dig3 = ft_isalnum(c3);
	int dig4 = ft_isalnum(c4);

	printf("%d\n", dig1);
	printf("%d\n", dig2);
	printf("%d\n", dig3);
	printf("%d\n", dig4);
} // */
