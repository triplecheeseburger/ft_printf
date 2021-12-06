/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:17:19 by hakim             #+#    #+#             */
/*   Updated: 2021/12/06 23:29:41 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	ssize_t	count;
	va_list	ap;
	int		index;

	if (format == 0)
		return (-1);
	count = 0;
	index = 0;
	va_start(ap, format);
	while (format[index] != '\0')
	{
		if (format[index] != '%' && ++count)
			write(1, &format[index++], 1);
		else
			count += f_proc(format, &index, ap);
	}
	va_end(ap);
	return (count);
}

int	f_proc(const char *format, int *index, va_list ap)
{
	int	(*func[128])(va_list);
	int	count;

	func_init(func);
	// if format[index + 1] is func;;;;;;
	count = func[(int)format[*index + 1]](ap);
	*index += 2;
	return(count);
}

void	func_init(int (*func[])(va_list))
{
	func['c'] = write_c;
	func['s'] = write_s;
	func['p'] = write_p;
	func['d'] = write_d;
	func['i'] = write_d;
	func['u'] = write_u;
	func['x'] = write_x;
	func['X'] = write_X;
	func['%'] = write_5; 
}

int	write_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	write_s(va_list ap)
{
	char	*s;
	int		index;

	index = 0;
	s = va_arg(ap, char *);
	while (s[index] != '\0')
		write(1, &s[index++], 1);
	return (index);
}

int	write_p(va_list ap)
{
	long long	ptr;
	int			index;
	int			count;
	char		toprint[16];

	ptr = va_arg(ap, long long);
	index = 15;
	while (index >= 0)
	{
		toprint[index] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
		--index;
	}
	while (++index < 16 && toprint[index] == '0')
		;
	if (index == 16)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count = 2;
	while (index < 16 && ++count)
		write(1, &toprint[index++], 1);
	return (count);
}

int	write_d(va_list ap)
{
	int	d;

	d = va_arg(ap, int);
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	return (ft_putnbr(d));
}

int	ft_putnbr(int n)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
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

int	write_u(va_list ap)
{
	unsigned int	u;

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

int	write_x(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, int);
	return (ft_putx(u));
}

int	ft_putx(unsigned int u)
{
	char	a[8];
	int		i;
	int		count;

	count = 0;
	i = 8;	
	if (u == 0 && ++count)
		write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789abcdef"[u % 16];
		u /= 16;
		++count;
	}
	write(1, &a[i], 8 - i);
	return (count);
}

int	write_X(va_list ap)
{
	unsigned int	u;

	u = va_arg(ap, int);
	return (ft_putX(u));
}

int	ft_putX(unsigned int u)
{
	char	a[8];
	int		i;
	int		count;

	count = 0;
	i = 8;	
	if (u == 0 && ++count)
		write(1, "0", 1);
	while (u)
	{
		a[--i] = "0123456789ABCDEF"[u % 16];
		u /= 16;
		++count;
	}
	write(1, &a[i], 8 - i);
	return (count);
}

int write_5(va_list ap)
{
	write(1, "%", 1);
	return (1);
}
