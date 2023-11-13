/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:40 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/13 14:40:12 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static int	ft_countwords(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			s += ft_wordlen(s, c);
		}
		else
			s++;
	}
	return (count);
}

static void	*free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	count = ft_countwords(s, c);
	array = malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	array[count] = NULL;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			array[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!array[i++])
				return (free_array(array));
			s += ft_wordlen(s, c);
		}
		else
			s++;
	}
	return (array);
}
/*
int main(void)
{
  char str[0] = "4";
  char sep = ' ';
  char **result = ft_split(str, sep);
  int i;

  if (result)
  {
	  i = 0;
	  while (result[i] != NULL)
	  {
		  printf("Word %d: %s\n", i + 1, result[i]);
		  free (result[i]);
		  i++;
	  }
	  free (result);
  }
  else
	  printf("Memory allocation failed.\n");
  return (0);
} // */
