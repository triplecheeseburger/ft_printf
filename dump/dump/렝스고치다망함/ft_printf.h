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
typedef struct s_opts
{
	t_bool	flags[49];
	int		prec;
	int		width;
}	t_options;

int		ft_printf(const char *format, ...);
int		f_proc(const char *format, int *index, va_list ap,
			int (*func[])(va_list, t_options *));
int		find_conv(const char *format);
int		write_c(va_list ap, t_options *opts);
int		write_s(va_list	ap, t_options *opts);
int		write_p(va_list ap, t_options *opts);
int		write_d(va_list ap, t_options *opts);
int		write_u(va_list ap, t_options *opts);
int		write_x(va_list ap, t_options *opts);
int		write_0(va_list ap, t_options *opts);
int		write_5(va_list ap, t_options *opts);
int		get_length_d(int d, t_options *opts);
int		get_length_u(unsigned int u);
int		get_length_x(unsigned int u, t_options *opts);
int		get_length_s(char *s, t_options *opts);
int		print_integer(int d, t_options *opts);
int		print_uinteger(unsigned int d, t_options *opts);
int		print_hex(unsigned int u, t_options *opts);
int		print_he0(unsigned int u, t_options *opts);
int		print_ptr(int index, int count, char *toprint, t_options *opts);
int		ft_putnbr_prec(long long n, t_options *opts);
int		ft_putui_prec(unsigned int u, t_options *opts);
int		ft_putx_prec(unsigned int u, t_options *opts);
int		ft_put0_prec(unsigned int u, t_options *opts);
int		ft_atoi(const char *str, int *outdex);
int		proc_sign_dp(int sign, t_options *opts);
int		proc_sign_x(unsigned int u, t_options *opts);
int		proc_sign_0(unsigned int u, t_options *opts);
void	func_init(int (*func[])(va_list, t_options *));
void	opts_init(t_options *opts);
t_bool	is_flag(const char *format);
size_t	ft_strlen(const char *str);

#endif
