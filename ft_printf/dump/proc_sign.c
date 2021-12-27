/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 03:08:49 by hakim             #+#    #+#             */
/*   Updated: 2021/12/27 03:08:51 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	proc_sign_dp(int sign, t_options options)
{
	int	count;

	count = 0;
	if (sign == TRUE)
	{
		if (options.flags['+'] == 1)
			count += write(1, "+", 1);
		else if (options.flags[' '] == 1)
			count += write(1, " ", 1);
	}
	return (count);
}

int	proc_sign_x(unsigned int u, t_options options)
{
	int	count;

	count = 0;
	if (options.flags['#'] == 1 && u != 0)
		count += write(1, "0x", 2);
	return (count);
}

int	proc_sign_0(unsigned int u, t_options options)
{
	int	count;

	count = 0;
	if (options.flags['#'] == 1 && u != 0)
		count += write(1, "0X", 2);
	return (count);
}
