/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:23:00 by hakim             #+#    #+#             */
/*   Updated: 2021/12/21 16:23:02 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	options_init(t_options *options)
{
	options->flags['#'] = FALSE;
	options->flags[' '] = FALSE;
	options->flags['+'] = FALSE;
	options->flags['-'] = FALSE;
	options->flags['0'] = FALSE;
	options->precision = FALSE;
	options->width = FALSE;
}

void	func_init(int (*func[])(va_list, t_options *))
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
