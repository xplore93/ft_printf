/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:59:38 by estina            #+#    #+#             */
/*   Updated: 2019/11/23 21:28:13 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	point(va_list ap, int *size, t_flags *flags)
{
	char	*aux;

	aux = ft_strjoin("0x", hex_itoa(va_arg(ap, unsigned long), 0));
	handle_pointer(size, flags, &aux);
}

static int	bonus_cases(char **str, va_list ap, int *size)
{
	int		*i;

	if (!ap)
		return (0);
	if (**str == 'n')
	{
		i = va_arg(ap, int*);
		*i = *size;
		return (1);
	}
	return (0);
}

static void	handle_int(t_flags *flags, va_list ap, int *size)
{
	int		num;
	char	*number;

	num = va_arg(ap, int);
	number = ft_itoa(num);
	if (flags->flag_plus && num >= 0)
		number = ft_strjoin("+", number);
	handle(size, flags, number);
	free(number);
}

void		handle_types(char **str, va_list ap, int *size, t_flags *flags)
{
	if (bonus_cases(str, ap, size))
		return ;
	else if (**str == 'c' || **str == '%')
		handle_char(size, ap, flags, **str);
	else if (**str == 's')
		handle_string(size, ap, flags);
	else if (**str == 'i' || **str == 'd')
		handle_int(flags, ap, size);
	else if (**str == 'u')
		handle(size, flags, unsigned_itoa(va_arg(ap, unsigned int)));
	else if (**str == 'x')
		handle(size, flags, hex_itoa(va_arg(ap, unsigned long), 0));
	else if (**str == 'X')
		handle(size, flags, hex_itoa(va_arg(ap, unsigned long), 1));
	else if (**str == 'p')
		point(ap, size, flags);
	else
		return ;
}
