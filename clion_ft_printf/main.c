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

int	main(void)
{
    int  a;
    long long b;
    unsigned int u;

    u = 2147483647 * 2 + 1;
    a = 2147483647;
	printf("%d\n", ft_printf("%s\n%p\n%d\n%i\n%u\n%x\n%X\n", "hello world!", &b, a, a, u, a, a));
    printf("%d\n", printf("%s\n%p\n%d\n%i\n%u\n%x\n%X\n", "hello world!", &b, a, a, u, a, a));
}
