/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_csp5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:35:12 by hakim             #+#    #+#             */
/*   Updated: 2021/12/07 13:27:55 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_c(va_list ap, t_options options)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(ap, int);
	if (options.flags['-'] == FALSE)
	{
		while (options.width-- > 1)
			count += write(1, " ", 1);
		count += write(1, &c, 1);
	}
	else if (options.flags['-'] == TRUE)
	{
		count += write(1, &c, 1);
		while (options.width-- > 1)
			count += write(1, " ", 1);
	}
	return (count);
}

int	write_s(va_list ap, t_options options)
{
	char	*s;
	int		count;
	int		toprint;

	count = 0;
	s = va_arg(ap, char *);
	if (s == 0)
		s = "(null)";
	toprint = set_toprint(options, s);
	if (options.flags['-'] == FALSE)
	{
		while (options.width-- > toprint)
			count += write(1, " ", 1);
		while (toprint--)
			count += write(1, s++, 1);
	}
	else if (options.flags['+'] == TRUE)
	{
		while (toprint--)
			count += write(1, s++, 1);
		while (options.width-- > toprint)
			count += write(1, " ", 1);
	}
	return (count);
}

int	set_toprint(t_options options, char *s)
{
	if (options.precision == FALSE)
		return ((int)ft_strlen(s));
	else
		return (options.precision);
}

int	write_5(va_list ap, t_options options)
{
	if (ap || options.width)
		write(1, "", 0);
	return (write(1, "%", 1));
}
