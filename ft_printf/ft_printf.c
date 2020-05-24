/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:35:20 by estina            #+#    #+#             */
/*   Updated: 2019/11/29 21:53:42 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	check_minus_zero():
**	Sets the minus/zero flags to 1 depending of the case.
*/

static void	check_minus_zero(char **str, t_flags *flags)
{
	if (**str == '-')
	{
		flags->flag_minus = 1;
		flags->flag_zero = 0;
	}
	if (**str == '0' && !flags->flag_minus)
		flags->flag_zero = 1;
	if (**str == '+')
		flags->flag_plus = 1;
	if (**str == ' ')
		flags->flag_plus = 2;
	if (**str == '#')
		flags->flag_sharp = 1;
	(*str)++;
}

/*
**	flags_handler():
**	Search all the flags and calls functions to handle each flag.
**	Works with '0-.' flags. If ap is NULL, return.
**	Bonus: works with '+'
*/

static void	flags_handler(char **str, va_list ap, t_flags *flags)
{
	if (!ap)
		return ;
	while (**str == '0' || **str == '-' || **str == '+' ||
		**str == ' ' || **str == '#')
		check_minus_zero(str, flags);
	if (**str == '*' || ft_isdigit(**str))
	{
		if (flags->flag_minus)
			flag_minus_handle(ap, str, flags);
		else if (flags->flag_zero)
			flag_zero_handle(ap, str, flags);
		else
			flag_none_handle(ap, str, flags);
	}
	if (**str == '.')
		flag_point_handle(ap, str, flags);
}

/*
**	init_flags():
**	Sets all the flags to 0.
*/

static void	init_flags(t_flags *flags)
{
	flags->flag_minus = 0;
	flags->flag_point = 0;
	flags->flag_zero = 0;
	flags->flag_align_right = 0;
	flags->flag_plus = 0;
	flags->flag_ll = 0;
	flags->flag_sharp = 0;
	flags->spaces_zeros = 0;
	flags->width_precision = 0;
	flags->flag_hh = 0;
}

/*
**	check_percent():
**	If % encountered, sets the flags to 0
**		and call flags_handler() to handle flags.
**	Then calls handle_types() to handle the conversions.
**	Else prints the character to STDOUT
*/

static void	check_percent(char **str, t_flags *flags, va_list ap, int *size)
{
	if (**str == '%')
	{
		(*str)++;
		init_flags(flags);
		flags_handler(str, ap, flags);
		handle_types(str, ap, size, flags);
	}
	else
	{
		ft_putchar_fd(**str, 1);
		(*size)++;
	}
}

/*
**	Main function:
**	for each iteration of the loop, calls check_percent() while the string
**	is not ended.
*/

int			ft_printf(const char *format, ...)
{
	int		size;
	char	*str;
	va_list	ap;
	t_flags	flags;

	size = 0;
	str = (char*)format;
	va_start(ap, format);
	while (*str)
	{
		check_percent(&str, &flags, ap, &size);
		if (!*str)
			break ;
		str++;
	}
	va_end(ap);
	return (size);
}
