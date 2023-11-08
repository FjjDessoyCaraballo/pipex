/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:48:20 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/10/30 14:21:45 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	void			*found_char;
	size_t			i;

	i = 0;
	found_char = NULL;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			found_char = &p[i];
			return (found_char);
		}
		i++;
	}
	return (found_char);
}
/*
int main(void)
{
	char s[] = "Coitus Supremus";

	char *ptr = memchr(s, 'c', sizeof(s));
	
	printf("piss off %s\n", ptr);
	return (0);
}*/
