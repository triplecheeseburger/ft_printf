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

int	write_u(va_list ap, t_options *options)
{
	unsigned int	u;
	int				count;

	u = va_arg(ap, int);
	count = 0;
	if (u == 0 && options->precision == 0)
	{
		while (options->width--)
			count += (int)write(1, " ", 1);
		return (count);
	}
	options->length = get_length_u(u);
	count = print_uinteger(u, options);
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

int	print_uinteger(unsigned int u, t_options *options)
{
	int		count;

	count = 0;
	if (options->width <= options->length)
		return (ft_putui_precision(u, options));
	if (options->flags['-'] == FALSE)
	{
		while (options->width > options->length
			&& options->width-- > options->precision)
			count += (int)write(1, &options->padding, 1);
		count += ft_putui_precision(u, options);
	}
	else if (options->flags['-'] == TRUE)
	{
		count += ft_putui_precision(u, options);
		while (options->width-- > options->length)
			count += (int)write(1, " ", 1);
	}
	return (count);
}

int	ft_putui_precision(unsigned int u, t_options *options)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
	while (options->precision > options->length && ++options->length)
		count += (int)write(1, "0", 1);
	if (u == 0)
		count += (int)write(1, "0", 1);
	while (u)
	{
		a[--i] = u % 10 + '0';
		u /= 10;
	}
	count += (int)write(1, &a[i], 10 - i);
	return (count);
}
