int	ft_putnbr_padding(int n, int length, t_options options)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
	options.precision -= n < 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		if (n == -2147483648)
		{
			while (options.precision-- > length)
				count += write(1, "0", 1);
			count += write(1, "2147483648", 10));
			return (count);
		}
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

int	write_d(va_list ap, t_options options)
{
	int	d;
	int	count;
	int length;

	d = va_arg(ap, int);
	count = proc_sign_dp(d >= 0, options);
	options.width -= count;
	if (d == 0 && options.precision == 0)
	{
		while (options.width--)
			count += write(1, " ", 1);
		return (count);
	}
	length = get_length_d(d);
	count += ft_putnbr_padding((long long)d, length, options);
//	if (options.precision == FALSE || options.precision - (d < 0) <= length)
//		return (count + no_precision_d(d, options, length));
//	count += yes_precision_d(d, options, length));
//	return (count);
//	count += ft_putnbr(d);
//	return (count);
//	options.precision -= d < 0;
}
/*
int	yes_precision_d(int d, t_options options, int length)
{
	int count;

	count = 0;
	if (options.width <= options.precision)
	{

	}
	else if (options.width > options.precision)
	{

	}
	return (count);
}
*/

int	ft_putnbr_precision(long long n, int length, t_options options)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
	options.precision -= n < 0;
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

int	no_precision_d(int d, t_options options, int length)
{
	int		count;
	char	padding;

	count = 0;
	if (options.flags['0'] == TRUE && options.precision != FALSE)
		padding = '0';
	else
		padding = ' ';
	if (options.width <= length)
		return (ft_putnbr_precision((long long)d, length, options));
	if (options.flags['-'] == FALSE)
	{
		while (options.width-- > length)
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

int	get_length_d(int d)
{
	int	count;

	count = 0;
	if (d == 0)
		return (1);
	if (d < 0)
		++count;
	while (d && ++count)
		d /= 10;
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
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
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

#include "ft_printf.h"

int	write_p(va_list ap, t_options options)
{
	unsigned long long	ptr;
	int					index;
	int					count;
	char				toprint[16];

	ptr = va_arg(ap, long long);
	count = proc_sign_dp(TRUE, options);
	options.width -= count;
	if (ptr == 0)
		return (print_null_ptr(count, options));
	index = 16;
	while (--index >= 0)
	{
		toprint[index] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	while (++index < 16 && toprint[index] == '0')
		;
	count = print_ptr(index, count, options);
	return (count);
}

int	print_ptr(int index, int count, char *toprint, t_options options)
{
	if (index == 16)
		index = 15;
	if (options.flags['-'] == FALSE)
	{
		while (options.width-- > 16 - index + 2)
			count += write(1, " ", 1);
		write(1, "0x", 2);
		count += 2;
		while (index < 16)
			count += write(1, &toprint[index++], 1);
	}
	else if (options.flags['-'] == TRUE)
	{
		write(1, "0x", 2);
		count += 2;
		while (index < 16)
			count += write(1, &toprint[index++], 1);
		while (options.width-- > 16 - index + 2)
			count += write(1, " ", 1);
	}
	return (count);
}


int	print_null_ptr(int count, t_options options)
{
	if (options.width <= 3)
		return (count + write(1, "0x0", 3));
	if (options.flags['-'] == FALSE)
	{
		while (options.width-- > 3)
			count += write(1, " ", 1);
		count += write(1, "0x0", 3));
	}
	else if (options.flags['-'] == TRUE)
	{
		count += write(1, "0x0", 3);
		while (options.width-- > 3)
			count += write(1, " ", 1);
	}
	return (count);
}
