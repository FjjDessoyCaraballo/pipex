/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:25:47 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/08 12:12:46 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_new(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = str_new(ft_strlen(s));
	if (!str)
		return (NULL);
	i = 0;
	result = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (result);
}
/*
// TESTER FUNCTION
char    strupper_and_one(unsigned int index, char character)
{
    (void)index;
    if (character >= 'a' && character <= 'z')
    {
        return (char)(character - 32);
    }
    return (character);
}

int    main(int argc, char **argv)
{
    char    *str_mapi_ft;
    int        all_upper;
    int        i;
    int        j;

    i = 1;
    while (i < argc)
    {
        str_mapi_ft = ft_strmapi(argv[i], &strupper_and_one);
        all_upper = 1;
        j = 0;
        while (str_mapi_ft[j])
        {
            if (islower(str_mapi_ft[j]))
            {
                all_upper = 0;
                break ;
            }
            j++;
        }
        if (str_mapi_ft[0] == '1' || ft_strlen(str_mapi_ft) == 0)
        {
            if (all_upper)
                printf("G");
            else
                printf("[%s|%s]", argv[i], str_mapi_ft);
        }
        else
            printf("[%s|%s]", argv[i], str_mapi_ft);
        if (str_mapi_ft)
            free(str_mapi_ft);
        i++;
    }
    printf("\n");
    return (0);
}  // */
