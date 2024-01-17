/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skipina <skipina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:18:15 by skipina           #+#    #+#             */
/*   Updated: 2024/01/14 15:51:56 by jkangash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	draw_line(int x, int l, int m, int r)
{
	int	i;

	i = 0;
	if (x >= 1)
		ft_putchar(l);
	while (i <= (x - 3))
	{
		ft_putchar(m);
		i++;
	}
	if (x >= 2)
		ft_putchar(r);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (y >= 1 && x >= 1)
		draw_line(x, 'A', 'B', 'C');
	while (i < y - 2 && x >= 1)
	{
		draw_line(x, 'B', ' ', 'B');
		i++;
	}
	if (y >= 2 && x >= 1)
	{
		draw_line(x, 'C', 'B', 'A');
	}
}
