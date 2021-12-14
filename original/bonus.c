/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:21:32 by hakim             #+#    #+#             */
/*   Updated: 2021/12/14 21:21:36 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# define SHARP 0
# define PLUS 1
# define SPACE 2

int proc_sign(const char *format)
{
	int	flags[3];
	int conv;
	int index;

	index = 0;
	conv = find_conv(format);
	while (index < 3)
		flags[index++] = 0;
	index = 0;
	while (index < conv)
	{
		if (format[index] == '#')
			flags[SHARP] = 1;
		if (format[index] == '+')
			flags[PLUS] = 1;
		if (format[index] == ' ')
			flags[SPACE] = 1;
		++index;
	}

}
