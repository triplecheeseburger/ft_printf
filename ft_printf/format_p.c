/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 04:05:52 by hakim             #+#    #+#             */
/*   Updated: 2021/12/27 04:05:55 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
