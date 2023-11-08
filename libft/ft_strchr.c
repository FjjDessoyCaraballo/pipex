/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:45:27 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/10/30 11:33:15 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	ch = (char)c;
	while (str[i] != ch)
	{
		if (str[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (&str[i]);
}
/*
int	main(void) {
    const char *testString = "Hello, World!";
    int characterToFind = 'o';

    char *result = ft_strchr(testString, characterToFind);

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
} //  */
