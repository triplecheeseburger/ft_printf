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

int	write_p(va_list ap, t_options *opts)
{
	unsigned long long	ptr;
	int					index;
	int					count;
	char				toprint[16];

	ptr = va_arg(ap, long long);
	count = proc_sign_dp(TRUE, opts);
	opts->width -= count;
	index = 16;
	while (--index >= 0)
	{
		toprint[index] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
	}
	while (++index < 16 && toprint[index] == '0')
		;
	count = print_ptr(index, count, toprint, opts);
	return (count);
}

int	print_ptr(int index, int count, char *toprint, t_options *opts)
{
	int	printed;

	if (index == 16)
		index = 15;
	if (opts->flags['-'] == FALSE)
	{
		while (opts->width-- > 16 - index + 2)
			count += write(1, " ", 1);
		write(1, "0x", 2);
		count += 2;
		while (index < 16)
			count += write(1, &toprint[index++], 1);
	}
	else if (opts->flags['-'] == TRUE)
	{
		write(1, "0x", 2);
		count += 2;
		while (index < 16)
			count += write(1, &toprint[index++], 1);
		printed = count;
		while (opts->width-- > printed)
			count += write(1, " ", 1);
	}
	return (count);
}
