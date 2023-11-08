/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:29:06 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/10/30 11:57:38 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	ch = (char)c;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (str[i] == ch)
		{
			return (&str[i]);
		}
		i--;
	}
	return (NULL);
}
/*

int	main(void)
{
    const char *testString = "Hello, World!";
    int characterToFind = 'o';

    char *result = ft_strrchr(testString, characterToFind);

    if (result != NULL)
    {
        printf("Character '%c' found at position: %ld\n", characterToFind,
		result - testString);
    }
    else
    {
        printf("Character '%c' not found in the string.\n", characterToFind);
    }

    return (0);
}*/
