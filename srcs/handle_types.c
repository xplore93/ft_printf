/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:59:38 by estina            #+#    #+#             */
/*   Updated: 2019/11/26 05:03:25 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_bonus(char **str, t_flags *flags, int *size, va_list ap)
{
	if (!ft_strncmp(*str, "hh", 2))
		*str += 2;
	else if (**str == 'h')
		(*str)++;
	else if (!ft_strncmp(*str, "ll", 2))
	{
		flags->flag_ll = 2;
		*str += 2;
	}
	else if (**str == 'l')
	{
		flags->flag_ll = 1;
		(*str)++;
	}
	else if (**str == 'f')
		handle_float(size, flags, ap);
}

static void	handle_pb(char **str, va_list ap, int *size, t_flags *flags)
{
	char	*aux;
	char	*tmp;

	handle_bonus(str, flags, size, ap);
	if (**str == 'p')
	{
		tmp = hex_itoa(va_arg(ap, unsigned long), 0);
		aux = ft_strjoin("0x", tmp);
		handle_pointer(size, flags, &aux);
		free(tmp);
	}
	else if (**str == 'n')
		handle_n(str, ap, size);
}

static void	handle_int(t_flags *flags, va_list ap, int *size)
{
	char	*aux;

	if (!flags->flag_ll)
		aux = ft_itoa(va_arg(ap, int));
	else
		aux = long_long_itoa(va_arg(ap, long long int));
	handle(size, flags, aux);
	free(aux);
}

static void	handle_hex(va_list ap, char **str, t_flags *flags, int *size)
{
	char	*aux;

	aux = hex_itoa(va_arg(ap, unsigned long), (**str == 'x' ? 0 : 1));
	if (flags->flag_sharp && *aux != '0')
	{
		if (**str == 'x')
			aux = ft_strjoin("0x", aux);
		else
			aux = ft_strjoin("0X", aux);
		handle_pointer(size, flags, &aux);
	}
	else
	{
		handle(size, flags, aux);
		free(aux);
	}
}

/*
**	handle_types():
**	Depending of the type we introduce in the string, sends each argument to
**	the handler that transforms it into a simple string. Then calls the handle()
**	Bonus: works with 'n'
*/

void		handle_types(char **str, va_list ap, int *size, t_flags *flags)
{
	char	*aux;

	handle_pb(str, ap, size, flags);
	if (**str == 'c' || **str == '%')
		handle_char(size, ap, flags, **str);
	else if (**str == 's')
		handle_string(size, ap, flags);
	else if (**str == 'i' || **str == 'd')
		handle_int(flags, ap, size);
	else if (**str == 'u')
	{
		aux = unsigned_itoa(va_arg(ap, unsigned long long int));
		handle(size, flags, aux);
	}
	else if (**str == 'x' || **str == 'X')
		handle_hex(ap, str, flags, size);
}
