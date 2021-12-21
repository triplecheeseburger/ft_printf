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

void	options_init(t_options options)
{
	ft_bzero(options.flags, 128);
	options.precision = 0;
	options.width = 0;
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