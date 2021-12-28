/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:04:34 by hakim             #+#    #+#             */
/*   Updated: 2021/12/06 18:05:21 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	printf("ft return: %d\n", ft_printf("%+6.5d\n", -14));
	printf("pf return: %d\n", printf("%+6.5d\n", -14));
	printf("ft return: %d\n", ft_printf("%2.3d\n", 1000));
	printf("pf return: %d\n", printf("%2.3d\n", 1000));
	printf("ft return: %d\n", ft_printf("%2.3u\n", 1000));
	printf("pf return: %d\n", printf("%2.3u\n", 1000));
	printf("ft return: %d\n", ft_printf("%2.3x\n", 1000));
	printf("pf return: %d\n", printf("%2.3x\n", 1000));
	printf("ft return: %d\n", ft_printf("%2.3X\n", 1000));
	printf("pf return: %d\n", printf("%2.3X\n", 1000));
	printf("ft return: %d\n", ft_printf("%#2.3x\n", 1000));
	printf("pf return: %d\n", printf("%#2.3x\n", 1000));
	printf("ft return: %d\n", ft_printf("%#2.3X\n", 1000));
	printf("pf return: %d\n", printf("%#2.3X\n", 1000));
	printf("ft return: %d\n", ft_printf("%.3s", "hello"));
	printf("pf return: %d\n", printf("%.3s", "hello"));
}
