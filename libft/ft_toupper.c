/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:00:23 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/10/31 11:37:13 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c + ('A' - 'a'));
	else
		return (c);
}
/* // TEST
int main(void)
{
	char c1[] = "HELLO";
	char c2[] = "hello";
	char c3[] = "";
	char c4[] = "#";
	char c5[] = "Hello";
	char c6[] = "Hello ";

	int dig1 = ft_str_is_uppercase(c1);
	int dig2 = ft_str_is_uppercase(c2);
	int dig3 = ft_str_is_uppercase(c3);
	int dig4 = ft_str_is_uppercase(c4);
	int dig5 = ft_str_is_uppercase(c5);
	int dig6 = ft_str_is_uppercase(c6);

	printf("%d\n", dig1);
	printf("%d\n", dig2);
	printf("%d\n", dig3);
	printf("%d\n", dig4);
	printf("%d\n", dig5);
	printf("%d\n", dig6);
}*/
