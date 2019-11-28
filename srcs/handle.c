/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:39:34 by estina            #+#    #+#             */
/*   Updated: 2019/11/28 05:20:57 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	handle_align():
**	In case that width_precision is bigger than len, reduces the spaces_zeros
**	size by width_precision - length. Then prints spaces while spaces_zeros
**	is bigger than length.
*/

static void	handle_align(int *size, t_flags *flags, int len, char *str)
{
	if (flags->width_precision > len)
	{
		flags->spaces_zeros -= flags->width_precision - len;
		if (*str == '-' || *str == '+')
			len++;
	}
	while (flags->spaces_zeros-- > len)
	{
		ft_putstr_fd(" ", 1);
		(*size)++;
	}
}

/*
**	handle_zeros():
**	If Zero flag is active, prints 0 while spaces_zeros is bigger than length.
**	Otherwise prints 0 while width_precision is bigger than length. Ignores the
**	sign of the number.
*/

static void	handle_zeros(int *size, t_flags *flags, int *len, char *str)
{
	int		*chars;

	if (flags->flag_zero)
		chars = &flags->spaces_zeros;
	else
		chars = &flags->width_precision;
	if (*str == '-' || *str == '+')
	{
		ft_putstr_fd((*str == '-' ? "-" : "+"), 1);
		if (flags->flag_point)
		{
			(*size)++;
			(*len)--;
		}
	}
	while (*chars > *len)
	{
		ft_putstr_fd("0", 1);
		(*size)++;
		flags->spaces_zeros--;
		flags->width_precision--;
	}
}

/*
**	check_point():
**	If the point flag is active with 0 width/precision, then the pointer
**	to the string is moved to the end. In this case, the number will not
**	be written. The length is set to 0.
*/

static void	check_point(t_flags *flags, int *len, char **str)
{
	*len = ft_strlen(*str);
	if (flags->flag_point && !flags->width_precision)
	{
		if (**str == '0')
		{
			*str += *len;
			*len = 0;
		}
		else if (!ft_strncmp(*str, "+0", 2))
		{
			free(*str);
			*str = ft_strdup("+");
			*len = 1;
		}
	}
}

static void	check_plus(t_flags *flags, char **str)
{
	char	*aux;

	if (flags->flag_plus == 1)
	{
		if (**str != '-')
		{
			aux = ft_strjoin("+", *str);
			*str = aux;
		}
	}
	if (flags->flag_plus == 2 && **str != '-')
	{
		ft_putstr_fd(" ", 1);
		flags->spaces_zeros--;
	}
}

/*
**	handle():
**	Handler for all kind of number formats(int, hex, unsigned int, etc)
**	Firstly checks if the point flag is active with 0 width/precision.
**	If Align_right flag is active, handles it. If Zero's or Point's flag
**		is active, handles it too. Then the sign and prints the number.
**	Minus flag also is checked at the end. Return 0 if the string is NULL.
**	Return 1 in any other case.
*/

int			handle(int *size, t_flags *flags, char *str)
{
	int		len;

	if (!str)
		return (0);
	check_plus(flags, &str);
	check_point(flags, &len, &str);
	if (flags->flag_align_right)
		handle_align(size, flags, len, str);
	if (flags->flag_zero || flags->flag_point)
		handle_zeros(size, flags, &len, str);
	if ((flags->flag_zero || flags->flag_point) && (*str == '-' || *str == '+'))
	{
		str++;
		flags->spaces_zeros--;
	}
	ft_putstr_fd(str, 1);
	if (flags->flag_minus)
		handle_align(size, flags, len, str);
	*size += len;
	return (1);
}
