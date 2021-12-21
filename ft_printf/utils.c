/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:19:06 by hakim             #+#    #+#             */
/*   Updated: 2021/12/21 16:19:08 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

t_bool	is_flag(const char *format)
{
	char	*flags;
	int		index;

	index = 0;
	flags = "# +-0.";
	while (index < 6)
	{
		if (*format == flags[index])
			return (1);
		++index;
	}
	return (0);
}