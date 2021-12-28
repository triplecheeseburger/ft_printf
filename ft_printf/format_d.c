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

int	write_d(va_list ap, t_options *options)
{
	int	d;
	int	count;

	d = va_arg(ap, int);
	count = 0;
	if (d == 0 && options->precision == 0)
	{
		while (options->width--)
			count += (int)write(1, " ", 1);
		return (count);
	}
	options->length = get_length_d(d, options);
	count += print_integer(d, options);
	return (count);
}

int	proc_sign_dp(int sign, t_options *options)
{
	int	count;

	count = 0;
	if (sign == TRUE)
	{
		if (options->flags['+'] == 1)
			count += (int)write(1, "+", 1);
		else if (options->flags[' '] == 1)
			count += (int)write(1, " ", 1);
	}
	return (count);
}

int	get_length_d(int d, t_options *options)
{
	int	count;

	count = 0;
	if (d == 0)
		return (1);
	if (d < 0 || options->flags['+'] == TRUE || options->flags[' '] == TRUE)
		++count;
	while (d && ++count)
		d /= 10;
	return (count);
}

int	print_integer(int d, t_options *options)
{
	int		count;

	count = 0;
	if (options->flags['-'] == FALSE)
	{
		if (d < 0 && options->padding == '0'
			&& options->width > options->precision)
			options->precision = --options->width;
		if (d < 0 && options->precision > options->length
			&& options->width > options->precision)
			--options->width;
		while (options->width > options->length
			&& options->width-- > options->precision)
			count += (int)write(1, &options->padding, 1);
		count += ft_putnbr_precision((long long)d, options);
	}
	else if (options->flags['-'] == TRUE)
	{
		count += ft_putnbr_precision((long long)d, options);
		while (options->width-- > options->length)
			count += (int)write(1, " ", 1);
	}
	return (count);
}

int	ft_putnbr_precision(long long n, t_options *options)
{
	char	a[10];
	int		i;
	int		count;

	count = proc_sign_dp(n >= 0, options);
	i = 10;
	options->precision += n < 0;
	if (n < 0)
	{
		count += (int)write(1, "-", 1);
		n = -n;
	}
	while (options->precision > options->length && ++options->length)
		count += (int)write(1, "0", 1);
	if (n == 0)
		count += (int)write(1, "0", 1);
	while (n)
	{
		a[--i] = n % 10 + '0';
		n /= 10;
	}
	count += (int)write(1, &a[i], 10 - i);
	return (count);
}
