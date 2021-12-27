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

# define TRUE 1
# define FALSE -1

typedef char	t_bool;
typedef struct s_options
{
	t_bool	flags[49];
	int		precision;
	int		width;
}	t_options;

int		ft_printf(const char *format, ...);
int		f_proc(const char *format, int *index, va_list ap,
			int (*func[])(va_list, t_options));
int		find_conv(const char *format);
int		write_c(va_list ap, t_options options);
int		write_s(va_list	ap, t_options options);
int		write_p(va_list ap, t_options options);
int		write_d(va_list ap, t_options options);
int		write_u(va_list ap, t_options options);
int		write_x(va_list ap, t_options options);
int		write_0(va_list ap, t_options options);
int		write_5(va_list ap, t_options options);
int		get_length_d(int d, t_options options);
int		get_length_u(unsigned int u);
int		get_length_x(unsigned int u, t_options options);
int		print_integer(int d, t_options options, int length);
int		print_integer_zero(int d, t_options options, int length);
int		print_uinteger(unsigned int d, t_options options, int length);
int		print_hex(unsigned int u, t_options options, int length);
int		print_he0(unsigned int u, t_options options, int length);
int		print_ptr(int index, int count, char *toprint, t_options options);
int		ft_putnbr_precision(long long n, int length, t_options options);
int		ft_putui_precision(unsigned int u, int length, t_options options);
int		ft_putx_precision(unsigned int u, int length, t_options options);
int		ft_put0_precision(unsigned int u, int length, t_options options);
int		ft_atoi(const char *str, int *outdex);
int		proc_sign_dp(int sign, t_options options);
int		proc_sign_x(unsigned int u, t_options options);
int		proc_sign_0(unsigned int u, t_options options);
int		set_toprint(t_options options, char *s);
void	func_init(int (*func[])(va_list, t_options));
void	options_init(t_options *options);
t_bool	is_flag(const char *format);
size_t	ft_strlen(const char *str);

#endif
