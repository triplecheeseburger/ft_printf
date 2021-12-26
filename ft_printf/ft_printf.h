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

typedef char t_bool;
typedef struct	s_options
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
int		print_null_ptr(int count, t_options options);
int		print_ptr(int index, int count, char *toprint, t_options options);
int		proc_sign_dp(int sign, t_options *options);
int		ft_putnbr(int n);
int		ft_putui(unsigned int u);
int		ft_putx(unsigned int u);
int		ft_put0(unsigned int u);
int		ft_atoi(const char *str, int *outdex);
void	ft_bzero(void *s, size_t n);
void	func_init(int (*func[])(va_list, t_options));
void	options_init(t_options *options);
t_bool	is_flag(const char *format);
size_t	ft_strlen(const char *str);
size_t	set_toprint(t_options options, char *s);

#endif
