/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:51:23 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/07 12:55:57 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t	find_len;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	find_len = ft_strlen(find);
	if (!len)
		return (0);
	if (find_len == 0 || len == 0)
		return ((char *)s);
	while (s[i] != '\0' && i < len)
	{
		j = 0;
		while (s[i + j] == find[j] && (i + j) < len)
		{
			j++;
			if (find[j] == '\0')
				return ((char *)(s + i));
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    char test[50];

    strcpy(test, "Hey guys, you you");

    printf("%p\n", ft_strnstr(test, "you", 10));
    printf("%p\n", strnstr(test, "you", 10));
} // */
