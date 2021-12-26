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

	d = va_arg(ap, int);
	count = proc_sign_dp(d >= 0, options);
	count += ft_putnbr(d);
	return (count);
}

int	ft_putnbr(int n)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0 && ++count)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0 && ++count)
		write(1, "0", 1);
	while (n)
	{
		a[--i] = n % 10 + '0';
		n /= 10;
		++count;
	}
	write(1, &a[i], 10 - i);
	return (count);
}

int	write_u(va_list ap, t_options options)
{
	unsigned int	u;

	if (&options)
		write(1, "", 0);
	u = va_arg(ap, int);
	return (ft_putui(u));
}

int	ft_putui(unsigned int u)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
	if (u == 0 && ++count)
		write(1, "0", 1);
	while (u)
	{
		a[--i] = u % 10 + '0';
		u /= 10;
		++count;
	}
	write(1, &a[i], 10 - i);
	return (count);
}
