/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:08:53 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/01 10:28:34 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdst;

	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	if (dst == src || n == 0)
		return (dst);
	if (cdst < csrc || cdst >= csrc + n)
		return (ft_memcpy(dst, src, n));
	ft_memmove(cdst + n - 1, csrc + n - 1, 1);
	ft_memmove(cdst, csrc, n - 1);
	return (dst);
}
/*
int main(void)
{
	char dest[] = "oldstring";
	char sorc[] = "newstring";

	printf("Before memmove dest = %s, src = %s\n", dest, sorc);
	ft_memmove(dest, sorc, 2);
	//memmove(dest, sorc, 2);
	printf("After memove dest = %s, src = %s\n", dest, sorc);
	
	return (0);
} */
