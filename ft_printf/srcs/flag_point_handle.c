/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_point_handle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 01:53:06 by estina            #+#    #+#             */
/*   Updated: 2019/11/24 19:49:35 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_flag(int num, t_flags *flags)
{
	flags->flag_point = 1;
	flags->width_precision = num;
	if (flags->flag_zero)
		flags->flag_align_right = 1;
	flags->flag_zero = 0;
}

static void	size_count(int aux, int *size)
{
	while (aux >= 10)
	{
		aux /= 10;
		(*size)++;
	}
}

void		flag_point_handle(va_list ap, char **str, t_flags *flags)
{
	int		num;
	int		aux;
	int		size;

	(*str)++;
	num = 0;
	if (**str == '*')
	{
		num = va_arg(ap, int);
		(*str)++;
	}
	else if (ft_isdigit(**str))
	{
		num = ft_atoi(*str);
		aux = num;
		size = 1;
		while (**str == '0' && ft_isdigit(*(*str + 1)))
			(*str)++;
		size_count(aux, &size);
		*str += size;
	}
	set_flag(num, flags);
}
