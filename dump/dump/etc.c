int	ft_putnbr_padd(int n, t_options opts)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
	opts.prec -= n < 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		if (n == -2147483648)
		{
			while (opts.prec-- > length)
				count += write(1, "0", 1);
			count += write(1, "2147483648", 10));
			return (count);
		}
		n = -n;
	}
	while (opts.prec-- > length)
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

int	write_d(va_list ap, t_options opts)
{
	int	d;
	int	count;
	int length;

	d = va_arg(ap, int);
	count = proc_sign_dp(d >= 0, opts);
	opts.width -= count;
	if (d == 0 && opts.prec == 0)
	{
		while (opts.width--)
			count += write(1, " ", 1);
		return (count);
	}
	length = get_length_d(d);
	count += ft_putnbr_padd((long long)d, opts);
//	if (opts.prec == FALSE || opts.prec - (d < 0) <= length)
//		return (count + no_prec_d(d, opts));
//	count += yes_prec_d(d, opts));
//	return (count);
//	count += ft_putnbr(d);
//	return (count);
//	opts.prec -= d < 0;
}
/*
int	yes_prec_d(int d, t_options opts)
{
	int count;

	count = 0;
	if (opts.width <= opts.prec)
	{

	}
	else if (opts.width > opts.prec)
	{

	}
	return (count);
}
*/

int	ft_putnbr_prec(long long n, t_options opts)
{
	char	a[10];
	int		i;
	int		count;

	count = 0;
	i = 10;
	opts.prec -= n < 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	while (opts.prec-- > length)
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

int	no_prec_d(int d, t_options opts)
{
	int		count;
	char	padd;

	count = 0;
	if (opts.flags['0'] == TRUE && opts.prec != FALSE)
		padd = '0';
	else
		padd = ' ';
	if (opts.width <= length)
		return (ft_putnbr_prec((long long)d, opts));
	if (opts.flags['-'] == FALSE)
	{
		while (opts.width-- > length)
			count += write(1, &padd, 1);
		count += ft_putnbr_prec((long long)d, opts);
	}
	else if (opts.flags['-'] == TRUE)
	{
		count += ft_putnbr_prec((long long)d, opts);
		while (opts.width-- > length)
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

int	write_p(va_list ap, t_options opts)
{
	unsigned long long	ptr;
	int					index;
	int					count;
	char				toprint[16];

	ptr = va_arg(ap, long long);
	count = proc_sign_dp(TRUE, opts);
	opts.width -= count;
	if (ptr == 0)
		return (print_null_ptr(count, opts));
	index = 16;
	while (--index >= 0)
	{
		toprint[index] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	while (++index < 16 && toprint[index] == '0')
		;
	count = print_ptr(index, count, opts);
	return (count);
}

int	print_ptr(int index, int count, char *toprint, t_options opts)
{
	if (index == 16)
		index = 15;
	if (opts.flags['-'] == FALSE)
	{
		while (opts.width-- > 16 - index + 2)
			count += write(1, " ", 1);
		write(1, "0x", 2);
		count += 2;
		while (index < 16)
			count += write(1, &toprint[index++], 1);
	}
	else if (opts.flags['-'] == TRUE)
	{
		write(1, "0x", 2);
		count += 2;
		while (index < 16)
			count += write(1, &toprint[index++], 1);
		while (opts.width-- > 16 - index + 2)
			count += write(1, " ", 1);
	}
	return (count);
}


int	print_null_ptr(int count, t_options opts)
{
	if (opts.width <= 3)
		return (count + write(1, "0x0", 3));
	if (opts.flags['-'] == FALSE)
	{
		while (opts.width-- > 3)
			count += write(1, " ", 1);
		count += write(1, "0x0", 3));
	}
	else if (opts.flags['-'] == TRUE)
	{
		count += write(1, "0x0", 3);
		while (opts.width-- > 3)
			count += write(1, " ", 1);
	}
	return (count);
}

int	print_integer(int d, t_options opts)
{
	int		count;
	char	padd;

	count = 0;
	if (opts.flags['0'] == TRUE && opts.prec == FALSE)
		padd = '0';
	else
		padd = ' ';
	if (opts.width <= length)
		return (ft_putnbr_prec((long long)d, opts));
	if (opts.flags['-'] == FALSE)
	{
		while (opts.width-- > length)
			count += write(1, &padd, 1);
		count += ft_putnbr_prec((long long)d, opts);
	}
	else if (opts.flags['-'] == TRUE)
	{
		count += ft_putnbr_prec((long long)d, opts);
		while (opts.width-- > length)
			count += write(1, " ", 1);
	}
	return (count);
}