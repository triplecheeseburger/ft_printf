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

int	write_0(va_list ap, t_options *opts)
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
	length = get_length_x(u, opts);
	count += print_he0(u, opts);
	return (count);
}

int	print_he0(unsigned int u, t_options *opts)
{
	int		count;
	char	padd;

	count = 0;
	if (opts->flags['0'] == TRUE && opts->prec == FALSE)
		padd = '0';
	else
		padd = ' ';
	if (opts->width <= length)
		return (ft_put0_prec(u, opts));
	if (opts->flags['-'] == FALSE)
	{
		while (opts->width > length && opts->width-- > opts->prec)
			count += write(1, &padd, 1);
		count += ft_put0_prec(u, opts);
	}
	else if (opts->flags['-'] == TRUE)
	{
		count += ft_put0_prec(u, opts);
		while (opts->width-- > length)
			count += write(1, " ", 1);
	}
	return (count);
}

int	ft_put0_prec(unsigned int u, t_options *opts)
{
	char	a[8];
	int		i;
	int		count;

	count = proc_sign_0(u, opts);
	i = 8;
	while (opts->prec-- > opts->length && ++opts->length)
		count += write(1, "0", 1);
	if (u == 0)
		count += write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789ABCDEF"[u % 16];
		u /= 16;
	}
	count += write(1, &a[i], 8 - i);
	return (count);
}

int	proc_sign_0(unsigned int u, t_options *opts)
{
	int	count;

	count = 0;
	if (opts->flags['#'] == 1 && u != 0)
		count += write(1, "0X", 2);
	return (count);
}
