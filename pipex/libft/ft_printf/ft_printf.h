/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdessoy- <fdessoy-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:17:12 by fdessoy-          #+#    #+#             */
/*   Updated: 2023/11/23 15:10:38 by fdessoy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_str(char *s, int *check);
int	ft_char(int c, int *check);
int	ft_nbr(int n, int *check);
int	ft_unsig_nbr(unsigned int n, int *check);
int	format_check(const char *format, va_list args, int *check);
int	ft_hex(unsigned long n, int caps, int *check);
int	ft_pointer(void *ptr, int *check);

#endif
