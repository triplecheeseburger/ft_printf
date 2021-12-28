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

int	write_x(va_list ap, t_options *options)
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
	options->length = get_length_x(u, options);
	count += print_hex(u, options);
	return (count);
}

int	get_length_x(unsigned int u, t_options *options)
{
	int	count;

	count = 0;
	if (u == 0)
		return (1);
	if (options->flags['#'] == TRUE)
	{
		count += 2;
		options->precision += 2;
	}
	while (u && ++count)
		u = u / 16;
	return (count);
}

int	print_hex(unsigned int u, t_options *options)
{
	int		count;

	count = 0;
	if (options->width <= options->length)
		return (ft_putx_precision(u, options));
	if (options->flags['-'] == FALSE)
	{
		while (options->width > options->length
			&& options->width-- > options->precision)
			count += (int)write(1, &options->padding, 1);
		count += ft_putx_precision(u, options);
	}
	else if (options->flags['-'] == TRUE)
	{
		count += ft_putx_precision(u, options);
		while (options->width-- > options->length)
			count += (int)write(1, " ", 1);
	}
	return (count);
}

int	ft_putx_precision(unsigned int u, t_options *options)
{
	char	a[8];
	int		i;
	int		count;

	count = proc_sign_x(u, options);
	i = 8;
	while (options->precision > options->length && ++options->length)
		count += (int)write(1, "0", 1);
	if (u == 0)
		count += (int)write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789abcdef"[u % 16];
		u /= 16;
	}
	count += (int)write(1, &a[i], 8 - i);
	return (count);
}

int	proc_sign_x(unsigned int u, t_options *options)
{
	int	count;

	count = 0;
	if (options->flags['#'] == 1 && u != 0)
		count += (int)write(1, "0x", 2);
	return (count);
}
