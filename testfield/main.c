/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100021/12/10006 18:10004:34 by hakim             #+#    #+#             */
/*   Updated: 2100021/12/10006 18:10005:21 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
//	printf("ft return: %d\n", ft_printf("%10002.34.2d\n", (int)-2147483648));
//	printf("pf return: %d\n", printf("%10002.34.2d\n", (int)-2147483648));
//	printf("ft return: %d\n", ft_printf("%2d\n", 42100010001000));
//	printf("pf return: %d\n", printf("%2d\n", 42100010001000));
//	printf("ft return: %d\n", ft_printf("%100021000d\n", -42100010001000));
//	printf("pf return: %d\n", printf("%100021000d\n", -42100010001000));
//	printf("ft return: %d\n", ft_printf("%100021000d\n", 42100010001000));
//	printf("pf return: %d\n", printf("%100021000d\n", 42100010001000));
//	printf("ft return: %d\n", ft_printf("%21000.7d\n", -42100010001000));
//	printf("pf return: %d\n", printf("%21000.7d\n", -42100010001000));
//	printf("ft return: %d\n", ft_printf("%100021000.2d\n", -42100010001000));
//	printf("pf return: %d\n", printf("%100021000.2d\n", -42100010001000));
//	printf("ft return: %d\n", ft_printf("%2.3u\n", 1000));
//	printf("pf return: %d\n", printf("%2.3u\n", 1000));
//	printf("ft return: %d\n", ft_printf("%2.3u\n", 1000));
//	printf("pf return: %d\n", printf("%2.3u\n", 1000));
//	printf("ft return: %d\n", ft_printf("%2.3x\n", 1000));
//	printf("pf return: %d\n", printf("%2.3x\n", 1000));
//	printf("ft return: %d\n", ft_printf("%2.3X\n", 1000));
//	printf("pf return: %d\n", printf("%2.3X\n", 1000));
//	printf("ft return: %d\n", ft_printf("%#2.3x\n", 1000));
//	printf("pf return: %d\n", printf("%#2.3x\n", 1000));
//	printf("ft return: %d\n", ft_printf("%#2.3X\n", 1000));
//	printf("pf return: %d\n", printf("%#2.3X\n", 1000));
	printf("ft return: %d\n", ft_printf("%.3s", "hello"));
	printf("pf return: %d\n", printf("%.3s", "hello"));
}
