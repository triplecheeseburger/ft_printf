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

int	write_x(va_list ap, t_options options)
{
	unsigned int	u;
	int 			count;
	int 			length;

	u = va_arg(ap, int);
	count = 0;
	if (u == 0 && options.precision == 0)
	{
		while (options.width--)
			count += write(1, " ", 1);
		return (count);
	}
	length = get_length_x(u, options);
	count += print_hex(u, options, length);
	return (count);
}

int	proc_sign_x(unsigned int u, t_options options)
{
	int	count;

	count = 0;
	if (options.flags['#'] == 1 && u != 0)
		count += write(1, "0x", 2);
	return (count);
}

int	get_length_x(unsigned int u, t_options options)
{
	int	count;

	count = 0;
	if (u == 0)
		return (1);
	if (options.flags['#'] == TRUE)
		count += 2;
	while (u && ++count)
		u = u / 16;
	return (count);
}

int	print_hex(unsigned int u, t_options options, int length)
{
	int		count;
	char	padding;

	count = 0;
	if (options.flags['0'] == TRUE && options.precision != FALSE)
		padding = '0';
	else
		padding = ' ';
	if (options.width <= length)
		return (ft_putx_precision(u, length, options));
	if (options.flags['-'] == FALSE)
	{
		while (options.width-- > length)
			count += write(1, &padding, 1);
		count += ft_putx_precision(u, length, options);
	}
	else if (options.flags['-'] == TRUE)
	{
		count += ft_putx_precision(u, length, options);
		while (options.width-- > length)
			count += write(1, " ", 1);
	}
	return (count);
}

int	ft_putx_precision(unsigned int u, int length, t_options options)
{
	char	a[8];
	int		i;
	int		count;

	count = proc_sign_x(u, options);
	i = 8;
	while (options.precision-- > length)
		count += write(1, "0", 1);
	if (u == 0)
		count += write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789abcdef"[u % 16];
		u /= 16;
	}
	count += write(1, &a[i], 8 - i);
	return (count);
}
