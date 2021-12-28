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

int	write_u(va_list ap, t_options *opts)
{
	unsigned int	u;
	int				count;
	int				length;

	u = va_arg(ap, int);
	count = 0;
	if (u == 0 && opts->prec == 0)
	{
		while (opts->width--)
			count += write(1, " ", 1);
		return (count);
	}
	length = get_length_u(u);
	count = print_uinteger(u, opts);
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

int	print_uinteger(unsigned int u, t_options *opts)
{
	int		count;
	char	padd;

	count = 0;
	if (opts->flags['0'] == TRUE && opts->prec == FALSE)
		padd = '0';
	else
		padd = ' ';
	if (opts->width <= length)
		return (ft_putui_prec(u, opts));
	if (opts->flags['-'] == FALSE)
	{
		while (opts->width > length && opts->width-- > opts->prec)
			count += write(1, &padd, 1);
		count += ft_putui_prec(u, opts);
	}
	else if (opts->flags['-'] == TRUE)
	{
		count += ft_putui_prec(u, opts);
		while (opts->width-- > length)
			count += write(1, " ", 1);
	}
	return (count);
}

int	ft_putui_prec(unsigned int u, t_options *opts)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
	while (opts->prec-- > opts->length && ++opts->length)
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
