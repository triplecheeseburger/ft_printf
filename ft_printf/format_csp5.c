/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_csp5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 00:35:12 by hakim             #+#    #+#             */
/*   Updated: 2021/12/07 13:17:07 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_c(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int	write_s(va_list ap)
{
	char	*s;
	int		index;

	index = 0;
	s = va_arg(ap, char *);
	if (s == 0)
		return (write(1, "(null)", 6));
	while (s[index] != '\0')
		write(1, &s[index++], 1);
	return (index);
}

int	write_p(va_list ap)
{
	unsigned long long	ptr;
	int					index;
	int					count;
	char				toprint[16];

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
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	count = 2;
	while (index < 16 && ++count)
		write(1, &toprint[index++], 1);
	return (count);
}

int write_5(va_list ap)
{
	if (ap)
		write(1, "", 0);
	return (write(1, "%", 1));
}
