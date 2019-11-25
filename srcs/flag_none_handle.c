/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_none_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 01:55:10 by estina            #+#    #+#             */
/*   Updated: 2019/11/24 19:37:49 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_flags(int num, t_flags *flags)
{
	if (num < 0)
	{
		flags->flag_minus = 1;
		flags->spaces_zeros = -num;
	}
	else
	{
		flags->flag_align_right = 1;
		flags->spaces_zeros = num;
	}
}

void		flag_none_handle(va_list ap, char **str, t_flags *flags)
{
	int		num;
	int		aux;
	int		size;

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
		while (aux >= 10)
		{
			aux /= 10;
			size++;
		}
		*str += size;
	}
	else
		num = 0;
	set_flags(num, flags);
}
