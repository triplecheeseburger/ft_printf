/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_du.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:36:30 by hakim             #+#    #+#             */
/*   Updated: 2021/12/07 13:28:44 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	write_d(va_list ap, t_options *opts)
{
	int	d;
	int	count;
	int	length;

	d = va_arg(ap, int);
	count = 0;
	if (d == 0 && opts->prec == 0)
	{
		while (opts->width--)
			count += write(1, " ", 1);
		return (count);
	}
	length = get_length_d(d, opts);
	count += print_integer(d, opts);
	return (count);
}

int	proc_sign_dp(int sign, t_options *opts)
{
	int	count;

	count = 0;
	if (sign == TRUE)
	{
		if (opts->flags['+'] == 1)
			count += write(1, "+", 1);
		else if (opts->flags[' '] == 1)
			count += write(1, " ", 1);
	}
	return (count);
}

int	get_length_d(int d, t_options *opts)
{
	int	count;

	count = 0;
	if (d == 0)
		return (1);
	if (d < 0 || opts->flags['+'] == TRUE || opts->flags[' '] == TRUE)
		++count;
	while (d && ++count)
		d /= 10;
	return (count);
}

int	print_integer(int d, t_options *opts)
{
	int		count;
	char	padd;

	count = 0;
	padd = ' ';
	if (opts->flags['0'] == TRUE && opts->prec == FALSE)
		padd = '0';
	if (opts->width <= length)
		return (ft_putnbr_prec((long long)d, opts));
	if (opts->flags['-'] == FALSE)
	{
		if (d < 0 && opts->width-- >= opts->prec)
			opts->prec = opts->width--;
		while (opts->width > length && opts->width-- > opts->prec)
			count += write(1, &padd, 1);
		count += ft_putnbr_prec((long long)d, opts);
	}
	else if (opts->flags['-'] == TRUE)
	{
		count += ft_putnbr_prec((long long)d, opts);
		while (opts->width-- > length)
			count += write(1, " ", 1);
	}
	return (count);
}

int	ft_putnbr_prec(long long n, t_options *opts)
{
	char	a[10];
	int		i;
	int		count;

	count = proc_sign_dp(n >= 0, opts);
	i = 10;
	opts->prec += n < 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	while (opts->prec > opts->length && ++opts->length)
		count += write(1, "0", 1);
	if (n == 0)
		count += write(1, "0", 1);
	while (n)
	{
		a[--i] = n % 10 + '0';
		n /= 10;
	}
	count += write(1, &a[i], 10 - i);
	return (count);
}
