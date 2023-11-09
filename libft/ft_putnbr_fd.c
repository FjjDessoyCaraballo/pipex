/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:23:34 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/09 13:29:36 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	buffer[13];

	i = 10;
	buffer[11] = '\0';
	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		while (n > 0)
		{
			buffer[i] = 48 + (n % 10);
			n /= 10;
			i--;
		}
		ft_putstr_fd(&buffer[i + 1], fd);
	}
}
