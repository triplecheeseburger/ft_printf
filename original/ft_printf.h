/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:34:54 by hakim             #+#    #+#             */
/*   Updated: 2021/12/07 19:49:35 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		f_proc(const char *format, int *index, va_list ap,
			int (*func[])(va_list));
int		find_conv(const char *format);
int		write_c(va_list ap);
int		write_s(va_list	ap);
int		write_p(va_list ap);
int		write_d(va_list ap);
int		write_u(va_list ap);
int		write_x(va_list ap);
int		write_0(va_list ap);
int		write_5(va_list ap);
int		ft_putnbr(int n);
int		ft_putui(unsigned int u);
int		ft_putx(unsigned int u);
int		ft_put0(unsigned int u);
void	func_init(int (*func[])(va_list));

#endif
