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
	printf("ft return: %d\n", ft_printf("%0014.2d\n", (int)-2147483648));
	printf("pf return: %d\n", printf("%0014.2d\n", (int)-2147483648));
	printf("ft return: %d\n", ft_printf("%2d\n", 42000));
	printf("pf return: %d\n", printf("%2d\n", 42000));
	printf("ft return: %d\n", ft_printf("%020d\n", -42000));
	printf("pf return: %d\n", printf("%020d\n", -42000));
	printf("ft return: %d\n", ft_printf("%020d\n", 42000));
	printf("pf return: %d\n", printf("%020d\n", 42000));
	printf("ft return: %d\n", ft_printf("%20.7d\n", -42000));
	printf("pf return: %d\n", printf("%20.7d\n", -42000));
	printf("ft return: %d\n", ft_printf("%020.2d\n", -42000));
	printf("pf return: %d\n", printf("%020.2d\n", -42000));
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
	printf("ft return: %d\n", ft_printf("%-5.7s", "us"));
	printf("pf return: %d\n", printf("%-5.7s", "us"));
}
