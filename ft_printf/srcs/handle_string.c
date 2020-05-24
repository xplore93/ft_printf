/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:01:48 by estina            #+#    #+#             */
/*   Updated: 2019/11/24 20:21:02 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_align(int *size, t_flags *flags, int len)
{
	while (flags->spaces_zeros-- > len)
	{
		ft_putstr_fd(" ", 1);
		(*size)++;
	}
}

static void	handle_point(t_flags *flags, char *str)
{
	while (flags->width_precision-- > 0)
	{
		ft_putchar_fd(*str, 1);
		str++;
	}
}

static void	handle_zero(int *size, t_flags *flags, int len)
{
	while (flags->spaces_zeros-- > len)
	{
		ft_putstr_fd("0", 1);
		(*size)++;
	}
}

int			handle_string(int *size, va_list ap, t_flags *flags)
{
	char	*str;
	int		len;

	str = va_arg(ap, char*);
	if (!str)
	{
		str = ft_strdup("(null)");
	}
	if (flags->flag_point && flags->width_precision < (int)ft_strlen(str))
		len = (flags->width_precision >= 0 ? flags->width_precision
			: ft_strlen(str));
	else
		len = ft_strlen(str);
	if (flags->flag_align_right)
		handle_align(size, flags, len);
	if (flags->flag_zero)
		handle_zero(size, flags, len);
	if (flags->flag_point && flags->width_precision == len)
		handle_point(flags, str);
	else
		ft_putstr_fd(str, 1);
	if (flags->flag_minus)
		handle_align(size, flags, len);
	*size += len;
	return (1);
}
