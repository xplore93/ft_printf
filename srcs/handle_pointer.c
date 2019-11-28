/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:11:06 by estina            #+#    #+#             */
/*   Updated: 2019/11/28 05:29:18 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_right(int *size, t_flags *flags, char **str)
{
	if (flags->width_precision > (int)ft_strlen(*str))
		flags->spaces_zeros -= flags->width_precision + 2;
	else
		flags->spaces_zeros -= ft_strlen(*str);
	while (flags->spaces_zeros-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*size)++;
	}
}

static void	flag_minus(int *size, t_flags *flags, char **str)
{
	if (!flags->flag_align_right)
		flags->spaces_zeros -= ft_strlen(*str);
	if (flags->flag_point)
		flags->spaces_zeros -= 2;
	while (flags->spaces_zeros-- > 0)
	{
		ft_putchar_fd(' ', 1);
		(*size)++;
	}
}

static void	flag_point(int *size, t_flags *flags, char **str)
{
	int		*chars;

	if (flags->flag_zero)
		chars = &flags->spaces_zeros;
	else
		chars = &flags->width_precision;
	ft_putchar_fd(**str, 1);
	(*str)++;
	ft_putchar_fd(**str, 1);
	(*str)++;
	*size += 2;
	if (flags->flag_zero)
		*chars -= 2;
	while (*chars > (int)ft_strlen(*str))
	{
		ft_putchar_fd('0', 1);
		(*size)++;
		flags->spaces_zeros--;
		flags->width_precision--;
	}
}

int			handle_pointer(int *size, t_flags *flags, char **str)
{
	if (!str)
		return (0);
	if (!ft_strncmp("0x0", *str, 4) && !flags->width_precision)
		if (flags->flag_point)
		{
			free(*str);
			*str = "0x";
		}
	if (flags->flag_align_right)
		flag_right(size, flags, str);
	if (flags->flag_point || flags->flag_zero)
		flag_point(size, flags, str);
	ft_putstr_fd(*str, 1);
	*size += ft_strlen(*str);
	if (flags->flag_minus)
		flag_minus(size, flags, str);
	return (1);
}
