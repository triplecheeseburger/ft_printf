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

int	write_c(va_list ap, t_options *opts)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(ap, int);
	if (opts->flags['-'] == FALSE)
	{
		while (opts->width-- > 1)
			count += write(1, " ", 1);
		count += write(1, &c, 1);
	}
	else if (opts->flags['-'] == TRUE)
	{
		count += write(1, &c, 1);
		while (opts->width-- > 1)
			count += write(1, " ", 1);
	}
	return (count);
}

int	write_s(va_list ap, t_options *opts)
{
	char	*s;
	int		count;
	int		length;

	count = 0;
	s = va_arg(ap, char *);
	if (s == 0)
		s = "(null)";
	length = get_length_s(s, opts);
	if (opts->flags['-'] == FALSE)
	{
		while (opts->width-- > length)
			count += write(1, " ", 1);
		while (length-- && *s != '\0')
			count += write(1, s++, 1);
	}
	else if (opts->flags['-'] == TRUE)
	{
		while (length-- && *s != '\0')
			count += write(1, s++, 1);
		length += count + 1;
		while (opts->width-- > length)
			count += write(1, " ", 1);
	}
	return (count);
}

int	get_length_s(char *s, t_options *opts)
{
	int	len;

	len = (int)ft_strlen(s);
	if (opts->prec == FALSE)
		return (len);
	else if (opts->width > len && opts->prec > len)
		return ((int)ft_strlen(s));
	else
		return (opts->prec);
}

int	write_5(va_list ap, t_options *opts)
{
	if (ap || opts->width)
		write(1, "", 0);
	return (write(1, "%", 1));
}
