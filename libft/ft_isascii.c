/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:26:46 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/10/30 11:19:39 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/* // TEST
int main(void)
{
	int t1 = 'c';
	int t2 = '$';
	int t3 = '3';
	int t4 = '\n';
	int t5 = &#160;

	printf("%d\n", ft_isascii(t1));
	printf("%d\n", ft_isascii(t2));
	printf("%d\n", ft_isascii(t3));
	printf("%d\n", ft_isascii(t4));
	printf("%d\n", ft_isascii(t5));
	
}*/
