/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 13:08:37 by estina            #+#    #+#             */
/*   Updated: 2019/11/28 05:38:15 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_flags
{
	int			flag_minus;
	int			flag_point;
	int			flag_zero;
	int			flag_align_right;
	int			flag_plus;
	int			flag_ll;
	int			flag_sharp;
	int			flag_hh;

	int			spaces_zeros;
	int			width_precision;
}				t_flags;

void			flag_minus_handle(va_list ap, char **str, t_flags *flags);
void			flag_none_handle(va_list ap, char **str, t_flags *flags);
void			flag_point_handle(va_list ap, char **str, t_flags *flags);
void			flag_zero_handle(va_list ap, char **str, t_flags *flags);

void			handle_char(int *size, va_list ap, t_flags *flags, char c);
void			handle_float(int *size, t_flags *flags, va_list ap);
void			handle_n(char **str, va_list ap, int *size);
void			handle_plus(t_flags *flags, int *len, char *str);
int				handle_pointer(int *size, t_flags *flags, char **str);
int				handle_string(int *size, va_list ap, t_flags *flags);
void			handle_types(char **str, va_list ap, int *size, t_flags *flags);
int				handle(int *size, t_flags *flags, char *str);
void			handle_unsigned(va_list ap, int *size, t_flags *flags);

char			*hex_itoa(unsigned long nbr, int upper);
char			*long_itoa(long int n);
char			*long_long_itoa(long long int n);
char			*unsigned_itoa(unsigned long int n);
char			*unsigned_long_itoa(unsigned long long int n);

int				ft_printf(const char *format, ...);

#endif
