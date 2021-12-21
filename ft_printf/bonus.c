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
# define MINUS 0
# define ZERO 1
# define DOT 2

enum {SHARP, PLUS, SPACE};

int proc_flags(const char *format)
{
	proc_signs(format);
	proc_widths(format);
}

int proc_signs(const char *format)
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

int proc_widths(const char *format)
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
		if (format[index] == '-')
			flags[MINUS] = 1;
		if (format[index] == '0')
			flags[ZERO] = 1;
		if (format[index] == '.')
			flags[DOT] = 1;
		++index;
	}
}

void	flags_init(const char *format, int *flags)
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
		if (format[index] == '-')
			flags[MINUS] = 1;
		if (format[index] == '0')
			flags[ZERO] = 1;
		if (format[index] == '.')
			flags[DOT] = 1;
		++index;
	}
}