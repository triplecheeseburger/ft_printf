/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:17:19 by hakim             #+#    #+#             */
/*   Updated: 2021/12/07 19:48:39 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	ssize_t	count;
	va_list	ap;
	int		index;
	int		(*func[128])(va_list);

	if (format == 0)
		return (-1);
	count = 0;
	index = 0;
	va_start(ap, format);
	func_init(func);
	while (format[index] != '\0')
	{
		if (format[index] != '%' && ++count)
			write(1, &format[index++], 1);
		else
			count += f_proc(format, &index, ap, func);
	}
	va_end(ap);
	return (count);
}

int	f_proc(const char *format, int *index, va_list ap, int (*func[])(const char *, va_list))
{
	int to_add;

	to_add = find_conv(&format[*index]);
	count = func[(int)format[*index + to_add]](format, ap);
	*index += to_add + 1;
	return (count);
}

void	func_init(int (*func[])(const char *, va_list))
{
	func['c'] = write_c;
	func['s'] = write_s;
	func['p'] = write_p;
	func['d'] = write_d;
	func['i'] = write_d;
	func['u'] = write_u;
	func['x'] = write_x;
	func['X'] = write_0;
	func['%'] = write_5;
}

int	find_conv(const char *format)
{
	char	*conv;
	int		index;
	int		cndex;

	index = 1;
	conv = "cspdiuxX%";
	while (format[index] != '\0')
	{
		cndex = 0;
		while (conv[cndex] != '\0')
			if (format[index] == conv[cndex++])
				return (index);
		++index;
	}
	return (0);
}