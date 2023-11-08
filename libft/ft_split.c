/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:40 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/06 16:07:27 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// this function takes care of allocation of each new substring
// ft_substring is used for allocation inside tab which points to tab_p
static void	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*tmp;

	tmp = s;
	tab_p = tab;
	while (*tmp)
	{
		while (*s == sep)
			++s;
		tmp = s;
		while (*tmp && *tmp != sep)
			++tmp;
		if (*tmp == sep || tmp > s)
		{
			*tab_p = ft_substr(s, 0, tmp - s);
			s = tmp;
			++tab_p;
		}
	}
	*tab_p = NULL;
}
// counts how many strings are there to make space for further allocation

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			++s;
		if (*s)
			++word_count;
		while (*s && *s != sep)
			++s;
	}
	return (word_count);
}
// size here is defined by ft_count_words and adds space for a null
// ft_allocate allocates all letters until it finds the indicated split

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}
/*
int main(void)
{
  char str[] = "hello world";
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
} */
