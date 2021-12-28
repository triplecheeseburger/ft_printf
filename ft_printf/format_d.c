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

int	write_d(va_list ap, t_options options)
{
	int	d;
	int	count;
	int	length;

	d = va_arg(ap, int);
	count = 0;
	if (d == 0 && options.precision == 0)
	{
		while (options.width--)
			count += write(1, " ", 1);
		return (count);
	}
	length = get_length_d(d,options);
	count += print_integer(d, options, length);
	return (count);
}

int	proc_sign_dp(int sign, t_options options)
{
	int	count;

	count = 0;
	if (sign == TRUE)
	{
		if (options.flags['+'] == 1)
			count += write(1, "+", 1);
		else if (options.flags[' '] == 1)
			count += write(1, " ", 1);
	}
	return (count);
}

int	get_length_d(int d, t_options options)
{
	int	count;

	count = 0;
	if (d == 0)
		return (1);
	if (d < 0 || options.flags['+'] == TRUE || options.flags[' '] == TRUE)
		++count;
	while (d && ++count)
		d /= 10;
	return (count);
}

int	print_integer(int d, t_options options, int length)
{
	int		count;
	char	padding;

	count = 0;
	if (options.flags['0'] == TRUE && options.precision == FALSE)
		padding = '0';
	else
		padding = ' ';
	if (options.width <= length)
		return (ft_putnbr_precision((long long)d, length, options));
	if (options.flags['-'] == FALSE)
	{
		if (d < 0 && options.width-- >= options.precision)
			options.precision = options.width--;
		while (options.width > length && options.width-- > options.precision)
			count += write(1, &padding, 1);
		count += ft_putnbr_precision((long long)d, length, options);
	}
	else if (options.flags['-'] == TRUE)
	{
		count += ft_putnbr_precision((long long)d, length, options);
		while (options.width-- > length)
			count += write(1, " ", 1);
	}
	return (count);
}

int	ft_putnbr_precision(long long n, int length, t_options options)
{
	char	a[10];
	int		i;
	int		count;

	count = proc_sign_dp(n >= 0, options);
	i = 10;
	options.precision += n < 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	while (options.precision-- > length)
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
