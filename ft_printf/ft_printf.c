/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:17:19 by hakim             #+#    #+#             */
/*   Updated: 2021/12/07 16:51:21 by hakim            ###   ########.fr       */
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

int	f_proc(const char *format, int *index, va_list ap, int (*func[])(va_list))
{
	int	count;

	count = func[(int)format[*index + 1]](ap);
	*index += 2;
	return (count);
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
	func['X'] = write_0;
	func['%'] = write_5;
}
