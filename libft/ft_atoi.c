/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:51:35 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/08 15:32:24 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	long	res;
	int		sign;

	sign = 1;
	res = 0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		i++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
		{
			sign *= -1;
			i++;
		}
		i++;
	}
	while (*s != '\0' && (*s >= '0' && *s <= '9'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
		if (res < 0)
		{
			if (sign == 1)
				return (9223372036854775807);
			return (9223372036854775808 - 1);
		}
	}
	res = res * sign;
	return ((int)res);
}
/*
int main(void)
{
	char str[] = "-9147483648";

	int val = ft_atoi(str);
	printf("%d \n", val);
	return (0);
} // */
