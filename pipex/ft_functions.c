#include <stdlib.h>
#include <unistd.h>

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	value;

	value = (unsigned char)c;
	p = s;
	while (len > 0)
	{
		*p = value;
		p++;
		len--;
	}
	return (s);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	a;

	a = count * size;
	if (a < count && a < size)
		return (NULL);
	ptr = malloc(a);
	if (!ptr)
		return (NULL);
	if (ptr)
		ft_memset(ptr, 0, a);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	l;

	l = ft_strlen(s);
	if (!s || start > l)
		return ((char *)ft_calloc(1, 1));
	l = ft_strlen(s + start);
	if (l >= len)
		l = len;
	new_str = (char *)malloc(l + 1);
	if (!new_str)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (*str1 != '\0' && *str2 != '\0' && i < n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		i++;
	}
	if (i == n)
		return (0);
	return (*str1 - *str2);
}

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
#include <stdio.h>
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

// #include <stdio.h>

// int main(void)
// {
// 	char *str = "cat";

// 	char **arr = ft_split(str, ' ');
// 	for (int i = 0; arr[i] != NULL; i++)
// 		printf("%s\n", arr[i]);
// 	return (0);
// }

