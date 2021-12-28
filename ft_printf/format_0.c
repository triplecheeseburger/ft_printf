/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:27:28 by hakim             #+#    #+#             */
/*   Updated: 2021/12/28 02:27:29 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_0(va_list ap, t_options *options)
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
	count += print_he0(u, options);
	return (count);
}

int	print_he0(unsigned int u, t_options *options)
{
	int		count;

	count = 0;
	if (options->width <= options->length)
		return (ft_put0_precision(u, options));
	if (options->flags['-'] == FALSE)
	{
		while (options->width > options->length
			&& options->width-- > options->precision)
			count += (int)write(1, &options->padding, 1);
		count += ft_put0_precision(u, options);
	}
	else if (options->flags['-'] == TRUE)
	{
		count += ft_put0_precision(u, options);
		while (options->width-- > options->length)
			count += (int)write(1, " ", 1);
	}
	return (count);
}

int	ft_put0_precision(unsigned int u, t_options *options)
{
	char	a[8];
	int		i;
	int		count;

	count = proc_sign_0(u, options);
	i = 8;
	while (options->precision > options->length && ++options->length)
		count += (int)write(1, "0", 1);
	if (u == 0)
		count += (int)write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789ABCDEF"[u % 16];
		u /= 16;
	}
	count += (int)write(1, &a[i], 8 - i);
	return (count);
}

int	proc_sign_0(unsigned int u, t_options *options)
{
	int	count;

	count = 0;
	if (options->flags['#'] == 1 && u != 0)
		count += (int)write(1, "0X", 2);
	return (count);
}
