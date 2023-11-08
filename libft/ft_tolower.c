/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:00:08 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/10/31 10:45:12 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
	else
		return (c);
}
/* // TEST
int main(void)
{
	char c1[] = "Hello";
	char c2[] = "hello";
	char c3[] = "";
	char c4[] = "#";

	int dig1 = ft_str_is_lowercase(c1);
	int dig2 = ft_str_is_lowercase(c2);
	int dig3 = ft_str_is_lowercase(c3);
	int dig4 = ft_str_is_lowercase(c4);

	printf("%d\n", dig1);
	printf("%d\n", dig2);
	printf("%d\n", dig3);
	printf("%d\n", dig4);
}
*/
