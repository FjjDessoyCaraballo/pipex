/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:51:35 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/08 13:49:51 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *s)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
		if (res < 0)
			return (-1);
		return (1);
	}
	res = res * sign;
	return ((int)res);
}

int main(void)
{
	char str[] = "-9147483648";

	int val = ft_atoi(str);
	printf("%d \n", val);
	return (0);
} // */
