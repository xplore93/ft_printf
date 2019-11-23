/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:11:06 by estina            #+#    #+#             */
/*   Updated: 2019/11/23 16:30:09 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_zero(int *size, t_flags *flags, char **str)
{
	ft_putstr_fd("0x", 1);
	*str += 2;
	*size += 2;
	flags->spaces_zeros -= ft_strlen(*str) + 2;
	while (flags->spaces_zeros-- > 0)
	{
		ft_putchar_fd('0', 1);
		(*size)++;
	}
}

static void	flag_minus_none(int *size, t_flags *flags, char **str)
{
	flags->spaces_zeros -= ft_strlen(*str);
	while (flags->spaces_zeros-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*size)++;
	}
}

static void	spaces_zeros(int *size, t_flags *flags, char **str)
{
	size_t	len;

	len = ft_strlen(*str);
	if (**str == '-')
		flags->spaces_zeros--;
	if ((flags->spaces_zeros - len) > (flags->width_precision - len))
		if (!flags->flag_minus && !flags->flag_zero)
		{
			if (flags->width_precision <= (int)len)
				flags->width_precision = 0;
			while (flags->spaces_zeros-- > flags->width_precision)
			{
				ft_putchar_fd(' ', 1);
				(*size)++;
			}
		}
}

static void	flag_point(int *size, t_flags *flags, char **str)
{
	ft_putstr_fd("0x", 1);
	*str += 2;
	*size += 2;
	flags->spaces_zeros -= ft_strlen(*str) + 2;
	spaces_zeros(size, flags, str);
	flags->width_precision -= ft_strlen(*str);
	if (**str == '-')
		flags->width_precision++;
	if (**str == '-' && flags->width_precision > 0)
	{
		ft_putchar_fd(**str, 1);
		(*size)++;
		(*str)++;
	}
	while (flags->width_precision-- > 0)
	{
		ft_putchar_fd('0', 1);
		(*size)++;
		flags->spaces_zeros--;
	}
}

int			handle_pointer(int *size, t_flags *flags, char **str)
{
	if (!*str)
		return (0);
	if (!ft_strncmp("0x0", *str, 4) && !flags->width_precision)
		if (flags->flag_point)
		{
			free(*str);
			*str = "0x";
		}
	if (flags->flag_point && flags->width_precision > (int)ft_strlen(*str))
		flag_point(size, flags, str);
	if (flags->flag_zero)
		flag_zero(size, flags, str);
	if (flags->spaces_zeros && !flags->flag_minus)
		flag_minus_none(size, flags, str);
	ft_putstr_fd(*str, 1);
	*size += ft_strlen(*str);
	if (flags->flag_minus)
		flag_minus_none(size, flags, str);
	return (1);
}
