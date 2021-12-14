/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:37:22 by hakim             #+#    #+#             */
/*   Updated: 2021/12/07 13:29:11 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_x(const char *format, va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, int);
	proc_sign(format);
	return (ft_putx(u));
}

int	ft_putx(unsigned int u)
{
	char	a[8];
	int		i;
	int		count;

	count = 0;
	i = 8;
	if (u == 0 && ++count)
		write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789abcdef"[u % 16];
		u /= 16;
		++count;
	}
	write(1, &a[i], 8 - i);
	return (count);
}

int	write_0(const char *format, va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, int);
	proc_sign(format);
	return (ft_put0(u));
}

int	ft_put0(unsigned int u)
{
	char	a[8];
	int		i;
	int		count;

	count = 0;
	i = 8;
	if (u == 0 && ++count)
		write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789ABCDEF"[u % 16];
		u /= 16;
		++count;
	}
	write(1, &a[i], 8 - i);
	return (count);
}
