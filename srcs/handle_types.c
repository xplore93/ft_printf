/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:59:38 by estina            #+#    #+#             */
/*   Updated: 2019/12/02 15:22:30 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_bonus(char **str, t_flags *flags)
{
	if (!ft_strncmp(*str, "hh", 2))
	{
		flags->flag_hh = 2;
		*str += 2;
	}
	else if (**str == 'h')
	{
		flags->flag_hh = 1;
		(*str)++;
	}
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
}

static int	handle_pb(char **str, va_list ap, int *size, t_flags *flags)
{
	char	*aux;
	char	*tmp;

	handle_bonus(str, flags);
	if (**str == 'f')
	{
		handle_float(size, flags, ap);
		return (1);
	}
	else if (**str == 'p')
	{
		tmp = hex_itoa(va_arg(ap, unsigned long), 0);
		aux = ft_strjoin("0x", tmp);
		handle_pointer(size, flags, &aux);
		free(tmp);
		return (1);
	}
	else if (**str == 'n')
	{
		handle_n(ap, size);
		return (1);
	}
	return (0);
}

static void	handle_int(t_flags *flags, va_list ap, int *size)
{
	char	*aux;

	if (!flags->flag_ll && !flags->flag_hh)
		aux = ft_itoa(va_arg(ap, int));
	else if (flags->flag_ll == 2)
		aux = long_long_itoa(va_arg(ap, long long int));
	else if (flags->flag_ll == 1)
		aux = long_itoa(va_arg(ap, long int));
	else if (flags->flag_hh == 1)
		aux = ft_itoa((short)va_arg(ap, int));
	else
		aux = ft_itoa((char)va_arg(ap, int));
	handle(size, flags, aux);
	free(aux);
}

static void	handle_hex(va_list ap, char **str, t_flags *flags, int *size)
{
	char	*aux;

	aux = pointer_handler(flags, ap, str);
	if (flags->flag_sharp && *aux != '0')
	{
		if (**str == 'x')
			aux = ft_strjoin("0x", aux);
		else
			aux = ft_strjoin("0X", aux);
		handle_pointer(size, flags, &aux);
	}
	else
		handle(size, flags, aux);
	free(aux);
}

/*
**	handle_types():
**	Depending of the type we introduce in the string, sends each argument to
**	the handler that transforms it into a simple string. Then calls the handle()
**	Bonus: works with 'n'
*/

void		handle_types(char **str, va_list ap, int *size, t_flags *flags)
{
	if (handle_pb(str, ap, size, flags))
		return ;
	if (**str == 'c' || **str == '%')
		handle_char(size, ap, flags, **str);
	else if (**str == 's')
		handle_string(size, ap, flags);
	else if (**str == 'i' || **str == 'd')
		handle_int(flags, ap, size);
	else if (**str == 'u')
		handle_unsigned(ap, size, flags);
	else if (**str == 'x' || **str == 'X')
		handle_hex(ap, str, flags, size);
	else
	{
		ft_putchar_fd(**str, 1);
		(*size)++;
	}
}
