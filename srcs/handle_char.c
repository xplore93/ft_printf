/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:01:25 by estina            #+#    #+#             */
/*   Updated: 2019/11/23 16:28:31 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_zeros(int *size, t_flags *flags)
{
	while (flags->spaces_zeros-- > 1)
	{
		ft_putchar_fd('0', 1);
		(*size)++;
	}
}

static void	print_spaces(int *size, t_flags *flags)
{
	while (flags->spaces_zeros-- > 1)
	{
		ft_putchar_fd(' ', 1);
		(*size)++;
	}
}

void		handle_char(int *size, va_list ap, t_flags *flags, char c)
{
	if (!flags->flag_minus && !flags->flag_zero)
		print_spaces(size, flags);
	if (flags->flag_zero)
		print_zeros(size, flags);
	(*size)++;
	if (c == 'c')
		ft_putchar_fd((char)va_arg(ap, int), 1);
	else
		ft_putchar_fd('%', 1);
	if (flags->flag_minus)
		print_spaces(size, flags);
}
