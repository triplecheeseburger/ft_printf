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

typedef char t_bool;
typedef struct	s_options
{
	t_bool	flags[128];
	int		precision;
	int		width;
}	t_options;

int		ft_printf(const char *format, ...);
int		f_proc(const char *format, int *index, va_list ap,
			int (*func[])(const char *, va_list, t_options));
int		proc_sign(const char *format);
int		find_conv(const char *format);
int		write_c(const char *format, va_list ap, t_options options);
int		write_s(const char *format, va_list	ap, t_options options);
int		write_p(const char *format, va_list ap, t_options options);
int		write_d(const char *format, va_list ap, t_options options);
int		write_u(const char *format, va_list ap, t_options options);
int		write_x(const char *format, va_list ap, t_options options);
int		write_0(const char *format, va_list ap, t_options options);
int		write_5(const char *format, va_list ap, t_options options);
int		ft_putnbr(int n);
int		ft_putui(unsigned int u);
int		ft_putx(unsigned int u);
int		ft_put0(unsigned int u);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	func_init(int (*func[])(const char *, va_list));
void	options_init(t_options options);
t_bool	is_flag(const char *format);

#endif
