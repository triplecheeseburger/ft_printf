/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:27:36 by hakim             #+#    #+#             */
/*   Updated: 2021/12/28 02:27:39 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_u(va_list ap, t_options options)
{
	unsigned int	u;
	int				count;
	int				length;

	u = va_arg(ap, int);
	count = 0;
	if (u == 0 && options.precision == 0)
	{
		while (options.width--)
			count += write(1, " ", 1);
		return (count);
	}
	length = get_length_u(u);
	count = print_uinteger(u, options, length);
	return (count);
}

int	get_length_u(unsigned int u)
{
	int	count;

	count = 0;
	if (u == 0)
		return (1);
	while (u && ++count)
		u /= 10;
	return (count);
}

int	print_uinteger(unsigned int u, t_options options, int length)
{
	int		count;
	char	padding;

	count = 0;
	if (options.flags['0'] == TRUE && options.precision == FALSE)
		padding = '0';
	else
		padding = ' ';
	if (options.width <= length)
		return (ft_putui_precision(u, length, options));
	if (options.flags['-'] == FALSE)
	{
		while (options.width > length && options.width-- > options.precision)
			count += write(1, &padding, 1);
		count += ft_putui_precision(u, length, options);
	}
	else if (options.flags['-'] == TRUE)
	{
		count += ft_putui_precision(u, length, options);
		while (options.width-- > length)
			count += write(1, " ", 1);
	}
	return (count);
}

int	ft_putui_precision(unsigned int u, int length, t_options options)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
	while (options.precision-- > length)
		count += write(1, "0", 1);
	if (u == 0)
		count += write(1, "0", 1);
	while (u)
	{
		a[--i] = u % 10 + '0';
		u /= 10;
	}
	count += write(1, &a[i], 10 - i);
	return (count);
}
