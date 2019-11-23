/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 00:01:48 by estina            #+#    #+#             */
/*   Updated: 2019/11/23 19:19:55 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_init(char *aux, int *size, t_flags *flags)
{
	int		len;

	if (!flags->flag_point)
		flags->spaces_zeros -= ft_strlen(aux);
	if (!flags->flag_minus)
	{
		if (flags->width_precision == 0)
			len = 0;
		else if (flags->width_precision < (int)ft_strlen(aux))
			len = flags->width_precision;
		else
			len = (int)ft_strlen(aux);
		while ((flags->spaces_zeros-- - len) > 0)
		{
			ft_putchar_fd(' ', 1);
			(*size)++;
		}
	}
}

static void	print_chars(char *aux, int *size, t_flags *flags)
{
	if (flags->width_precision > 0
		&& (flags->width_precision < (int)ft_strlen(aux)))
		while (flags->width_precision-- > 0)
		{
			ft_putchar_fd(*aux, 1);
			aux++;
			(*size)++;
		}
	else if (flags->flag_point && flags->width_precision == 0)
		return ;
	else
	{
		*size += ft_strlen(aux);
		ft_putstr_fd(aux, 1);
	}
}

static void	print_end(char *aux, int *size, t_flags *flags, int len)
{
	if (flags->flag_minus)
	{
		if (len > (int)ft_strlen(aux))
			len = (int)ft_strlen(aux);
		while ((flags->spaces_zeros-- - len) > 0)
		{
			ft_putchar_fd(' ', 1);
			(*size)++;
		}
	}
}

int			handle_string(int *size, va_list ap, t_flags *flags)
{
	char	*aux;
	int		len;

	len = 0;
	aux = va_arg(ap, char*);
	if (!aux)
	{
		aux = ft_strdup("(null)");
	}
	print_init(aux, size, flags);
	len = flags->width_precision;
	print_chars(aux, size, flags);
	print_end(aux, size, flags, len);
	return (1);
}
