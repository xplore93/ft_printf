/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estina <estina@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 01:49:53 by estina            #+#    #+#             */
/*   Updated: 2019/11/24 19:38:16 by estina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	chage_flag(int num, t_flags *flags)
{
	num *= -1;
	flags->flag_zero = 0;
	flags->flag_minus = 1;
	flags->spaces_zeros = num;
}

void		flag_zero_handle(va_list ap, char **str, t_flags *flags)
{
	int		num;
	int		aux;
	int		size;

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
		while (aux >= 10)
		{
			aux /= 10;
			size++;
		}
		*str += size;
	}
	flags->spaces_zeros = num;
	if (num < 0)
		chage_flag(num, flags);
}
