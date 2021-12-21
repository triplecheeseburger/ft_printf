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
	t_options	options;
	int 		conv;
	int			count;
	int 		opdex;

	conv = *index + find_conv(&format[*index]);
	options_init(options);
	opdex = -1;
	while (++opdex < conv && is_flag(&format[++*index]))
		options.flags[(int)format[*index]] = 1;
	options.width = ft_atoi(&format[*index++]);
	if (format[*index++] == '.')
		options.flags['.'] = 1;
	options.precision = ft_atoi(&format[*index]);
	count = func[(int)format[conv]](format, ap, options); // have to pass options
	*index = conv + 1;
	return (count);
}