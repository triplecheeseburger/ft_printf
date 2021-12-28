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

void	write_0(va_list ap, t_options *opts)
{
	unsigned int	u;

	u = va_arg(ap, int);
	if (u == 0 && opts->prec == 0)
	{
		while (opts->width--)
			opts->count += write(1, " ", 1);
		return ;
	}
	get_length_x(u, opts);
	print_he0(u, opts);
}

void	print_he0(unsigned int u, t_options *opts)
{
	if (opts->width <= opts->length)
	{
		ft_put0_prec(u, opts);
		return ;
	}
	if (opts->flags['-'] == FALSE)
	{
		while (opts->width > opts->length && opts->width-- > opts->prec)
			opts->count += write(1, &opts->padd, 1);
		ft_put0_prec(u, opts);
	}
	else if (opts->flags['-'] == TRUE)
	{
		ft_put0_prec(u, opts);
		while (opts->width-- > opts->length)
			opts->count += write(1, " ", 1);
	}
}

void	ft_put0_prec(unsigned int u, t_options *opts)
{
	char	a[8];
	int		i;

	if (opts->flags['#'] == 1 && u != 0)
		opts->count += write(1, "0X", 2);
	i = 8;
	while (opts->prec > opts->length && ++opts->length)
		opts->count += write(1, "0", 1);
	if (u == 0)
		opts->count += write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789ABCDEF"[u % 16];
		u /= 16;
	}
	opts->count += write(1, &a[i], 8 - i);
}
