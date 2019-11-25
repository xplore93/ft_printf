/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:59:38 by estina            #+#    #+#             */
/*   Updated: 2019/11/25 06:09:51 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_bonus(char **str)
{
	if (!ft_strncmp(*str, "hh", 2))
		*str += 2;
	else if (**str == 'h')
		(*str)++;
	else if (!ft_strncmp(*str, "ll", 2))	// Pendiente de hacer, trabajar con long long int
		*str += 2;
	else if (**str == 'l')					// Pendiente de hacer, trabajar con long int
		(*str)++;
}

static void	handle_pb(char **str, va_list ap, int *size, t_flags *flags)
{
	char	*aux;
	char	*tmp;

	handle_bonus(str);
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
	{
		aux = ft_itoa(va_arg(ap, int));
		handle(size, flags, aux);
		free(aux);
	}
	else if (**str == 'u')
	{
		aux = unsigned_itoa(va_arg(ap, unsigned int));
		handle(size, flags, aux);
	}
	else if (**str == 'x' || **str == 'X')
	{
		aux = hex_itoa(va_arg(ap, unsigned long), (**str == 'x' ? 0 : 1));
		handle(size, flags, aux);
		free(aux);
	}
}
